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

// functions prototypes

void util_beacon_transmission(float battery_voltage, int solar_current,
                                int battery_current, float temperature);


#endif
