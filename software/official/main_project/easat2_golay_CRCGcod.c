/*
Proyecto:		EASAT 2
Organizacion:	AMSAT EA
Autor: 			Felipe Baena - EA7KAN
*/

#include <stdio.h>
#include "easat2_golay_CRCG.h"

#define POLY  0xAE3  /* or use the other polynomial, 0xC75 */

//************************************************* 				CODIFICACION GOLAY												
unsigned long golay(unsigned long cw){ 
/* This function calculates [23,12] Golay codewords. 
   The format of the returned longint is 
   [checkbits(11),data(12)]. */ 

  int i; 
  unsigned long c; 
  cw&=0xfffl;      		/*l long... añade 12 0s a la izquierda*/  
  c=cw; 				/* save original codeword */ 
  for (i=1; i<=12; i++)  /* examine each data bit */ 
    { 
      if (cw & 1)        /* test data bit */ 
        cw^=POLY;        /* XOR polynomial */ 
      cw>>=1;            /* shift intermediate result */
    } 
  return((cw<<12)|c);    /* assemble codeword */ 
} 
//PARIDAD

int golay_parity(unsigned long cw){  
/* This function checks the overall parity of codeword cw.
   If parity is even, 0 is returned, else 1. */ 

  unsigned char p; 

  /* XOR the bytes of the codeword */ 
  p=*(unsigned char*)&cw; 
  p^=*((unsigned char*)&cw+1); 
  p^=*((unsigned char*)&cw+2); 

  /* XOR the halves of the intermediate result */ 
  p=p ^ (p>>4); 
  p=p ^ (p>>2); 
  p=p ^ (p>>1); 

  /* return the parity result */ 
  return(p & 1); 
} 


//Deteccion errores sindrome



unsigned long golay_syndrome(unsigned long cw) 
/* This function calculates and returns the syndrome 
   of a [23,12] Golay codeword. */ 
{ 
  int i; 
  cw&=0x7fffffl;
  for (i=1; i<=12; i++)  /* examine each data bit */ 
    { 
      if (cw & 1)        /* test data bit */ 
        cw^=POLY;        /* XOR polynomial */ 
      cw>>=1;            /* shift intermediate result */ 
    } 
  return(cw<<12);        /* value pairs with upper bits of cw */
} 


//IMPRIME  | Solo se ha hecho para pruebas...

int golay_dec2bin(unsigned long c)
{
   int i = 0;
   for(i = 23; i >= 0; i--){
     if((c & (1 << i)) != 0){
       printf("1");
     }else{
       printf("0");
     } 
   }
   return 1;
}
