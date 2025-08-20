#include<stdio.h>
int mayormenor(int,int,int,int);

int main()
{
  int numero1,numero2,numero3,selec;
 
 printf("ingresar 3 valores entre 0 y 99, ingresa 96,97 y 98 para finalizar\n ");
 do
 {
 printf("ingresa valor 1:\n");
 scanf(" %d",&numero1);
 if(numero1<=0 || numero1>=99)
 {
 printf("error. ingresar dentro del rango:\n");
 }
 }while(numero1<=0 || numero1>=99);
 
 do
 {
 printf("ingresa valor 2:\n");
 scanf(" %d",&numero2);
 if(numero2<=0 || numero2>=99)
 {
 printf("error. ingresar dentro del rango:\n");
 }
 }while(numero2<=0 || numero2>=99);
 
 do
 {
 printf("ingresa valor 3:\n");
 scanf(" %d",&numero3);
 if(numero3<=0 || numero3>=99)
 {
 printf("error. ingresar dentro del rango:\n");
 }
 }while(numero3<=0 || numero3>=99);
 
 
 while(numero1!=96 && numero2!=97 && numero3!=98)
 {
   
   printf("ingrese 1 para calcular el mayor o 2 para el menor\n");
   scanf(" %d",&selec);
   
   switch(selec)
   {
    
    case 1: printf("el mayor es: %d\n",mayormenor(numero1,numero2,numero3,selec));
            break;
   
    case 2: printf("el menor es: %d\n",mayormenor(numero1,numero2,numero3,selec));
            break;
    }
   
   
   printf("ingresar 3 valores entre 0 y 99, ingresa 96,97 y 98 para finalizar\n ");
 do
 {
 printf("ingresa valor 1:\n");
 scanf(" %d",&numero1);
 if(numero1<=0 || numero1>=99)
 {
 printf("error. ingresar dentro del rango:\n");
 }
 }while(numero1<=0 || numero1>=99);
 
 do
 {
 printf("ingresa valor 2:\n");
 scanf(" %d",&numero2);
 if(numero2<=0 || numero2>=99)
 {
 printf("error. ingresar dentro del rango:\n");
 }
 }while(numero2<=0 || numero2>=99);
 
 do
 {
 printf("ingresa valor 3:\n");
 scanf(" %d",&numero3);
 if(numero3<=0 || numero3>=99)
 {
 printf("error. ingresar dentro del rango:\n");
 }
 }while(numero3<=0 || numero3>=99);
 
} 
   
   
   
   
   return 0;
   }
   
   
   
   int mayormenor(int num1,int num2,int num3,int selector)
   {
    
   int  mayorvalor,menorvalor,retorno;
  
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
      
      
   
   if((num1<num2 && num2<=num3) || (num1<num3 && num3<=num2))
  {
   menorvalor=num1 ;
   }
   else
   if((num2<num1 && num1<=num3) || (num2<num3 && num3<=num1))
   {
      menorvalor=num2;
      }
     else
     {
      menorvalor=num3;
      }
   
   if(selector==1)
   {
    retorno= mayorvalor;
    }
    else
    if(selector==2)
    {
     retorno=menorvalor;
     }
  
  return retorno;
  }
     