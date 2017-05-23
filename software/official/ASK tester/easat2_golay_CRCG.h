/*
Proyecto:		EASAT 2
Organizacion:	AMSAT EA
Autor: 			Felipe Baena - EA7KAN
*/

#ifndef easat2CRCG_H
#define easat2CRCG_H


//Codifica Golay
unsigned long golay(unsigned long cw);
int parity(unsigned long cw);

//Detecta errores / Sindrome
unsigned long syndrome(unsigned long cw);

//Corrección
int weight(unsigned long cw);
unsigned long rotate_left(unsigned long cw, int n);  
unsigned long rotate_right(unsigned long cw, int n);
unsigned long correct(unsigned long cw, int *errs);

//Imprime en binario el valor obtenido
int dec2bin(unsigned long c);





#endif