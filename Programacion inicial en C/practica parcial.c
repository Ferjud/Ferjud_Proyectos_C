#include<stdio.h>
#include<ctype.h>

int main()
{
 int i,j,puntaje,ganador,peorjugador;
 int puntaje_total=0,mayorpuntaje=0,menorpuntaje=200;
 
 for(i=1;i<=2;i++)
 {
 
  puntaje_total=0;
 
  printf("ingrese puntajes del jugador %d\n" ,i);
  
   for(j=1;j<=2;j++)
   {
    do
    {
     printf("ingresar puntaje %d:",j);
     scanf(" %d",&puntaje);
     }while(puntaje<=1 || puntaje>=200);
     
     puntaje_total+=puntaje;
     }
    
    if(puntaje_total>mayorpuntaje)
    {
     mayorpuntaje=puntaje_total;
     ganador=i;
     }
     
    if(puntaje_total<menorpuntaje)
    {
      menorpuntaje=puntaje_total;
      peorjugador=i;
      }
      
      printf("puntaje del jugador %d: %d\n",i,puntaje_total);
  }    
      
      printf("el ganador es el jugador: %d\n",ganador);
      
      printf("el jugador con menor puntaje es el jugador: %d", peorjugador);
      
   return 0;
   
  }   