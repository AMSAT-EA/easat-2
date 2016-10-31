/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_initialize.c
 *
 * Description : EASAT2 MCU initializing functions
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_util_initialize.h"

// this function initializes the MCU

void initialize(void) {
    
       
    // configure PORTS, ADCs, and so on

    // set PORTD as output

    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;

    // set D outputs as digital

    ANSELDbits.ANSD0 = 0;
    ANSELDbits.ANSD1 = 0;
    ANSELDbits.ANSD2 = 0;
    ANSELDbits.ANSD3 = 0;
    ANSELDbits.ANSD4 = 0;
    ANSELDbits.ANSD5 = 0;
    ANSELDbits.ANSD6 = 0;
    ANSELDbits.ANSD7 = 0;

    // clean D latches
    
    LATDbits.LATD0   = 0;
    LATDbits.LATD1   = 0;
    LATDbits.LATD2   = 0;
    LATDbits.LATD3   = 0;
    LATDbits.LATD4   = 0;
    LATDbits.LATD5   = 0;
    LATDbits.LATD6   = 0;
    LATDbits.LATD7   = 0;    

}