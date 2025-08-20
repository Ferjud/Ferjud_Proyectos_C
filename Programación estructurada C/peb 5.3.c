#include <stdio.h>

// Definición de la función para ingresar los valores
void ingresarValores(int *entero, float *flotante, char *caracter);


int main() {
    int entero;
    float flotante;
    char caracter;

    // Llamada a la función para ingresar los valores
    ingresarValores(&entero, &flotante, &caracter);

    // Mostrando los valores ingresados
    printf("Valor entero: %d\n", entero);
    printf("Valor flotante: %.2f\n", flotante);
    printf("Caracter: %c\n", caracter);

    return 0;
}
void ingresarValores(int *entero, float *flotante, char *caracter) {
    printf("Ingresa un valor entero: ");
    scanf("%d", entero);

    printf("Ingresa un valor flotante: ");
    scanf("%f", flotante);

    printf("Ingresa un caracter: ");
    scanf(" %c", caracter);  // Espacio antes del %c para consumir el salto de línea o espacio en blanco pendiente
}