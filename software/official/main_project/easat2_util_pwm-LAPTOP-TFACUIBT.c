/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_util_pwm.c
 *
 * Description : Functions related to timer interruption
 * Last update : 18 January 2017                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_util_pwm.h"


/*
   this is the PWM init function. PWM will be used for CW beacon 
   We use the TMR2 8 bit timer and PWM in enhanced mode
   There will be two PWM outputs at 1 Khz, one for buzzer and one
   for the audio signal to RF module.
   For using RD2 as PWM we have to use CCP2 module
   
 */

 void util_pwm_initialize(void) {
 
    // Set pins as outputs so PWM module drives them
     
    PINOUT_BUZZER_PWM       = 0;
    PINOUT_BEACON_AUDIO_PWM = 0;
    
    // to select TMR2 for CCP2 PWM module we set C2TSEL bits to 0
    
    CCPTMRS0bits.C2TSEL = 0;
    
    // P2M   = 01 Full-Bridge output forward, so we get the PWM
    // signal on P2B to buzzer.
    
    // CCP2M = 1100, PWM mode with P1D active-high.
    
    CCP2CONbits.P2M   = 0b01;   
    CCP2CONbits.CCP2M = 0b1100;
     
    // configure TMR2 to be the one generating PWM
     
    T2CONbits.T2OUTPS = 0b0000;  // postcale off
    T2CONbits.TMR2ON  = 0b0;     // timer 2 off
    T2CONbits.T2CKPS  = 0b01;    // prescaler set to divide by 4 (it can be 1, 4 or 16)

    // Timer 2 Period Register (PR2) = (<clk> / 4 / <prescale> / <freq>) - 1
    // Thus, the PWM frequency is:
    // 2MHz clock / 4 = 500k instruction rate (per second).
    // (500 Khz / <prescale> = 4) / <PR2+1>)
    
    PR2 = (PWM_INSTRUCTIONS_RATE / 4 / PWM_FREQ) - 1;  		// 124

    // The Duty Cycle is controlled by the ten-bit CCPR2L<7,0>:DC2B1:DC2B0
    // 50% Duty Cycle = 0.5 * (<PR2+1> * 4)
    // The 8 most significant bits of the value are needed here
    // The 2 least significant bits of the value are written
    // to the DC1B1 and DC1B0 bits in CCP1CON
      
    CCPR2L = (((((PR2+1) * 2) >> 2)) & 0xFF);
	CCP2CONbits.DC2B = (((PR2+1) * 2) & 0x03);
    
    // clear TMR2 interruption flag
    
    PIR1bits.TMR2IF = 0;

    
}


// this function starts the PWM
 
void util_pwm_start(void) {
    
    // enable the CCP2 pins output driver by clearing
    // the associated TRIS bits.
    
    PINOUT_BUZZER_PWM       = 0;
    PINOUT_BEACON_AUDIO_PWM = 0;
    
    // start TMR2 to get the PWM on
            
    T2CONbits.TMR2ON = 1;

}


// this function stops the PWM

void util_pwm_stop(void) {
    
    // disables the CCP2 pins output driver by clearing
    // the associated TRIS bits.
    
    PINOUT_BUZZER_PWM       = 1;
    PINOUT_BEACON_AUDIO_PWM = 1;
    
    // stops TMR2 to get the PWM off
            
    T2CONbits.TMR2ON = 0;

}


// this function checks if PWM is on

int util_check_pwm_on(void) {

    return (T2CONbits.TMR2ON == 1);

}

