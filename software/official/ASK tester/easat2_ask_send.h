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

#define BIT_TIME_MS             10
#define HALF_BIT_TIME_MS        5
#define LOW                     0
#define HIGH                    1
#define BIT_0                   0
#define BIT_1                   1

#define GOLAY_COMMAND_SIZE      24      // 24 bits

// functions prototypes

void send_ask_command(unsigned long command);


#endif
