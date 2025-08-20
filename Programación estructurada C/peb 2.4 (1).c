#include<stdio.h>

int validar(int, int);

int main() {
    int i, j;
    int mat[10][15] = {{0}}; // Matriz para contar pasajes por agencia y tour
    int vectotal[15] = {0}; // Vector para almacenar el total de pasajes por agencia
    int agencia, tour, pasajes;

    printf("VENTAS DEL DIA\n\n");

    // Entrada de datos
    for (j = 0; j < 15; j++) 
    {
        printf("Ingresa código de agencia (1-15): ");
        agencia = validar(1, 15);

        for (i = 0; i < 10; i++) 
        {
            printf("\nIngresa código de tour (1-10): ");
            tour = validar(1, 10);

            printf("\nIngresa cantidad de pasajes (0-20): ");
            pasajes = validar(0, 20);

            // Actualizar la matriz con los pasajes vendidos
            mat[tour - 1][agencia - 1] += pasajes;

            // Actualizar el total de pasajes por agencia
            vectotal[agencia - 1] += pasajes;
        }
    }

    // Mostrar encabezados de columnas
    printf("\n\t\t");
    for (j = 0; j < 15; j++) 
    {
        printf("Agencia %d\t", j + 1);
    }
    printf("\n")=

    // Mostrar resultados en orden de filas (tours) y luego columnas (agencias)
    for (i = 0; i < 10; i++) 
    {  // Recorrer filas (tours)
        printf("Tour %d\t", i + 1);  // Imprimir encabezado de fila (tour)
        for (j = 0; j < 15; j++) 
        {  // Recorrer columnas (agencias)
            printf("%d\t\t", mat[i][j]);  // Imprimir cantidad de pasajes vendidos
        }
        printf("\n");
    }

    // Mostrar totales por agencia
    printf("Total\t");
    for (j = 0; j < 15; j++) 
    {
        printf("%d\t\t", vectotal[j]);
    }
    printf("\n");

    return 0;
}

int validar(int liminf, int limsup) 
{
    int n;

    do {
        scanf("%d", &n);
        if (n > limsup || n < liminf) 
        {
            printf("Error. Fuera de rango. Intenta de nuevo: ");
        }
    } while (n > limsup || n < liminf);

    return n;
}