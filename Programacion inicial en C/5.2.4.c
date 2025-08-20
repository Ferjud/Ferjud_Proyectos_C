#include <stdio.h>

int main()
{
    char cod;
    int imp, impE = 0, impC = 0, impT = 0;

    printf("Ingrese codigo: C cheque, E efectivo, o T tarjeta. F para salir: ");
    scanf(" %c", &cod); 

    while (cod != 'F')
    {
        printf("Ingrese importe: ");
        scanf("%d", &imp);

        switch (cod)
        {
        case 'C':
            impC += imp + (imp * 20 / 100);
            break;

        case 'E':
            impE += imp - (imp * 10 / 100);
            break;

        case 'T':
            impT += imp + (imp * 12 / 100);
            break;
        }

        printf("Ingrese codigo: C cheque, E efectivo, o T tarjeta. F para salir: ");
        scanf(" %c", &cod);
    }

    printf("Efectivo en caja: %d\n", impE);
    printf("Ventas con tarjeta de credito: %d\n", impT);
    printf("Ventas con cheque: %d\n", impC);
    printf("Total de ventas: %d\n", impE + impT + impC);
    printf("Importe del IVA: %d\n", ((impE + impT + impC) * 21 / 100));

    return 0;
}