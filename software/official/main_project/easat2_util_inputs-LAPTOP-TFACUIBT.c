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
#include "easat2_util_onewire.h"
#include "easat2_util_waits.h"


// get the battery voltage

float util_getBatteryVoltage(void) {

    float value = 0.0, voltage = 0.0;

    ADCON0bits.CHS  = PINOUT_ADC_BATTERY_VOLTAGE_CHANNEL; // Select ADC channel 0
    ADCON0bits.ADON = 1;        // Turn on ADC
    PIR1bits.ADIF   = 0;        // make sure ADC interuption not set
    
    ADCON0bits.GO   = 1;        // begin conversion
    while(!PIR1bits.ADIF);      // wait for A/D convert complete

    value           = ADRES;    // get the value from the A/D
    PIR1bits.ADIF   = 0;        // clear A/D Interrupt Flag

    ADCON0bits.ADON = 0;        // Turn off ADC

    // convert the value to real voltage

    // 10 bits = 1024 steps (0 to 1023) so max voltage is 1023
    // voltage = ( Reference in V / 1023) * Result

    voltage = (ADC_VOLTAGE_REFERENCE / 1023.0) * value;

    // adjust value due to the voltage divisor at the enter of ADC
    
    voltage = voltage * ADC_BATTERY_VOLTAGE_SCALER_FACTOR;
    
    return voltage;
            
}
            
// get the solar panels current 

int util_getSolarCurrent(void ) {

    float value = 0.0, solarCurrent = 0.0;

    ADCON0bits.CHS  = PINOUT_ADC_SOLAR_CURRENT_CHANNEL; // Select ADC channel 1
    ADCON0bits.ADON = 1;        // Turn on ADC
    PIR1bits.ADIF   = 0;        // make sure ADC interuption not set
    
    ADCON0bits.GO   = 1;        // begin conversion
    while(!PIR1bits.ADIF);      // wait for A/D convert complete

    value           = ADRES;    // get the value from the A/D
    PIR1bits.ADIF   = 0;        // clear A/D Interrupt Flag

    ADCON0bits.ADON = 0;        // Turn off ADC

    // convert the value to real voltage

    // 10 bits = 1024 steps (0 to 1023) so max voltage is 1023
    // voltage = ( Reference in V / 1023) * Result

    solarCurrent = (ADC_VOLTAGE_REFERENCE / 1023.0) * value;

    // adjust value due to the voltage divisor at the enter of ADC
    
    solarCurrent = solarCurrent * ADC_SOLAR_CURRENT_SCALER_FACTOR;
    
    return (int)solarCurrent;
        
}
            
// get the battery current

int util_getBatteryCurrent(void) {

    float value = 0.0, batteryCurrent = 0.0;

    ADCON0bits.CHS  = PINOUT_ADC_BATTERY_CURRENT_CHANNEL; // Select ADC channel 12
    ADCON0bits.ADON = 1;        // Turn on ADC
    PIR1bits.ADIF   = 0;        // make sure ADC interuption not set
    
    ADCON0bits.GO   = 1;        // begin conversion
    while(!PIR1bits.ADIF);      // wait for A/D convert complete

    value           = ADRES;    // get the value from the A/D
    PIR1bits.ADIF   = 0;        // clear A/D Interrupt Flag

    ADCON0bits.ADON = 0;        // Turn off ADC

    // convert the value to real voltage

    // 10 bits = 1024 steps (0 to 1023) so max voltage is 1023
    // voltage = ( Reference in V / 1023) * Result

    batteryCurrent = (ADC_VOLTAGE_REFERENCE / 1023.0) * value;

    // adjust value due to the voltage divisor at the enter of ADC
    
    batteryCurrent = batteryCurrent * ADC_BATTERY_CURRENT_SCALER_FACTOR;
    
    return (int)batteryCurrent;
    
}

// get the system temperature

