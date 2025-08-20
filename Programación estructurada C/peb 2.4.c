#include<stdio.h>

int validar(int, int);

int main() {
    int i, j;
    int mat[10][15] = {{0}}; // Matriz para contar pasajes por agencia y tour
    int vecagencias[15] = {0}; // Vector para almacenar los códigos de las agencias
    int vectours[10] = {0}; // Vector para almacenar los códigos de los tours
    int vectotal[15] = {0}; // Vector para almacenar el total de pasajes por agencia
    int agencia, tour, pasajes;

    printf("VENTAS DEL DIA\n\n");

    // Entrada de datos
    for (j = 0; j < 15; j++) {
        printf("Ingresa código de agencia (1-15): ");
        agencia = validar(1, 15);
        vecagencias[j] = agencia;

        for (i = 0; i < 10; i++) {
            printf("\nIngresa código de tour (1-10): ");
            tour = validar(1, 10);
            vectours[i] = tour;

            printf("\nIngresa cantidad de pasajes (0-20): ");
            pasajes = validar(0, 20);

            // Actualizar la matriz con los pasajes vendidos
            mat[tour - 1][agencia - 1] += pasajes;

            // Actualizar el total de pasajes por agencia
            vectotal[j] += pasajes;
        }
    }

    // Mostrar resultados en forma de matriz
    printf("\n\t\t");
    for (j = 0; j < 15; j++) {
        printf("Agencia %d\t", vecagencias[j]); // Encabezados de las agencias
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("Tour %d\t\t", i + 1); // Encabezados de los tours
        for (j = 0; j < 15; j++) {
            printf("%d\t\t", mat[i][j]); // Valores de pasajes vendidos
        }
        printf("\n");
    }

    // Mostrar totales por agencia
    printf("Total\t\t");
    for (j = 0; j < 15; j++) {
        printf("%d\t\t", vectotal[j]);
    }
    printf("\n");

    return 0;
}

int validar(int liminf, int limsup) {
    int n;

    do {
        scanf("%d", &n);
        if (n > limsup || n < liminf) {
            printf("Error. Fuera de rango. Intenta de nuevo: ");
        }
    } while (n > limsup || n < liminf);

    return n;
}