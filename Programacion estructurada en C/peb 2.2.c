#include<stdio.h>


int main()
{
  int mat[5][4]={{0}},i,j,vecfila[5]={0},veccolumna[4]={0};
  
  for(i=0;i<5;i++)
  {
    for(j=0;j<4;j++)
    {
     printf("pos %d,%d:",i+1,j+1);
     scanf("%d",&mat[i][j]);
      }
    }
    
    
   for(i=0;i<5;i++)
  {
    for(j=0;j<4;j++)
    {
     printf("%d ",mat[i][j]);
      }
      printf("\n");
    }
    
    sumafilas(mat,5,4,vecfila);
    
    sumacolumas(mat,5,4,veccolumna);
    
    for(i=0;i<5;i++)
    {
     printf("\nsuma de la fila %d: %d ",i+1,vecfila[i]);
     }
     
     printf("\n\n");
     for(j=0;j<4;j++)
     {
       printf("\nsuma de la columna %d: %d ",j+1,veccolumna[i]);
      }
     
    
    
    
   
   return 0;
   }    
   
 
 
 
 void sumafilas(int matriz[][4],int cf,int cc,int vectorfila[])
 {
    int i,j;
    
    for(i=0;i<cf;i++)
    {
     for(j=0;j<cc;j++)
      {
        vectorfila[i]+=matriz[i][j];
        }
      } 
 }     
  
 void sumacolumnas(int matriz[][4],int cf,int cc,int vectorcolumna[])
 {
    int i,j;
    
    for(j=0;i<cc;j++)
    {
     for(i=0;i<cf;i++)
      {
        vectorcolumna[j]+=matriz[i][j];
        }
      } 
  }               