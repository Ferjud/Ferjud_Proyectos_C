#include<stdlib.h>
#include<stdio.h>
int igualdadvec(int[],int[],int);


int main()
{
  int i,v1[3],v2[3],ce=3;
  
  
  for(i=0;i<=ce-1;i++)
 {
   
   printf("ingrese numero %d para el vector 1:",i+1);
   scanf(" %d",&v1[i]);
   }
   
   for(i=0;i<=ce-1;i++)
 {
   
    printf("ingrese numero %d para el vector 2:",i+1);
    scanf(" %d",&v2[i]);
    }
    

     printf("%d",igualdadvec(v1,v2,3));


   return 0;
   
}


int igualdadvec(int vec1[],int vec2[],int ce)
{

  int i,retorno,cont=0;

 
    
      for(i=0;i<=ce-1;i++)
      {
        
         if(vec1[i]==vec2[i])
         {
           cont++;
         }
         
         }
         
         if(cont==ce)
         {
          retorno=1;
         }
         else
         {
         retorno=0;
         
         }
         
  return retorno;       
 }        