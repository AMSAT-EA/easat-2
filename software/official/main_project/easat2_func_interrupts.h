/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_func_interrupts.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_FUNC_INTERRUPTS
#define EASAT2_FUNC_INTERRUPTS

#include "easat2.h"
#include "easat2_init_timer.h"

#define TMR1_HALF_SECOND                    50
#define SAMPLE_TABLE_SIZE                   100   // 100 samples in a second
#define INITIAL_NOISE_MEAN_VALUE            32000 // initial value ADC max is 1024
#define INITIAL_ACTIVACION_THRESOLD         32000 // initial value ADC max is 1024
#define THRESOLD_EXCEED_TIMES_ACTIVATION    200   // times thresold has to be exceeded
                                                  // to consider it is a transmission 
                                                  // 200 = 2 seconds

#define THRESOLD_NOISE_MULTIPLIER           2     // thresold is calculated with this
#define THRESOLD_FLOOR_VALUE                128   // minimun thresold 0.256V
                                            

#define REPEATER_ACTIVE_CYCLES              12000 // 2 minutes transmitter active */
// functions prototypes

void interrupt high_priority_int();
void interrupt low_priority low_priority_int();


#endif
