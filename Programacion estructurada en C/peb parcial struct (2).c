#include<stdio.h>
#include<string.h>

struct productos
{
 int codigo;
 float precio;
 char descripcion [51];
 };
 
 int busq(struct productos [],int,int);
 
 int main()
 {
  float prec;
  struct productos v[200];
  int i,ingresos=0,rechazados=0,codmod,op,totaling;
  
  for(i=0;i<200;i++)
  {
   printf("ingrese código numérico de producto: ");
   scanf("%d",&v[i].codigo);
   getchar();
   
   do{
   printf("ingrese el precio(mayor a 0): ");
   scanf("%f",&prec);
   getchar();
   if(prec<=0)
   {
    printf("precio incorrecto. ingrese nuevamente\n\n");
    }
   }while(prec<=0);
   
   v[i].precio=prec;
   
   printf("ingrese descripción: ");
   fgets(v[i].descripcion,51,stdin);
   fflush(stdin);
   }
   
   do{
   printf("ingrese código de artículo a modificar(0 finaliza): ");
   scanf("%d",&codmod); 
   if(busq(v,codmod,200)==-1 && codmod!=0)
   {
    printf("error.Ingrese nuevamente\n\n");
     }
   }while(busq(v,codmod,200)==-1 && codmod!=0);
   
   
   while(codmod!=0)
   {
     printf("1-precio 2-descripción 3-ambos\n\n");
     ingresos++;
     
     do{
     printf("ingrese opción: ");
     scanf("%d",&op);
     getchar();
     if(op!=1 && op!=2 && op!=3)
     {
       printf("incorrecto.Vuelva a ingresar");
       }
      }while(op!=1 && op!=2 && op!=3);
      
      char cadena[51];
      
      switch(op)
      {
        case 1: 
                 for(i=0;i<200;i++)
                 {
                   if(v[i].codigo==codmod)
                   {
                     do{
                       printf("ingrese el precio(mayor a 0): ");
                       scanf("%f",&prec);
                       getchar();
                       if(prec<=0)
                        {
                         printf("precio incorrecto. ingrese nuevamente\n\n");
                          }
                       }while(prec<=0);
   
                       v[i].precio=prec;
                     }
                   }
                   break;
                   
        case 2: 
                  for(i=0;i<200;i++)
                  {
                    if(v[i].codigo==codmod)
                    {
                     printf("ingrese descripción: ");
                     fgets(cadena,51,stdin);
                     strcpy(v[i].descripcion,cadena);
                     fflush(stdin);
                      }  
                    }
                    break;
     
        case 3:
                  for(i=0;i<200;i++)
                  {
                    if(v[i].codigo==codmod)
                    {
                      
                        do{
                       printf("ingrese el precio(mayor a 0): ");
                       scanf("%f",&prec);
                       getchar();
                       if(prec<=0)
                        {
                         printf("precio incorrecto. ingrese nuevamente\n\n");
                          }
                       }while(prec<=0);
   
                       v[i].precio=prec;
                       
                       
                       printf("ingrese descripción: ");
                       fgets(cadena,51,stdin);
                       strcpy(v[i].descripcion,cadena);
                       fflush(stdin);
                        
                       
                     }
                   }
                   break;
           }      
           
           
           do{
            printf("ingrese código de artículo a modificar(0 finaliza): ");
            scanf("%d",&codmod);  
            getchar();
            if(busq(v,codmod,200)==-1 && codmod!=0)
            {
             printf("error.Ingrese nuevamente");
             }
            }while(busq(v,codmod,200)==-1 && codmod!=0);
         
         }   
         
     totaling=ingresos+rechazados;
     
     if(totaling!=0)
     {
     printf("porcentaje de códigos rechazados: %.2f",(float)rechazados/totaling*100);   
       }
      else{
        printf("no se rechazaron codigos");
         }
         
         
     printf("\n\n\tcódigo\tprecio\tdescripción\n\n");
     for(i=0;i<2;i++)
     {
      printf("\t%d\t%.2f\t%s\n\n",v[i].codigo,v[i].precio,v[i].descripcion);
       }
     
     return 0;
     }
     
  
  
  int busq(struct productos v[],int abuscar,int n)
   {
     int i=0,pos=-1;
     
     while(i<n && pos==-1)
     {
      if(abuscar==v[i].codigo)
      {
        pos=i;
        }
        else{
           i++;
           }
         }
         
     return pos;
            
   }