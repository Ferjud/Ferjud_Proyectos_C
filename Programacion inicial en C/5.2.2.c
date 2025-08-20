#include <stdio.h>

int main()
 {
    int dia,mes;
    
    do
    {
      printf("Ingrese dia:");
      
      scanf("%d",&dia);
      
      printf("ingrese mes:");
      
      scanf("%d",&mes);
      
      if( (dia>30 && mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
         || dia<1 || mes<1)
      {
        printf("eror. Volver a ingresar un numero correcto\n ");
   
       }
       
       } while((dia>30 && mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) || dia<1 || mes<1);
    
    
    
    return 0;
}