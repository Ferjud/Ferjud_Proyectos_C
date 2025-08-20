#include <stdio.h>

int diasmes(int, int);
int validarfechas(int, int, int);
void restardiafecha(int, int, int);

int main() {
    int dias, meses, años, n;

    printf("Ingrese día, mes y año para validar\n");

    do {
        printf("Día: ");
        scanf("%d", &dias);
        if (!(dias >= 1 && dias <= 31)) {
            printf("Error. Ingrese día válido.\n");
        }
    } while (!(dias >= 1 && dias <= 31));

    do {
        printf("Mes: ");
        scanf("%d", &meses);
        if (!(meses >= 1 && meses <= 12)) {
            printf("Error. Ingrese mes válido.\n");
        }
    } while (!(meses >= 1 && meses <= 12));

    do {
        printf("Año: ");
        scanf("%d", &años);
        if (!(años >= 1582 && años <= 2024)) {
            printf("Error. Ingrese año válido.\n");
        }
    } while (!(años >= 1582 && años <= 2024));

    if (validarfechas(dias, meses, años) == 1) 
    {
        printf("La fecha es correcta\n");
        
        printf("fecha restada 1 dia: \n");
       
        restardiafecha(dias, meses, años);
    } 
    else 
    {
        printf("La fecha es incorrecta\n");
    }

    return 0;
}

int validarfechas(int diaa, int mess, int añoo) 
{
    int retorno;
    if (diaa <= diasmes(mess, añoo)) 
    {
        retorno = 1;
    }
     else
     {
        retorno = 0;
    }
    return retorno;
}

int diasmes(int mes, int año) 
{
    int dia;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) 
    {
        dia = 31;
    } 
   
    else
     if (mes == 4 || mes == 6 || mes == 9 || mes == 11) 
     {
      
        dia = 30;
    } 
    else
     if (mes == 2) 
    {
        if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) 
        {
            dia = 29; // Año bisiesto
        } 
        else 
        {
            dia = 28; // Año no bisiesto
        }
    }

    return dia;
}

void restardiafecha(int diaresta, int mesresta, int añoresta)
 {
    diaresta= diaresta - 1;

    while (diaresta < 1) 
    {
        diaresta = diasmes(mesresta, añoresta);
        mesresta--;

        if (mesresta < 1)
         {
            mesresta = 12;
            añoresta--;
          }
    }

    printf("%d,%d,%d\n", diaresta, mesresta, añoresta);
}