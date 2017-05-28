/*
 *                                                       
 * Project     : EASAT2 ASK                                           
 * File        : easat2_ask_send.c
 *
 * Description : EASAT2 MCU initializing functions
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include "easat2_ask.h"
#include "easat2_ask_send.h"


// this function sends the command string (formed by a binary sequence)
// in ASK Manchester modulation at 50 bits / second from LSB to MSB

void send_ask_command(unsigned long command) {
    
    int current_signal_level = LOW;
    int bit_to_transfer      = BIT_0;
    int i = 0; 
       
    /* send command from LSB to MSB */
     
    do {
            
        bit_to_transfer = command & 1;  // get only LSB bit
        
        // start 
        // set signal position
        
        // begin of bit time
        
        // to transmit 1 we need a transition from 0 to 1 so we set low (0)
        if (bit_to_transfer == BIT_1 && current_signal_level == HIGH) 
            current_signal_level = LOW;
        
        // to transmit 0 we need a transition from 1 to 0 so we set high (1))
        if (bit_to_transfer == BIT_0 && current_signal_level == LOW) 
            current_signal_level = HIGH;
        
        PINOUT_ASK_OUTPUT = current_signal_level;
        
        // half of bit time
        
        util_waits_delay_ms(HALF_BIT_TIME_MS);        // half of bit time
 
       // to transmit 1 we need a transition from 0 to 1 so we set low (0)
        if (bit_to_transfer == BIT_1 && current_signal_level == HIGH) 
            current_signal_level = LOW;
        
        // to transmit 0 we need a transition from 1 to 0 so we set high (1))
        if (bit_to_transfer == BIT_0 && current_signal_level == LOW) 
            current_signal_level = HIGH;
         
        PINOUT_ASK_OUTPUT = current_signal_level;
        
        util_waits_delay_ms(HALF_BIT_TIME_MS);        // half of bit time
        
        // end of bit time
     
        ////////////////////////////
        
        // set next bit to transfer in LSB position
        command = command >> 1;
                
        i++;
                    
    } while (i < GOLAY_COMMAND_SIZE);
    
  
    
}

    

