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

#define PWM_FREQ (1000)             // 1 KHz
#define PWM_CRYSTAL_FREQ           _XTAL_FREQ
#define PWM_INSTRUCTIONS_RATE      (PWM_CRYSTAL_FREQ/4)

void util_pwm_initialize(void);
void util_pwm_start(void);
void util_pwm_stop(void);

#endif
