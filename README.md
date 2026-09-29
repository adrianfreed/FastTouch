# FastTouch
Use this library to detect whether your choice of Arduino pin is being touched.
The technique works with any Arduino pin that has an internal pull up resistor that
can be enabled. It returns a measure of how long it takes for a pin to rise
to a HIGH level after the pull up is enabled. This will be slowed by any
capacitive load added.

## Supported Platforms

- **AVR** (Uno, Mega, Leonardo, Lilypad USB, Flora, Pro Mini, etc.)
- **SAMD21** (Adafruit Playground Express, Feather M0, etc.)
- **Teensy** (2.0, 3.x, 4.x)
- **RP2040 / RP2350** (Raspberry Pi Pico, Pico 2, RP2350B boards)

## Basic Usage

```cpp
#include <FastTouch.h>

void loop() {
    int value = fastTouchRead(pin);
    // 0 = no touch, higher = more capacitance (touch detected)
}
```

`fastTouchRead(pin)` works on all supported platforms. On AVR and SAMD21 it is
implemented as a macro for maximum speed; on Teensy and RP2040/RP2350 it is a
function.

`fastTouchMax()` returns the maximum value `fastTouchRead` can return (11 on
AVR, 23 on SAMD21, 60 on Teensy 3.x, 64 on Teensy 4.x and RP2040/RP2350).

## RP2040 / RP2350 Parallel Multi-Channel API

On RP2040 and RP2350 (including the 48-GPIO RP2350B), the SIO block allows
reading all GPIO pins in a single CPU cycle via `sio_hw->gpio_in`. FastTouch
exploits this to scan any number of channels in parallel — total scan time is
independent of channel count.

This is ideal for musical instruments, touch surfaces, and other applications
where many electrodes must be scanned with minimal latency. A 25-channel scan
completes in well under 5 microseconds at 150 MHz.

### API

```cpp
void fastTouchBegin(uint32_t sense_mask);
```

Call once in `setup()` to initialise all pins in `sense_mask` for capacitive
sensing. Each bit position corresponds to a GPIO number (bit 0 = GP0, etc.).
Configures each pin as GPIO with internal pullup and leaves them discharged.

```cpp
void fastTouchReadAll(uint32_t sense_mask, uint8_t *results, int n_samples);
```

Performs a complete parallel scan:
1. Discharges all pins in `sense_mask` simultaneously (output LOW)
2. Waits 2 microseconds for discharge
3. Releases all pins to input simultaneously (pullups charge)
4. Captures `n_samples` snapshots of `sio_hw->gpio_in` (interrupts disabled)
5. For each pin, counts how many samples were still LOW

Results are stored in `results[]` indexed by GPIO number (e.g. `results[0]`
for GP0, `results[5]` for GP5). Higher values indicate more capacitance
(touch detected). `n_samples` is clamped to 255.

Interrupts are disabled only during the sampling window (~500 ns for 64
samples at 150 MHz), not during the discharge phase.

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

### Compile-Time Guards

The RP2040/RP2350 code is enabled when `ARDUINO_ARCH_RP2040` is defined, which
covers both RP2040 and RP2350 in the Arduino-Pico core. The variant macros
`PICO_RP2350` and `PICO_RP2350B` can be used for further differentiation if
needed.

### Notes

- The single-pin `fastTouchRead(pin)` also works on RP2040/RP2350, using the
  same SIO register approach but for one pin at a time. It calls `gpio_init()`
  automatically on first use of each pin to ensure the pad input buffer is
  enabled.
- The parallel API currently uses a 32-bit mask (GP0-GP29). For RP2350B pins
  30-47 (`gpio_hi_in`), a 64-bit variant could be added in a future release;
  the primary use case of 25 channels on GP0-GP24 is fully covered.
- Uses atomic SIO register writes (`gpio_oe_set`, `gpio_oe_clr`, `gpio_clr`)
  for single-cycle pin state transitions.
- **Pullup strategy:** Internal pullups (~50kΩ) are pre-enabled once in
  `fastTouchBegin()` and left on permanently. During the discharge phase the
  output driver easily overpowers the pullup (~66 µA per pin), holding the pin
  LOW. When OE is cleared the pullup is already live and charging begins
  immediately — no APB pad-register writes in the critical section at all.
  The extra current during discharge (25 pins × 66 µA ≈ 1.65 mA for 2 µs) is
  negligible.
- Requires the Arduino-Pico core (Earle Philhower) with pico-sdk headers:
  `hardware/gpio.h`, `hardware/sync.h`, `hardware/structs/sio.h`.
