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
#include "easat2_util_timer.h"

// this function initializes the MCU

void initialize(void) {
          
    // configure PORTS, ADCs, and so on

    /* here we configure the Fixed Voltage Reference (FVR) channel
       for the ADC */

    // 1.024 V as FVR (VREF+)

    VREFCON0bits.FVREN = 1; // Voltage Fixed Reference (VREF) enabled
    VREFCON0bits.FVRS0 = 1; // Fixed Voltage Reference Peripheral
    VREFCON0bits.FVRS1 = 0; // output is 1x (1.024 V)

    VREFCON0bits.FVRST = 1; // Fixed Voltage Reference output is ready for use

    /* This code block configures the ADC
       for polling, FVR BUF2 and Vss as reference and Frc clock */

    ADCON1 = 0x08;      // b'00001000' ; ADC VREF+=FVR BUF2,VREF-=Vss
    ADCON2 = 0xAF;      // b'10101111' ; right justify, Frc, 12 TAD ACQ time
    
    // set PORTA as input

    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA4 = 1;
    TRISAbits.TRISA5 = 1;
    
    // TRISAbits.TRISA6 = 1; Crystal is connected here
    // TRISAbits.TRISA7 = 1; Crystal is connected here

    // set A inputs as analog (except AN3). Only 0, 1, 2, 3 and 5 can be used

    ANSELAbits.ANSA0 = 1;
    ANSELAbits.ANSA1 = 1;
    ANSELAbits.ANSA2 = 1;
    ANSELAbits.ANSA3 = 0;   // digital thermometer here
    
    ANSELAbits.ANSA5 = 1;     

    // clean A latches

    LATAbits.LATA0   = 0;
    LATAbits.LATA1   = 0;
    LATAbits.LATA2   = 0;
    LATAbits.LATA3   = 0;
    LATAbits.LATA4   = 0;
    LATAbits.LATA5   = 0;
    
    // LATAbits.LATA6   = 0; Crystal
    // LATAbits.LATA7   = 0; Crystal

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

    // initialize TIMER 1
    
    util_timer1_initialize();
}