float util_getTemperature(void) {

    int byte_mem[THERMOMETER_TABLE_SIZE];
    int bit_mem[THERMOMETER_BIT_TABLE_SIZE];

    int shift_reg_bit0 = 0;
    int shift_reg_bit1 = 0;
    int shift_reg_bit2 = 0;
    int shift_reg_bit3 = 0;
    int shift_reg_bit4 = 0;
    int shift_reg_bit5 = 0;
    int shift_reg_bit6 = 0;
    int shift_reg_bit7 = 0;
    int shift_reg_bit_temp = 0;

    int num_bit = 0, num_byte = 0, bit_in_byte = 0;
    
    float temperature = 0.0;
    float sign        = 1.0;
    int i = 0;
    
    // reset the thermometer

    /* Tx Reset Master issues reset pulse.
     * Rx Presence DS18B20 responds with presence pulse. */
    if (util_onewire_reset()) return THERMOMETER_FAIL_VALUE_1;

    /* Tx CCh Master issues Skip ROM command. */
    util_onewire_write_byte(THERMOMETER_SKIP_ROM_COMMAND);          

    /* Tx 44h Master issues Convert T command. */
    util_onewire_write_byte(THERMOMETER_CONVERT_T_COMMAND);

    /* Wait for temperature conversion -> Read until bus is 1 again */

    // set RA3 as input
    TRISAbits.TRISA3 = 1;

    // we wait until RA3 is 1 again or MAX_ATTEMPS
    
    for (i = 0; i < MAX_THERMOMETER_WAIT_ATTEMPS && PORTAbits.RA3 == 0; i++)
        util_waits_delay_secs(1);

    if (i == MAX_THERMOMETER_WAIT_ATTEMPS) return THERMOMETER_FAIL_VALUE_2;

    /* Tx Reset Master issues reset pulse.
     * Rx Presence DS18B20 responds with presence pulse. */
    if (util_onewire_reset()) return THERMOMETER_FAIL_VALUE_3;

    /* Tx CCh Master issues Skip ROM command. */
    util_onewire_write_byte(THERMOMETER_SKIP_ROM_COMMAND);
            
    /* Tx BEh Master issues Read Scratchpad command. */
    util_onewire_write_byte(THERMOMETER_READ_SCRATCHPAD_COMMAND);
            
     /*
     * Rx9 data bytes
     * Master reads entire scratchpad including CRC.
     * The master then recalculates the CRC of the first eight data bytes
     * from the scratchpad and compares the calculated CRC
     * with the read CRC (byte 9). If they match, the master continues;
     * if not, the read operation is repeated. */

    // temperature LSB
    byte_mem[0] = util_onewire_read_byte();
    // temperature MSB
    byte_mem[1] = util_onewire_read_byte();
    // TH register
    byte_mem[2] = util_onewire_read_byte();
    // TL register
    byte_mem[3] = util_onewire_read_byte();
    // configuration register
    byte_mem[4] = util_onewire_read_byte();
    // reserved
    byte_mem[5] = util_onewire_read_byte();
    // reserved
    byte_mem[6] = util_onewire_read_byte();
    // reserved
    byte_mem[7] = util_onewire_read_byte();
    // crc
    byte_mem[8] = util_onewire_read_byte();

    // we store together all the bits copying them from the byte table

    for (num_byte = 0; num_byte < THERMOMETER_TABLE_SIZE; num_byte++) {
        for (bit_in_byte = 0; bit_in_byte < BITS_IN_BYTE; bit_in_byte++)
            bit_mem[num_bit++] = (byte_mem[num_byte] >> bit_in_byte) & 0x01;
    }
      
    // go over the bit table and use the crc polynom on the bits

    for (i = 0; i < THERMOMETER_BIT_TABLE_SIZE; i++) {

        // check crc polynomy x8+x5+x4+1
        // we use a 8 position shift register
        
        shift_reg_bit_temp  = shift_reg_bit0^bit_mem[i]; // lsb

        shift_reg_bit0 = shift_reg_bit1;
        shift_reg_bit1 = shift_reg_bit2;
        shift_reg_bit2 = shift_reg_bit3 ^ shift_reg_bit_temp;
        shift_reg_bit3 = shift_reg_bit4 ^ shift_reg_bit_temp;
        shift_reg_bit4 = shift_reg_bit5;
        shift_reg_bit5 = shift_reg_bit6;
        shift_reg_bit6 = shift_reg_bit7;
        shift_reg_bit7 = shift_reg_bit_temp;            // msb

    }

    // if all bits in shift register contain 0, then crc is OK

    if (shift_reg_bit0 != 0 || shift_reg_bit1 != 0 || shift_reg_bit2 != 0 &&
        shift_reg_bit3 != 0 || shift_reg_bit4 != 0 || shift_reg_bit5 != 0 &&
        shift_reg_bit6 != 0 || shift_reg_bit7 != 0)
        return THERMOMETER_CRC_FAIL;

    // if crc is ok we get the temperature value

    if (bit_mem[11] == 0) sign = 1.0; else sign = -1.0;

    temperature = (float)bit_mem[0]/16.0 + (float)bit_mem[1]/8.0  +
                  (float)bit_mem[2]/4.0  + (float)bit_mem[3]/2.0  +
                  (float)bit_mem[4]      + (float)bit_mem[5]*2.0  ;
    temperature = temperature +
                  (float)bit_mem[6]*4.0  + (float)bit_mem[7]*8.0  +
                  (float)bit_mem[8]*16.0 + (float)bit_mem[9]*32.0 +
                  (float)bit_mem[10]*64.0;

    temperature = temperature * sign;
    
    return temperature;

}
