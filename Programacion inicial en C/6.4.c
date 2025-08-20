#include<stdio.h>
int leeryvalidar(int,int);


int main()
{
 
  numero=leeryvalidar(10,50);
  
  while(numero!=-10)
  {
  
  
  
  
  
  
  

return 0;
}
  
  
  
  int leeryvalidar(int liminf,limsup)
  {
    int num;
    
     do 
     {
      printf("ingrese numero entre 10 y 50,-10 finaliza:");
      scanf(" %d",&num);
      
      if(num!=-10 && !(num>liminf && num<limsup))
      {
       printf("error.ingrese dentro del rango");
     }while(num!=-10 && !(num>liminf && num<limsup));
       
       
       
   int resto(int dividendo,int divisor)
   {
       int resto;
       
       resto=dividendo%divisor;
       
      return resto;
      } 
      
    
    int espar(int)
    {
    
       