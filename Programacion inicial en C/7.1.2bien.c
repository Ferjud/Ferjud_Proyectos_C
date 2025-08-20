#include <stdio.h>

int CargaVector(int[], int);
void Invertir(int[], int[], int);
void Mostrar(int[], int);

int main() {
    int vec[10], vecinv[10];
    int ce = CargaVector(vec, 10);
    Invertir(vec, vecinv, ce);
    Mostrar(vecinv, ce);
    return 0;
}

int CargaVector(int v[], int ce) {
    int i = 0, num;
    while (i < ce) {
        printf("Ingrese un numero en la posicion %d: ", i + 1);
        scanf("%d", &v[i]);
        i++;
    }
    return ce;
}

void Invertir(int v[], int v2[], int ce) {
    int i;
    for (i = 0; i < ce; i++) {
        v2[i] = v[ce - (i + 1)];
    }
}

void Mostrar(int v2[], int ce) {
    int i;
    for (i = 0; i < ce; i++) {
        printf("El numero de la posicion %d es: %d\n", i + 1, v2[i]);
    }
}