/*
Proyecto:		EASAT 2
Organizacion:	AMSAT EA
Autor: 			Felipe Baena - EA7KAN
*/

#include <stdio.h>
#include "easat2_golay_CRCG.h"




int weight(unsigned long cw) 
/* This function calculates the weight of 
   23 bit codeword cw. */ 
{ 
  int bits,k; 

  /* nibble weight table */ 
  const char wgt[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4}; 

  bits=0; /* bit counter */ 
  k=0; 
  /* do all bits, six nibbles max */ 
  while ((k<6) && (cw)) 
    { 
      bits=bits+wgt[cw & 0xf]; 
      cw>>=4; 
      k++; 
    } 

  return(bits); 
} 

//Rota a la IZQ



unsigned long rotate_left(unsigned long cw, int n) 
/* This function rotates 23 bit codeword cw left by n bits. */ 
{ 
  int i; 

  if (n != 0) 
    { 
      for (i=1; i<=n; i++) 
        { 
          if ((cw & 0x400000l) != 0) 
            cw=(cw << 1) | 1; 
          else 
            cw<<=1; 
        } 
    } 

  return(cw & 0x7fffffl); 
} 
//Rota a la DER
unsigned long rotate_right(unsigned long cw, int n) 
/* This function rotates 23 bit codeword cw right by n bits. */ 
{ 
  int i; 

  if (n != 0) 
    { 
      for (i=1; i<=n; i++) 
        { 
          if ((cw & 1) != 0) 
            cw=(cw >> 1) | 0x400000l; 
          else 
            cw>>=1; 
        } 
    } 

  return(cw & 0x7fffffl); 
} 

//CORRIGE


unsigned long correct(unsigned long cw, int *errs) 
/* This function corrects Golay [23,12] codeword cw, returning the 
   corrected codeword. This function will produce the corrected codeword 
   for three or fewer errors. It will produce some other valid Golay 
   codeword for four or more errors, possibly not the intended 
   one. *errs is set to the number of bit errors corrected. */ 
{ 
  unsigned char 
    w;                /* current syndrome limit weight, 2 or 3 */ 
  unsigned long 
    mask;             /* mask for bit flipping */ 
  int 
    i,j;              /* index */ 
  unsigned long 
    s,                /* calculated syndrome */ 
    cwsaver;          /* saves initial value of cw */ 

  cwsaver=cw;         /* save */ 
  *errs=0; 
  w=3;                /* initial syndrome weight threshold */ 
  j=-1;               /* -1 = no trial bit flipping on first pass */ 
  mask=1; 
  while (j<23) /* flip each trial bit */ 
    { 
      if (j != -1) /* toggle a trial bit */ 
        { 
          if (j>0) /* restore last trial bit */ 
            { 
              cw=cwsaver ^ mask; 
              mask+=mask; /* point to next bit */ 
            } 
          cw=cwsaver ^ mask; /* flip next trial bit */ 
          w=2; /* lower the threshold while bit diddling */ 
        } 

      s=syndrome(cw); /* look for errors */ 
      if (s) /* errors exist */ 
        { 
          for (i=0; i<23; i++) /* check syndrome of each cyclic shift */ 
            { 
              if ((*errs=weight(s)) <= w) /* syndrome matches error pattern */
                { 
                  cw=cw ^ s;              /* remove errors */ 
                  cw=rotate_right(cw,i);  /* unrotate data */ 

                  if (j >= 0) /* count toggled bit (per Steve Duncan) */
                    *errs=*errs+1;

                  return(s=cw); 
                } 
              else 
                { 
                  cw=rotate_left(cw,1);   /* rotate to next pattern */ 
                  s=syndrome(cw);         /* calc new syndrome */ 
                } 
            } 
          j++; /* toggle next trial bit */ 
        } 
      else 
        return(cw); /* return corrected codeword */ 
    } 

  return(cwsaver); /* return original if no corrections */ 
} /* correct */