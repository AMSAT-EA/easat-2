/*
 *                                                       
 * Project     : EASAT2 ASK                                           
 * File        : easat2_ask_func_interrupts.c
 *
 * Description : Functions related to timer interruption
 * Last update : 18 January 2017                                              
 *                                                                            
*/

#include "easat2_ask.h"
#include "easat2_ask_func_interrupts.h"


// this is the high priority interruption function.
// TMR1 triggers 100 times per second (100 Hz - 10ms cycle)
// Sample table size is 128, so it is stored more than 1 second

void interrupt high_priority_int() {

    static int tmr1_interrupt_number = 0;
    
    if (PIR1bits.TMR2IF) {
        
       // clear interruption flag
        
        PIR1bits.TMR2IF = 0;  
        
    } else {
    
      // check if it is TMR1 overflow
    
      if (PIR1bits.TMR1IF) {

        /* initial timer value */
        
        TMR1H = TIMER1H_VAL; /* EC77 for 60535 */
        TMR1L = TIMER1L_VAL;
                           
        tmr1_interrupt_number++;
                
        // blink LED each half second and clear software watchdog
        
        if (tmr1_interrupt_number == TMR1_HALF_SECOND) {

            // blink auxiliar green LED
            PINOUT_TIMER_LED = !PINOUT_TIMER_LED;
            
            // clear the software watchdog timer (131 seconds timer)
            // the watchdog has been configured by software fuses
        
            ClrWdt();

            // start count again
            
            tmr1_interrupt_number = 0;
            
        }

        
        // clear interruption flag
        
        PIR1bits.TMR1IF = 0; 
        
    }

  }
}


// this is the high priority interruption function

void interrupt low_priority low_priority_int() {

  
    
 }


