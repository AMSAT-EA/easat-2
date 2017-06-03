/*
 *                                                       
 * Project     : EASAT2 ASK                                            
 * File        : easat2_ask_utils_waits.c
 *
 * Description : EASAT2 MCU delays library
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include "easat2_ask.h"
#include "easat2_ask_util_waits.h"


// this function causes a delay in hours

void util_waits_delay_hours(int hours) {
    for (int i = 0; i < hours; i++)
        util_waits_delay_mins(MINUTES_IN_HOUR);
}

// this function causes a delay in minutes

void util_waits_delay_mins(int minutes) {
    for (int i = 0; i < minutes; i++)
        util_waits_delay_secs(SECONDS_IN_MINUTE);     
}

// this function causes a delay in seconds

void util_waits_delay_secs(int secs) {
    for (int i = 0; i < secs; i++) {
        for (int j = 0; j < DECS_OF_SEC; j++ )
            util_waits_delay_ms(CENTS_OF_SEC);
    }       
}

// this function causes a delay in ms

void util_waits_delay_ms(int ms) {
    for (int i = 0; i < ms; i++)
        __delay_ms(1);    
}

// this function causes a delay in hundred of us

void util_waits_delay_hundred_us(int hun_us) {
    for (int i = 0; i < hun_us; i++)
        __delay_us(HUNDRED_US);
}
