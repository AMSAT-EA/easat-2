/*
Proyecto:		EASAT 2
Organización:	AMSAT EA
Autor: 			Felipe Baena - EA7KAN
*/

#include <stdio.h>
#include "easat2CRCG.h"



int main( int argc, char **argv ){


	unsigned long c, syn, corregido;
	int errores;
	
	
//*************************		CODIFICA GOLAY CON PARIDAD
	
	c=golay(0xAAA);				//Codifica Golay la palabra 0xAAA | Solo se ha hecho para pruebas....
	
	if(1==parity(c))			//Comprueba paridad
	{
		c+= 0x800000;			//Añade 1 en el caso de que no haya paridad de unos
	}


	printf("Codigo Golay en binario: ");	//*****************
	dec2bin(c);								//Imprime el código	
	printf("\n");							//***************** 
	
	c=0xB0BAAA;							// linea para desvirtuar la trama a posta	***************		PRUEBAS
	
	
//************************		DETECCION Y CORRECCION DE ERRORES


	if(0==syndrome(c)){					// No hay errores, trama de bits correcta....

		printf("Entregar trama de bits \n");	
	}else{
				
			corregido= correct(c, &errores); 
			
				if(1==parity(corregido))			//Comprueba paridad
				{
					corregido+= 0x800000;			//Añade 1 en el caso de que no haya paridad de unos
				}
			
			
			printf("Codigo Golay en binario: ");			//*****************
			dec2bin(corregido);								//Imprime el código	
			printf("\n");	
				
			printf("Bits cambiados         : ");	//*****************************
			dec2bin(c);								//Imprime el código	desvirtuado
			printf("\n");	
											
		
	}
	
	return 0;
		
}



