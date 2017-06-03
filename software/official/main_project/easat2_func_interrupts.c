/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_func_interrupts.c
 *
 * Description : Functions related to timer interruption
 * Last update : 18 January 2017                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_func_interrupts.h"


// this is the high priority interruption function.
// TMR1 triggers 100 times per second (100 Hz - 10ms cycle)
// Sample table size is 128, so it is stored more than 1 second

void interrupt high_priority_int() {

    static int tmr1_interrupt_number = 0;

    static unsigned int samples[SAMPLE_TABLE_SIZE];
    static unsigned int sample_position           = 0;
    static unsigned short long noise_avg_value    = INITIAL_NOISE_MEAN_VALUE;
    static unsigned int activation_threshold      = INITIAL_ACTIVACION_THRESHOLD;
    static unsigned int times_threshold_exceeded  = 0;
    static unsigned int cycles_transmitter_active = 0;   /* (number of interruptions) */
    static unsigned char is_transmitter_active    = 0;
    
    static unsigned int total_add                 = 0;   /* total add for average level */  
    static unsigned int valid_samples             = 0;   /* valid samples in sample size */
    
    unsigned int sample                           = 0;   /* ADC sample value */
    
    // ASK variables
    static unsigned int previous_signal_level     = LOW;	
    unsigned int current_signal_level             = LOW;

    unsigned int received_bit                     = BIT_0;
    static unsigned int previous_received_bit     = BIT_0;

    static unsigned int num_received_bits         = 0; // number of continuos bit received
    // code
    
    if (PIR1bits.TMR2IF) {
        
       // clear interruption flag
        
        PIR1bits.TMR2IF = 0;  
        
    } else {
    
      // check if it is TMR1 overflow
    
      if (PIR1bits.TMR1IF) {

        /* initial timer value */
        
        TMR1H = TIMER1H_VAL; /* EC77 for 60535 */
        TMR1L = TIMER1L_VAL;
             
        // change output in hardware watchdog pin (60 seconds configuration)
        
        PINOUT_WATCHDOG = !PINOUT_WATCHDOG;
            
        // TMR1 overflow interruption count
               
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
        
        if (sample > THRESHOLD_FLOOR_VALUE && sample > activation_threshold) {

            // this means a 1 to ASK (we are over threshold level)
            current_signal_level = HIGH;
            
            // count times
            times_threshold_exceeded++;
                     
            if (times_threshold_exceeded == THRESHOLD_EXCEED_TIMES_ACTIVATION) {
                             
                // turn on repeater              
                PINOUT_REPEATER_PTT_ON = 1;               
                
                is_transmitter_active     = 1;
                cycles_transmitter_active = 0;
                
                times_threshold_exceeded   = 0;
                
            }

        } else {

            // this means a 0 to ASK (we are under threshold level)        
            current_signal_level     = LOW;
            
            // reset times that threshold has been continuosly exceeded
            times_threshold_exceeded = 0;         
            
            if (cycles_transmitter_active == REPEATER_ACTIVE_CYCLES) {
                // turn off repeater
                PINOUT_REPEATER_PTT_ON    = 0;
                is_transmitter_active     = 0;
            }
            
            samples[sample_position]  = sample; // store value in table   
            
            /* we add the new sample and substract the oldest one */
            total_add += sample;
            
            if (sample_position > 0)
                total_add -= samples[sample_position-1];
            else
                total_add -= samples[SAMPLE_TABLE_SIZE-1];
            
            /* move pointer */
            sample_position++;
        
            // check if we have to start from first position again (cycle)
            if (sample_position == SAMPLE_TABLE_SIZE) sample_position = 0;

            // only calculate average when the table is full of samples
            if (valid_samples   == SAMPLE_TABLE_SIZE) {
                
                // calculate new noise mean value
                noise_avg_value      = total_add;              
                // we use integes because it is faster
                noise_avg_value      = noise_avg_value >> AVERAGE_NOISE_RIGHT_SHIFTS;
                // calculate new thresold
                // new thresold has to be a fixed percentage over current noise
                activation_threshold = noise_avg_value < THRESHOLD_NOISE_LEFT_SHIFTS;
                
            }
            
        }     
        
        ///////////////////////////////////////////////        
		// ASK commands management
        ///////////////////////////////////////////////

        // ASK signal management
        
        if (previous_signal_level == LOW && current_signal_level == HIGH) {
            
            // low to high means bit 1
            received_bit = BIT_1;
            
            // count the bit
            if (num_received_bits < ASK_COMMAND_LENGTH) num_received_bits++;
                    
        }  else {
	
                if (previous_signal_level == HIGH && current_signal_level == LOW) {
                    
                    // high to low means 0
                    received_bit = BIT_0;
                    
                    // count the bit
                    if (num_received_bits < ASK_COMMAND_LENGTH) num_received_bits++;
                            
                } else {
			
                    // low to low or high to high means nothing at this timing
                    received_bit = NOTHING;
		
                    // reset bit counter
                    num_received_bits = 0;
                }
        }
	
        // if we have a bit we store it in the command buffer
        // but only if we don't have a previous command pending of check
        // (so we do not overwrite it)

        if (received_bit != NOTHING && num_received_bits <= ASK_COMMAND_LENGTH
                && !global_command_pending_check) {

            global_command_buffer << 1;
            global_command_buffer = global_command_buffer & 0xfffffe;       // set LSB to 0
            global_command_buffer = global_command_buffer | received_bit;	// set LSB to received_bit
	
        }

        // check if we just finished to receive a command
        if (received_bit == NOTHING && previous_received_bit != NOTHING && !global_command_pending_check
                && num_received_bits == ASK_COMMAND_LENGTH) {
                       
            // if we received nothing but in last timer expiration we had a bit
            // we check if we have a possible commmand

            global_command_pending_check = 1;

        }

        if (received_bit == NOTHING && previous_received_bit == NOTHING && !global_command_pending_check) {
	
            // if we received nothing last two times and no command if pending to decode we clean the command buffer

            global_command_buffer = 0;
            num_received_bits     = 0;

        }             

        ///////////////////////////////////////////////
        // end of ASK management
        ///////////////////////////////////////////////        
        
        // clear interruption flag
        
        PIR1bits.TMR1IF = 0; 
        
    }

  }
}


// this is the high priority interruption function

void interrupt low_priority low_priority_int() {

  
    
 }


