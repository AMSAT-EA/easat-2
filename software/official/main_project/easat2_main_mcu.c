/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_main_mcu.c
 *
 * Description : EASAT2 MCU main program
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include"easat2.h"
#include"easat2_main_mcu.h"
#include"easat2_util_initialize.h"
#include"easat2_util_inputs.h"
#include"easat2_util_waits.h"
#include"easat2_util_transmission.h"

        
void main(void) {
    
    // initialize MCU
    initialize();
                
    // main loop
    main_loop();
           
}
    
// this is the code main loop

void main_loop(void) {
        
    float battery_voltage;
    int solar_current;
    int battery_current;
    float temperature;
            
        do {
            
            // get the sensor values
            
            // get the battery voltage
            battery_voltage = getBatteryVoltage();
            
            // get the solar panels current 
            solar_current   = getSolarCurrent();
            
            // get the battery current
            battery_current = getBatteryCurrent();
            
            // get the system temperature
            temperature     = getTemperature();

            // check if is there enough power to transmit and do it if so
            
            if (battery_voltage > MIN_TRANSMIT_VOLTAGE) {              
                util_beacon_transmission(battery_voltage, solar_current, battery_current, temperature);
            }
            
            // wait until next cycle
            util_wait_delay_mins(MAIN_LOOP_SLEEP_MINUTES);                              
            
            
        } while (1);
        
        
    
}