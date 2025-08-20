#include<stdio.h>


int main()
{
  int  vector[5]={0},i;
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
     printf("\n%d\n",vector[i]);
     }
     
  return 0;
  }