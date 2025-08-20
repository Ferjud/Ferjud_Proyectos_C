#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main()
{
  int i, vec[5]={0};
  
  srand(time(NULL));
  
  printf("orden de grupos:\n");
  
  for(i=0;i<6;i++)
  {
   vec[i]=(rand()%5)+1;
    }
    
    for(i=0;i<6;i++)
    {
      printf("%d ",vec[i]);
      }
      
 
   