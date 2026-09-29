// Parallel 25-channel capacitive touch on RP2350B
// Adrian Freed 2024
//
// Reads GP0-GP24 together through the SIO block: all 25 pins are released
// at once and sampled together, so the sampling does not take longer as
// channels are added. It also compiles for RP2040 and RP2350A.
//
// Check your board before sensing on GP23 and GP24. The Raspberry Pi Pico and
// Pico 2 wire them to the power supply's mode pin and to VBUS sense, and the
// W models to the radio; some RP2350B boards do the same (Pimoroni Pico Plus
// 2: VBUS sense on GP24; its W version: the radio on GP23-GP24). Take such
// pins out of SENSE_MASK.

#if !defined(ARDUINO_ARCH_RP2040)
#error "This example needs an RP2040 or RP2350 board on the Arduino-Pico core"
#endif

#include <FastTouch.h>

const uint32_t SENSE_MASK = 0x1FFFFFF; // GP0-GP24
const int N_CHANNELS = 25;
uint8_t values[32]; // indexed by GPIO number

void setup()
{
  Serial.begin(115200);
  while (!Serial) delay(10);
  fastTouchBegin(SENSE_MASK);
  Serial.println("FastTouch parallel 25-channel RP2350B");
}

void loop()
{
  fastTouchReadAll(SENSE_MASK, values, 64);

  for (int i = 0; i < N_CHANNELS; i++) {
    Serial.print(values[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(20);
}
