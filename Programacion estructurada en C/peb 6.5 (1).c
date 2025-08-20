#include<stdio.h>

typedef struct
{
 int cod;
 float precio;
 char descripcion[51];
 }Sproductos;
 
 int main()
 {
  FILE*arch,*arch1;
  Sproductos prod;
  float porc;
  int band=0,codact;
  
  arch=fopen("precios.dat","r+b");
     
     if(arch==NULL)
     {
      printf("Error apertura de archivo precios");
      exit(1);
      }
      printf("ingrese el código para actualizar:");
      scanf("%d",&codact);
      
      while (codact != 0) 
      {
       band = 0;
       rewind(arch);  // Reiniciar lectura desde el principio del archivo
     
       while (fread(&prod, sizeof(prod), 1, arch) && band == 0) 
       {
       
         if (prod.cod == codact) 
         {
            band = 1;
            printf("Ingrese el nuevo precio: ");
            scanf("%f", &prod.precio);

            fseek(arch, -sizeof(prod), SEEK_CUR);  // Mueve el puntero hacia atrás para sobrescribir
            fwrite(&prod, sizeof(prod), 1, arch);  // Actualiza el registro
            fflush(arch);  // Asegura que el cambio se guarde en el archivo
        }
      }
      if (band == 0) 
       {
         printf("Código inexistente.\n");
         }
       printf("Ingrese el código para actualizar su precio (0 para salir): ");
       scanf("%d", &codact);
     }
        
        
        arch1=fopen("precio.csv","wt");//exportar
          
          if(arch1==NULL)
          {
            printf("error apertura csv");
            exit(1);
            }
            
          fprintf(arch1,"código;precio;descripción\n");
          
          fread(&prod,sizeof(prod),1,arch);
            
            while(!feof(arch))
            {
              fprintf(arch1,"%d,%.2f,%s\n",prod.cod,prod.precio,prod.descripcion);
              
              fread(&prod,sizeof(prod),1,arch);
             }
             
             fclose(arch);
             fclose(arch1);
            
        
        return 0;
        
      }
      
      
      
          
          
      