#include <stdio.h>
#include <string.h>

 int main ()
  {
   char nombre [40] = "Fernando", apellido [40] ="Dobal";
   char resultado [80];
   
   
    strcpy(resultado, nombre);

    // Agregar la coma y el espacio
    strcat(resultado, ", ");

    // Agregar el apellido
    strcat(resultado, apellido);

    // Mostrar el resultado
    printf("Resultado: %s\n", resultado);
    
  return 0;
  }