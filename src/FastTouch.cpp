//
//  FastTouch.cpp
//  
//
//  Created by AdrianFreed on 3/12/18.
//
//

#include "FastTouch.h"




#if defined(CORE_TEENSY)

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

// Single-pin capacitive touch read via SIO gpio_in.
// Returns count of samples (out of 64) where the pin was still LOW
// after releasing from discharge to INPUT_PULLUP.
//
// gpio_init() is called once per pin (lazy) to set the SIO function
// and enable the pad input buffer (IE bit). The pullup is also
// enabled once and left on permanently — during discharge the output
// driver easily overpowers the ~50kΩ internal pullup (~66µA), so
// the pin stays LOW regardless. When OE is cleared the pullup is
// already live and charging begins immediately with no APB writes
// in the critical section.
int fastTouchRead(int pin)
{
    static uint32_t _ft_rp_inited = 0;
    uint32_t mask = 1UL << pin;

    // First call per pin: init GPIO and pre-enable pullup
    if (!(_ft_rp_inited & mask)) {
        gpio_init(pin);
        gpio_pull_up(pin);
        _ft_rp_inited |= mask;
    }

    // Discharge: drive pin LOW — pullup stays enabled but the
    // output driver wins, pin is held LOW
    sio_hw->gpio_clr = mask;
    sio_hw->gpio_oe_set = mask;
    delayMicroseconds(2);

    // Release to input — pullup is already live, charging starts
    uint32_t saved = save_and_disable_interrupts();
    sio_hw->gpio_oe_clr = mask;

    int count = 0;
    for (int i = 0; i < 64; i++) {
        if (!(sio_hw->gpio_in & mask))
            count++;
    }
    restore_interrupts(saved);

    // Leave pin discharged for next cycle
    sio_hw->gpio_clr = mask;
    sio_hw->gpio_oe_set = mask;

    return count;
}

// Configure all sense pins for parallel capacitive touch.
// Call once at startup. Initialises each pin as GPIO with input
// buffer enabled, pre-enables the internal pullup (left on
// permanently), and leaves all pins discharged (output LOW).
//
// The pullup draws ~66µA per pin while the output driver holds
// LOW during discharge (25 pins ≈ 1.65mA for 2µs) — negligible.
void fastTouchBegin(uint32_t sense_mask)
{
    for (int i = 0; i < 32; i++) {
        if (sense_mask & (1UL << i)) {
            gpio_init(i);
            gpio_pull_up(i);
            gpio_set_dir(i, GPIO_OUT);
            gpio_put(i, 0);
        }
    }
}

// Parallel multi-channel capacitive touch read.
// Discharges all pins in sense_mask simultaneously, waits 2 us,
// clears OE in a single SIO write (pullups already live from
// fastTouchBegin), then samples sio_hw->gpio_in n_samples times
// with interrupts disabled. No APB writes in the critical section.
//
// For each pin in sense_mask, stores in results[bit_position] the
// number of samples where that pin was still LOW (higher = more
// capacitance = touch detected).
//
// n_samples is clamped to 255 (uint8_t max).
void fastTouchReadAll(uint32_t sense_mask, uint8_t *results, int n_samples)
{
    if (n_samples > 255) n_samples = 255;

    // Zero result counters for active pins
    for (int i = 0; i < 32; i++) {
        if (sense_mask & (1UL << i))
            results[i] = 0;
    }

    // Discharge all sense pins: output LOW
    // Pullups stay enabled — driver overpowers them
    sio_hw->gpio_clr = sense_mask;
    sio_hw->gpio_oe_set = sense_mask;
    delayMicroseconds(2);

    // --- Critical section: single SIO write + sample loop ---
    uint32_t saved = save_and_disable_interrupts();
    sio_hw->gpio_oe_clr = sense_mask;   // pullups already live

    for (int s = 0; s < n_samples; s++) {
        uint32_t low = (~sio_hw->gpio_in) & sense_mask;
        while (low) {
            int b = __builtin_ctz(low);
            results[b]++;
            low &= low - 1;             // clear lowest set bit
        }
    }
    restore_interrupts(saved);
    // --- End critical section ---

    // Re-discharge all sense pins
    sio_hw->gpio_clr = sense_mask;
    sio_hw->gpio_oe_set = sense_mask;
}

#endif // ARDUINO_ARCH_RP2040

int fastTouchMax()
{
#if defined(ARDUINO_ARCH_RP2040)
    return 64;
#else
    return 60;
#endif
}


