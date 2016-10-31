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

#define DECS_OF_SEC             10          // a second in ten parts
#define CENTS_OF_SEC            100         // a second in one hundred parts
#define SECONDS_IN_MINUTE       60
#define MINUTES_IN_HOUR         60
#define HUNDRED_US              100

// functions prototypes

void util_waits_delay_hours(int hours);
void util_waits_delay_mins(int minutes);
void util_waits_delay_secs(int secs);
void util_waits_delay_ms(int ms);
void util_waits_delay_hundred_us(int us);

#endif
