/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_eeprom.c
 *
 * Description : Functions related to EEPROM management
 * Last update : 18 January 2017                                              
 *                                                                            
*/

#include "easat2.h"


// this function checks that EEPROM contents are OK using the CRC checksum

int util_eeprom_check(void) {
    
    
    
    
}


// this function fixes corrupt eeprom by comparing the three banks

int util_eeprom_fix(void) {
    
    
    
}


// this function calculates and writes the CRC

int util_eeprom_write_CRC(void) {
    
    
    
    
}

// this function writes a byte to the eeprom

int util_eeprom_write(int address, int value ) {
    

 //volatile unsigned char value = 0x09;
   // unsigned char address = 0xE5;
    eeprom_write(address, value);     // Writing value 0x9 to EEPROM address 0xE5        
    value = eeprom_read (address);    // Reading the value from address 0xE5

    
}


// this function reads one byte from the eeprom

int util_eeprom_read(int address) {

 
    
}
