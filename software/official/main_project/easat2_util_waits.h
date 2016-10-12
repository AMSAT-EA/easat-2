/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_waits.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_UTIL_WAITS
#define EASAT2_UTIL_WAITS

#include "easat2.h"

// functions prototypes

void util_wait_delay_hours(int hours);
void util_wait_delay_mins(int minutes);
void util_waits_delay_secs(int secs);
void util_waits_delay_ms(int ms);
void util_waits_delay_us(int us);

#endif
