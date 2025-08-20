#include<stdio.h>

typedef struct
{
 int codart;
 char descripcion [51];
 int stock; 
 }Sprod;
 
 
 int main()
 {
  Sprod prod;
  int band=0,cantvend;
  FILE*archstock,*archfalta;
  
  archstock=fopen("stock.dat","r");
  
   if(archstock==NULL)
   {
    printf("error al abrir archivo\n\n");
    exit(1);
     }
     
     printf("VENTAS\n\n");
    
     printf("ingrese codigo de articulo:");
     scanf("%d",&cod);
     while(cod!=0)
     { 
      while(fread(&prod,sizeof(prod),1,archstock)==1 && band==0)
      {
        if(prod.codart==cod)
        {
          printf("ingrese cantidad vendida:");
          scanf("%d",&cantvend);
          
          if(cantvend<=prod.stock)
          {
            prod.stock-=cantvend;
            }
            else{
              prod.stock=0;
              fseek(&prod,-sizeof(prod),1,1);
              
      
      
  
   return 0;
   } 









