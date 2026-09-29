//
//
//FastTouch.h
// Fast Touch Sensing for AVR, SAMD21, Teensy and RP2040/RP2350
// Copyright (c) 2006-2026 Adrian Freed. MIT License; see LICENSE.
// Tested on Teensy 2.0, Clio, Lilypad,  Lilypad USB, Flora, Leonardo, UNO, Micro, BLEpad, PRO Mini,
// Teensy 3.2 (more sensitive with optimized compiler settings and higher clock rate)
// Teensy 3LC
//

#ifndef FastTouch_h
#define FastTouch_h

#include <Arduino.h>
#if defined(CORE_TEENSY)
#include "core_pins.h"
#endif

#ifndef BIT_SET
# define BIT_SET(value, bit)             ((value) |=  (1UL << (bit)))
#endif



//Arduino
// (the ATmega1281/2561 are not listed: they have no ports H-L, which this map uses)
#if (defined(ARDUINO_AVR_MEGA) || \
defined(ARDUINO_AVR_MEGA1280) || \
defined(ARDUINO_AVR_MEGA2560) || \
defined(__AVR_ATmega1280__) || \
defined(__AVR_ATmega2560__))

#define __digitalPinToPortReg(P) \
(((P) >= 22 && (P) <= 29) ? &PORTA : \
((((P) >= 10 && (P) <= 13) || ((P) >= 50 && (P) <= 53)) ? &PORTB : \
(((P) >= 30 && (P) <= 37) ? &PORTC : \
((((P) >= 18 && (P) <= 21) || (P) == 38) ? &PORTD : \
((((P) >= 0 && (P) <= 3) || (P) == 5) ? &PORTE : \
(((P) >= 54 && (P) <= 61) ? &PORTF : \
((((P) >= 39 && (P) <= 41) || (P) == 4) ? &PORTG : \
((((P) >= 6 && (P) <= 9) || (P) == 16 || (P) == 17) ? &PORTH : \
(((P) == 14 || (P) == 15) ? &PORTJ : \
(((P) >= 62 && (P) <= 69) ? &PORTK : &PORTL))))))))))

#define __digitalPinToDDRReg(P) \
(((P) >= 22 && (P) <= 29) ? &DDRA : \
((((P) >= 10 && (P) <= 13) || ((P) >= 50 && (P) <= 53)) ? &DDRB : \
(((P) >= 30 && (P) <= 37) ? &DDRC : \
((((P) >= 18 && (P) <= 21) || (P) == 38) ? &DDRD : \
((((P) >= 0 && (P) <= 3) || (P) == 5) ? &DDRE : \
(((P) >= 54 && (P) <= 61) ? &DDRF : \
((((P) >= 39 && (P) <= 41) || (P) == 4) ? &DDRG : \
((((P) >= 6 && (P) <= 9) || (P) == 16 || (P) == 17) ? &DDRH : \
(((P) == 14 || (P) == 15) ? &DDRJ : \
(((P) >= 62 && (P) <= 69) ? &DDRK : &DDRL))))))))))

#define __digitalPinToPINReg(P) \
(((P) >= 22 && (P) <= 29) ? &PINA : \
((((P) >= 10 && (P) <= 13) || ((P) >= 50 && (P) <= 53)) ? &PINB : \
(((P) >= 30 && (P) <= 37) ? &PINC : \
((((P) >= 18 && (P) <= 21) || (P) == 38) ? &PIND : \
((((P) >= 0 && (P) <= 3) || (P) == 5) ? &PINE : \
(((P) >= 54 && (P) <= 61) ? &PINF : \
((((P) >= 39 && (P) <= 41) || (P) == 4) ? &PING : \
((((P) >= 6 && (P) <= 9) || (P) == 16 || (P) == 17) ? &PINH : \
(((P) == 14 || (P) == 15) ? &PINJ : \
(((P) >= 62 && (P) <= 69) ? &PINK : &PINL))))))))))

#define __digitalPinToBit(P) \
(((P) >=  7 && (P) <=  9) ? (P) - 3 : \
(((P) >= 10 && (P) <= 13) ? (P) - 6 : \
(((P) >= 22 && (P) <= 29) ? (P) - 22 : \
(((P) >= 30 && (P) <= 37) ? 37 - (P) : \
(((P) >= 39 && (P) <= 41) ? 41 - (P) : \
(((P) >= 42 && (P) <= 49) ? 49 - (P) : \
(((P) >= 50 && (P) <= 53) ? 53 - (P) : \
(((P) >= 54 && (P) <= 61) ? (P) - 54 : \
(((P) >= 62 && (P) <= 69) ? (P) - 62 : \
(((P) == 0 || (P) == 15 || (P) == 17 || (P) == 21) ? 0 : \
(((P) == 1 || (P) == 14 || (P) == 16 || (P) == 20) ? 1 : \
(((P) == 19) ? 2 : \
(((P) == 5 || (P) == 6 || (P) == 18) ? 3 : \
(((P) == 2) ? 4 : \
(((P) == 3 || (P) == 4) ? 5 : 7)))))))))))))))


