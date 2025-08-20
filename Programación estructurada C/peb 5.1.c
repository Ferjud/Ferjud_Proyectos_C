#include <stdio.h>

int main() {
    // Crear una variable entera
    int num;

    // Crear un puntero a la variable entera
    int *puntero = &num;

    // Asignar el valor 10 a la variable mediante el puntero
    *puntero = 10;

    // Mostrar la dirección de la variable
    printf("La dirección de la variable entera es: %p\n", &num);

    // Mostrar la dirección del puntero
    printf("La dirección del puntero es: %p\n", &puntero);

    // Mostrar el contenido de la variable
    printf("El contenido de la variable es: %d\n", num);

    // Mostrar el contenido de la variable accediendo mediante el puntero
    printf("El contenido de la variable accediendo mediante el puntero es: %d\n", *puntero);

    // Mostrar el contenido del puntero
    printf("El contenido del puntero es: %p\n", puntero);

    return 0;
}