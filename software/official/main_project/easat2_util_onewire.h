/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_onewire.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_UTIL_ONEWIRE
#define EASAT2_UTIL_ONEWIRE

#include "easat2.h"

#define THERMOMETER_FAIL_VALUE_1        -99.1       // this means error
#define THERMOMETER_FAIL_VALUE_2        -99.2       // this means error
#define THERMOMETER_FAIL_VALUE_3        -99.3       // this means error
#define THERMOMETER_FAIL_VALUE_4        -99.4       // this means error
#define THERMOMETER_FAIL_VALUE_5        -99.5       // this means error
#define THERMOMETER_FAIL_VALUE_6        -99.6       // this means error
#define THERMOMETER_CRC_FAIL            -99.7       // this means error

// ONEWIRE COMMANDs for THERMOMETER

#define THERMOMETER_SKIP_ROM_COMMAND            0xCC
#define THERMOMETER_WRITE_SCRATCHPAD_COMMAND    0x4E
#define THERMOMETER_READ_SCRATCHPAD_COMMAND     0xBE
#define THERMOMETER_CONVERT_T_COMMAND           0x44

#define ONEWIRE_RESET_DELAY_DOWN_US     560 // 480 us - 640 us
#define ONEWIRE_RESET_DELAY_UP_US       70  //  15 us -  60 us + (60 - 240)
#define ONEWIRE_PRESENCE_FINAL_DELAY_US 420 //  min 480-RESET_DELAY_UP_US

// to write a 1 in the onewire bus

#define ONEWIRE_WRITE_DELAY_ONE_DOWN_US 10  // time down
#define ONEWIRE_WRITE_DELAY_ONE_UP_US   55    // time up

// to write a 0 in the onewire bus

#define ONEWIRE_WRITE_DELAY_ZERO_DOWN_US 70  // time down
#define ONEWIRE_WRITE_DELAY_ZERO_UP_US   10  // time up

// time between writing bits on bus

#define ONEWIRE_WRITE_DELAY_SLOT_US      10  // minimun 1

// read slot delays

#define ONEWIRE_READ_DELAY_ONE_DOWN_US   1
#define ONEWIRE_READ_DELAY_US            5
#define ONEWIRE_READ_DELAY_SLOT_US       60


// functions prototypes

int util_onewire_reset(void);
void util_onewire_write_byte(int value);
int util_onewire_read_byte (void);
void util_onewire_write_bit(int bit_in);
int util_onewire_read_bit(void);


#endif
