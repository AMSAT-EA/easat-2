/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_inputs.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_UTIL_INPUTS
#define EASAT2_UTIL_INPUTS

#include "easat2.h"

// functions prototypes

float util_getBatteryVoltage(void);
int util_getSolarCurrent(void);
int util_getBatteryCurrent(void);
float util_getTemperature(void);

#define ADC_VOLTAGE_REFERENCE 2.048         // internal common ADC reference
#define ADC_BATTERY_VOLTAGE_SCALER_FACTOR   5.7
#define ADC_SOLAR_CURRENT_SCALER_FACTOR     1.0
#define ADC_BATTERY_CURRENT_SCALER_FACTOR   1.0

#define MAX_THERMOMETER_WAIT_ATTEMPS        5
#define THERMOMETER_TABLE_SIZE              9   // in bytes ( 8 + crc one)
#define THERMOMETER_BIT_TABLE_SIZE          (THERMOMETER_TABLE_SIZE*8)

#define BITS_IN_BYTE                        8

#endif
