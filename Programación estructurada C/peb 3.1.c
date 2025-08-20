#include <stdio.h>
#include <string.h>
 
 
 
 int main ()
  {
  char cadena [501];
   
   printf ("Ingrese una cadena de no más de 500 caracteres \n");
   fgets (cadena,501,stdin);
   
   printf ("La cadena ingresada contiene: %d caracteres", strlen(cadena)-1 );

  return 0;
 }  