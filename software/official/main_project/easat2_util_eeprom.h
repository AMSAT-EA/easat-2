/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_eeprom.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_UTIL_EEPROM
#define EASAT2_UTIL_EEPROM

#include "easat2.h"

// functions prototypes

int util_eeprom_check(void);
int util_eeprom_fix(void);
int util_eeprom_write_CRC(void);
int util_eeprom_write(int address, int value);
int util_eeprom_read(int address);


#endif
