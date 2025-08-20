#include<stdio.h>
busq(int [][15],int,int,int);





int main()
{
 int piso,dep,mat[5][15]={{0}},recaudación=0,i,j,x;

do{
 printf("ingrese numero de piso de piso(1-5), 99 para finalizar: ");
 scanf("%d",&piso);
 if(!(piso>=1 && piso<=5) && piso!=99)
 {
  printf("Error.Ingrese piso valido\n");
   }
  }while (!(piso>=1 && piso<=5) && piso!=99);
 
 while(piso!=99)
 {
   do{
   printf("ingrese número de departamento (1-15): ");
   scanf("%d",&dep);
   if(dep<1 || dep>15)
   {
    printf("Error. Ingrese departamentl valido\n ");
     }
    }while(dep<1 || dep>15);  
   
   if(mat[piso-1][dep-1]!=1000)
   {
    mat[piso-1][dep-1]=1000;
    recaudación+=1000;
    }
     else{
      printf("Error. Cobro ya asignado anteriormente,vuelva a ingresar\n");
       }
       
       
       do{
       printf("ingrese numero de piso de piso(1-5), 99 para finalizar: ");
       scanf("%d",&piso);
       if(!(piso>=1 && piso<=5) && piso!=99)
       {
       printf("Error.Ingrese piso valido\n");
        }
      }while (!(piso>=1 && piso<=5) && piso!=99);
 
    
 }  
 
   printf("\t\t\tTOTAL RECAUDADO\n");
   printf("\t\t DEPARTAMENTOS DEUDORES\n\n");
  
   for(i=0;i<5;i++)
   {
   printf("\npiso %d ",i+1);
     }
  
  
   for(j=0;j<15;j++)
   {
     printf("\tdepto %d",j+1);
    for(i=0;i<5;i++)
    {
      if(mat[i][j]==1000)
      {
       printf("\t%d",mat[i][j]);
       }
       else{
         printf("\tX   ");
       }
      }  
    }   
      printf("\n\nrecaudación total: %d",recaudación);
       
    
    return 0; 
  }  
    
     
   
   
   
 
 
 
 
 
 
 
 
 
 
 int busq(int matriz[][15],int valorabuscar,int x,int k)
 {
  int pos=-1,i=0,j=0,n;
  
  while((i<n && j<k) && pos==-1)
  {
    if(matriz[i][j]==valorabuscar)
    {
      pos=1;
      }
      else{
        j++;
        }
        if(j==14)
        {
         j=0;
         i++;
         }
    }
      return pos;
 }   
 
     