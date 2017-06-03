/*
 *                                                       
 * Project     : EASAT2 ASK                                            
 * File        : easat2_ask_init_timer.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_ASK_INIT_TIMER
#define EASAT2_ASK_INIT_TIMER

#include "easat2_ask.h"

#define TIMER1H_VAL 0xEC
#define TIMER1L_VAL 0x77    ; 60535

// functions prototypes

void init_timer1_initialize(void);
void init_timer2_initialize(void);

#endif
