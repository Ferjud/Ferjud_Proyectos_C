#include<stdio.h>
#include<time.h>


int main()
{
 int mat[5][8]={{0}},i,j,k=0,contmax=0,max;
 int vecfila[40]={0},veccolumna[40]={0};
 
 
  srand(time(NULL));
  
  for(i=0;i<5;i++)
  {
   for(j=0;j<8;j++)
   {
    mat[i][j]=rand()%90+10;
    }
   }
   
   for(i=0;i<5;i++)
   {
    printf("\n");
    for(j=0;j<8;j++)
    {
     printf("%d  ",mat[i][j]);
      }
    }
      
    max=mat[0][0];
   for(i=0;i<5;i++)
   {
    for(j=1;j<8;j++)
     {
       if(mat[i][j]>max)
       {
        max=mat[i][j];
        }
     }   
   }      
    
    
    for(i=0;i<5;i++)
    {
    for(j=0;j<8;j++)
     {
       if(mat[i][j]==max)
       {
         vecfila[k]=i;
         veccolumna[k]=j;
         contmax++;
         k++;
         }
     }   
   }      
        
    
      
       printf("\nel maximo se repite %d veces\n\n",contmax);
       
       printf("los maximos aparecen en las posiciones: ");
       for(i=0;i<k;i++)
       {
        printf("%d %d\n",vecfila[i]+1,veccolumna[i]+1);
         }
         
    return 0;
    }     