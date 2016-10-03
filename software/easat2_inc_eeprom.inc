;************************************************************************************
;
; Proyecto EASAT 2
; Fichero: easat2_inc_eeprom.inc
; Descripción: Fichero de mapeo de la memoria EEPROM
; Última modificación: 03 de octubre de 2016
;
;************************************************************************************

; mapeo de la memoria EEPROM    
    
    ORG   0xF00000			    ; mapear en EEPROM

MENSAJE         DE "EASAT2 25 12 010 015"
FIN_MENSAJE     DE 0h
			
		
COMIENZO_TABLA	DE "A.-"
LETRA_B         DE "B-..."
LETRA_C         DE "C-.-."
LETRA_D         DE "D-.."
LETRA_E         DE "E."
LETRA_F         DE "F..-."
LETRA_G         DE "G--."
LETRA_H         DE "H...."
LETRA_I         DE "I.."
LETRA_J         DE "J.---"
LETRA_K         DE "K-.-"
LETRA_M         DE "L.-.."
LETRA_N         DE "N-."
LETRA_O         DE "O---"
LETRA_P         DE "P.--."
LETRA_Q         DE "Q--.-"
LETRA_R         DE "R.-.-"
LETRA_S         DE "S..."
LETRA_T         DE "T-"
LETRA_U         DE "U..-"
LETRA_V         DE "V...-"
LETRA_W         DE "W.--"
LETRA_X         DE "X-..-"
LETRA_Y         DE "Y-.--"
LETRA_Z         DE "Z--.."
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
INTERROGACION	DE "?..--.."
BARRA           DE "/-..-."
ARROBA          DE ".--.-."
FIN_MEMORIA     DE 0xFF



