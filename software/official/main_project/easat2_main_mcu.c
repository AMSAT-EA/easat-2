/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_main_mcu.c
 *
 * Description : EASAT2 MCU main program
 * Last update : 10 October 2016                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_main_mcu.h"
#include "easat2_init_initialize.h"
#include "easat2_util_inputs.h"
#include "easat2_util_waits.h"
#include "easat2_util_transmission.h"

        
void main(void) {
    
    // initialize MCU
    init_initialize();
                
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
            
            // first of all clear the watchdog timer (131 seconds timer)
            // the watchdog has been configured by software fuses
            ClrWdt();
            
            // get the sensor values
            
            // get the battery voltage
            battery_voltage = util_getBatteryVoltage();
            
            // get the solar panels current 
            solar_current   = util_getSolarCurrent();
            
            // get the battery current
            battery_current = util_getBatteryCurrent();
            
            // get the system temperature
            temperature     = util_getTemperature();

            // check if is there enough power to transmit and do it if so
            
            if (battery_voltage >= MIN_TRANSMIT_VOLTAGE) {
                util_beacon_transmission(battery_voltage, solar_current, battery_current, temperature);
            } else {
                // wait to let battery charge before checking again
                util_waits_delay_hours(LOW_BATTERY_SLEEP_HOURS);
            }
            
            // wait until next cycle
            util_waits_delay_mins(MAIN_LOOP_SLEEP_MINUTES);
            
            
        } while (1);
        
        
    
}