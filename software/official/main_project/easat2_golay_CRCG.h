/*
Proyecto:		EASAT 2
Organizacion:	AMSAT EA
Autor: 			Felipe Baena - EA7KAN
*/

#ifndef easat2CRCG_H
#define easat2CRCG_H


//Codifica Golay
unsigned long golay(unsigned long cw);
int golay_parity(unsigned long cw);

//Detecta errores / Sindrome
unsigned long golay_syndrome(unsigned long cw);

//Corrección
int weight(unsigned long cw);
unsigned long golay_rotate_left(unsigned long cw, int n);  
unsigned long golay_rotate_right(unsigned long cw, int n);
unsigned long golay_correct(unsigned long cw, int *errs);

//Imprime en binario el valor obtenido
int golay_dec2bin(unsigned long c);





#endif