//
//  FastTouch.cpp
//  
//
//  Created by AdrianFreed on 3/12/18.
//
//

#include "FastTouch.h"




// ARM Teensys only: Teensy 2.0 is AVR and gets the fastTouchRead macro in FastTouch.h
#if defined(CORE_TEENSY) && !defined(AVR)

//#if defined(__IMXRT1052__) || defined(__IMXRT10562__)

#if defined(__IMXRT1052__) || defined(__IMXRT1062__)

FASTRUN
int fastTouchRead(int  pin)
{
    int i;
    const struct digital_pin_bitband_and_config_table_struct *p;
    if (pin >= CORE_NUM_DIGITAL) return -1;
     p = digital_pin_to_info_PGM + pin;
 
    
    pinMode(pin, OUTPUT_OPENDRAIN);
    digitalWrite(pin, LOW);
    delayMicroseconds(1);
    /* disable interrupts */
    noInterrupts();
    pinMode(pin, INPUT_PULLUP);
    i=0;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    i++;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    i++;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    i++;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    i++;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    i++;
    if((*(p->reg + 2) & p->mask)!=0)
        goto out;
    i++;
    
    for(;i<64;++i)
        if((*(p->reg + 2) & p->mask)!=0)
            break;
//        v += fastDigitalRead(pin)? 0:1;
    {
   
        pinMode(pin, OUTPUT_OPENDRAIN);
        digitalWrite(pin, LOW);
        
        
        
    }
out:
    interrupts();
    return i;
}
#elif defined(__MKL26Z64__)|| defined(__IMXRT1052__) || defined(__IMXRT1062__) /* Teensy 3LC */
FASTRUN
int fastTouchRead(int pin)
{
    const unsigned m = digitalPinToBitMask(pin);
    
    pinMode(pin, OUTPUT_OPENDRAIN);
    digitalWrite(pin, LOW);
    delayMicroseconds(50);
    /* disable interrupts */
    noInterrupts();
    pinMode(pin, INPUT_PULLUP);
    
    //    for(int i=0;i<64;++i)
    //    ft_o += *port&x;
    {
        register unsigned a,b,c,d,e,f;
        register unsigned aa,ba,ca,da;
#ifdef CONDITIONALAPPROACH
        register unsigned i=0;

        
        a = *portInputRegister(pin) & m  ;
        a = *portInputRegister(pin)  & m ;
        a = *portInputRegister(pin) & m  ;
        b = *portInputRegister(pin) & m  ;
        c = *portInputRegister(pin) & m  ;
        d = *portInputRegister(pin) & m  ;
        e = *portInputRegister(pin) & m  ;
        f = *portInputRegister(pin) & m  ;
        aa = *portInputRegister(pin) & m;
        ba = *portInputRegister(pin) & m;
        ca = *portInputRegister(pin) & m;
        da = *portInputRegister(pin) & m;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
        if( *portInputRegister(pin) & m )
            goto out;
        ++i;
    out:   ;

#else
        register unsigned i;
        
        i = *portInputRegister(pin) & m;
        i = *portInputRegister(pin) & m;

        i = *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        i+= *portInputRegister(pin) & m;
        
        
        
#endif
        
        
        interrupts();

        //        i += ((a & m)?0:1 ) + ((b& m )?0:1 ) +
        // ((c & m)?0:1 ) + ((d& m)?0:1 ) + ((e & m)?0:1 ) + ((f& m)?0:1 );
        //i += ((aa & m)?0:1 ) + ((ba& m )?0:1 ) +
        // ((ca & m)?0:1 ) + ((da & m)?0:1 ) + ((ea & m)?0:1 ) + ((fa& m)?0:1 );
        {volatile unsigned t = i, mm = m;
            while(mm >>= 1)
                t >>= 1;
            i = 64 -t; }   //+(a+b+c+d+e+f+da+ca+ba+aa    10+
        pinMode(pin, OUTPUT_OPENDRAIN);
        digitalWrite(pin, LOW);
        
        return i;
        
    }
}
#else
FASTRUN
int fastTouchRead(int pin)
{
    pinMode(pin, OUTPUT_OPENDRAIN);
    digitalWriteFast(pin, LOW);
    delayMicroseconds(50);
    /* disable interrupts */
    noInterrupts();
    pinMode(pin, INPUT_PULLUP);
    
    //    for(int i=0;i<64;++i)
    //    ft_o += *port&x;
    {
        register unsigned i=0;
        register uint8_t a,b,c,d,e,f;
        register uint8_t aa,ba,ca,da;
        
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        
        
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        a = *portInputRegister(pin) ;
        b = *portInputRegister(pin) ;
        c = *portInputRegister(pin) ;
        d = *portInputRegister(pin) ;
        e = *portInputRegister(pin) ;
        f = *portInputRegister(pin) ;
        aa = *portInputRegister(pin) ;
        ba = *portInputRegister(pin) ;
        ca = *portInputRegister(pin) ;
        da = *portInputRegister(pin) ;
        
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
        if( *portInputRegister(pin))
            goto out;
        ++i;
    out:
        
        
        
        interrupts();
        //        i += ((a & m)?0:1 ) + ((b& m )?0:1 ) +
        // ((c & m)?0:1 ) + ((d& m)?0:1 ) + ((e & m)?0:1 ) + ((f& m)?0:1 );
        //i += ((aa & m)?0:1 ) + ((ba& m )?0:1 ) +
        // ((ca & m)?0:1 ) + ((da & m)?0:1 ) + ((ea & m)?0:1 ) + ((fa& m)?0:1 );
        {volatile uint8_t t =10-(a+b+c+d+e+f+da+ca+ba+aa);
            i+= t; }
        pinMode(pin, OUTPUT_OPENDRAIN);
        digitalWriteFast(pin, LOW);
        
        return i;
        
    }
}
#endif
#endif

