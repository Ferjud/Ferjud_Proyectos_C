#include<stdio.h>


int main()
{
  int mat[3][3]={{0}},i,j,valor,mat1[3][3];
  
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
     printf("pos %d,%d:",i+1,j+1);
     scanf("%d",&mat[i][j]);
      }
    }
    
    
   for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
     printf("%d ",mat[i][j]);
      }
      printf("\n");
    }

    
    printf("ingrese un valor entero positivo");  
    scanf("%d",&valor);
    
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
       mat1[i][j]=mat[i][j]*valor;
       }
     }
     
    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
      {
       printf("%d  ",mat1[i][j]);
      }
      printf("\n");
    }
      
   
   return 0;
   }    