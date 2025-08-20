#include<stdio.h>


int main()
{
  int  vector[5]={0},i,menor,mayor,band=0,cont=0,pos;
  
   printf("ingrese números enteros de 3 cifras a la lista:");
   
   for(i=0;i<5;i++)
   {
    do{
     scanf("%d",&vector[i]);
      if(vector[i]<100 || vector[i]>999)
      {
       printf("Error. Ingrese dentro del rango:");
        }
     }while(vector[i]<100 || vector[i]>999);
   }
    
    for(i=0;i<5;i++)
    {
     if(band==0 || vector[i]>mayor)
     {
      mayor=vector[i];
      band=1;
       }
      } 
       for(i=0;i<5;i++)
       {
        if(band==0 || vector[i]<mayor)
         {
          menor=vector[i];
          pos=i;
          band=1;
           }
       }    
       
       
          for(i=0;i<5;i++)
            {
              if(vector[i]==menor)
               {
                cont++;
                }
            }
            
          printf("El menor es %d y se repite %d veces",menor,cont);
            
          
          printf("El mayor es %d y se encuentra en la posicion/nes:",mayor);
       
       
           for(i=0;i<5;i++)
            {
            if(vector[i]==mayor)
             {
               printf("%d\n",i+1);
               }
              } 
       
       
            
            
            
          
             
  return 0;
  }
  
  
  