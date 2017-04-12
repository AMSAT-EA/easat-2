/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_transmission.c
 *
 * Description : Functions to interface with transmission module
 * Last update : 26 October 2016                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_util_transmission.h"
#include "easat2_util_waits.h"
#include "easat2_util_pwm.h"

// This is the function to be called to transmit the beacon message
// It receives the sensor values (battery voltage, solar panel current,
// battery current and the system temperature in Celsius) and it uses
// one of the ports to communicate with the RF module to transmit the
// beacon message.

void util_beacon_transmission(float battery_voltage, int solar_current,
                                int battery_current, float temperature) {
    
    char BEACON_MESSAGE[MAX_BEACON_MESSAGE];
    char BEACON_BUFFER[MAX_BEACON_BUFFER];
    
    // build the beacon message
    
    memset(BEACON_MESSAGE, 0, sizeof(BEACON_MESSAGE));
    strcpy(BEACON_MESSAGE, EASAT2_BEACON_HEADER);
    
    memset(BEACON_BUFFER, 0, sizeof(BEACON_BUFFER));
    sprintf(BEACON_BUFFER, " %.1f %.1f %3.0d %3.0d", temperature, battery_voltage,
        solar_current, battery_current);

    strcat(BEACON_MESSAGE, BEACON_BUFFER);
        
    // go over the message and call a function that will
    // transmit the current letter to the RF module
    
    for (int i = 0; i < strlen(BEACON_MESSAGE); i++) {
        util_transmit_letter(BEACON_MESSAGE[i]);
    }
 
}

// This function receives the ASCII letter to be transmited using
// the RF module. It translates the letter to its morse sequence
// and calls the function that will transmit the sequence to the
// RF module.

void util_transmit_letter(char letter) {
    
    switch (letter) {
        
        // decode the letter to its morse representation
        // and call the function to transmit it
        
        case CHAR_A:  
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_A);
            break;
        case CHAR_B: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_B);
            break;
        case CHAR_C:            
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_C);
            break;
        case CHAR_D: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_D);
            break;
        case CHAR_E: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_E);
            break;
        case CHAR_F: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_F);
            break;
        case CHAR_G: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_G);
            break;
        case CHAR_H: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_H);
            break;
        case CHAR_I: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_I);
            break;
        case CHAR_J: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_J);
            break;
        case CHAR_K: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_K);
            break;
        case CHAR_L: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_L);
            break;
        case CHAR_M: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_M);
            break;
        case CHAR_N: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_N);
            break;
        case CHAR_O: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_O);
            break;
        case CHAR_P: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_P);
            break;
        case CHAR_Q: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_Q);
            break;
        case CHAR_R: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_R);
            break;
        case CHAR_S: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_S);
            break;
        case CHAR_T: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_T);
            break;
        case CHAR_U: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_U);
            break;
        case CHAR_V: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_V);
            break;
        case CHAR_W: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_W);
            break;
        case CHAR_X: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_X);
            break;
        case CHAR_Y: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_Y);
            break;
        case CHAR_Z: 
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_LETTER_Z);
            break; 
        case DIGIT_0:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_0);
            break;
        case DIGIT_1:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_1);
            break;
        case DIGIT_2:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_2);
            break;
        case DIGIT_3:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_3);
            break;
        case DIGIT_4:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_4);
            break;            
        case DIGIT_5:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_5);
            break;
        case DIGIT_6:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_6);
            break;            
        case DIGIT_7:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_7);
            break;            
        case DIGIT_8:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_8);
            break;            
        case DIGIT_9:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_DIGIT_9);
            break;            
        case SYMBOL_COMMA:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_SYMBOL_COMMA);
            break;       
        case SYMBOL_QUESTION:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_SYMBOL_QUESTION);
            break; 
        case SYMBOL_SLASH:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_SYMBOL_SLASH);
            break; 
        case SYMBOL_DOT:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_SYMBOL_DOT);
            break;
        case SYMBOL_DASH:
            util_transmit_morse_sequence((char*)MORSE_SEQUENCE_SYMBOL_DASH);
            break;
        case SYMBOL_SPACE:
            util_transmit_space_between_words();
            break;
        default:
            break;
            
    }

    /* after the letter, digit or symbol wait */
    util_transmit_space_between_letters();

}

// This function receives a dots and dashes sequence in ASCII
// and it transmits it to the RF module using the configured port
// It uses a function to transmit the dot and another one to
// transmit the dash.
// It also waits the needed time between each dot and dash

void util_transmit_morse_sequence(char * morse_sequence) {

    /* go over the sequence */
    
    for (int i = 0; i < strlen(morse_sequence); i++) {
        
        switch(morse_sequence[i]) {
            
            case SYMBOL_DOT:
                util_transmit_dot();
                break;   
            case SYMBOL_DASH:
                util_transmit_dash();
                break;   
            default:  
                break;
        }

        // after a dot or dash always wait the required time
        util_transmit_space_between_dots_dashes();
   
    } 
    
}

// This function transmits a dot using the port
// Transmiting a dot is just put to high the output of the port
// the required time and then to low.
// To make the buzzer sound, a 1 Khz square signal is generated inside

void util_transmit_dot(void) {
    
    // set to high the configured outputs
    
    PINOUT_BEACON_LED = 1;  // led pin
//    PINOUT_BEACON_OUT = 1;  // RF module pin
    
    util_pwm_start();  
    util_waits_delay_ms(DOT_DURATION_MS);         
    util_pwm_stop();  
    
    PINOUT_BEACON_LED = 0;  // led pin
//    PINOUT_BEACON_OUT = 0;  // RF module pin
    
}

// This function transmits a dot using the port
// Transmiting a dot is just put to high the output of the port
// the required time and then to low. The dash duration is three
// times the dot duration.
// To make the buzzer sound, a 1 Khz square signal is generated inside

void util_transmit_dash(void) {
    
    // set to high the configured outputs
    
    PINOUT_BEACON_LED = 1;  // led pin on
//    PINOUT_BEACON_OUT = 1;  // RF module pin on
    
    util_pwm_start();  
    util_waits_delay_ms(DASH_DURATION_MS);    
    util_pwm_stop();  
    
    PINOUT_BEACON_LED = 0;  // led pin off
 //   PINOUT_BEACON_OUT = 0;  // RF module pin off
}

// This function waits the required time between dots and dashes
// Each time a dot or dash is transmited this function has to be called

void util_transmit_space_between_dots_dashes(void) {
    util_waits_delay_ms(DOTS_DASHES_SEPARATION_MS);
}

// This function waits the required time between letters (and digits))
// Each time a letter, digit or symbol is transmited this function has
// to be called.

void util_transmit_space_between_letters(void) {
    util_waits_delay_ms(LETTERS_SEPARATION_MS); 
}

// This function waits the required time between words
// Each time a word is transmited this function has to be called.

void util_transmit_space_between_words(void) {
    util_waits_delay_ms(WORDS_SEPARATION_MS);     
}

// This function makes the buzzer sound just 1ms

void util_transmit_buzzer_1ms_cycle(void) {
           
//    PINOUT_BUZZER = 1;  // buzzer pin high
    util_waits_delay_hundred_us(BUZZER_HALF_CYCLE_HUNDRED_US);
//    PINOUT_BUZZER = 0;  // buzzer pin low
    util_waits_delay_hundred_us(BUZZER_HALF_CYCLE_HUNDRED_US);
           
}