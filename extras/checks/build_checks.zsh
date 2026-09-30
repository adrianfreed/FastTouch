#!/bin/zsh
# FastTouch build checks.
#
# Compiles the library's examples and a few probe sketches for every family
# FastTouch supports, runs controls that must fail (including boards FastTouch
# does not support), and reads back, from the disassembly of the six
# fastTouchMax() probe builds that keep the function, the constant it returns.
# Every line marked PASS or FAIL counts; the exit status is 0 only when all of
# them pass.
#
# usage: extras/checks/build_checks.zsh [BASE] [WORKDIR]
#   BASE     optional commit: also build this tree's sketches for the existing
#            examples (and the braid build) against the library as it was at
#            BASE, and compare the .hex/.bin output files byte for byte (build
#            time pinned). Listed for information; not graded.
#   WORKDIR  build scratch, which must not exist yet (default under $TMPDIR)
# env: BRAID_DIR=<PinRoleSwitching>/firmware/braid adds the braid XIAO build
#      with -DBRAID_USE_FASTTOUCH (needs Seeeduino:samd).
#
# Needs zsh, python3, git and arduino-cli with arduino:avr, adafruit:avr,
# adafruit:samd, teensy:avr, rp2040:rp2040 and esp32:esp32 installed (esp32 only
# as an unsupported-board control); BRAID_DIR also needs Seeeduino:samd.
set -u
HERE=${0:A:h}
FT=${HERE:h:h}
BASE=${1:-}
W=${2:-${TMPDIR:-/tmp}/fasttouch-checks-$$}
[[ -e $W ]] && { print -u2 "$W exists; refusing to reuse it"; exit 2 }
mkdir -p $W/sk $W/out || exit 2
A15=$(arduino-cli config get directories.data)/packages
ARMBIN=$(print -r -- $A15/rp2040/tools/pqt-gcc/*/bin(N[1]))
AVRBIN=$(print -r -- $A15/arduino/tools/avr-gcc/*/bin(N[1]))
[[ -n $ARMBIN && -n $AVRBIN ]] || { print -u2 "rp2040 or arduino avr toolchain not found under $A15"; exit 2 }

cp -R $FT/Examples/FastTouch*(/) $W/sk/ || exit 2
mkdir -p $W/sk/probe_rp2350b $W/sk/probe_max
cat > $W/sk/probe_rp2350b/probe_rp2350b.ino <<'EOF'
#include <FastTouch.h>
#if !defined(PICO_RP2350)
#error "not an RP2350 build"
#endif
#if !defined(PICO_RP2350A) || PICO_RP2350A
#error "not an RP2350B build (PICO_RP2350A is undefined or nonzero)"
#endif
uint8_t v[32];
void setup() { Serial.begin(115200); fastTouchBegin(0xFFFFFFFF); }
void loop() { fastTouchReadAll(0xFFFFFFFF, v, 64); Serial.println(fastTouchRead(31) + fastTouchMax() + v[31]); delay(20); }
EOF
cat > $W/sk/probe_max/probe_max.ino <<'EOF'
#include <FastTouch.h>
void setup() { Serial.begin(9600); }
void loop() { Serial.println(fastTouchRead(2)); Serial.println(fastTouchMax()); delay(100); }
EOF

