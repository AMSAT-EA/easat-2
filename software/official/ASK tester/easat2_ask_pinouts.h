/*
 *                                                       
 * Project     : EASAT2 ASK                                            
 * File        : easat2_ask_pinouts.h
 *
 * Description : This file include all the necessary project includes
 * Last update : 01 April 2017                                              
 *                                                                            
*/

#ifndef EASAT2_ASK_PINOUTS_H
#define	EASAT2_ASK_PINOUTS_H

#include <xc.h>
#include "easat2_ask_config.h"

// pinout configuration, look in initialize file for i/o analog/digital conf

#define PINOUT_ASK_OUTPUT                 (PORTBbits.RB1)                                        
#define PINOUT_ASK_LED                    (PORTBbits.RB2)
#define PINOUT_TIMER_LED                  (PORTBbits.RB3)

// PORTB
                                                        

// PORTC

// PORTD
                                                          
// PORTE


// TRIS registers that change while execution


#endif
