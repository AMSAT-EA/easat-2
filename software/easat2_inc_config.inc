;************************************************************************************
;
; Proyecto EASAT 2
; Fichero: easat2_inc_config.inc
; Descripción: Fichero de configuración de los flags del PIC
; Última modificación: 03 de octubre de 2016
;
;************************************************************************************

;==========================================================================
;
;   IMPORTANT: For the PIC18 devices, the __CONFIG directive has been
;              superseded by the CONFIG directive.  The following settings
;              are available for this device.
;
;   Oscillator Selection bits:
;     FOSC = LP            LP oscillator
;     FOSC = XT            XT oscillator
;     FOSC = HSHP          HS oscillator (high power > 16 MHz)
;     FOSC = HSMP          HS oscillator (medium power 4-16 MHz)
;     FOSC = ECHP          EC oscillator, CLKOUT function on OSC2 (high power, >16 MHz)
;     FOSC = ECHPIO6       EC oscillator, port function on RA6 (high power, >16 MHz)
;     FOSC = RC            External RC, CLKOUT on OSC2
;     FOSC = RCIO6         External RC oscillator, port function on RA6
;     FOSC = INTIO67       Internal oscillator block, port function on RA6 and RA7
;     FOSC = INTIO7        Internal oscillator block, CLKOUT function on RA6, port function on RA7
;     FOSC = ECMP          EC oscillator, CLKOUT on OSC2 (medium power, 4-16 MHz)
;     FOSC = ECMPIO6       EC oscillator (medium power, 4-16 MHz)
;     FOSC = ECLP          EC oscillator, CLKOUT on OSC2 (low power, < 4 MHz)
;     FOSC = ECLPIO6       EC oscillator  (low power, < 4 MHz)
;
;   4X PLL Enable:
;     PLLCFG = OFF         Oscillator used directly
;     PLLCFG = ON          Oscillator multiplied by 4
;
;   Primary clock enable bit:
;     PRICLKEN = OFF       Primary clock can be disabled by software
;     PRICLKEN = ON        Primary clock is always enabled
;
;   Fail-Safe Clock Monitor Enable bit:
;     FCMEN = OFF          Fail-Safe Clock Monitor disabled
;     FCMEN = ON           Fail-Safe Clock Monitor enabled
;
;   Internal/External Oscillator Switchover bit:
;     IESO = OFF           Oscillator Switchover mode disabled
;     IESO = ON            Oscillator Switchover mode enabled
;
;   Power-up Timer Enable bit:
;     PWRTEN = ON          Power up timer enabled
;     PWRTEN = OFF         Power up timer disabled
;
;   Brown-out Reset Enable bits:
;     BOREN = OFF          Brown-out Reset disabled in hardware and software
;     BOREN = ON           Brown-out Reset enabled and controlled by software (SBOREN is enabled)
;     BOREN = NOSLP        Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
;     BOREN = SBORDIS      Brown-out Reset enabled in hardware only (SBOREN is disabled)
;
;   Brown Out Reset Voltage bits:
;     BORV = 285           VBOR set to 2.85 V nominal
;     BORV = 250           VBOR set to 2.50 V nominal
;     BORV = 220           VBOR set to 2.20 V nominal
;     BORV = 190           VBOR set to 1.90 V nominal
;
;   Watchdog Timer Enable bits:
;     WDTEN = OFF          Watch dog timer is always disabled. SWDTEN has no effect.
;     WDTEN = NOSLP        WDT is disabled in sleep, otherwise enabled. SWDTEN bit has no effect
;     WDTEN = SWON         WDT is controlled by SWDTEN bit of the WDTCON register
;     WDTEN = ON           WDT is always enabled. SWDTEN bit has no effect
;
;   Watchdog Timer Postscale Select bits:
;     WDTPS = 1            1:1
;     WDTPS = 2            1:2
;     WDTPS = 4            1:4
;     WDTPS = 8            1:8
;     WDTPS = 16           1:16
;     WDTPS = 32           1:32
;     WDTPS = 64           1:64
;     WDTPS = 128          1:128
;     WDTPS = 256          1:256
;     WDTPS = 512          1:512
;     WDTPS = 1024         1:1024
;     WDTPS = 2048         1:2048
;     WDTPS = 4096         1:4096
;     WDTPS = 8192         1:8192
;     WDTPS = 16384        1:16384
;     WDTPS = 32768        1:32768
;
;   CCP2 MUX bit:
;     CCP2MX = PORTB3      CCP2 input/output is multiplexed with RB3
;     CCP2MX = PORTC1      CCP2 input/output is multiplexed with RC1
;
;   PORTB A/D Enable bit:
;     PBADEN = OFF         PORTB<5:0> pins are configured as digital I/O on Reset
;     PBADEN = ON          PORTB<5:0> pins are configured as analog input channels on Reset
;
;   P3A/CCP3 Mux bit:
;     CCP3MX = PORTE0      P3A/CCP3 input/output is mulitplexed with RE0
;     CCP3MX = PORTB5      P3A/CCP3 input/output is multiplexed with RB5
;
;   HFINTOSC Fast Start-up:
;     HFOFST = OFF         HFINTOSC output and ready status are delayed by the oscillator stable status
;     HFOFST = ON          HFINTOSC output and ready status are not delayed by the oscillator stable status
;
;   Timer3 Clock input mux bit:
;     T3CMX = PORTB5       T3CKI is on RB5
;     T3CMX = PORTC0       T3CKI is on RC0
;
;   ECCP2 B output mux bit:
;     P2BMX = PORTC0       P2B is on RC0
;     P2BMX = PORTD2       P2B is on RD2
;
;   MCLR Pin Enable bit:
;     MCLRE = INTMCLR      RE3 input pin enabled; MCLR disabled
;     MCLRE = EXTMCLR      MCLR pin enabled, RE3 input pin disabled
;
;   Stack Full/Underflow Reset Enable bit:
;     STVREN = OFF         Stack full/underflow will not cause Reset
;     STVREN = ON          Stack full/underflow will cause Reset
;
;   Single-Supply ICSP Enable bit:
;     LVP = OFF            Single-Supply ICSP disabled
;     LVP = ON             Single-Supply ICSP enabled if MCLRE is also 1
;
;   Extended Instruction Set Enable bit:
;     XINST = OFF          Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
;     XINST = ON           Instruction set extension and Indexed Addressing mode enabled
;
;   Background Debug:
;     DEBUG = ON           Enabled
;     DEBUG = OFF          Disabled
;
;   Code Protection Block 0:
;     CP0 = ON             Block 0 (000800-001FFFh) code-protected
;     CP0 = OFF            Block 0 (000800-001FFFh) not code-protected
;
;   Code Protection Block 1:
;     CP1 = ON             Block 1 (002000-003FFFh) code-protected
;     CP1 = OFF            Block 1 (002000-003FFFh) not code-protected
;
;   Code Protection Block 2:
;     CP2 = ON             Block 2 (004000-005FFFh) code-protected
;     CP2 = OFF            Block 2 (004000-005FFFh) not code-protected
;
;   Code Protection Block 3:
;     CP3 = ON             Block 3 (006000-007FFFh) code-protected
;     CP3 = OFF            Block 3 (006000-007FFFh) not code-protected
;
;   Boot Block Code Protection bit:
;     CPB = ON             Boot block (000000-0007FFh) code-protected
;     CPB = OFF            Boot block (000000-0007FFh) not code-protected
;
;   Data EEPROM Code Protection bit:
;     CPD = ON             Data EEPROM code-protected
;     CPD = OFF            Data EEPROM not code-protected
;
;   Write Protection Block 0:
;     WRT0 = ON            Block 0 (000800-001FFFh) write-protected
;     WRT0 = OFF           Block 0 (000800-001FFFh) not write-protected
;
;   Write Protection Block 1:
;     WRT1 = ON            Block 1 (002000-003FFFh) write-protected
;     WRT1 = OFF           Block 1 (002000-003FFFh) not write-protected
;
;   Write Protection Block 2:
;     WRT2 = ON            Block 2 (004000-005FFFh) write-protected
;     WRT2 = OFF           Block 2 (004000-005FFFh) not write-protected
;
;   Write Protection Block 3:
;     WRT3 = ON            Block 3 (006000-007FFFh) write-protected
;     WRT3 = OFF           Block 3 (006000-007FFFh) not write-protected
;
;   Configuration Register Write Protection bit:
;     WRTC = ON            Configuration registers (300000-3000FFh) write-protected
;     WRTC = OFF           Configuration registers (300000-3000FFh) not write-protected
;
;   Boot Block Write Protection bit:
;     WRTB = ON            Boot Block (000000-0007FFh) write-protected
;     WRTB = OFF           Boot Block (000000-0007FFh) not write-protected
;
;   Data EEPROM Write Protection bit:
;     WRTD = ON            Data EEPROM write-protected
;     WRTD = OFF           Data EEPROM not write-protected
;
;   Table Read Protection Block 0:
;     EBTR0 = ON           Block 0 (000800-001FFFh) protected from table reads executed in other blocks
;     EBTR0 = OFF          Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
;
;   Table Read Protection Block 1:
;     EBTR1 = ON           Block 1 (002000-003FFFh) protected from table reads executed in other blocks
;     EBTR1 = OFF          Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
;
;   Table Read Protection Block 2:
;     EBTR2 = ON           Block 2 (004000-005FFFh) protected from table reads executed in other blocks
;     EBTR2 = OFF          Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
;
;   Table Read Protection Block 3:
;     EBTR3 = ON           Block 3 (006000-007FFFh) protected from table reads executed in other blocks
;     EBTR3 = OFF          Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
;
;   Boot Block Table Read Protection bit:
;     EBTRB = ON           Boot Block (000000-0007FFh) protected from table reads executed in other blocks
;     EBTRB = OFF          Boot Block (000000-0007FFh) not protected from table reads executed in other blocks
;
;==========================================================================	
	
	
; PIC18F25K22 CONFIGuration Bit Settings

