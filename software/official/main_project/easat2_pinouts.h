/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : pinouts.h
 *
 * Description : This file include all the necessary project includes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_PINOUTS_H
#define	EASAT2_PINOUTS_H

#include <xc.h>
#include "easat2_config.h"

// pinout configuration, look in initialize file for i/o analog/digital conf

// ADC channels

#define PINOUT_ADC_BATTERY_VOLTAGE_CHANNEL    0   // AN0 (RA0)
#define PINOUT_ADC_SOLAR_CURRENT_CHANNEL      1   // AN1 (RA1)
#define PINOUT_ADC_BATTERY_CURRENT_CHANNEL    2   // AN2 (RA2)
                                                  // AN3 is used as digital
#define PINOUT_ADC_RF_IN_SIGNAL_POWER_CHANNEL 4   // AN4 (RA4)

// PORTA, configured as input (termomether is bidirectional)

#define PINOUT_BATTERY_VOLTAGE_CHANNEL    (PORTAbits.RA0) // used as ADC channel
#define PINOUT_SOLAR_CURRENT_CHANNEL      (PORTAbits.RA1) // used as ADC channel
#define PINOUT_BATTERY_CURRENT_CHANNEL    (PORTAbits.RA2) // used as ADC channel
#define PINOUT_TERMOMETHER                (PORTAbits.RA3) // digital termomether
#define PINOUT_RF_IN_SIGNAL_POWER_CHANNEL (PORTAbits.RA4) // used as ADC channel

// PORTB


// PORTC


// PORTD, configured as output
                                                // RD0 avaliable
#define PINOUT_BEACON_LED      (PORTDbits.RD1)  // main test led pin
#define PINOUT_BUZZER          (PORTDbits.RD2)  // test buzzer 1 Khz square wave
#define PINOUT_BEACON_ON       (PORTDbits.RD3)  // beacon switch on /off
#define PINOUT_TIMER_LED       (PORTDbits.RD4)  // aux blinking timer led
#define PINOUT_WATCHDOG        (PORTDbits.RD5)  // out signal to watchdog
#define PINOUT_REPEATER_ON     (PORTDbits.RD6)  // repeater on / off


#endif
