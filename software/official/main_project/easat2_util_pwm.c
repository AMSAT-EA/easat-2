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

    // TMR2 has been already configured in the timer files
               
    // Disable CCP2 pin output driver by setting it (set as input)
    // this prevents spurious signals while setup   
     
    PINOUT_BUZZER_PWM       = 1;    // set to input to disable
    PINOUT_BEACON_AUDIO_PWM = 1;    // it will be enabled by pwm start function
   
    // to select TMR2 for CCP2 PWM module we set C2TSEL bits to 0
    
    CCPTMRS0bits.C2TSEL     = 0;

    // initialize the TMR2 period register
    
    PR2 = PWM_PERIOD_REGISTER_VALUE; // 124
    
    // configure auto shutdown off
     
    // force shutdown condition
    
    
    // configure ECCP2 for PWM enhanced mode     
    
    CCP2CONbits.P2M    = 0b00;   // single output mode (but with up to 4 pins!)
    CCP2CONbits.CCP2M  = 0b1100; // PWM mode P2A modulated (changed in steering)
    
    // Steering mode setup. We want the PWM in P2B and P2C (RD2 and RD3)
    
    PSTR2CONbits.STR2A = 0;     // set as port pin
    PSTR2CONbits.STR2B = 1;     // PWM signal from CCP2M
    PSTR2CONbits.STR2C = 1;     // PWM signal from CCP2M
    PSTR2CONbits.STR2D = 0;     // set as port pin    
    
    // set 50% duty cycle       
       
    CCPR2L             = PWM_DUTY_CYCLE_MSB_VALUE;       
	CCP2CONbits.DC2B   = PWM_DUTY_CYCLE_LSB_VALUE; 
    
    // TMR2 off until PWM use is required
    
    T2CONbits.TMR2ON = 0b0;     // timer 2 off
      
    // clear TMR2 interruption flag
    
    PIR1bits.TMR2IF  = 0;

    
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

