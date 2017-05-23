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
    
    do {
            
        // codify command in Golay format
        golay_command = golay(test_command);
                     
        // send command
        send_ask_command(golay_command);
            
        // wait until next cycle
        util_waits_delay_mins(MAIN_LOOP_SLEEP_MINUTES);
            
            
    } while (1);    
        
    
}