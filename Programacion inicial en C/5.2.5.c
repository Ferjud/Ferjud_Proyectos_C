#include <stdio.h>

int main()
{
    int dni,n1,n2;

    printf("Ingrese dni del alumno. DNI neg salir: ");
    scanf(" %d", &dni); 

    while (dni>=0)
    {
        printf("Ingrese nota 1:");
        scanf("%d", &n1);

        printf("Ingrese nota 2:");
        scanf("%d", &n2);
        
        if(n1>=7 && n2>=7)
        {
          printf("el alumno con dni %d de notas %d y %d promociona\n ", dni,n1,n2);
          }
          
          else if(n1>=4 && n2>=4)
          {
           printf("el alumno con dni %d de notas %d y %d aprueba\n ", dni,n1,n2);
           }
           
           else
           {
            printf("el alumno con dni %d de notas %d y %d reprueba\n ", dni,n1,n2);
            }
            
            
            
        
        
        
        

        printf("Ingrese dni del alumno. DNI neg salir: ");
    scanf(" %d", &dni); 
        
    }

    
    return 0;
}