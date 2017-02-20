/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_timer.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_UTIL_TIMER
#define EASAT2_UTIL_TIMER

#include "easat2.h"

#define TMR1_HALF_SECOND 5

// functions prototypes

void util_timer1_initialize(void);
void interrupt high_priority_int();
void interrupt low_priority low_priority_int();


#endif
