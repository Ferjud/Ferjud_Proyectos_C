#include<stdio.h>
#include<stdlib.h>

typedef struct
{
 int dni;
 char nomyap[21];
 int pagado;
 }anotados;
 
typedef struct
{
 int telefono;
 int dni;
 char nomyap[21];
 }futuros;
 
 
 
 int main()
 {
  FILE*archreg,*archfut;
  
  archreg=fopen("INSCRIPTOS.dat","r+b");
  
  if(archreg==NULL)
  {
   printf("error al abrir el archivo");
   exit(1);
   }
   
   archfut=fopen("interesados.dat","r+b");
   
   if(archfut==NULL)
   {
    printf("error al abrir el archivo");
    exit(1);
    }
    
   
   printf("ingrese DNI:");
   scanf("%d",&numdni);
   
   while(numdni>=0)
   {
     band=0;
     rewind(archint);
     
     while(fread(&anotados,sizeof(anotados),1,archint)==1 && band=0)
     {
       if(anotados.dni==numdni)
       {
        if(anotados.pagado==0)
        {
         printf("¿desea registrar el pago?(S-si,N-no): ");
         scanf("%c",&op);
         if(op=='S')
         {
          anotados.pagado=1;
           }
         }
        }
        else{
               
          
   
 
  