/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_timer.c
 *
 * Description : Functions related to timer interruption
 * Last update : 18 January 2017                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_util_timer.h"

#define TIMER1H_VAL 0x3C
#define TIMER1L_VAL 0xAF

// this is the TMR1 initializing function

void util_timer1_initialize(void) {
    
    /* We want timer interrupt to be triggered in 100 ms intervals
     * Fosc / 4 = 2 Mhz / 4 = 500.000 counts in a second
     * 100 ms = 10 Hz -> we need 10 overflow interrupts in each second
  
     * 500.000 counts in a second / 10 overflows per second = 50.000 counts per overflow
     * TMR1 generates interrupt in overflow at 65535, so
     * if we need overflow each 50.000 counts ...    
     * TMR1 = 65535 - 50000 = 15535
    */     

    /* enable priority interrupts */
    RCONbits.IPEN     = 1;
    
    /* TXCON Timer1/3/5 control register */
    
    T1CONbits.TMR1ON  = 0; /* initially disable timer1 */
    
    /* CS - Clock Source Select bits */
    T1CONbits.TMR1CS0 = 0; /* using internal clock (Fosc/4) */
    T1CONbits.TMR1CS1 = 0; /* using internal clock (Fosc/4) */

    /* CKPS - Input Clock Prescaler selection bits */
    T1CONbits.T1CKPS1 = 0; /* 1:1 prescaler */
    T1CONbits.T1CKPS0 = 0; /* 1:1 prescaler */

    /* OSCEN - Secondary Oscillator Enable control bits */
    T1CONbits.T1OSCEN = 0; /* not using dedicated oscillator */
    
    /* RD - Read / Write mode Enable bit */
    T1CONbits.RD16    = 1; /* 16 bits operation */

    /* initial timer value */
    TMR1H = TIMER1H_VAL; /* 3CAF for 15535 */
    TMR1L = TIMER1L_VAL;
    
    /* INTCON register for TIMER1 interruption configuration */
    PIE1bits.TMR1IE   = 1; /* enable timer1 interrupt on overflow */
    IPR1bits.TMR1IP   = 1; /* high priority interrupt */
    PIR1bits.TMR1IF   = 0; /* clear interrupt flag */

    T1CONbits.TMR1ON  = 1; /* enable timer1 */
    
    INTCONbits.PEIE   = 0; /* Disable pheriperical interrupts */
    INTCONbits.GIE    = 1; /* Enable global interrupts */

}

// auxiliary global interruption variables

int tmr1_interrupt_number = 0;

// this is the high priority interruption function

void interrupt high_priority_int() {


    // check if it is TMR1 overflow
    
    if (TMR1IE && TMR1IF) {

        // TMR1 overflow interruption
               
        tmr1_interrupt_number++;
                
        // blink LED each half second
        
        if (tmr1_interrupt_number == TMR1_HALF_SECOND) {

            // blink auxiliar green LED
            PORTDbits.RD4 = !PORTDbits.RD4;

            tmr1_interrupt_number = 0;
            
        }

        // read currents from battery and solar panels
        
        
        // check if it is time to store values in EEPROM
        
        
        // check AGC
        
       
        // clear interruption flag
        
        TMR1IF=0;
   
    }

}


// this is the high priority interruption function

void interrupt low_priority low_priority_int() {

  
    
 }


