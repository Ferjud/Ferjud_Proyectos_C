#include <stdio.h>
#include <ctype.h>

int main() 
{
    int i,num, ternapositivos=0, ternanegativos=0;
    int ternanegcompleta=0,ternaposcompleta=0;


    for (i = 1; i <= 6; i++)
    {
        printf("Ingrese un numero distinto de cero: ");
        scanf("%d", &num);
        
        if(num>0)
        {
          ternapositivos++;
          ternanegativos=0;
          }
          
          if(num<0)
          {
           ternanegativos++;
           ternapositivos=0;
           }
           
        
           if(ternapositivos==3)
           {
             ternaposcompleta++ ;
             ternanegcompleta++ ;
        }
        
     }   
        
         printf("la cantidad de ternas positivas son: %d\n", ternaposcompleta);
         
         printf("la cantidad de ternas negativas son: %d\n", ternanegcompleta);
          
    return 0;
}