/*
 *                                                       
 * Project     : EASAT2 ASK                                            
 * File        : easat2_ask_main_mcu.c
 *
 * Description : EASAT2 ASK tester MCU main program
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include <stdio.h>
#include "easat2_ask.h"
#include "easat2_ask_main_mcu.h"
#include "easat2_ask_init_initialize.h"
#include "easat2_ask_util_waits.h"
#include "easat2_golay_CRCG.h"

// global variable for timer
volatile int global_timer_flag = 0;      // set to 1 when timer has been fired

void main(void) {
    
    // initialize MCU
    init_initialize();
                
    // main loop
    main_loop();
           
}
    
// this is the code main loop

void main_loop(void) {
        
    unsigned long test_command  = TEST_COMMAND;
    unsigned long golay_command = 0;
    
    // waits 5 seconds before doing anything
    
    util_waits_delay_secs(5);
    
    do {
                    
        // code command in Golay format
        // golay_command = golay(test_command);

        // golay_command = (unsigned long)TEST_COMMAND;
        
        // send command
        // send_ask_command(golay_command);

        send_ask_command(0xAA123456);            
       
        // wait until next cycle
 
        util_waits_delay_secs(4); // plus 1 internal seconds wait
            
    } while (1);    
        
    
}