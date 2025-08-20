#include <stdio.h>

struct alumno 
{
    int dni;
    char apnom[81];
    float n1;
    float n2;
    float prom;
};

int ingreso(struct alumno[], int);
void informe_promo(struct alumno[], int);
void resultado(struct alumno[], int);

int main() 
{
    struct alumno v[80];
    int cant;

    cant = ingreso(v, 80);
    resultado(v, cant);
    informe_promo(v, cant);

    return 0;
}

// Funciones

int ingreso(struct alumno v[], int n) 
{
    int i = 0, dni;

    printf("Ingresa dni: ");
    scanf("%d", &dni);

    while (dni > 0 && i < n) 
    {
        v[i].dni = dni;
        printf("Ingresa apellidos y nombres: ");
        fflush(stdin);
        gets(v[i].apnom);
        printf("Ingresa las notas: ");
        scanf("%f %f", &v[i].n1, &v[i].n2);
        v[i].prom = (v[i].n1 + v[i].n2) / 2;

        i++;
        printf("Ingresa dni: ");
        scanf("%d", &dni);
    }

    return i;
}

void resultado(struct alumno v[], int cant) 
{
    int i, contap = 0, contdesap = 0;

    for (i = 0; i < cant; i++) 
    {
        if (v[i].n1 >= 4 && v[i].n2 >= 4) 
        {
            contap++;
         } else {
            contdesap++;
        }
    }

    printf("Cantidad aprobada: %d\n", contap);
    printf("Cantidad desaprobada: %d\n", contdesap);
}

void informe_promo(struct alumno v[], int cont) 
{
    int i;

    printf("Alumnos promocionados:\n");

    for (i = 0; i < cont; i++) 
    {
        if (v[i].n1 >= 7 && v[i].n2 >= 7) 
        {
            printf("%d  %s  %.2f\n", v[i].dni, v[i].apnom, v[i].prom);
        }
    }
}