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
  FILE*archorig;
  FILE*archtemp;
  Sprod prod;
  
archorig=fopen("archorig.dat","rb");
archtemp=fopen("archtemp.dat","wb");

  if(archorig==NULL || archtemp==NULL)
  {
    printf("ERROR ABERTURA");
    exit(1);
   }
   

fread(&prod,sizeof(prod),1,archorig);
 
 while(!feof(archorig))
  {
    if(codaeliminar!=prod.cod)
     {
       fwrite(&prod,sizeof(prod),1,archtemp);
       }
     
     fread(&prod,sizeof(prod),1,archorig);
   }
   
     remove("archorig.dat");
     rename("archtemp.dat","archorig.dat");
     
     fclose(archorig);
     fclose(archtemp);
     
   }  