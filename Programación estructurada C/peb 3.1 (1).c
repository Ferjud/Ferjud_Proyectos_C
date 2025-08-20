#include <stdio.h>
#include <string.h>

 int main ()
  {
   char frase[500];
   int cont=1,cont_esp=1,contpalabras=0,i;
   
   //punto a
   printf("ingrese una frase: ");
   fgets(frase,500,stdin);
   
   for(i=0;i<strlen(frase);i++)
   {
     if(frase[i]==' ')
     {
      cont++;
      }
   }
      printf("la cantidad de palabras son: %d\n",cont); 
    
    
    //punto b
    for (i = 0; i < strlen(frase); i++) 
    {
     if (frase[i] != ' ') 
      {
        // Si encontramos un carácter que no es espacio y venimos de un espacio, es una nueva palabra
        if (cont_esp > 0) 
        {
            contpalabras++;   // Contamos la palabra
         }
        cont_esp = 0;  // Reiniciar el contador de espacios cuando estamos en una palabra
      } 
  
      else 
       {
        cont_esp++;  // Contamos los espacios
        }
}
      
     
      printf("la cantidad de palabras considerando más de 1 espacio consecutivo: %d",contpalabras);
      
   return 0;
   }