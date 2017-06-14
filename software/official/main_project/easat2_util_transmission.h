/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_transmission.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_UTIL_TRANSMISSION
#define EASAT2_UTIL_TRANSMISSION

#include "easat2.h"
#include <stdio.h>
#include <string.h>

// functions prototypes

void util_beacon_transmission(float battery_voltage, int solar_current,
                                int battery_current, float temperature);

void util_command_ack_transmission(unsigned int command, unsigned int value);

void util_transmit_letter(char letter);
void util_transmit_morse_sequence(char * morse_sequence); 
void util_transmit_dot(void);
void util_transmit_dash(void);

void util_transmit_space_between_dots_dashes(void);
void util_transmit_space_between_letters(void);
void util_transmit_space_between_words(void);

void util_transmit_buzzer_1ms_cycle(void);

#define EASAT2_BEACON_COMMAND_HEADER "EASAT2 ACK"

#define MAX_BEACON_MESSAGE          128
#define MAX_BEACON_BUFFER           64

#define EASAT2_BEACON_HEADER        "EASAT2"

#define BUZZER_PRESENT              1      // 1 if present, 0 if not
#define US_IN_A_MS                  1000   // microseconds in a milisecond
#define BUZZER_CYCLE_HUNDRED_US     10     // 10*100 = 1000 us cycle (1ms = 1 Khz)
#define BUZZER_HALF_CYCLE_HUNDRED_US  (int)(BUZZER_CYCLE_HUNDRED_US/2)

#define PORT_D_OUTPUT_LED           1  
#define PORT_D_OUTPUT_BUZZER        2
#define PORT_D_OUTPUT_RF            3

// beacon speed selection

// only WPM has to be specified. Dot duration and other parameters
// are calculated from it.

// WPM (words per minute) = 2.4 * dots_per_sec = 2400 / dot_duration_ms

// dot duration in ms  = 2400 / WPM
// dash duration in ms = 3 times dot duration
// separation between letters is 3 times dot duration
// separation between words is 7 times dot duration

// if we choose 32 WPM -> dot_length in ms = 2400 / 32 = 75 ms

// dot duration would be         -> (75 ms)
// dash duration would be 3 dots -> (75 ms * 3 = 225 ms)

// separation between dots and dashes would be 1 dot -> (75 ms)
// separation between letters would be 3 dots -> (75 ms * 3 = 225 ms)
// separation between words would be 7 dots   -> (75 ms * 7 = 525 ms)   
      
#define BEACON_WPM                  32

#define CONST_DOTS_SEG              2400
    
#define DOT_DURATION_MS             (int)(CONST_DOTS_SEG/BEACON_WPM) // in ms
#define DASH_DURATION_MS            (DOT_DURATION_MS*3)         // in ms
    
#define DOTS_DASHES_SEPARATION_MS   DOT_DURATION_MS
#define LETTERS_SEPARATION_MS       3*DOT_DURATION_MS
#define WORDS_SEPARATION_MS         7*DOT_DURATION_MS
       

#endif
