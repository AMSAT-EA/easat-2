/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_config.h
 *
 * Description : MCU configuration registers
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_CONFIG_H
#define	EASAT2_CONFIG_H

#include <xc.h>

/*  Configuration for PIC18F45K22 */

#define _XTAL_FREQ 2000000      // 2 Mhz

#pragma config FOSC = XT        // Oscillator (LP,XT,HSHP,HSMP,RC,RCIO6,ECHP,
                                // ECHPIO6,INTIO67,INTIO7,ECMPIO6,ECLP,ECLPIO6)
  
#pragma config IG PLLCFG = OFF  // 4X PLL Enable
#pragma config PRICLKEN = ON    // Primary clock enable
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable
#pragma config IESO = OFF       // Internal/External Oscillator Switchover

// config2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable
#pragma config BOREN  = OFF     // Brown-out Reset Enable  (OFF,ON,NOSLP,SBODIS)
#pragma config BORV   = 190     // Brown Out Reset Volt.(285,250,220,190)[V/100]

// config2H
#pragma config WDTEN = ON       // Watchdog Timer Enable (OFF,NOSLP,SWON,ON)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select (1:32768)

// config3H
#pragma config CCP2MX = PORTC1  // ECCP2 B output mux (PORTB3, PORTC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable
#pragma config CCP3MX = PORTB5  // CCP3 MUX (PORTB5, PORTC6)
#pragma config HFOFST = OFF     // HFINTOSC Fast Start-up
#pragma config T3CMX  = PORTB5  // Timer3 Clock input mux (PORTB5,PORTC0)
#pragma config P2BMX  = PORTC0  // ECCP2 B output mux (PORTB5,PORTC0)

#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable (MCLR / RE3)

// config4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable
#pragma config LVP = OFF        // Single-Supply ICSP Enable
#pragma config XINST = OFF      // Extended Instruction Set Enable

// config5L
#pragma config CP0 = OFF        // Code Protection Block 0
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF

// config5H
#pragma config CPB = OFF        // Boot Block Code Protection
#pragma config CPD = OFF        // Data EEPROM Code Protection

// config6L
#pragma config WRT0 = OFF       // Write Protection Block 0
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT3 = OFF

// config6H
#pragma config WRTC = ON        // #pragma configuration Register Write Protection
#pragma config WRTB = OFF       // Boot Block Write Protection
#pragma config WRTD = ON        // Data EEPROM Write Protection

// config7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF

// config7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection	
	
#endif

