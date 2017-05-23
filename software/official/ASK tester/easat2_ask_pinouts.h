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


#define PINOUT_ASK_OUTPUT                 (PORTAbits.RA0)                                        
#define PINOUT_ASK_LED                    (PORTAbits.RA1)
#define PINOUT_TIMER_LED                  (PORTAbits.RA2)

// PORTB
                                                        

// PORTC

// PORTD
                                                          
// PORTE


// TRIS registers that change while execution


#endif
