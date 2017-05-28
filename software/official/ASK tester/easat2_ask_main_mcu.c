/*
 *                                                       
 * Project     : EASAT2 ASK                                            
 * File        : easat2_ask_main_mcu.c
 *
 * Description : EASAT2 MCU main program
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
 
// this function set blinks the led

void blink_debugging_led(void) {
    
    // turn on debugging LED
    PINOUT_ASK_LED = 1;

    // let LED on 500ms   
    util_waits_delay_ms(LED_TIME_ON_MS);
    
    // turn off debugging LED
    PINOUT_ASK_LED = 0;
    
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
        
        // blink led
        blink_debugging_led();
            
        // wait until next cycle
        util_waits_delay_secs(MAIN_LOOP_SLEEP_SECONDS);
            
            
    } while (1);    
        
    
}