//
//  FastTouch.cpp
//  
//
//  Created by AdrianFreed on 3/12/18.
//
//

#include "FastTouch.h"


#if defined(AVR)
// works on 1.8.5
// not on Teensy 2.0 because compiler does not do lto

int xxfastTouchRead(int pin)
{
    volatile byte *  port = __digitalPinToPINReg(pin);
    const byte mask = 1l<<__digitalPinToBit(pin);
    pinMode(pin, OUTPUT);
    
    digitalWrite(pin, LOW);
    delayMicroseconds(200);
    /* disable interrupts */
    noInterrupts();
    pinMode(pin, INPUT);
    BIT_SET(*__digitalPinToPortReg(pin), __digitalPinToBit(pin));

    
    //    for(int i=0;i<64;++i)
    //    ft_o += *port&x;
    {
        register int i=0;
        
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
        if( *port &mask)
            goto out;
        ++i;
    out:
        
        
        
        interrupts();
        return i;
        
    }
}

int xfastTouchRead( int pin)
{
    volatile byte *  port = __digitalPinToPINReg(pin);
    const byte mask = 1l<<__digitalPinToBit(pin);
    int ft_o,ft_p,ft_q,ft_r,ft_s,ft_t,ft_u,ft_v,ft_w,ft_x, ft_y, ft_z,ft_a,ft_b,ft_c,ft_d,
    ft_e, ft_f,ft_g,ft_h,ft_i,ft_j, ft_k, ft_l,ft_m,ft_n,ft_O, ft_P, ft_Q;
    digitalWrite(pin, LOW);
    pinMode(pin, OUTPUT);
    delayMicroseconds(200);
    pinMode(pin, INPUT);
    // noInterrupts();
    BIT_SET(*__digitalPinToPortReg(pin), __digitalPinToBit(pin));
    ft_o = *port;
    ft_p = *port;
    ft_q = *port;
    ft_r = *port;
    ft_s = *port;
    ft_t = *port;
    ft_u = *port;
    ft_v = *port;
    ft_w = *port;
    ft_x = *port;
    ft_y = *port;
    ft_z = *port;
    ft_a = *port;
    ft_b = *port;
    ft_c = *port;
    ft_d = *port;
    ft_e = *port;
    ft_f = *port;
    ft_g = *port;
    ft_h = *port;
    ft_i = *port;
    ft_j = *port,
    ft_k = *port;
    ft_l = *port;
    ft_m = *port;
    ft_n = *port;
    ft_O = *port;
    ft_P = *port;
    ft_Q = *port;

    //    interrupts();
    /* enable interrupts */ \
    {
        const int mask = (1<< __digitalPinToBit(pin));
        
        int out = 28 - (  ((ft_p & mask) + (ft_q & mask) + \
                           
                           (ft_r & mask) + (ft_s & mask) + \
                           (ft_t & mask)+ (ft_u & mask)+ \
                           (ft_v & mask)+ (ft_w & mask)+ \
                           (ft_x & mask)+ (ft_y & mask)+ \
                           (ft_z & mask)+
                           
                           (ft_a & mask) + (ft_b & mask) + \
                           (ft_c & mask)+ (ft_d & mask)+ \
                           (ft_e & mask)+ (ft_f & mask)+ \
                           (ft_g & mask)+ (ft_h & mask)+
                           (ft_i & mask)
                           + (ft_j & mask)+ (ft_k & mask)+ \
                           (ft_l & mask)+
                           (ft_m & mask)+ (ft_n & mask)+ \
                           (ft_O & mask)+
                           (ft_P & mask)+ (ft_Q & mask)
                           )>> __digitalPinToBit(pin));
        return out;
    }
}
#elif defined(_SAMD21)
static volatile uint32_t *port;
int xxfastTouchRead(int pin)
{
    const uint32_t mask = 1l<< (1ul << g_APinDescription[pin].ulPin);
    port = &PORT->Group[g_APinDescription[pin].ulPort].IN.reg;
    pinMode(pin, OUTPUT);
    uint32_t output = 0;
    
    digitalWrite(pin, LOW);
    delayMicroseconds(8);
    /* disable interrupts */
    noInterrupts();
    pinMode(pin, INPUT_PULLUP);
    for( int i=0;i<64;++i)
            output += *port & mask;
    interrupts();
    return output >> g_APinDescription[pin].ulPin;
    //    for(int i=0;i<64;++i)
    //    ft_o += PORT->Group[g_APinDescription[pin].ulPort].IN.reg&x;
    {
        register int i=0;
        
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
        if( PORT->Group[g_APinDescription[pin].ulPort].IN.reg &mask)
            goto out;
        ++i;
    out:
        
        
        
        interrupts();
        return i;
        
    }
}

#elif defined(CORE_TEENSY)
#if defined(__MKL26Z64__) /* Teensy 3LC */
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
        ++i;      if( *portInputRegister(pin) & m )
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

int fastTouchMax()
{
    return 60;
}


