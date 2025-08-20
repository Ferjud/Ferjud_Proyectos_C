#include <stdio.h>
int EstaDentroDelRango(int,int,int);
int LeerYValidar(int,int);

int main()
{
    int num, cant100_500 = 0, pares500_1200 = 0, cant1200_2000 = 0, sum1200_2000 = 0;

    printf("Ingrese números entre 100 y 2000 (99 para finalizar):\n");
    num = LeerYValidar(99, 2000);

    while (num != 99)
    {
        cant100_500 += EstaDentroDelRango(num,100,500);

        if (num % 2 == 0 && EstaDentroDelRango(num,500,1200))
            pares500_1200++;

        if (EstaDentroDelRango(num,1200,2000))
        {
            cant1200_2000++;
            sum1200_2000 += num;
        }

        num = LeerYValidar(99,2000);
    }

    printf("\nCantidad de números entre 100 y 500: %d", cant100_500);

    if (cant1200_2000 > 0)
        printf("\nPromedio de números entre 1200 y 2000: %.2f", (float)sum1200_2000 / cant1200_2000);
    else
        printf("\nNo se ingresaron números entre 1200 y 2000");

    printf("\nCantidad de números pares entre 500 y 1200: %d", pares500_1200);

    return 0;
}





int EstaDentroDelRango(int num, int li, int ls)
{
    int dentro;

    if (num >= li && num <= ls)
        dentro = 1;
    else
        dentro = 0;

    return dentro;
}

int LeerYValidar(int li, int ls)
{
    int n, error = 0;

    do
    {
        if (error) // error != 0
            printf("El valor es incorrecto\n");

        printf("Ingrese un numero entre %d y %d: ", li, ls);
        scanf("%d", &n);

        error = 1;
    } while (!EstaDentroDelRango(n,li,ls)); //EstaDentroDelRango==0

    return n;
}