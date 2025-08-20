#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int busqueda(int[],int,int);


int main()
{
  int i, vec[5]={0},grupo,pos;
  
  srand(time(NULL));
  
  printf("orden de grupos:\n");
  
  for(i=0;i<5;i++)
   {
  
   do{
   grupo=(rand()%5)+1;
   pos=busqueda(vec,grupo,i);
   } while(pos!=-1);
   vec[i]=grupo;
     
    }
    
    for(i=0;i<5;i++)
    {
      printf("%d ",vec[i]);
      }
   
    return 0;
    }
 
 int busqueda(int v[],int valorabuscar,int n)
 {
  int pos=-1,i=0;
  
  while(i<n && pos==-1)
  {
    if(v[i] == valorabuscar)
    {
     pos=i;
     }
     else{
        i++;
        }
    }
    return pos;
  }
  
  
  