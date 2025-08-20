#include <stdio.h>

int main() 
{
    int  i,mayornota,dni,dnimayornota, nota;

    for(i = 1; i<=10; i++)
    {
        printf("ingresar dni alumno %d:",i);
        scanf("%d",&dni);
        
        printf("ingresar nota promedio %d:",i);
        scanf("%d",&nota);
        
        mayornota=nota;
        dnimayornota=dni;
         
         if(nota>mayornota)
         {
           mayornota=nota;
           dnimayornota=dni;
          }
          
          }
          
          printf("el alumno con dni %d de nota %d tiene la mayor nota", dnimayornota, mayornota);
    
    return 0;
}