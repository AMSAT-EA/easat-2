/*
 *                                                       
 * Project     : EASAT2 ASK                                           
 * File        : easat2_ask_main.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_ASK_MAIN_MCU
#define EASAT2_ASK_MAIN_MCU

#include "easat2_ask.h"
#include "easat2_ask_send.h"

#define GOLAY_COMMAND_STRING_SIZE   32
                                
#define TEST_COMMAND (unsigned long) 0x550000A1 // header 55 + 24 bits Golay
                                               // Golay = 12 data bis + 12 CRC

#define MAIN_LOOP_SLEEP_MINUTES         1
#define MAIN_LOOP_SLEEP_SECONDS         10     // 10 seconds between sends
#define LED_TIME_ON_MS                  300    // 300 ms

// functions prototypes

void main_loop(void);
void blink_debugging_led(void);

#endif
