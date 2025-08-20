#include<stdio.h>

 struct medic
 {
  int cod;
  float precio;
  int stock;
  };
  
void ingreso(struct medic[],int);
int busq(struct medic[],int,int);
void informe(struct medic[],int);

int main()
{
 struct medic v[50];
 int x,codigo,precio;
 
 ingreso(v,50);
 printf("ing código para consultar precio");
 scanf("%d",&codigo);
 
 while(codigo!=0)
 {
   x=busq(v,codigo,50);
   
   if(x!=1)
   {
    printf("el precio del código %d es %.2f",codigo,v[x],precio);
    }
    else{
      printf("código inexistente");
          }
    
    printf("ing código para consultar el precio");
    scanf("%d",&codigo); 
  
  }
  
  informe(v,50);
  
  return 0;
  }
  
  
  
  void ingreso(struct medic v[],int n)
  {
   int i;
   
   for(i=0;i<n;i++)
   {
    printf("ing el codigo:");
    scanf("%d",&v[i].cod);
    
    printf("ing el precio:");
    scanf("%f",&v[i].precio);
    
    printf("ing stock:");
    scanf("%d",&v[i].stock);
   }//fin for 
  } 
   
  int busq(struct medic v[],int c,int n)
  {
    int i=0,pos=-1;
    
    while(i<n && pos==-1)
    {
      if(c==v[i].cod)
      {
       pos=i;
       }
       else{
          i++;
          }
       }
   
   return pos;
  } 
  
  void informe(struct medic v[],int n)
  {
    int i;
    
    for(i=0;i<n;i++)
    {
      if(v[i].stock<10)
      {
        printf("%d",v[i].cod);
        }
       } 
     }    