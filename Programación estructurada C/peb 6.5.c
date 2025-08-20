#include<studio.h>

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
      printf("ingrese el código para actualizar:");
      scanf("%d",codact);
      
      while(codact!=0)
      {
        band=0;
        
        fread(&prod,sizeof(prod),1,arch);
          
           while(!feof(arch) && band==0)
            {
              if(prod.cod==codact)
              {
               band=1;
               printf("ingrese precio:");
               scanf("%f",&prod.precio);
      
      
        while(!(feof(arch))
        {
          fseek(arch,sizeof(prod)*-1,1);//0-seek_set,1-seek_cur,2-seek-end
          //arch(archivo sobre el que quiero desplazarme)-sizeof(cantidad de bytes que quiero
          //desplazarme)-1(desde donde quiero desplazarme)
          
          fwrite(&prod,sizeof(prod),1,arch);
          fflush(arch);
         }
        else{
          fread(&prod,sizeof(prod),1,arch);
            } 
        } 
        
        if(band==0)
        {
          printf("código inexistente");  
          }
          
          printf("ingrese el código para actualizar su precio:");
          scanf("%d",&codact);
          
          fseek(arch,0,0);//0-seek_set
          
      }
        
        
        arch1=fopen("precio.csv","wt");//exportar
          
          if(arch1==NULL)
          {
            printf("error apertura csv");
            exit(1)
            }
            
          fprintf(arch1,"código;precio;descripción\n");
          
          fread(&prod,sizeof(prod),1,arch);
            
            while(!feof(arch))
            {
              fprintf(arch1,"%d,%.2f,%s\n",prod.cod,prod.precio,prod.descrip);
              
              fread("&prod",sizeof(prod),1,arch);
             }
             
             fclose(arch);
             fclose(arch1);
            
        
        return 0;
        
      }
      
      
      
          
          
      