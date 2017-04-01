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

#define TIMER1H_VAL 0xEC
#define TIMER1L_VAL 0x77    ; 60535

// this is the TMR1 initializing function

void util_timer1_initialize(void) {
    
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

// auxiliary global interruption variables

int tmr1_interrupt_number = 0;

// this is the high priority interruption function

void interrupt high_priority_int() {

    static unsigned int samples[SAMPLE_TABLE_SIZE];
    static int sample_position           = 0;
    static unsigned short long noise_mean_value  = INITIAL_NOISE_MEAN_VALUE;
    static unsigned int activation_thresold      = INITIAL_ACTIVACION_THRESOLD;
    static int times_thresold_exceeded           = 0;
    static int cycles_transmitter_active         = 0;   /* (number of interruptions) */
    static int is_transmitter_active             = 0;
    
    static int valid_samples                     = 0;   /* valid samples in sample size */
    
    unsigned int sample                          = 0;   /* ADC sample value */
                                                     
    // check if it is TMR1 overflow
    
    if (PIR1bits.TMR1IF) {

        /* initial timer value */
        
        TMR1H = TIMER1H_VAL; /* EC77 for 60535 */
        TMR1L = TIMER1L_VAL;
    
        // first of all clear the software watchdog timer (131 seconds timer)
        // the watchdog has been configured by software fuses
        
        ClrWdt();
            
        
        // CLEAR HARDWARE WATCHDOG TIMER!!
        
        
        
        
        
        
        // TMR1 overflow interruption
               
        tmr1_interrupt_number++;
                
        // blink LED each half second
        
        if (tmr1_interrupt_number == TMR1_HALF_SECOND) {

            // blink auxiliar green LED
            PINOUT_TIMER_LED = !PINOUT_TIMER_LED;

            tmr1_interrupt_number = 0;
            
        }

        /* check if sample tables is not full yet */
        
        if (valid_samples < SAMPLE_TABLE_SIZE) valid_samples++;
                
        // read currents from battery and solar panels
        
        
        // check if it is time to store values in EEPROM
        
        
        // check AGC
        
        
        // take RF (S-meter) signal sample from AN4 (RA5)
        
        ADCON0bits.CHS  = PINOUT_ADC_RF_IN_SIGNAL_POWER_CHANNEL; // ADC channel 4
        ADCON0bits.ADON = 1;        // Turn on ADC
        PIR1bits.ADIF   = 0;        // make sure ADC interuption not set
    
        ADCON0bits.GO   = 1;        // begin conversion
        while(!PIR1bits.ADIF);      // wait for A/D convert complete

        sample = ADRES;             // get the value from the A/D

        PIR1bits.ADIF   = 0;        // clear A/D Interrupt Flag
        ADCON0bits.ADON = 0;        // Turn off ADC
       
        if (is_transmitter_active) cycles_transmitter_active++;
        
        // check if taken signal sample is greater than thresold by at least
        // the configured value
        
        if (sample > THRESOLD_FLOOR_VALUE && sample > activation_thresold) {
        
            times_thresold_exceeded++;
                     
            if (times_thresold_exceeded == THRESOLD_EXCEED_TIMES_ACTIVATION) {
                             
                // turn on repeater
                
                // set output high
                PINOUT_REPEATER_ON = 1;               
                
                is_transmitter_active     = 1;
                cycles_transmitter_active = 0;
                
                times_thresold_exceeded   = 0;
                
            }
            

        } else {

            times_thresold_exceeded = 0;         
            
            if (cycles_transmitter_active == REPEATER_ACTIVE_CYCLES) {
                // turn off repeater
                PINOUT_REPEATER_ON = 0;
                is_transmitter_active     = 0;
            }
            
            samples[sample_position++]  = sample; // store value in table   
        
            // check if we have to start from first position again (cycle)
            if (sample_position == SAMPLE_TABLE_SIZE) sample_position = 0;

            if (valid_samples == SAMPLE_TABLE_SIZE) {
                
                // calculate new noise mean value
                noise_mean_value = 0;
        
                for (int i = 0; i < SAMPLE_TABLE_SIZE; i++) 
                    noise_mean_value += samples[i];
            
                // we use integes because it is faster
                noise_mean_value = (unsigned short long)(noise_mean_value / SAMPLE_TABLE_SIZE);
                                   
                // calculate new thresold
                // new thresold has to be a fixed percentage over current noise
            
                activation_thresold = noise_mean_value * THRESOLD_NOISE_MULTIPLIER;
                
            }
            
        }
        
        
        // clear interruption flag
        
        PIR1bits.TMR1IF = 0; 
        
    }

}


// this is the high priority interruption function

void interrupt low_priority low_priority_int() {

  
    
 }


