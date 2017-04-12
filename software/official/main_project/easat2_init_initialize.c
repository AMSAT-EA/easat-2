/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_init_initialize.c
 *
 * Description : EASAT2 MCU initializing functions
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_init_initialize.h"
#include "easat2_init_timer.h"
#include "easat2_util_pwm.h"

// this function initializes the MCU

void init_initialize(void) {
    
    // I/O initialize
    init_io_initialize();
    
    // timers initialize
    init_timer1_initialize();
    init_timer2_initialize();
    
    // PWM initialize
    util_pwm_initialize();
      
}

// this functions initializes PORTS and ADCs

void init_io_initialize(void) {
          
    // configure PORTS, ADCs, and so on

    /* here we configure the Fixed Voltage Reference (FVR) channel
       for the ADC */

    // 2.048 V as FVR (VREF+)

    VREFCON0bits.FVREN = 1; // Voltage Fixed Reference (VREF) enabled
    VREFCON0bits.FVRS0 = 0; // Fixed Voltage Reference Peripheral
    VREFCON0bits.FVRS1 = 1; // output is 2x (2.048 V)

    VREFCON0bits.FVRST = 1; // Fixed Voltage Reference output is ready for use

    /* This code block configures the ADC
       for polling, FVR BUF2 and Vss as reference and Frc clock */

    ADCON1 = 0x08;      // b'00001000' ; ADC VREF+=FVR BUF2,VREF-=Vss
    ADCON2 = 0xAF;      // b'10101111' ; right justify, Frc, 12 TAD ACQ time
    
    // set PORTA as input, except RA2 (DAC output)

    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 0;
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
    
    // disable all PORTB/E pull-up resistors (only usable in input mode)
     // PORTE MCLR internal pull-up is always on in MCLR mode
    
    WPUB = 0b00000000;
    RBPU = 0b11111111;
         
    // set PORTB as input for B0, the other ones are output

    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;

    // set B0 input as analog. Only 0, 1, 2, 3 and 5 can be used

    ANSELBbits.ANSB0 = 1;
    ANSELBbits.ANSB1 = 0;
    ANSELBbits.ANSB2 = 0;
    ANSELBbits.ANSB3 = 0;
    
    ANSELBbits.ANSB5 = 0;     

    // clean B latches

    LATBbits.LATB0   = 0;
    LATBbits.LATB1   = 0;
    LATBbits.LATB2   = 0;
    LATBbits.LATB3   = 0;
    LATBbits.LATB4   = 0;
    LATBbits.LATB5   = 0;
    
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
    
    // PORTE
    
    

}