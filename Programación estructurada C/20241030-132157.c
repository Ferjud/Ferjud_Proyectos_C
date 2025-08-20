#include<stdio.h>

typedef Struct
{
 int cod;
 float precio;
 char descripcion[51];
 }Sproductos;
 
 int main()
 {
  FILE*arch;
  Sproductos prod; float porc;
  
  arch=fopen("precios.dat","r+b");
     
     if(arch==NULL)
     {
      printf("Error apertura de archivo precios");
      exit(1)
      }
      printf("ingrese porcentaje a incrementar");
      scanf("%f",porc);
      
      fread(&prod,sizeof(prod),1,arch);
        while(!(feof(arch))
        {
          prod.precio+=prod.precio*porc/100*
          fseek(arch,sizeof(prod)*-1,1);//0-seek_set,1-seek_cur,2-seek-end
          //arch(archivo sobre el que quiero desplazarme)-sizeof(cantidad de bytes que quiero
          //desplazarme)-1(desde donde quiero desplazarme)
          
          fwrite(&prod,sizeof(prod),1,arch);
          fflush(arch);
         fread(&prod,sizeof(prod),1,arch);
        }
        
        fclose(arch);
        return 0;
        
      }
      
      
      
          
          
      