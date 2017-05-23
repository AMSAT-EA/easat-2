/*
 *                                                       
 * Project     : EASAT2 ASK                                            
 * File        : easat2_ask_init_timer.c
 *
 * Description : Functions related to timer interruption
 * Last update : 18 January 2017                                              
 *                                                                            
*/

#include "easat2_ask.h"
#include "easat2_ask_init_timer.h"


// this is the TMR1 initializing function

void init_timer1_initialize(void) {
    
    /* We want timer interrupt to be triggered in 10 ms intervals
     * Fosc / 4 = 2 Mhz / 4 = 500.000 counts in a second
     * 10 ms = 100 Hz -> we need 100 overflow interrupts in each second
  
     * 500.000 counts in a second / 100 overflows per second = 5.000 counts per overflow
     * TMR1 generates interrupt in overflow at 65535, so
     * if we need overflow each 5.000 counts ...    
     * TMR1 = 65535 - 5000 = 60535 (EC77h)
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
    TMR1H = TIMER1H_VAL; /* EC77 for 60535 */
    TMR1L = TIMER1L_VAL;
    
    /* INTCON register for TIMER1 interruption configuration */
    PIE1bits.TMR1IE   = 1; /* enable timer1 interrupt on overflow */
    IPR1bits.TMR1IP   = 1; /* high priority interrupt */
    PIR1bits.TMR1IF   = 0; /* clear interrupt flag */

    T1CONbits.TMR1ON  = 1; /* enable timer1 */
    
    INTCONbits.PEIE   = 0; /* Disable pheriperical interrupts */
    INTCONbits.GIE    = 1; /* Enable global interrupts */

}


// this is the TMR2 initializing function
// some parameters are changed in PWM initialization function

void init_timer2_initialize(void) {
    
    /* This timer is going to be used for PWM
       PWM configuration is made in the PWM files */     

    /* priority interrupts already configured in TMR1 */
           
    T2CONbits.TMR2ON  = 0; /* initially disable timer2 */
    
    /* TMR2 does not have CS - Clock Source Select bits */
    
    /* CKPS - Input Clock Prescaler selection bits */
    T2CONbits.T2CKPS0 = 1; /* 1:4 prescaler */
    T2CONbits.T2CKPS1 = 0; /* 1:4 prescaler */
    
    /* postscaler off */ 
    T2CONbits.T2OUTPS = 0b0000;  // postcale off
      
    /* TMR2 does not have OSCEN - Secondary Oscillator Enable control bits */
        
    /* TMR2 only has 8 bit operation RD - Read / Write mode Enable bit */
    
    /* initial timer value */
    TMR2 = 0; 
    
    /* INTCON register for TIMER2 interruption configuration */
    PIE1bits.TMR2IE   = 1; /* enable timer2 interrupt on overflow */
    IPR1bits.TMR2IP   = 0; /* disable high priority interrupt */
    PIR1bits.TMR2IF   = 0; /* clear interrupt flag */

    /* TMR2 will be enabled in PWM functions */
      
    /* pheriperical interrupts and Enable global interrupts already
       done in TMR1 setup */

}
