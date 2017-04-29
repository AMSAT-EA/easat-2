/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_pwm.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_UTIL_PWM
#define EASAT2_UTIL_PWM

#include "easat2.h"

#define PWM_FREQ                1000         // 1 KHz
#define PWM_PRESCALE            4

// TMR2 period register (PR2)
// PR2 = [ XTAL_FREQ / (4 x PWM_FREQ x TMRprescale) ] - 1

#define PWM_PERIOD_REGISTER_VALUE (_XTAL_FREQ / (4 * PWM_FREQ * PWM_PRESCALE)) - 1 // 124
#define PWM_DUTY_CYCLE_VALUE      2*(PWM_PERIOD_REGISTER_VALUE + 1)                // 250 for 50% duty cycle               

// the 10 bit duty cycle value must be stored in two parts.
// a 8 bit MSB stored in CCPR2L and 2 bit LSB part stores in DC2B1:DC2B0

// here values have been calculated for 50% duty cycle

#define PWM_DUTY_CYCLE_MSB_VALUE  (PWM_DUTY_CYCLE_VALUE >> 2) & 0xFF              // 62
#define PWM_DUTY_CYCLE_LSB_VALUE  (PWM_DUTY_CYCLE_VALUE)      & 0x03              // 2

void util_pwm_initialize(void);
void util_pwm_start(void);
void util_pwm_stop(void);

#endif
