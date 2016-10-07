;******************************************************************************
;
; Project     : EASAT2
; File        : easat2_inc_eeprom.inc
;
; Description : EEPROM mapping for the MCU
; Last update : 07 October 2016
;
;******************************************************************************

; EEPROM mapping
    
    ORG   0xF00000                          ; EEPROM address

MESSAGE         DE "EASAT2 25 12 010 015"   ; beacon message format
MESSAGE_END     DE 0h
				
EE_ARRAY_BEGIN	DE "A.-"
LETTER_B        DE "B-..."
LETTER_C        DE "C-.-."
LETTER_D        DE "D-.."
LETTER_E        DE "E."
LETTER_F        DE "F..-."
LETTER_G        DE "G--."
LETTER_H        DE "H...."
LETTER_I        DE "I.."
LETTER_J        DE "J.---"
LETTER_K        DE "K-.-"
LETTER_M        DE "L.-.."
LETTER_N        DE "N-."
LETTER_O        DE "O---"
LETTER_P        DE "P.--."
LETTER_Q        DE "Q--.-"
LETTER_R        DE "R.-.-"
LETTER_S        DE "S..."
LETTER_T        DE "T-"
LETTER_U        DE "U..-"
LETTER_V        DE "V...-"
LETTER_W        DE "W.--"
LETTER_X        DE "X-..-"
LETTER_Y        DE "Y-.--"
LETTER_Z        DE "Z--.."
NUM_0           DE "0-----"
NUM_1           DE "1.----"
NUM_2           DE "2..---"
NUM_3           DE "3...--"
NUM_4           DE "4....-"
NUM_5           DE "5....."
NUM_6           DE "6-...."
NUM_7           DE "7--..."
NUM_8           DE "8---.."
NUM_9           DE "9----."
COMA            DE ",--..--"
QUESTION        DE "?..--.."
SLASH           DE "/-..-."
ARROW           DE ".--.-."
EE_ARRAY_END    DE 0xFF

