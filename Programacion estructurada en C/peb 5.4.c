#include <stdio.h>

void cargarVector(int *vector, int longitud);
void mostrarVector(int *vector, int longitud);

int main() {
    int vector[10];
    cargarVector(vector, 10);
    mostrarVector(vector, 10);
    return 0;
}

void cargarVector(int *vector, int longitud) {
    int i;
    for (i = 0; i < longitud; i++) {
        printf("Ingrese el valor para la posición %d: ", i+1);
        scanf("%d", vector + i);
    }
}

void mostrarVector(int *vector, int longitud) {
    int i;
    printf("Contenido del vector: ");
    for (i = 0; i < longitud; i++) {
        printf("%d ", *(vector + i));
    }
    printf("\n");
}