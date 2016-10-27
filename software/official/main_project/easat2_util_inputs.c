/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_inputs.c
 *
 * Description : Functions to read port inputs (analog and digital)
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_util_inputs.h"


// get the battery voltage

float getBatteryVoltage(void) {
    
    return 3.702;
    
}
            
// get the solar panels current 
int getSolarCurrent(void ) {
    
    return 120;
    
}
            
// get the battery current
int getBatteryCurrent(void) {
    
    return 100;
    
    
}
            
// get the system temperature
float getTemperature(void) {
    
    return -12.502;
    
}

