#include<stdio.h>
int diasmes(int,int);
int validarfechas(int,int,int);
void sumardiafecha(int,int,int);

int main()
{

int dias, meses, años;

 printf("ingrese dia mes y año para validar\n");
 
 do
 {
 printf("dia:");
 scanf(" %d",&dias);
 if(!(dias>=1 && dias<=31))
 {
  printf("error.ingrese dia valido");
  }
  }while(!(dias>=1 && dias<=31));
 
 
 do
 {
 printf("mes:");
 scanf(" %d",&meses);
 if(!(meses>=1 && meses<=12))
 {
  printf("error.ingrese mes valido");
 }
 }while(!(meses>=1 && meses<=12));
 
 
 do
 {
 printf("año:");
 scanf(" %d",&años);
 if(!(años>=1582 && años<=2024))
 {
 printf("error.ingrese año valido");
 }
 }while(!(años>=1582 && años<=2024));
 
 if(validarfechas(dias,meses,años)==1)
 {
  printf("la fecha es correcta\n");
  
  printf("fecha sumada 1 dia:\n");
  
  sumardiafecha(dias,meses,años);
  
  }
   else
   {
   printf("la fecha es incorrecta");
   }
   
   
   
   
 
  return 0;
  }
  
  
  
  
  
  int validarfechas(int diaa,int mess,int añoo)
  {
    int retorno;
       
       if(diaa<=diasmes(mess,añoo))
       {
        retorno=1;
        }
        else
        {
        retorno=0;
        }
      
      return retorno;
      }  
   
  
  int diasmes(int mes,int año)
  {
 
  int dia;
  
   if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
   {
     dia=31;
     }
   
    else
    if(mes==4 || mes==6 || mes==9 || mes==11)
    {
     dia=30;
     }
  
    else
    if (mes == 2) 
    {
        if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) 
        {
            dia = 29;  // Año bisiesto
        } 
        else 
        {
            dia = 28;  // Año no bisiesto
        }
     }
     
     return dia;
     }
     
  
   void sumardiafecha(diasuma,messuma,añosuma)
   {
   
     if(diasuma==31)
     {
      if(messuma!=12)
      {
        printf("1,%d,%d",messuma+1,añosuma);
       }
       else
       {
       printf("1,1,%d",añosuma+1);
       }
     }  
       if(diasuma==30)
       {
        if(messuma==4 || messuma==6 || messuma==9 || messuma==11)
        {
         printf("1,%d,%d",messuma+1,añosuma);
         }
         else
         {
         printf("31,%d,%d",messuma,añosuma);
         }
       }
    
       else 
       if(diasuma<30 && messuma!=2)
       {
        printf("%d,%d,%d",diasuma+1,messuma,añosuma);
       }
       
      if(messuma==2)
      {
      if((añosuma % 4 == 0 && añosuma % 100 != 0) || (añosuma % 400 == 0)) 
      {
       if(diasuma<=28)
       {
         printf("%d,%d,%d",diasuma+1,messuma,añosuma);
         }
         else
         {
         printf("1,%d,%d",messuma+1,añosuma);
         }
      }
 
      else
      if(diasuma<28)
      {
       printf("%d,%d,%d",diasuma+1,messuma,añosuma);
       }
       }
    }   
         
         