# FastTouch
Use this library to detect whether your choice of Arduino pin is being touched.
The technique works with any Arduino pin that has an internal pull up resistor that
can be enabled. It returns a measure of how long it takes for a pin to rise
to a HIGH level after the pull up is enabled. This will be slowed by any
capacitive load added.

## Supported Platforms

- **AVR** with an ATmega168/168P/328/328P/328PB, 32U4/16U4, 1280/2560 or
  644/644P (Uno, Pro Mini, Mega, Leonardo, Lilypad USB, Flora, Teensy 2.0,
  etc.)
- **SAMD21** (Adafruit Playground Express, Feather M0, Seeed XIAO M0, etc.)
- **Teensy** (3.x, LC, 4.x)
- **RP2040 / RP2350** (Raspberry Pi Pico, Pico 2, RP2350B boards) on the
  Arduino-Pico core

Other boards stop at compile time with an `#error` that names these.

## Basic Usage

```cpp
#include <FastTouch.h>

void loop() {
    int value = fastTouchRead(pin);
    // 0 = no touch, higher = more capacitance (touch detected)
}
```

`fastTouchRead(pin)` works on all supported platforms. On AVR (including
Teensy 2.0) and SAMD21 it is implemented as a macro for speed; on Teensy 3.x,
LC and 4.x and on RP2040/RP2350 it is a function.

`fastTouchMax()` returns the largest value `fastTouchRead` can return on the
board being compiled for, counted from each implementation:

| Board | `fastTouchMax()` |
|---|---|
| AVR, including Teensy 2.0 | 11 |
| SAMD21 | 23 |
| Teensy 3.x | 127 |
| Teensy LC | 64 |
| Teensy 4.x | 64 |
| RP2040 / RP2350 | 64 |

## RP2040 / RP2350 Parallel Multi-Channel API

On RP2040 and RP2350 one read of the SIO register `sio_hw->gpio_in` returns
the levels of GPIO 0-29 (RP2040) or GPIO 0-31 (RP2350) together. FastTouch
uses this to release a whole set of pins at once and sample them together, so
the sampling does not take longer as channels are added.

Sense pins are GPIO 0-29 on RP2040 and RP2350A, and GPIO 0-31 on RP2350B.
RP2350B's GPIO 32-47 are read through a second register (`gpio_hi_in`) and are
not supported yet.

This suits musical instruments, touch surfaces, and other applications where
many electrodes must be scanned with little latency.

### API

```cpp
void fastTouchBegin(uint32_t sense_mask);
```

Call once in `setup()` to initialise all pins in `sense_mask` for capacitive
sensing. Each bit position corresponds to a GPIO number (bit 0 = GP0, etc.);
bits outside the sense-pin range above are ignored. Each pin becomes a GPIO
with its internal pullup on and is left driven LOW (discharged). Call it again
after any sense pin has been used for something else (`pinMode`, `analogRead`,
a peripheral).

```cpp
void fastTouchReadAll(uint32_t sense_mask, uint8_t *results, int n_samples);
```

Performs a complete parallel scan:
1. Discharges all pins in `sense_mask` together (output LOW)
2. Waits 2 microseconds for discharge
3. Releases all pins to input with one SIO write (the pullups charge them)
4. With interrupts disabled, stores `n_samples` reads of `sio_hw->gpio_in`
5. Discharges the pins again, then counts for each pin how many of the stored
   reads saw it LOW

Storing the reads first means every read runs the same instructions,
whatever the number of channels and however many are still LOW (the spacing
itself has not been measured).

Results are stored in `results[]` indexed by GPIO number (e.g. `results[0]`
for GP0, `results[5]` for GP5), so `results` needs 32 entries whatever the
mask. Higher values indicate more capacitance (touch detected). Each count is
0 to `n_samples`; `n_samples` is clamped to 0-255, and `fastTouchMax()` does
not apply to these counts. The reads go through one static buffer, so do not
call `fastTouchReadAll` from both cores at once or from an interrupt handler.

Interrupts are disabled only while the reads are taken, not during the
discharge or the counting.

### Example: 25 Channels on RP2350B

```cpp
#include <FastTouch.h>

const uint32_t SENSE_MASK = 0x1FFFFFF; // GP0-GP24
uint8_t values[32];

void setup() {
    Serial.begin(115200);
    fastTouchBegin(SENSE_MASK);
}

void loop() {
    fastTouchReadAll(SENSE_MASK, values, 64);
    for (int i = 0; i < 25; i++) {
        Serial.print(values[i]);
        Serial.print(" ");
    }
    Serial.println();
    delay(20);
}
```

Check your board before sensing on GP23 and GP24. The Raspberry Pi Pico and
Pico 2 wire them to the power supply's mode pin and to VBUS sense, and the W
models to the radio; some RP2350B boards do the same (Pimoroni Pico Plus 2:
VBUS sense on GP24; its W version: the radio on GP23-GP24). Leave such pins
out of the mask.

### Compile-Time Guards

The RP2040/RP2350 code is enabled when `ARDUINO_ARCH_RP2040` is defined, which
covers both RP2040 and RP2350 in the Arduino-Pico core. `PICO_RP2350` is
defined on RP2350 builds, and `PICO_RP2350A` tells the two RP2350 packages
apart: it is 1 on RP2350A (for example the Pico 2) and 0 on RP2350B. Do not
define `PICO_RP2350B`: the core stops the build if it is defined.

### Notes

- The single-pin `fastTouchRead(pin)` also works on RP2040/RP2350, using the
  same SIO registers for one pin. On every call it sets the pin's function to
  GPIO, turns its input buffer and pullup on and clears any pad isolation and
  overrides before discharging it, so it keeps working after `pinMode()` or
  `analogRead()` has reconfigured the pin. It does not change the pin's
  interrupt enables, drive strength, slew rate or Schmitt trigger. It returns
  -1 for a pin outside the sense-pin range.
- The mask is 32 bits wide, like `gpio_in` (GPIO 0-29 on RP2040, 0-31 on
  RP2350). Supporting RP2350B's GPIO 32-47 would need a second pass over
  `gpio_hi_in`.
- Uses the atomic SIO set/clear registers (`gpio_oe_set`, `gpio_oe_clr`,
  `gpio_clr`), so one write changes every pin in a mask.
- **Pullup strategy:** Internal pullups (~50kΩ) are switched on before the
  timed section and stay on. During the discharge phase the output driver
  easily overpowers a pullup, holding the pin LOW. When OE is cleared the
  pullup is already live and charging begins immediately, with no APB
  pad-register writes in the timed section. Between reads the sense pins stay
  driven LOW, so each pullup draws current the whole time: about 66 µA per pin
  at 3.3 V and ~50kΩ, or 1.65 mA for 25 pins.
- Requires the Arduino-Pico core (Earle Philhower) with pico-sdk headers:
  `hardware/gpio.h`, `hardware/sync.h`, `hardware/structs/sio.h`.
