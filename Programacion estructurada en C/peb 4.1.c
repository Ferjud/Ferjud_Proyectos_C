#include<stdio.h>


struct pedidos
{
 char codigo[7];
 float precio;
 char descripcion[32];
 int u_vend;
 float imp_vend;
 };
 
 void cargasinduplicados(struct pedidos[],int);
 int busq(struct pedidos[],char,int);
 
 int main()
 {
  struct pedidos v[50];
  char codaux[7];
  int i=0,cant;
  
 
 
  do{
  printf("ingrese codigo de producto(FIN para finalizar): ");
  fgets(codaux,7,stdin);
  if(busq(v,codaux,i)!=-1)
  {
    printf("El código ya existe. Ingrese nuevamente\n\n");
     }
  }while(busq(v,codaux,i)!=-1);   
    
   
  codaux[strlen(codaux)-1]="\0";
  
  while(strcmpi(codaux,"FIN")!=0 && i<50)
  {
    
    strcpy(v[i].codigo,codaux);
    
    printf("ingrese precio: ");
    scanf("%d",&v[i].precio);
    
    printf("ingrese descripción: ");
    fgets(v[i].descripcion,32,stdin);
    
    printf("cantidad de unidades vendidas del mes anterior: ");
    scanf("%d",&v[i].u_vend);
    
    printf("importe total vendido del producto del mes anterior: ");
    scanf("%f",&v[i].imp_vend);
    
    i++;
    
    printf("ingrese codigo de producto(FIN para finalizar): ");
    fgets(7,codaux,stdin);
  
    codaux[strlen(codaux)-1]="\0";
    
    }
    
    cant=i;
  
   printf("VENTAS DEL MES:");
   
   for(i=0;i<cant;i++)
   {
   
    printf("codigo %s\t",v[i].codigo);
    
    printf("cantidad pedida: ");
    scanf("%d",&v[i].u_vend);
    
    v[i].imp_vend=(float)v[i].u_vend*v[i].precio;
    
    }
 
    printf("descripción\t cant vend.\t imp vend.");
    
    for(i=0;i<cant;i++)
    {
      printf("%s\t %d\t    %.2f",v[i].descripcion,v[i].u_vend,v[i].imp_vend);
      }
  
  return 0;
  }    
  
  
  
    
  int busq(struct pedidos v[],char valorabuscar,int n)
  {
     int pos=-1,i=0;
     
     while(i<n && pos==-1)
     {
      if(strcmpi(v[i].codigo,valorabuscar)==0)
      {
       pos=i;
       }
       else{
         i++;
         }
       }
    
    return pos;
      
  }    
           
     
   
   
      
    
     
    
   
  
 
 