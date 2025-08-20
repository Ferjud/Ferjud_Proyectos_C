#include<stdio.h>
void ingresacod(int[],int);
int busq(int[],int,int);


int main()
{
 int veccod[10]={0},veccant[10]={0},i,mayorcant=0,menorcant=0,indice,cod,cant;
 int posición;
 
 ingresacod(veccod,10);
 
 printf("INGRESO DE PEDIDOS\n");
 
 do{
  printf("ingresa codigo de producto:");
  scanf("%d",&cod);
   if( (busq(veccod,cod,10)==-1) && cod!=0)
    {
     printf("error.ingrese nuevamente\n");
     }
  }while((busq(veccod,cod,10)==-1) && cod!=0);
  
 
 while(cod!=0)
  {
    do{
    printf("ingrese cantidades solicitadas:");
    scanf("%d",&cant);
     if(cant<0)
     {
       printf("error.ingrese cantidad válida\n");
       }
      }while(cant<0); 
      
      
      posición=busq(veccod,cod,10);
      
      veccant[posición]+=cant;
      
      
      do{
      printf("ingresa codigo de producto:");
      scanf("%d",&cod);
      
      if((busq(veccod,cod,10)==-1) && cod!=0)
       {
       printf("error.ingrese nuevamente\n");
        }
        
      }while((busq(veccod,cod,10)==-1) && cod!=0);
      
      
    }  
    
    
    for(i=0;i<10;i++)
    {
      printf("codigo:%d\t cantidad:%d\n",veccod[i],veccant[i]);
      }
    
    
    for(i=0;i<10;i++)
    {
      if(veccant[i]>mayorcant)
      {
       mayorcant=veccant[i];
       indice=i;
        }
      }  
        
        for(i=0;i<10;i++)
        {
         if(mayorcant==veccant[i])
         {
           printf("El o los producto-s con mas cantidad solicitada: %d\n",veccod[i]);
           }
          }  
          
          
          for(i=0;i<10;i++)
          {
           if(veccant[i]<menorcant)
            {
              menorcant=veccant[i];
              indice=i;
              }
             } 
        
            for(i=0;i<10;i++)
            {
             if(menorcant==veccant[i])
              {
               printf("El o los producto-s con menos cantidad solicitada: %d\n",veccod[i]);
                }
            }  
          
          
return 0;
}




void ingresacod(int vec[],int n)
{
  int i,valor,pos;
  
  for(i=0;i<n;i++)
  {
    do{
      printf("ing cod entero de 4 cifras:");
      scanf("%d",&valor);
      pos=busq(vec,valor,i);
       if(pos!=-1 || (valor<1000 || valor>9999))
        {
          printf("valor existente o fuera del rango. Ingrese nuevamente\n");
          }
       }while(pos!=-1 || (valor<1000 || valor>9999));
       vec[i]=valor;  
      }
    }
  
int busq(int v[],int valorabuscar,int n)
{
  int pos=-1, i=0;
  
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
    
    
  
  
     
    