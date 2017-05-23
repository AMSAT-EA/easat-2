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

#define TEST_COMMAND (unsigned int) 0xAAA      // 010101010000111101010101

#define MAIN_LOOP_SLEEP_MINUTES         1

// functions prototypes

void main_loop(void);


#endif