// --- RP2040 / RP2350 (Arduino-Pico core) ---
#if defined(ARDUINO_ARCH_RP2040)

#include "hardware/gpio.h"
#include "hardware/sync.h"
#include "hardware/structs/sio.h"

// Sense pins this code can use: RP2040 and RP2350A have GPIO 0-29, and
// RP2350B's sio_hw->gpio_in holds GPIO 0-31 (GPIO 32-47 are in gpio_hi_in).
// PICO_RP2350A is 0 only on RP2350B, and the core refuses PICO_RP2350B.
#if defined(PICO_RP2350) && defined(PICO_RP2350A) && !PICO_RP2350A
#define FT_RP_GPIOS 32
#else
#define FT_RP_GPIOS 30
#endif
#define FT_RP_VALID_MASK ((uint32_t)(((uint64_t)1 << FT_RP_GPIOS) - 1))

// Single-pin capacitive touch read via SIO gpio_in.
// Returns how many of 64 reads, taken after the pin is released from
// discharge onto its pull-up, still see it LOW (0..64), or -1 for a pin
// outside GPIO 0..FT_RP_GPIOS-1.
//
// Every call sets the pin up again (SIO function, input buffer on, pad
// isolation and overrides cleared, pull-up on) before discharging it, so it
// keeps working after pinMode() or analogRead() has reconfigured the pin; it
// leaves interrupt enables, drive strength, slew and Schmitt settings alone.
// Those are APB
// writes before the timed section; none happen inside it. During
// discharge the output driver holds the pin LOW against the ~50kΩ
// internal pull-up, and when OE is cleared the pull-up is already live.
int fastTouchRead(int pin)
{
    if (pin < 0 || pin >= FT_RP_GPIOS)
        return -1;
    const uint32_t mask = 1UL << pin;

    gpio_init(pin);        // SIO function, input buffer on, output off
    gpio_pull_up(pin);

    // Discharge: drive the pin LOW; the output driver wins over the pull-up
    sio_hw->gpio_clr = mask;
    sio_hw->gpio_oe_set = mask;
    delayMicroseconds(2);

    // Release to input: the pull-up is already live, charging starts
    uint32_t saved = save_and_disable_interrupts();
    sio_hw->gpio_oe_clr = mask;

    int count = 0;
    for (int i = 0; i < 64; i++)
        count += (int)((~sio_hw->gpio_in >> pin) & 1u);   // no branch on the level read
    restore_interrupts(saved);

    // Leave the pin discharged (driven LOW) until the next read
    sio_hw->gpio_clr = mask;
    sio_hw->gpio_oe_set = mask;

    return count;
}

