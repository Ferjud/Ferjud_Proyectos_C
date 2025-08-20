#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void cargacod(int[],int,int);
int buscar(int[],int,int);
void mostrarcod(int[],int);
void burbujeo(int[],int);
int busquedabinaria(int[],int,int);
void ordenarvec(int[],int[],int);

int main()
{
  int veccod[15]={0},veccant[15]={0},vecvend[15]={0},vecart[15]={0},ventasvend[5]={0},i=0,codart,codvend,cant;
  int posval,min,posvend;
  srand(time(NULL));
  
  cargacod(veccod,15,900);
  
  burbujeo(veccod,15);
  
  printf("codigos de articulos\n\n");
  mostrarcod(veccod,15);
  
  do{
  printf("\n\ningrese código de vendedor(1001-1005, 0 finaliza): ");
  scanf("%d",&codvend);
  }while((codvend<1001 || codvend>1005) && codvend!=0);
  
  while(codvend!=0)
  {
    do{
    printf("ingrese codigo de artículo: ");
    scanf("%d",&codart);
    posval=busquedabinaria(veccod,codart,15);
    if(posval==-1)
    {
      printf("Error. Código equivocado \n");
      }
     }while(posval==-1);
      
      
      do{
       printf("ingrese cantidad de unidades vendidas:"); 
       scanf("%d",&cant);
       if(cant<=0)
       {
         printf("cantidad no válida");
         }
       }while(cant<=0);
       
       vecvend[i]=codvend;
       
       vecart[i]=codart;
       
       veccant[i]=cant;
       
       ventasvend[codvend-1001]++;
       
       i++;
       
         do{
         printf("ingrese código de vendedor(1001-1005, 0 finaliza): ");
         scanf("%d",&codvend);
         }while((codvend<1001 || codvend>1005) && codvend!=0);
  } 
  
   ordenarvec(veccant,veccod,15);   
   
   printf("U.vendidas\t artículo\n");
   for(i=0;i<15;i++)
   {
     printf("%d\t\t %d\n",veccant[i],vecart[i]);   
      }
     
   
     min=ventasvend[0];
  
   for(i=1;i<5;i++)
   {
     if(ventasvend[i]<min)
     {
      min=ventasvend[i];
      posvend=i;
       }
   }     
       
    printf("\nlos vendedores que menos vendieron fueron:");
    for(i=0;i<5;i++)
    {
     if(ventasvend[i]==min)
     {
      printf("%d\n",i+1001);
        } 
    }     
      
    
  
  
  
  
  
  
  
  
  return 0;
  }
  
  
  
  
 void cargacod(int vectorcod[],int ce,int max)
 {
   int i,posicion,cod;
   
    for(i=0;i<ce;i++)
    {
     
     do{
      cod=rand()%max+100;
      posicion=buscar(vectorcod,cod,i);
      }while(posicion!=-1);
      
      vectorcod[i]=cod;
     }  
  }
  
  
  int buscar(int vectorcod[],int valorabuscar,int elem)
  {
    int pos=-1, i=0;
    
    while( pos==-1 && i<elem)
    {
      if(vectorcod[i]==valorabuscar)
      {
        pos=i;
        }
      else
      {
         i++;
         }
     }
     
   return pos;
   }
   
   void mostrarcod(int vectorcod[],int elem)
   {
     int i;
     
      for(i=0;i<elem;i++)
      {
        printf("%d ",vectorcod[i]);
         }
   }     
    
    
   void burbujeo(int vectorcod[],int elem)
   {
     int i,aux,j;
     
      for(i=0;i<elem-1;i++)
      {
         for(j=0;j<elem-1-i;j++)
         {
           if(vectorcod[j]>vectorcod[j+1])
           {
              aux=vectorcod[j];
              vectorcod[j]=vectorcod[j+1];
              vectorcod[j+1]=aux;
              }
           } 
      } 
   }   
           
   
   int busquedabinaria(int vectorcod[],int buscado,int elem)
   {
    int pos=-1,li=0, ls=elem-1,med;
   
     while (pos==-1 && li<=ls)
     {
       med=(li+ls)/2;
       if(vectorcod[med]==buscado)
       {
         pos=med;
        }
       else if(buscado>vectorcod[med])
       {
         li=med+1;
           }
       else
       {
         ls=med-1;
         }
      }  
      
      return pos;  
     }      
        
      
      
    void ordenarvec(int vectorcant[],int vectorcod[],int elem)
    {
        int i,aux,j;
     
         for(i=0;i<elem-1;i++)
          {
           for(j=0;j<elem-1-i;j++)
            {
             if(vectorcant[j]<vectorcant[j+1])
             {
              aux=vectorcant[j];
              vectorcant[j]=vectorcant[j+1];
              vectorcant[j+1]=aux;
             
              aux=vectorcod[j];
              vectorcod[j]=vectorcod[j+1];
              vectorcod[j+1]=aux;
              
              
              }
           } 
         }
      }
      
      
          
    
  
  
  