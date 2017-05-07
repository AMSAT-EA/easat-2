/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_pinouts.h
 *
 * Description : This file include all the necessary project includes
 * Last update : 01 April 2017                                              
 *                                                                            
*/

#ifndef EASAT2_PINOUTS_H
#define	EASAT2_PINOUTS_H

#include <xc.h>
#include "easat2_config.h"

// pinout configuration, look in initialize file for i/o analog/digital conf

// ADC channels

#define PINOUT_ADC_BATTERY_VOLTAGE_CHANNEL    0   // AN0  (RA0)
#define PINOUT_ADC_SOLAR_CURRENT_CHANNEL      1   // AN1  (RA1)
                                                  // AN2  (RA2) used by DAC
                                                  // AN3  is used as digital
#define PINOUT_ADC_RF_IN_SIGNAL_POWER_CHANNEL 4   // AN4  (AN4 is pin RA5)
#define PINOUT_ADC_BATTERY_CURRENT_CHANNEL    12  // AN12 (RB0)

// PORTA, configured as input (except RA3 termomether, that is bidirectional,
//        and RA2, where DAC is found)

#define PINOUT_BATTERY_VOLTAGE_CHANNEL    (PORTAbits.RA0) // used as ADC channel
#define PINOUT_SOLAR_CURRENT_CHANNEL      (PORTAbits.RA1) // used as ADC channel
#define PINOUT_AGC_DAC                    (PORTAbits.RA2) // DAC for AGC
#define PINOUT_THERMOMETER                (PORTAbits.RA3) // digital termomether
                                                          // RA4 avaliable
#define PINOUT_RF_IN_SIGNAL_POWER_CHANNEL (PORTAbits.RA5) // used as ADC channel
                                                          // RA6 crystal
                                                          // RA7 crystal
// PORTB, configured as output except RB0

#define PINOUT_BATTERY_CURRENT_CHANNEL    (PORTBbits.RB0) // used as ADC channel
#define PINOUT_REPEATER_PTT_ON            (PORTBbits.RB1) // repeater on (PTT-ENA line)
#define PINOUT_REPEATER_MODE_ON           (PORTBbits.RB2) // high for repeater mode on
#define PINOUT_HIPOWER_MODE_ON            (PORTBbits.RB3) // high for high power mode on
#define PINOUT_BEACON_MODE_ON             (PORTBbits.RB4) // high for beacon mode on
                                                          // RB5 avaliable
                                                          // RB6 external prog line
                                                          // RB7 external prog line
// PORTC

// PORTD, configured as output
                                                           // RD0 avaliable
#define PINOUT_BEACON_LED                 (PORTDbits.RD1)  // main test red led pin
#define PINOUT_BUZZER                     (PORTDbits.RD2)  // test buzzer 1 Khz square wave
#define PINOUT_BEACON_OUT                 (PORTDbits.RD3)  // Audio beacon out, same as buzzer
#define PINOUT_TIMER_LED                  (PORTDbits.RD4)  // aux green blinking timer led
#define PINOUT_WATCHDOG                   (PORTDbits.RD5)  // out signal to watchdog
                                                           // RD6 avaliable
                                                           // RD7 avaliable
// PORTE


// TRIS registers that change while execution

#define PINOUT_BUZZER_PWM                 (TRISDbits.TRISD2) // PWM CCP P2B
#define PINOUT_BEACON_AUDIO_PWM           (TRISDbits.TRISD3) // PWM CCP P2C

#endif
