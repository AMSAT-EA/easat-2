/*
 *                                                       
 * Project     : EASAT2 ASK                                           
 * File        : easat2_ask_send.c
 *
 * Description : EASAT2 ASK tester send function
 * Last update : 23 May 2017                                              
 *                                                                            
*/

#include "easat2_ask.h"
#include "easat2_ask_send.h"


// this function sends the command string (formed by a binary sequence)
// in ASK Manchester modulation at 50 bits / second from LSB to MSB
// Manchester modulation is like standard IEEE 802.3 (0 is transition from
// 1 to 0 and 1 is transition from 0 to 1)

void send_ask_command(unsigned long command_in) {
    
    unsigned long command = 0;
    int signal_level = LOW;
    int i = 0; 
    int bit_value = 0;
    
    int transitions[FULL_COMMAND_SIZE][TRANSITION_TABLE_COLUMNS]; // ASK transitions table
    
    // be sure we start with output at LOW
    
    PINOUT_ASK_OUTPUT = LOW; 
    signal_level      = LOW;
    
    // wait two seconds just in case signal was HIGH before we have put
    // it to LOW
    
    util_waits_delay_secs(1);

    PINOUT_ASK_LED = 1;
    
    /* we reverse command so header comes first in send (we send LSB to MSB) */
    
    for (i = 0 ; i < FULL_COMMAND_SIZE; i++) {
    
        bit_value = (command_in >> i) & 0x00000001;
              
        int position = FULL_COMMAND_SIZE-i-1;
        
        // stored in opposite order
        transitions[position][BIT_VALUE] = bit_value;

        if (bit_value == 0) {
            // a 0 is a transition from 1 to 0
            transitions[position][INITIAL_SIGNAL] = 1;
            transitions[position][FINAL_SIGNAL]   = 0;
        } else {
            // a 1 is a transition from 0 to 1
            transitions[position][INITIAL_SIGNAL] = 0;
            transitions[position][FINAL_SIGNAL]   = 1;            
        
        }
        
    }

    // initial sync
    global_timer_flag = 0;
    
    // wait for interruption to be fired (10 ms) (half of bit time)
    do { continue; } while (!global_timer_flag);       

    for (i = 0; i < FULL_COMMAND_SIZE; i++) {
            
        // initial sync
        global_timer_flag = 0;
        
        signal_level = transitions[i][INITIAL_SIGNAL];     

        // wait for interruption to be fired (10 ms) (half of bit time)
        do { continue; } while (!global_timer_flag);       

        PINOUT_ASK_OUTPUT = signal_level;

        global_timer_flag = 0;        
        
        signal_level = transitions[i][FINAL_SIGNAL];

        // wait for interruption to be fired (10 ms) (half of bit time)
        do { continue; } while (!global_timer_flag);       
        
        PINOUT_ASK_OUTPUT = signal_level;
  
    }

    // for the last bit
    
    // wait for interruption to be fired (10 ms) (half of bit time)
    global_timer_flag = 0;
    // wait for interruption to be fired (10 ms) (half of bit time)
    do { continue; } while (!global_timer_flag);       
    
    // end of bit time
    
    // set output to low at the end
    
    PINOUT_ASK_OUTPUT = LOW;       
    
    PINOUT_ASK_LED = 0;
    
}

    