// Configure the sense pins for parallel capacitive touch. Call once at
// startup, and again after any sense pin has been reconfigured (pinMode,
// analogRead, another peripheral). Bits of sense_mask outside
// GPIO 0..FT_RP_GPIOS-1 are ignored. Each pin becomes a GPIO with its input
// buffer and internal pull-up on, and is left driven LOW (discharged).
//
// While a sense pin is held LOW, its pull-up draws current the whole time
// it idles between reads: about 66µA per pin at 3.3V and ~50kΩ.
void fastTouchBegin(uint32_t sense_mask)
{
    sense_mask &= FT_RP_VALID_MASK;
    for (int i = 0; i < FT_RP_GPIOS; i++) {
        if (sense_mask & (1UL << i)) {
            gpio_init(i);
            gpio_pull_up(i);
            gpio_set_dir(i, GPIO_OUT);
            gpio_put(i, 0);
        }
    }
}

// Parallel multi-channel capacitive touch read.
// Discharges every pin in sense_mask (bits outside GPIO 0..FT_RP_GPIOS-1 are
// ignored) for 2 us, releases them all with one SIO write (their pull-ups are
// already on from fastTouchBegin), and with interrupts off stores n_samples
// raw reads of sio_hw->gpio_in. Only after that does it count, for each pin,
// the reads in which the pin was still LOW, into results[GPIO number]
// (higher = more capacitance = touch detected). Storing first means every
// read runs the same instructions whatever the number of pins or how many are
// still LOW (the spacing itself has not been measured).
//
// results[] needs 32 entries. n_samples is clamped to 0..255, so each count
// fits a uint8_t. Not reentrant: the reads go through one static buffer, so
// do not call it from both cores at once or from an interrupt handler.
void fastTouchReadAll(uint32_t sense_mask, uint8_t *results, int n_samples)
{
    static uint32_t samples[255];
    if (n_samples > 255) n_samples = 255;
    if (n_samples < 0) n_samples = 0;
    sense_mask &= FT_RP_VALID_MASK;

    // Discharge all sense pins: output LOW; the drivers win over the pull-ups
    sio_hw->gpio_clr = sense_mask;
    sio_hw->gpio_oe_set = sense_mask;
    delayMicroseconds(2);

    // --- Critical section: one SIO write, then n_samples stored reads ---
    uint32_t saved = save_and_disable_interrupts();
    sio_hw->gpio_oe_clr = sense_mask;   // pull-ups already live
    for (int s = 0; s < n_samples; s++)
        samples[s] = sio_hw->gpio_in;
    restore_interrupts(saved);
    // --- End critical section ---

    // Re-discharge: leave the sense pins driven LOW until the next read
    sio_hw->gpio_clr = sense_mask;
    sio_hw->gpio_oe_set = sense_mask;

    for (int i = 0; i < FT_RP_GPIOS; i++) {
        if (sense_mask & (1UL << i))
            results[i] = 0;
    }
    for (int s = 0; s < n_samples; s++) {
        uint32_t low = ~samples[s] & sense_mask;
        while (low) {
            int b = __builtin_ctz(low);
            results[b]++;
            low &= low - 1;             // clear lowest set bit
        }
    }
}

#endif // ARDUINO_ARCH_RP2040

// The largest value fastTouchRead() can return on this board, counted from
// the implementation above or the macro in FastTouch.h
int fastTouchMax()
{
#if defined(ARDUINO_ARCH_RP2040)
    return 64;    // 64 reads of gpio_in
#elif defined(AVR)
    return 11;    // the AVR macro sums 11 reads (ft_p..ft_z); includes Teensy 2.0
#elif defined(_SAMD21_)
    return 23;    // the SAMD21 macro sums 23 reads (ft_p..ft_z, ft_xo..ft_xz)
#elif defined(__IMXRT1052__) || defined(__IMXRT1062__)
    return 64;    // Teensy 4.x: the count loop stops at 64
#elif defined(__MKL26Z64__)
    return 64;    // Teensy LC: 64 minus the reads (of 64) that saw HIGH
#elif defined(CORE_TEENSY)
    return 127;   // Teensy 3.x: up to 117 chained LOW reads plus up to 10 from the ten reads before them
#else
    return 0;     // not reached: FastTouch.h stops other boards with #error
#endif
}