// --- Arduino 644 ---
#elif (defined(__AVR_ATmega644__) || \
defined(__AVR_ATmega644P__))

#define __digitalPinToPortReg(P) \
(((P) >= 0 && (P) <= 7) ? &PORTB : (((P) >= 8 && (P) <= 15) ? &PORTD : (((P) >= 16 && (P) <= 23) ? &PORTC : &PORTA)))
#define __digitalPinToDDRReg(P) \
(((P) >= 0 && (P) <= 7) ? &DDRB : (((P) >= 8 && (P) <= 15) ? &DDRD : (((P) >= 16 && (P) <= 23) ? &DDRC : &DDRA)))
#define __digitalPinToPINReg(P) \
(((P) >= 0 && (P) <= 7) ? &PINB : (((P) >= 8 && (P) <= 15) ? &PIND : (((P) >= 16 && (P) <= 23) ? &PINC : &PINA)))
#define __digitalPinToBit(P) \
(((P) >= 0 && (P) <= 7) ? (P) : (((P) >= 8 && (P) <= 15) ? (P) - 8 : (((P) >= 16 && (P) <= 23) ? (P) - 16 : (P) - 24)))

#elif defined(__AVR_ATmega32U4__) && defined(CORE_TEENSY)
#define __digitalPinToPortReg(P) \
(((P) == 22 || (P) == 23 || (P) == 5 || (P) == 6 || (P) == 7 || (P) == 8 || (P) == 11 || (P) == 12) ? &PORTD : (((P) == 9 || (P) == 10) ? &PORTC : (((P) >= 17 && (P) <= 21)) ? &PORTF : (((P) == 24) ? &PORTE : &PORTB)))
#define __digitalPinToDDRReg(P) \
(((P) == 22 || (P) == 23 || (P) == 5 || (P) == 6 || (P) == 7 || (P) == 8 || (P) == 11 || (P) == 12) ? &DDRD : (((P) == 9 || (P) == 10) ? &DDRC : (((P) >= 17 && (P) <= 21)) ? &DDRF : (((P) == 24) ? &DDRE : &DDRB)))
#define __digitalPinToPINReg(P) \
(((P) == 22 || (P) == 23 || (P) == 5 || (P) == 6 || (P) == 7 || (P) == 8 || (P) == 11 || (P) == 12) ? &PIND : (((P) == 9 || (P) == 10) ? &PINC : (((P) >= 17 && (P) <= 21)) ? &PINF : (((P) == 24) ? &PINE : &PINB)))
#define __digitalPinToBit(P) \
(((P) >= 0 && (P) <= 3) ? (P)  : (((P) >= 5 && (P) < 9) ?  (P) - 5 : (((P) == 4) ? 7 : (((P) == 9) ? 6 : (((P) == 10) ? 7 : \
(((P) == 11) ? 6 : (((P) == 12) ? 7 : (((P) == 13) ? 4 : (((P) == 14) ? 5 : (((P) == 15) ? 6 : (((P) == 16) ? 7 :\
(((P) == 17) ? 6 : (((P) == 18) ? 5 : (((P) == 19) ? 4 : (((P) == 20) ? 1 : (((P) == 21) ? 0 : (((P) == 22) ? 4 : (((P) == 23) ? 5 :\
(((P) == 24) ? 6 : 6 )))))))))))))))))))

// --- Arduino Leonardo ---
#elif (defined(ARDUINO_AVR_LEONARDO) || \
defined(__AVR_ATmega16U4__) || \
defined(__AVR_ATmega32U4__))


