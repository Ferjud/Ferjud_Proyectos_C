#include<stdio.h>
#include<ctype.h>

int main()
{
  char cod;
  
  do
  {
   printf("ingrese cod de imp:");
   fflush(stdin);
   scanf(" %c",&cod);
   
   } while(!(cod=='A' || cod=='L' || cod=='G' || cod=='T')
          && cod!='F');
          
   while(cod!='F')
   {
    printf("funciona bien\n");      
    
   do
   {
   printf("ingrese cod de imp:");
   scanf(" %c",&cod);
   }  while(!(cod=='A' || cod=='L' || cod=='G' || cod=='T')
          &&  cod!='F');
          
  }
  
 return 0;  
}          
    
          