; CONFIG1H
    CONFIG FOSC = XT        ; Oscillator (LP,XT,HSHP,HSMP,RC,RCIO6,ECHP,
                            ;  ECHPIO6,INTIO67,INTIO7,ECMPIO6,ECLP,ECLPIO6)
    CONFIG PLLCFG = OFF     ; 4X PLL Enable
    CONFIG PRICLKEN = ON    ; Primary clock enable
    CONFIG FCMEN = OFF      ; Fail-Safe Clock Monitor Enable
    CONFIG IESO = OFF       ; Internal/External Oscillator Switchover

; CONFIG2L
    CONFIG PWRTEN = OFF      ; Power-up Timer Enable
    CONFIG BOREN  = OFF      ; Brown-out Reset Enable  (OFF,ON,NOSLP,SBODIS)
    CONFIG BORV   = 190      ; Brown Out Reset Volt.(285,250,220,190)[V/100]

; CONFIG2H
    CONFIG WDTEN = OFF      ; Watchdog Timer Enable (OFF,NOSLP,SWON,ON)
    CONFIG WDTPS = 32768    ; Watchdog Timer Postscale Select (1:32768)

; CONFIG3H
    CONFIG CCP2MX = PORTC1  ; ECCP2 B output mux (PORTB3, PORTC1)
    CONFIG PBADEN = OFF     ; PORTB A/D Enable
    CONFIG CCP3MX = PORTB5  ; CCP3 MUX (PORTB5, PORTC6)
    CONFIG HFOFST = OFF     ; HFINTOSC Fast Start-up
    CONFIG T3CMX  = PORTB5  ; Timer3 Clock input mux (PORTB5,PORTC0)
    CONFIG P2BMX  = PORTC0  ; ECCP2 B output mux (PORTB5,PORTC0)

    CONFIG MCLRE = EXTMCLR  ; MCLR Pin Enable (MCLR / RE3)

