#include <FastTouch.h>

// Parallel 25-channel capacitive touch on RP2350B
// Adrian Freed 2024
//
// Reads GP0-GP24 simultaneously using the SIO block.
// All 25 channels are scanned in a single pass — total scan
// time is independent of channel count (~1 us at 150 MHz).

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
