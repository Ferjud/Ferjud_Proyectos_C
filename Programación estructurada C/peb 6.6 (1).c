#include<stdio.h>

typedef struct
{
 int cod;
 float precio;
 char descripcion [51];
 }Sprod;
 
 void borrar(int);
 
 int main()
 {
   int codd;
   
   printf("ingrese codigo del producto a borrar:");
   scanf("%d",&codd);
   
   borrar(codd);
    
   return 0;
   } 









void borrar (int codaeliminar)
 {
  FILE*archprod;
  FILE*archtemp;
  Sprod prod;
  
archprod=fopen("productos.dat","rb");
archtemp=fopen("archtemp.dat","wb");

  if(archprod==NULL || archtemp==NULL)
  {
    printf("ERROR ABERTURA");
    exit(1);
   }
   

fread(&prod,sizeof(prod),1,archprod);
 
 while(!feof(archprod))
  {
    if(codaeliminar!=prod.cod)
     {
       fwrite(&prod,sizeof(prod),1,archtemp);
       }
     
     fread(&prod,sizeof(prod),1,archprod);
   }
   
     remove("productos.dat");
     rename("archtemp.dat","productos.dat");
     
     fclose(archprod);
     fclose(archtemp);
     
   }  