#define __digitalPinToPortReg(P) \
((((P) >= 0 && (P) <= 4) || (P) == 6 || (P) == 12 || (P) == 24 || (P) == 25 || (P) == 29) ? &PORTD : (((P) == 5 || (P) == 13) ? &PORTC : (((P) >= 18 && (P) <= 23)) ? &PORTF : (((P) == 7) ? &PORTE : &PORTB)))
#define __digitalPinToDDRReg(P) \
((((P) >= 0 && (P) <= 4) || (P) == 6 || (P) == 12 || (P) == 24 || (P) == 25 || (P) == 29) ? &DDRD : (((P) == 5 || (P) == 13) ? &DDRC : (((P) >= 18 && (P) <= 23)) ? &DDRF : (((P) == 7) ? &DDRE : &DDRB)))
#define __digitalPinToPINReg(P) \
((((P) >= 0 && (P) <= 4) || (P) == 6 || (P) == 12 || (P) == 24 || (P) == 25 || (P) == 29) ? &PIND : (((P) == 5 || (P) == 13) ? &PINC : (((P) >= 18 && (P) <= 23)) ? &PINF : (((P) == 7) ? &PINE : &PINB)))
#define __digitalPinToBit(P) \
(((P) >= 8 && (P) <= 11) ? (P) - 4 : (((P) >= 18 && (P) <= 21) ? 25 - (P) : (((P) == 0) ? 2 : (((P) == 1) ? 3 : (((P) == 2) ? 1 : (((P) == 3) ? 0 : (((P) == 4) ? 4 : (((P) == 6) ? 7 : (((P) == 13) ? 7 : (((P) == 14) ? 3 : (((P) == 15) ? 1 : (((P) == 16) ? 2 : (((P) == 17) ? 0 : (((P) == 22) ? 1 : (((P) == 23) ? 0 : (((P) == 24) ? 4 : (((P) == 25) ? 7 : (((P) == 26) ? 4 : (((P) == 27) ? 5 : 6 )))))))))))))))))))


// --- Arduino Uno ---
#elif (defined(ARDUINO_AVR_UNO) || \
defined(ARDUINO_AVR_DUEMILANOVE) || \
defined(__AVR_ATmega168__) || \
defined(__AVR_ATmega168P__) || \
defined(__AVR_ATmega328__) || \
defined(__AVR_ATmega328P__) || \
defined(__AVR_ATmega328PB__))



#if defined(__AVR_ATmega328PB__)
#define __digitalPinToPortReg(P) \
(((P) >= 0 && (P) <= 7) ? &PORTD : (((P) >= 8 && (P) <= 13) ? &PORTB : (((P) >= 14 && (P) <= 19) ? &PORTC : &PORTE)))
#define __digitalPinToDDRReg(P) \
(((P) >= 0 && (P) <= 7) ? &DDRD : (((P) >= 8 && (P) <= 13) ? &DDRB : (((P) >= 14 && (P) <= 19) ? &DDRC : &DDRE)))
#define __digitalPinToPINReg(P) \
(((P) >= 0 && (P) <= 7) ? &PIND : (((P) >= 8 && (P) <= 13) ? &PINB : (((P) >= 14 && (P) <= 19) ? &PINC : &PINE)))
#define __digitalPinToBit(P) \
(((P) >= 0 && (P) <= 7) ? (P) : (((P) >= 8 && (P) <= 13) ? (P) - 8 : (((P) >= 14 && (P) <= 19) ? (P) - 14 : (((P) >= 20 && (P) <= 21) ? (P) - 18 : (P) - 22))))
#else
#define __digitalPinToPortReg(P) \
(((P) >= 0 && (P) <= 7) ? &PORTD : (((P) >= 8 && (P) <= 13) ? &PORTB : &PORTC))
#define __digitalPinToDDRReg(P) \
(((P) >= 0 && (P) <= 7) ? &DDRD : (((P) >= 8 && (P) <= 13) ? &DDRB : &DDRC))
#define __digitalPinToPINReg(P) \
(((P) >= 0 && (P) <= 7) ? &PIND : (((P) >= 8 && (P) <= 13) ? &PINB : &PINC))
#define __digitalPinToBit(P) \
(((P) >= 0 && (P) <= 7) ? (P) : (((P) >= 8 && (P) <= 13) ? (P) - 8 : (P) - 14))
#endif


#elif defined(AVR)
#error "FastTouch has no pin map for this AVR chip; it covers the ATmega168/168P/328/328P/328PB, 32U4/16U4, 1280/2560 and 644/644P"
#endif

