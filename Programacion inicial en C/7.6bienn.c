#include <stdio.h>

void CargaEmpleados();
void CuentaPorSector(int, int[]);
int TotalAPagar(int, int);

int main()
{
    CargaEmpleados();
    return 0;
}

void CargaEmpleados()
{
    int dni, conting = 0, codsec, sueldo,i;
    int totals = 0;
    int vecsec[5] = {0}; // Vector para contar empleados por sector

        do {
        printf("Ingrese DNI del empleado (99 o cantidad de ingresos mayor a 100 finaliza):\n");
        scanf("%d", &dni);
        } while (dni != 99 && !(dni >= 1000000 && dni <= 99999999));

    while (dni != 99 && conting <= 2)
    {
        conting++;

            do {
            printf("\nIngrese código de sector (1-5): ");
            scanf("%d", &codsec);
           } while (!(codsec >= 1 && codsec <= 5));

           do {
            printf("\nSueldo: ");
            scanf("%d", &sueldo);
           } while (sueldo <= 0);

        CuentaPorSector(codsec, vecsec);

        totals = TotalAPagar(sueldo, totals);

            do {
            printf("\nIngrese DNI del empleado (99 o cantidad de ingresos mayor a 100 finaliza):\n");
            scanf("%d", &dni);
            } while (dni != 99 && !(dni >= 1000000 && dni <= 99999999));
    }

    printf("Carga finalizada\n");
    printf("Total de sueldos a pagar: %d\n", totals);

    // Mostrar el conteo final por sector
    for (int i = 0; i < 5; i++)
    {
        printf("Sector %d: %d empleados\n", i + 1, vecsec[i]);
    }
}

void CuentaPorSector(int cod, int vecsec[])
{
    vecsec[cod - 1]++;
}

int TotalAPagar(int sueldos, int sueldototal)
{
    sueldototal += sueldos;
    return sueldototal;
}