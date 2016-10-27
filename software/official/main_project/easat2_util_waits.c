/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_utils_waits.c
 *
 * Description : EASAT2 MCU delays library
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_util_waits.h"


// this function causes a delay in hours

void util_wait_delay_hours(int hours) {
    
    
    
}

// this function causes a delay in minutes

void util_wait_delay_mins(int minutes) {
    
    
    
}

// this function causes a delay in seconds

void util_waits_delay_secs(int secs) {
    
    
    
}

// this function causes a delay in ms

void util_waits_delay_ms(int ms) {
    for (int i = 0; i < ms; i++)
        __delay_ms(1);    
}

// this function causes a delay in us

void util_waits_delay_us(int us) {  
    for (int i = 0; i < us; i++)
        __delay_us(1);    
}
