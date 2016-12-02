/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_onewire.c
 *
 * Description : Functions to read and write using one wire protocol
 * Last update : 11 November 2016                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_util_onewire.h"


// generate a 1-Wire reset, return 0 if presence was found,
// return 1 otherwise.

int util_onewire_reset(void) {

    int presence = 1;

    // set RA3 as output
    TRISAbits.TRISA3 = 0;
    // set the output low
    PORTAbits.RA3  = 0;

    // wait for the required delay (between 480us and 640 us)
    // 560 is fine
     __delay_us(ONEWIRE_RESET_DELAY_DOWN_US);

     // set output high
    PORTAbits.RA3 = 1;

    // wait for the required delay (between 15us and 60 us) at least to read
    // termometer can wait 15 to 60 to send pulse and
    // pulse can last from 60 to 240 us
    // 70 us works always (we can only choose 70 - 75)

    __delay_us(ONEWIRE_RESET_DELAY_UP_US);

    // set RA3 as input
    TRISAbits.TRISA3 = 1;

    // line should be low
    // read presence pulse from slave

    presence = PORTAbits.RA3;

    // wait for the pulse to finish minimum 480 us from line to UP
    // so at least (480-70 = 410). 420 is fine

    __delay_us(ONEWIRE_PRESENCE_FINAL_DELAY_US);

    // if presence is not 0 the reset has failed

    return presence;

}

// this function writes a byte to the onewire bus

void util_onewire_write_byte(int value) {
    
    int bit0, bit1, bit2, bit3, bit4, bit5, bit6, bit7;
            
    bit0 = (value >> 0) & 0x01;
    bit1 = (value >> 1) & 0x01;
    bit2 = (value >> 2) & 0x01;
    bit3 = (value >> 3) & 0x01;
    bit4 = (value >> 4) & 0x01;
    bit5 = (value >> 5) & 0x01;
    bit6 = (value >> 6) & 0x01;
    bit7 = (value >> 7) & 0x01;

    util_onewire_write_bit(bit0);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    util_onewire_write_bit(bit1);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    util_onewire_write_bit(bit2);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    util_onewire_write_bit(bit3);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    util_onewire_write_bit(bit4);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    util_onewire_write_bit(bit5);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    util_onewire_write_bit(bit6);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    util_onewire_write_bit(bit7);
    __delay_us(ONEWIRE_WRITE_DELAY_SLOT_US);
    
}

// this function reads a byte

int util_onewire_read_byte (void) {

    int bit0, bit1, bit2, bit3, bit4, bit5, bit6, bit7;
    int value = 0;

    // set RA3 as input
    TRISAbits.TRISA3 = 1;

    bit0 = util_onewire_read_bit();
    bit1 = util_onewire_read_bit();
    bit2 = util_onewire_read_bit();
    bit3 = util_onewire_read_bit();
    bit4 = util_onewire_read_bit();
    bit5 = util_onewire_read_bit();
    bit6 = util_onewire_read_bit();
    bit7 = util_onewire_read_bit();

    value = bit0 + (bit1 << 1) + (bit2 << 2) + (bit3 << 3) + (bit4 << 4)
              + (bit5 << 5) + (bit6 << 6) + (bit7 << 7);
       
    return value;
}

// send a bit. Provide the recovery time.

void util_onewire_write_bit(int bit_in) {

    // set RA3 as output
    TRISAbits.TRISA3 = 0;

    if (bit_in) {

        // set the output low
        PORTAbits.RA3  = 0;

        // wait for the required delay (between 0 and  us)
        // 10 us is right
        __delay_us(ONEWIRE_WRITE_DELAY_ONE_DOWN_US);

        // set output high
        PORTAbits.RA3 = 1;

        // wait to complete 60 us (55 is ok)
        __delay_us(ONEWIRE_WRITE_DELAY_ONE_UP_US);   

    } else {

        // set the output low
        PORTAbits.RA3  = 0;

        // wait for the required delay (minimun 60 us)
        // 70 us is right
        __delay_us(ONEWIRE_WRITE_DELAY_ZERO_DOWN_US);

        // set output high
        PORTAbits.RA3 = 1;

        // wait to complete 60 us (at least 1 - 10 is ok)
        __delay_us(ONEWIRE_WRITE_DELAY_ZERO_UP_US);

    }

}

// read a bit. 0 or 1 is returned

int util_onewire_read_bit(void) {

    int value = 0;

    // set RA3 as output
    TRISAbits.TRISA3 = 0;

    // set the output low
    PORTAbits.RA3  = 0;

    // wait for the required delay (between 0 and 1 us)
    __delay_us(ONEWIRE_READ_DELAY_ONE_DOWN_US);

    // set output high
    PORTAbits.RA3 = 1;

    // read before 15 us
    __delay_us(ONEWIRE_READ_DELAY_US);

    // get the value from the pin
    value = PORTAbits.RA3;

    // wait to complete the read slot
    __delay_us(ONEWIRE_READ_DELAY_SLOT_US);

    return value;
    
}
