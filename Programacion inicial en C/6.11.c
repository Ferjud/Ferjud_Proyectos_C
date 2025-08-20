#include <stdio.h>

int CantDiasMes(int, int);
int Bisiesto(int);
int fecha(int, int, int);
int incrementarDia(int, int, int,int);

int main()
{
    int dia, mes, anio, n;

    do
    {
        printf("Ingrese el día, mes y año: ");
        scanf("%d %d %d", &dia, &mes, &anio);
        
        printf("ingrese el número de días a incrementar:");
        scanf("%d", &n);

        // Utilizar la función incrementarDia para obtener la fecha completa
        int nuevaFecha = incrementarDia(dia, mes, anio,n);

        // Descomponer la nueva fecha en día, mes y año
        dia = nuevaFecha % 100;
        nuevaFecha /= 100;
        mes = nuevaFecha % 100;
        nuevaFecha /= 100;
        anio = nuevaFecha;

        printf("Fecha incrementada: %d/%d/%d\n", dia, mes, anio);
    } while (fecha(dia, mes, anio) == 0);

    printf("Fecha válida.\n");

    return 0;
}

int CantDiasMes(int anio, int mes)
{
    int cdm;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        cdm = 30;
    }
    else
    {
        if (mes == 2)
        {
            cdm = 28 + Bisiesto(anio);
        }
        else
        {
            cdm = 31;
        }
    }

    return cdm;
}

int Bisiesto(int an)
{
    int s;
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 == 0)
    {
        s = 1;
    }
    else
    {
        s = 0;
    }
    return s;
}

int fecha(int dia, int mes, int anio)
{
    if (mes >= 1 && mes <= 12)
    {
        if (dia >= 1 && dia <= CantDiasMes(anio, mes))
        {
            return 1; // Fecha correcta
        }
    }

    printf("Fecha incorrecta. Ingrese una fecha válida.\n");
    return 0; // Fecha incorrecta
}
int incrementarDia(int dia, int mes, int anio, int n)
{
    for (int i = 0; i < n; i++)
    {
        dia++;
        if (dia > CantDiasMes(anio, mes))
        {
            dia = 1;
            mes++;
            if (mes > 12)
            {
                mes = 1;
                anio++;
            }
        }
    }

    // Combinar día, mes y año en un solo número para devolver
    return anio * 10000 + mes * 100 + dia;
}