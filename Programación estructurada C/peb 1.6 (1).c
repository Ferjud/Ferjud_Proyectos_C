#include <stdio.h>
#include <stdlib.h>

int main() {
    int vec[13] = {1, 5, 10, 12, 15, 25, 40, 50, 60, 81}; // Espacio extra para insertar nuevos números
    int i = 0, j, num1,num2,num3;
  
    printf("Vector inicial:\n");
    for (i = 0; i < 10; i++)
     {
        printf("%d ", vec[i]);
      }
  
    printf("\n\nIngrese números entero para agregar al vector:\n");
    printf("Ingrese número 1: ");
    scanf("%d", &num1);
    printf("ingrese número 2: ");
    scanf("%d",&num2);
    printf("ingrese número 3: ");
    scanf("%d",&num3);
    // Encontrar la posición correcta para insertar el número usando while
    i = 0; // Reiniciar i para buscar la posición
    while (i < 10 && num1 > vec[i]) 
    {
        i++;
    }

    // Mover elementos para hacer espacio
    j = 10; // Empezar desde el final del vector actual
    while (j > i)
    {
        vec[j] = vec[j - 1];
        j--;
    }

    // Insertar el número en la posición correcta
    vec[i] = num1;

    // Imprimir el vector después de la inserción
    printf("\nVector después de la inserción del número 1:\n");
    for (i = 0; i < 11; i++) 
    {
        printf("%d ", vec[i]);
    }
    
    
    
    i = 0; // Reiniciar i para buscar la posición
    while (i < 11 && num2 > vec[i]) 
    {
        i++;
    }

    // Mover elementos para hacer espacio
    j = 11; // Empezar desde el final del vector actual
    while (j > i)
    {
        vec[j] = vec[j - 1];
        j--;
    }

    // Insertar el número en la posición correcta
    vec[i] = num2;

    // Imprimir el vector después de la inserción
    printf("\nVector después de la inserción del número 2:\n");
    for (i = 0; i < 12; i++) 
    {
        printf("%d ", vec[i]);
    }
    
    
    
    
        i = 0; // Reiniciar i para buscar la posición
    while (i < 12 && num3 > vec[i]) 
    {
        i++;
    }

    // Mover elementos para hacer espacio
    j = 12; // Empezar desde el final del vector actual
    while (j > i)
    {
        vec[j] = vec[j - 1];
        j--;
    }

    // Insertar el número en la posición correcta
    vec[i] = num3;

    // Imprimir el vector después de la inserción
    printf("\nVector después de la inserción del número 3:\n");
    for (i = 0; i < 13; i++) 
    {
        printf("%d ", vec[i]);
    }
    
    
  
    return 0;
}