; CONFIG4L
    CONFIG STVREN = ON      ; Stack Full/Underflow Reset Enable
    CONFIG LVP = OFF        ; Single-Supply ICSP Enable
    CONFIG XINST = OFF      ; Extended Instruction Set Enable

; CONFIG5L
    CONFIG CP0 = OFF        ; Code Protection Block 0
    CONFIG CP1 = OFF
    CONFIG CP2 = OFF
    CONFIG CP3 = OFF

; CONFIG5H
    CONFIG CPB = OFF        ; Boot Block Code Protection
    CONFIG CPD = OFF        ; Data EEPROM Code Protection

; CONFIG6L
    CONFIG WRT0 = OFF       ; Write Protection Block 0
    CONFIG WRT1 = OFF
    CONFIG WRT2 = OFF
    CONFIG WRT3 = OFF

; CONFIG6H
    CONFIG WRTC = ON       ; CONFIGuration Register Write Protection
    CONFIG WRTB = OFF       ; Boot Block Write Protection
    CONFIG WRTD = ON      ; Data EEPROM Write Protection

; CONFIG7L
    CONFIG EBTR0 = OFF      ; Table Read Protection Block 0
    CONFIG EBTR1 = OFF
    CONFIG EBTR2 = OFF
    CONFIG EBTR3 = OFF

; CONFIG7H
    CONFIG EBTRB = OFF      ; Boot Block Table Read Protection	
	