pass=0 fail=0
typeset -a f extra hb wb EX
grade () {  # ok-or-not description
  if [[ $1 == 0 ]]; then pass=$((pass + 1)); print -r -- "PASS | $2"
  else fail=$((fail + 1)); print -r -- "FAIL | $2"; fi
}
# build name fqbn lib sketch expect(ok|fail) [message the failure must contain] -- [extra args]
build () {
  local name=$1 fqbn=$2 lib=$3 sketch=$4 expect=$5; shift 5
  local msg=""; [[ $# -gt 0 && $1 != -- ]] && { msg=$1; shift }
  [[ $# -gt 0 && $1 == -- ]] && shift
  local od=$W/out/$name; mkdir -p $od
  # extra.time.local pinned: Teensy 3.x links the build time in (__rtc_localtime)
  arduino-cli compile -b $fqbn --library $lib --build-path $od/build --output-dir $od/bin \
    --build-property extra.time.local=1700000000 "$@" $W/sk/$sketch > $od/log.txt 2>&1
  local rc=$? size=$(awk '/Sketch uses|FLASH: code/ {sub(/^[ \t]+/, ""); sub(/ of program storage.*/, ""); print; exit}' $od/log.txt)
  if [[ $expect == ok ]]; then
    grade $(( rc != 0 )) "$name | $fqbn | builds | ${size:-rc=$rc}"
  else
    local hit=1; [[ $rc -ne 0 ]] && { [[ -z $msg ]] || grep -qF -- "$msg" $od/log.txt; } && hit=0
    grade $hit "$name | $fqbn | stops${msg:+ with \"$msg\"} | rc=$rc"
  fi
  (( rc != 0 )) && awk '/error:|Error during build/ {sub(/^.*\/(sk|src)\//, ""); print "       " $0; exit}' $od/log.txt
  return 0
}
maxconst () {  # build-name tool-bin-dir expected: the constant fastTouchMax() returns
  local name=$1 dir=$2 want=$3
  local elf=$(print -r -- $W/out/$name/build/*.ino.elf(N[1]))
  local nmb=$(print -r -- $dir/*-nm(N[1])) odb=$(print -r -- $dir/*-objdump(N[1]))
  local line=$([[ -n $elf ]] && $nmb -S $elf | awk '$4 == "_Z12fastTouchMaxv" {print $1, $2; exit}')
  if [[ -z $line ]]; then grade 1 "$name | fastTouchMax() not found in the ELF"; return; fi
  local a=${line% *} z=${line#* }
  local imm=$($odb -d --start-address=0x$a --stop-address=$(( 0x$a + 0x$z )) $elf | awk '
    /ldi[ \t]+r24,/ {for (i = 1; i <= NF; i++) if ($i ~ /^0x/) {gsub(/[^0-9A-Fa-fx]/, "", $i); print $i; exit}}
    /movs[ \t]+r0, #/ {for (i = 1; i <= NF; i++) if ($i ~ /^#/) {gsub(/[^0-9]/, "", $i); print $i; exit}}')
  local got=$(( ${imm:-0} ))
  grade $(( got != want )) "$name | fastTouchMax() returns $got, expected $want"
}

print "FastTouch $(git -C $FT rev-parse --short HEAD)$(git -C $FT diff --quiet HEAD -- src || print ' (src modified)'); $(arduino-cli version)"
print "== 0. AVR pin maps"
python3 $HERE/avr_pinmap_check.py $FT/src/FastTouch.h; grade $? "avr_pinmap_check.py: Port/DDR/PIN macros consistent"

print "== 1. RP2350B example"
build ex-rpipico rp2040:rp2040:rpipico $FT FastTouchParallelRP2350B ok
build ex-rpipico2 rp2040:rp2040:rpipico2 $FT FastTouchParallelRP2350B ok
build ex-rp2350b rp2040:rp2040:generic_rp2350:variantchip=RP2350B $FT FastTouchParallelRP2350B ok
build ex-uno arduino:avr:uno $FT FastTouchParallelRP2350B fail "This example needs an RP2040 or RP2350 board"

print "== 2. RP2350B probe and its control"
build probeB-rp2350b rp2040:rp2040:generic_rp2350:variantchip=RP2350B $FT probe_rp2350b ok
build probeB-control-rpipico2 rp2040:rp2040:rpipico2 $FT probe_rp2350b fail "not an RP2350B build"

print "== 3. fastTouchMax() on each family"
build max-uno arduino:avr:uno $FT probe_max ok
build max-cpx adafruit:samd:adafruit_circuitplayground_m0 $FT probe_max ok
build max-teensy2 teensy:avr:teensy2 $FT probe_max ok
build max-teensy31 teensy:avr:teensy31 $FT probe_max ok
build max-teensyLC teensy:avr:teensyLC $FT probe_max ok
build max-teensy40 teensy:avr:teensy40 $FT probe_max ok
build max-rpipico rp2040:rp2040:rpipico $FT probe_max ok
# uno inlines fastTouchMax (the AVR core links with LTO); teensy2 compiles the same defined(AVR) branch
maxconst max-teensy2 $AVRBIN 11
maxconst max-cpx $ARMBIN 23
maxconst max-teensy31 $ARMBIN 127
maxconst max-teensyLC $ARMBIN 64
maxconst max-teensy40 $ARMBIN 64
maxconst max-rpipico $ARMBIN 64

print "== 4. AVR pin maps: mapped chips build, the rest stop at the pin-map #error"
NOMAP="no pin map for this AVR chip"
build map-mega arduino:avr:mega $FT probe_max ok
build map-pro328 arduino:avr:pro:cpu=16MHzatmega328 $FT probe_max ok
build map-pro168 arduino:avr:pro:cpu=16MHzatmega168 $FT probe_max ok
# build.board overridden with build.mcu, so a board macro of the carrier FQBN
# (ARDUINO_AVR_UNO, ARDUINO_AVR_MEGA2560) cannot pick a map for the chip
build map-644p arduino:avr:uno $FT probe_max ok -- --build-property build.mcu=atmega644p --build-property build.board=AVR_ATMEGA644P
build nomap-1281 arduino:avr:mega $FT probe_max fail "$NOMAP" -- --build-property build.mcu=atmega1281 --build-property build.board=AVR_ATMEGA1281
build nomap-gemma adafruit:avr:gemma $FT probe_max fail "$NOMAP"
build nomap-teensypp2 teensy:avr:teensypp2 $FT probe_max fail "$NOMAP"

print "== 4b. boards outside AVR, SAMD21, Teensy and RP2040/RP2350 stop at the library's #error"
UNSUP="FastTouch supports AVR, SAMD21, Teensy and RP2040/RP2350"
build unsup-samd51 adafruit:samd:adafruit_itsybitsy_m4 $FT probe_max fail "$UNSUP"
build unsup-esp32s3 esp32:esp32:m5stack_capsule $FT probe_max fail "$UNSUP"

print "== 5. existing examples"
EX=(
  "reportlily|arduino:avr:LilyPadUSB|FastTouchSerialReportLilypadUSB"
  "tonelily|arduino:avr:LilyPadUSB|FastTouchSerialToneLilypadUSB"
  "tonecpx|adafruit:samd:adafruit_circuitplayground_m0|FastTouchSerialTonePlaygroundExpress"
  "teensy40|teensy:avr:teensy40|FastTouchSerialReportTeensy"
  "teensyLC|teensy:avr:teensyLC|FastTouchSerialReportTeensy"
  "teensy31|teensy:avr:teensy31|FastTouchSerialReportTeensy"
)
for e in $EX; do f=("${(@s:|:)e}"); build ${f[1]} ${f[2]} $FT ${f[3]} ok; done

if [[ -n ${BRAID_DIR-} ]]; then
  print "== 6. braid XIAO build with FastTouch ($BRAID_DIR)"
  mkdir -p $W/sk/braidsensing && cp $BRAID_DIR/braidsensing.ino $BRAID_DIR/braid_core.* $BRAID_DIR/braid_links.* $W/sk/braidsensing/
  build braid-xiao Seeeduino:samd:seeed_XIAO_m0 $FT braidsensing ok -- --build-property "compiler.cpp.extra_flags=-DBRAID_USE_FASTTOUCH"
  EX+=("braid-xiao|Seeeduino:samd:seeed_XIAO_m0|braidsensing|compiler.cpp.extra_flags=-DBRAID_USE_FASTTOUCH")
fi

if [[ -n $BASE ]]; then
  print "== 7. the same example sketches against the library at $BASE (information, not graded)"
  mkdir -p $W/lib-base && git -C $FT archive $BASE | tar -x -C $W/lib-base || { print -u2 "cannot export $BASE"; exit 2 }
  for e in $EX; do
    f=("${(@s:|:)e}"); extra=(); [[ -n ${f[4]-} ]] && extra=(--build-property ${f[4]})
    od=$W/out/${f[1]}-base; mkdir -p $od
    arduino-cli compile -b ${f[2]} --library $W/lib-base --build-path $od/build --output-dir $od/bin \
      --build-property extra.time.local=1700000000 $extra $W/sk/${f[3]} > $od/log.txt 2>&1
    rc=$?
    hb=($od/bin/*.(hex|bin)(N)); wb=($W/out/${f[1]}/bin/*.(hex|bin)(N))
    if (( rc != 0 || ${#hb} == 0 || ${#hb} != ${#wb} )); then print "   ${f[1]}: not compared (base build rc=$rc, ${#hb} vs ${#wb} files)"; continue; fi
    res=identical
    for i in {1..${#hb}}; do cmp -s ${hb[i]} ${wb[i]} || res="DIFFER in ${hb[i]:t}"; done
    print "   ${f[1]}: ${#hb} output files, $res"
  done
fi

print "== RP2040/RP2350 disassembly of the timed functions: $W/rp-disassembly.txt"
for spec in max-rpipico:_Z13fastTouchReadi ex-rpipico:_Z16fastTouchReadAllmPhi \
            probeB-rp2350b:_Z13fastTouchReadi probeB-rp2350b:_Z16fastTouchReadAllmPhi ex-rpipico2:_Z16fastTouchReadAllmPhi; do
  elf=$(print -r -- $W/out/${spec%%:*}/build/*.ino.elf(N[1])); sym=${spec#*:}
  [[ -z $elf ]] && continue
  print "== ${spec%%:*}: $sym"
  $ARMBIN/arm-none-eabi-objdump -d --no-show-raw-insn --disassemble=$sym $elf | awk '/^ *[0-9a-f]+:/'
done > $W/rp-disassembly.txt 2>&1

print "build checks: $pass passed, $fail failed (work dir $W)"
exit $(( fail > 0 ))