#if defined(AVR)
static   byte ft_o,ft_p,ft_q,ft_r,ft_s,ft_t,ft_u,ft_v,ft_w,ft_x, ft_y, ft_z;
#define fastTouchRead(pin) \
( digitalWrite(pin, LOW), \
pinMode(pin, OUTPUT), \
delay(1), \
pinMode(pin, INPUT),  \
/* disable interrupts */ \
BIT_SET(*__digitalPinToPortReg(pin), __digitalPinToBit(pin)), \
ft_o = *__digitalPinToPINReg(pin), \
ft_p = *__digitalPinToPINReg(pin), \
ft_q = *__digitalPinToPINReg(pin), \
ft_r = *__digitalPinToPINReg(pin), \
ft_s = *__digitalPinToPINReg(pin), \
ft_t = *__digitalPinToPINReg(pin), \
ft_u = *__digitalPinToPINReg(pin), \
ft_v = *__digitalPinToPINReg(pin), \
ft_w = *__digitalPinToPINReg(pin), \
ft_x = *__digitalPinToPINReg(pin), \
ft_y = *__digitalPinToPINReg(pin), \
ft_z = *__digitalPinToPINReg(pin), \
/* enable interrupts */ \
!(ft_p & (1<< __digitalPinToBit(pin))) + !(ft_q & (1<< __digitalPinToBit(pin))) + \
!(ft_r & (1<< __digitalPinToBit(pin))) + !(ft_s & (1<< __digitalPinToBit(pin))) + \
!(ft_t & (1<< __digitalPinToBit(pin)))+ !(ft_u & (1<< __digitalPinToBit(pin)))+ \
!(ft_v & (1<< __digitalPinToBit(pin)))+ !(ft_w & (1<< __digitalPinToBit(pin)))+ \
!(ft_x & (1<< __digitalPinToBit(pin)))+ !(ft_y & (1<< __digitalPinToBit(pin)))+ \
!(ft_z & (1<< __digitalPinToBit(pin)))    )
#elif defined(_SAMD21_)

static volatile  uint32_t ft_o,ft_p,ft_q,ft_r,ft_s,ft_t,ft_u,ft_v,ft_w,ft_x, ft_y, ft_z;
static volatile  uint32_t ft_xo,ft_xp,ft_xq,ft_xr,ft_xs,ft_xt,ft_xu,ft_xv,ft_xw,ft_xx, ft_xy, ft_xz;
#define fastTouchRead(pin) \
( pinMode(pin, OUTPUT), \
digitalWrite(pin, LOW), \
delay(1), \
pinMode(pin, INPUT_PULLUP),  \
/* disable interrupts */ \
ft_p = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_q = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_r = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_s = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_t = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_u = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_v = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_w = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_x = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_y = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_z = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xo = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xp = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xq = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xr = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xs = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xt = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xu = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xv = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xw = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xx = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xy = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
ft_xz = PORT->Group[g_APinDescription[pin].ulPort].IN.reg, \
/* enable interrupts */ \
!(ft_p & (1ul << g_APinDescription[pin].ulPin)) + !(ft_q & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_r & (1ul << g_APinDescription[pin].ulPin)) + !(ft_s & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_t & (1ul << g_APinDescription[pin].ulPin)) + !(ft_u & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_v & (1ul << g_APinDescription[pin].ulPin)) + !(ft_w & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_x & (1ul << g_APinDescription[pin].ulPin)) + !(ft_y & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_z &  (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_xo & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_xp & (1ul << g_APinDescription[pin].ulPin)) + !(ft_xq & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_xr & (1ul << g_APinDescription[pin].ulPin)) + !(ft_xs & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_xt & (1ul << g_APinDescription[pin].ulPin)) + !(ft_xu & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_xv & (1ul << g_APinDescription[pin].ulPin)) + !(ft_xw & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_xx & (1ul << g_APinDescription[pin].ulPin)) + !(ft_xy & (1ul << g_APinDescription[pin].ulPin)) + \
!(ft_xz & (1ul << g_APinDescription[pin].ulPin))  \
)

#elif defined(ARDUINO_ARCH_RP2040)
// RP2040 and RP2350 (A and B variants) via pico-sdk SIO block.
// Sense pins: GPIO 0-29 on RP2040 and RP2350A, GPIO 0-31 on RP2350B
// (sio_hw->gpio_in holds GPIO 0-29 on RP2040 and 0-31 on RP2350; RP2350B's
// GPIO 32-47 are not supported).
#include "hardware/gpio.h"
#include "hardware/sync.h"
#include "hardware/structs/sio.h"

// 0..fastTouchMax(), or -1 for a pin outside the sense-pin range above
int fastTouchRead(int pin);

// Parallel multi-channel API: read all channels in one scan.
// Bits of sense_mask outside the sense-pin range are ignored.
void fastTouchBegin(uint32_t sense_mask);
// results[] is indexed by GPIO number, so it needs 32 entries; each count is
// 0..n_samples, and n_samples is clamped to 0..255. Not reentrant: the reads
// go through one static buffer, so do not call it from both cores at once or
// from an interrupt handler.
void fastTouchReadAll(uint32_t sense_mask, uint8_t *results, int n_samples);

#elif defined(CORE_TEENSY)
// Teensy 3.x, LC and 4.x; Teensy 2.0 is AVR and uses the macro above
int fastTouchRead(int pin);

#else
#error "FastTouch supports AVR, SAMD21, Teensy and RP2040/RP2350 (Arduino-Pico core) boards; this board is none of those"
#endif

// The largest value fastTouchRead() can return on this board
// (fastTouchReadAll counts go up to its n_samples instead)
int fastTouchMax(void);

#endif /* FastTouch_h */
