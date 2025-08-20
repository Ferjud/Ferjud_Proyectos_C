#include<stdio.h>
float mayorvalor(float,float,float);
float promedio(float,float,float);
float suma(float,float,float);

int main()
{
 float n1,n2,n3;
 int op;
 printf("para finalizar, ingrese 3 valores ordenados de menor a mayor\n");
  printf("ingrese valor 1:");
  scanf(" %f",&n1);
  
  printf("ingrese valor 2:");
  scanf(" %f",&n2);
  
  printf("ingrese valor 3:");
  scanf(" %f",&n3);
  
  while(!(n3>n2 && n2>n1))
  {
   
    printf("OPCIONES POSIBLES\n");
    printf("1-mayor valor\n");
    printf("2-promedio\n");
    printf("3-suma\n");
    printf("4-finalizar\n");
    
    do
    {
    printf("digite su opcion:");
    scanf(" %d",&op);
    if(op!=1 && op!=2 && op!=3 && op!=4)
    {
    printf("error. ingrese op valida.");
    }
    }while(op!=1 && op!=2 && op!=3 && op!=4);
    
   while(op!=4)
   {
   
    switch(op)
    {
      case 1: printf("el mayor valor es: %.2f",mayorvalor(n1,n2,n3));
              break;
              
      case 2: printf("el promedio es: %.2f",promedio(n1,n2,n3));
               break;
               
      case 3: printf("la suma es: %.2f",suma(n1,n2,n3));
              break;
              
      }
    
      do
    {
    printf("digite su opcion:");
    scanf(" %d",&op);
    if(op!=1 && op!=2 && op!=3 && op!=4)
    {
    printf("error. ingrese op valida.");
    }
    }while(op!=1 && op!=2 && op!=3 && op!=4);
    
    }
    
  printf("para finalizar, ingrese 3 valores ordenados de menor a mayor\n");
  printf("ingrese valor 1:");
  scanf(" %f",&n1);
  
  printf("ingrese valor 2:");
  scanf(" %f",&n2);
  
  printf("ingrese valor 3:");
  scanf(" %f",&n3);
  
  
}  
    
  return 0;
  }  
 
 
 
 
 
 float mayorvalor(float num1,float num2, float num3)
 {
 
  float mayorvalor;
  
  if((num1>num2 && num2>=num3) || (num1>num3 && num3>=num2))
  {
   mayorvalor=num1 ;
   }
   else
   if((num2>num1 && num1>=num3) || (num2>num3 && num3>=num1))
   {
      mayorvalor=num2;
      }
     else
     {
      mayorvalor=num3;
      }
      
   return mayorvalor;
   }
   
   
   float promedio(float numero1,float numero2,float numero3)
   {
    float promedio,suma;
    
    suma=numero1+numero2+numero3;
   
    promedio=suma/3.;
    
    return promedio;
    }  
    
   
   float suma(float valor1,float valor2,float valor3)
   {
     float suma;
   
     suma=valor1+valor2+valor3;
     
     return suma;
     }   
     
     