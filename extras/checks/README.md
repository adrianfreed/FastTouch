# Build checks

These scripts are not part of the library; the Arduino IDE ignores `extras/`.
They back the build claims in the message of commit 80f236a and can be re-run
after any change.

- `build_checks.zsh` compiles the examples and a few probe sketches for every
  family FastTouch supports, runs controls that must fail (including boards
  FastTouch does not support), and reads back, from the disassembly of the
  six `fastTouchMax()` probe builds that keep the function, the constant it
  returns.
- `avr_pinmap_check.py` checks that in each AVR pin map of `src/FastTouch.h`
  the `PORT`, `DDR` and `PIN` macros test the same pin ranges for the same
  port. It fails on the 644 map as it was before 80f236a.

## Running

```sh
extras/checks/build_checks.zsh                # check this tree
extras/checks/build_checks.zsh 632fdea        # also compare the examples' output with 632fdea
BRAID_DIR=~/Documents/PinRoleSwitching/firmware/braid extras/checks/build_checks.zsh
```

The script needs zsh, python3, git and arduino-cli with arduino:avr,
adafruit:avr, adafruit:samd, teensy:avr, rp2040:rp2040 and esp32:esp32
installed (esp32 only as an unsupported-board control), plus Seeeduino:samd
for the braid build. Every line marked PASS or FAIL counts, and
the exit status is 0 only when all of them pass. The comparison with a base
commit is listed for information and not graded.

`results-2026-09-29.txt` is the run on 80f236a with `632fdea` as the base and
the braid build included. It used arduino-cli 1.5.1 with arduino:avr 1.8.8,
adafruit:avr 1.4.15, adafruit:samd 1.7.17, Seeeduino:samd 1.8.6,
teensy:avr 1.62.0, rp2040:rp2040 6.1.1 and esp32:esp32 3.3.12.

## What the sections check

0. The AVR pin maps are consistent (`avr_pinmap_check.py`).
1. `FastTouchParallelRP2350B` builds for rpipico, rpipico2 and
   generic_rp2350 variantchip=RP2350B, and stops with its own `#error` on an
   Uno.
2. A probe builds only when `PICO_RP2350A` is defined and 0: its control, on
   a Pico 2 (RP2350A), must stop at its `#error`. This is how the checks know
   the RP2350B build really targets the 48-GPIO chip, the same test the
   library makes.
3. A `fastTouchMax()` probe builds on uno, Circuit Playground Express,
   teensy2, teensy31, teensyLC, teensy40 and rpipico. The value each build
   returns is read from its disassembly: 11 (Teensy 2.0, standing for AVR),
   23, 127, 64, 64 and 64. The Uno build inlines the function, so it has none
   to read.
4. The AVR pin maps: the Mega, Pro Mini 328 and Pro Mini 168 build. With
   `build.mcu` and `build.board` both overridden, an ATmega644P builds through
   the 644 map, while an ATmega1281, an ATtiny85 Gemma and a Teensy++ 2.0 stop
   at the pin-map `#error`. No 644 core was installed, so the 644 pin
   numbering itself is unchecked.
   4b. A SAMD51 board (ItsyBitsy M4) and an ESP32-S3 board (M5Stack Capsule)
   stop at the library's "FastTouch supports AVR, SAMD21, Teensy and
   RP2040/RP2350" `#error`.
5. The existing examples build for their boards: LilyPad USB, Circuit
   Playground Express, Teensy 4.0, LC and 3.1.
6. With `BRAID_DIR` set, the braid firmware builds for the XIAO M0 with
   FastTouch.
7. With a base commit, this tree's sketches for sections 5 and 6 are built
   against the library as it was at that commit, and the `.hex`/`.bin` output
   files are compared byte for byte. The build time is pinned, because
   Teensy 3.x links it into the image. The RP2350B example is not compared,
   and a base commit's own example sketches are not used: 632fdea's Playground
   Express sketch, for one, does not build.

The RP2040/RP2350 disassembly of `fastTouchRead` and `fastTouchReadAll` is
written to the work directory, for reading the timed loops.
