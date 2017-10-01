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
    
    unsigned int sample = 0, oldest_sample        = 0;   /* ADC sample value */
    
    // ASK variables
    static unsigned int previous_signal_level     = LOW;	
    static unsigned int current_signal_level      = LOW; // needed static as well!!

    unsigned int received_bit                     = BIT_0;
    static unsigned int previous_received_bit     = BIT_0;

    static int decoder_status                     = IDLE;
    
    static int bit_to_process                     = 0;
    
    
static int num_bits_received = 0;    
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
        
        if (tmr1_interrupt_number == TMR1_HALF_SECOND ||
                ((tmr1_interrupt_number == TMR1_CENT_SECOND) && (global_command_pending_check == 1))) {

            // blink auxiliar green LED
            PINOUT_TIMER_LED = !PINOUT_TIMER_LED;
            
            // clear the software watchdog timer (131 seconds timer)
            // the watchdog has been configured by software fuses
        
            ClrWdt();

            // start count again
            
            tmr1_interrupt_number = 0;
            
        }
               
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
        
        // store previous signal level (neeed for ASK decoding)
        previous_signal_level = current_signal_level;
        
        // check if taken signal sample is greater than thresold by at least
        // the configured value
        
        if (sample > activation_threshold) {

            // this means a 1 to ASK (we are over threshold level)
            current_signal_level = HIGH;
            
            // count times
            times_threshold_exceeded++;
                     
            if (times_threshold_exceeded >= THRESHOLD_EXCEED_TIMES_ACTIVATION) {
                             
                // turn on repeater              
                PINOUT_REPEATER_PTT_ON    = 1;               
                
                is_transmitter_active     = 1;
                cycles_transmitter_active = 0;
                
                times_threshold_exceeded  = 0;
                
            }

        } else {

            // this means a 0 to ASK (we are under threshold level)        
            current_signal_level       = LOW;
            
            // reset times that threshold has been continuosly exceeded
            times_threshold_exceeded   = 0;         
            
            if (cycles_transmitter_active >= REPEATER_ACTIVE_CYCLES) {
                // turn off repeater
                PINOUT_REPEATER_PTT_ON = 0;
                is_transmitter_active  = 0;
            }
            
            if (valid_samples == SAMPLE_TABLE_SIZE) oldest_sample = samples[sample_position];
                else oldest_sample = 0;

            samples[sample_position] = sample; // store new value in table             
 
            /* check if sample tables is not full yet */
            if (valid_samples < SAMPLE_TABLE_SIZE) valid_samples++;
 
            /* move pointer */
            sample_position++;

            /* check if we have to start from first position again (cycle) */
            if (sample_position == SAMPLE_TABLE_SIZE) sample_position = 0;
 
            /* we add the new sample and subtract the oldest one */
            total_add = total_add + sample - oldest_sample;
 
            /* only calculate average when the table is full of samples */            
            if (valid_samples   == SAMPLE_TABLE_SIZE) {
                
                // calculate new noise mean value
                noise_avg_value      = total_add;              
                // we divide all the sum between the number of samples (128)
                noise_avg_value      = noise_avg_value >> AVERAGE_NOISE_RIGHT_SHIFTS; 
                // calculate new thresold
                
                // new thresold is just the average between max ADC value and noise
                // so (max_adc_value + current_noise lvl / 2)
                activation_threshold = (MAX_ADC_VALUE + noise_avg_value) << THRESHOLD_NOISE_LEFT_SHIFTS;
            activation_threshold = 50;
            
            }
            
        }     
        
        ///////////////////////////////////////////////        
		// ASK commands management
        ///////////////////////////////////////////////

        // ASK signal management
        
        // first transition is to set position high or low, it does not
        // mean a bit
        
        if (decoder_status == IDLE && current_signal_level == HIGH) {
                   
            bit_to_process = 1;
            decoder_status = PROCESSING;
              
        }
        
        if (bit_to_process) {
            
            if (previous_signal_level == LOW && current_signal_level == HIGH) {     

                // low to high means bit 1
                received_bit = BIT_1;

            }  else {
	
                if (previous_signal_level == HIGH && current_signal_level == LOW) {
                    
                    // high to low means 0
                    received_bit = BIT_0;
                                               
                } else {
			
                    // low to low or high to high here means end of transmission
                    received_bit   = NOTHING;
                    decoder_status = IDLE;
                    bit_to_process = 0;
                                        
                   if (num_bits_received == 32) {
                        
                    }

                }
                
            }
        
            if (received_bit != NOTHING) {
                num_bits_received++;

            }    
            else {
                
                if (num_bits_received == 32) {
            
                    global_command_pending_check = !global_command_pending_check;
                    
                }
                num_bits_received = 0;
                
            }
               
        
    
            // if we have a bit we store it in the command buffer
            // but only if we don't have a previous command pending of check
            // (so we do not overwrite it)

//            if (received_bit != NOTHING && !global_command_pending_check) {

 //               global_command_buffer = global_command_buffer << 1;
 //               global_command_buffer = global_command_buffer | received_bit;	// set LSB to received_bit
	
                // check is header is OK, if so we check for a command
                       
 //               if ((global_command_buffer & ASK_COMMAND_HEADER_MASK) == ASK_COMMAND_HEADER_32BITS) {
                //         global_command_pending_check = 1;         
  //              }   
            
  //          }

 //           if (received_bit == NOTHING && !global_command_pending_check) {
            
                // if we received nothing and no command if pending to decode we clean the command buffer
 //             global_command_buffer = 0;
            
  //          }             
            
            bit_to_process = 0; // now it will come a sync transition (0->0, 0->1, 1->0 or 1->1)
        
        
        } else {
            
            // this a a sync pulse (0->0, 0->1, 1->0 or 1->1)
            // but in next timer trigger we have to process
            
            bit_to_process = 1;
            
        }

 
    
   //     }

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


