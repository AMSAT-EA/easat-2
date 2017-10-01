/*
 *                                                       
 * Project     : EASAT2 ASK                                            
 * File        : easat2_ask_send.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_ASK_SEND
#define EASAT2_ASK_SEND

#include "easat2_ask.h"
#include "easat2_ask_util_waits.h"
#include "easat2_ask_init_timer.h"

#define BIT_TIME_MS             20      // 50 bits / seg -> 1 bit each 20 ms
#define HALF_BIT_TIME_MS        10
#define LOW                     0
#define HIGH                    1
#define BIT_0                   0
#define BIT_1                   1

#define GOLAY_COMMAND_SIZE      24      // 24 bits
#define FULL_COMMAND_SIZE       32      // 24 + 8 header = 32 bits

#define BIT_VALUE               0
#define INITIAL_SIGNAL          1
#define FINAL_SIGNAL            2

#define TRANSITION_TABLE_COLUMNS 3

// functions prototypes

void send_ask_command(unsigned long command);


#endif
