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
 int busq(struct pedidos[],int,int);
 
 int main()
 {
  struct v[50];
  char codaux[7];
  int i=0,cant;
  
  printf("ingrese codigo de producto(FIN para finalizar): ");
  fgets(7,codaux,stdin);
  
  codaux[codaux(strlen)-1]="\0";
  
  while(strcmpi(codaux,"FIN")!=0 && i<50)
  {
    
    v[i].codigo=codaux;
    
    printf("ingrese precio: ");
    scanf("%d",&v[i].precio)
    
    printf("ingrese descripción: ");
    fgets(32,v[i].descripcion,stdin);
    
    printf("cantidad de unidades vendidas del mes anterior: ");
    scanf("%d",&v[i].u_vend);
    
    printf("importe total vendido del producto del mes anterior: ");
    scanf("%f",&v[i].imp_vend);
    
    i++;
    
    printf("ingrese codigo de producto(FIN para finalizar): ");
    fgets(7,codaux,stdin);
  
    codaux[codaux(strlen)-1="\0";
    
    }
    
    cant=i;
  
   printf("VENTAS DEL MES:");
   
   for(i=0;i<cant;i++)
   {
   
    cargasinduplicados(v,cant);
    
    printf("cantidad pedida: ");
    scanf("%d",&v[i].u_vend);
    
    v[i].imp_vend=(float)v[i].u_ vend*v[i].precio;
    
    }
 
    printf("descripción\t cant vend.\t imp vend.");
    
    for(i=0;i<cant;i++)
    {
      printf("%s\t %d\t    %.2f",v[i].descripcion,v[i].u_vend,v[i].imp_vend);
      }
  
  return 0;
  }    
  
  
  void cargasinduplicados(struct pedidos v[],int n)
  {
   int i,pos,valor;
   
   for(i=0;i<n;i++)
   {
    do{
     printf("ing código: ");
     scanf("%d",&valor);
     pos=busq(v,valor,i);
      if(pos!=-1)
      {
        printf("valor existente");
        }
      }while(pos!=-1);    
     }
    }
    
  int busq(struct pedidos v[],int valorabuscar,int n)
  {
     int pos=-1,i=0;
     
     while(i<n && pos==-1)
     {
      if(v[i]==valorabuscar)
      {
       pos=i;
       }
       else{
         i++;
         }
       }
    
    return pos;
      
  }    
           
     
   
   
      
    
     
    
   
  
 
 