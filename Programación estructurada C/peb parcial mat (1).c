#include<stdio.h>

int DatoVal(int, int);
void ordenar(int [], int [], int);

int main()
{
    int mat[23][15]={{0}}, votos, vecprovincias[23]={0}, veclistadoce[23]={0};
    int lista, i, j, band=0, vecvotxprov[23]={0}, vecvotxlista[15]={0};
    int menorcant = -1, mayorvotos = 0, ganadora = 0, prov;

    printf("Ingrese número de provincia\n");
    printf("1-23, con 0 finaliza: ");
    prov = DatoVal(0, 23);

    while (prov != 0)
    {
        printf("Ingrese número de lista (1-15), con 0 finaliza: ");
        lista = DatoVal(1, 15);

        do
        {
            printf("Ingrese cantidad de votos: ");
            scanf("%d", &votos);

            if (votos <= 0)
            {
                printf("Cantidad incorrecta. Vuelva a ingresar\n");
            }
        } while (votos <= 0);

        mat[prov-1][lista-1] += votos;  // Guardar votos en la columna de la lista

        printf("Ingrese número de provincia: ");
        printf("1-23, con 0 finaliza: ");
        prov = DatoVal(0, 23);
    }

    // Buscar la menor cantidad de votos
    for (i = 0; i < 23; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if ((mat[i][j] > 0) && (band == 0 || mat[i][j] < menorcant))
            {
                menorcant = mat[i][j];
                band = 1;
            }
        }
    }
    
    printf("Datos de quienes tienen menor cantidad de votos con %d\n", menorcant);
    printf("Número de provincia\tNúmero de lista\n");
    
    for (i = 0; i < 23; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (mat[i][j] == menorcant)
            {
                printf("\t%d\t\t\t%d\n", i+1, j+1);
            }
        }
    }

    // Sumar votos por provincia
    for (i = 0; i < 23; i++)
    {
        for (j = 0; j < 15; j++)
        {
            vecvotxprov[i] += mat[i][j];
        }
        printf("\nVotos de la provincia %d: %d\n", i+1, vecvotxprov[i]);
    }

    // Sumar votos por lista y determinar la lista ganadora
    for (j = 0; j < 15; j++)
    {
        for (i = 0; i < 23; i++)
        {
            vecvotxlista[j] += mat[i][j];
        }

        if (vecvotxlista[j] > mayorvotos)
        {
            mayorvotos = vecvotxlista[j];
            ganadora = j + 1;
        }
    }
    
    printf("\nLa lista ganadora es: %d\n\n", ganadora);

    // Copiar votos de la lista 12
    for (i = 0; i < 23; i++)
    {
        veclistadoce[i] = mat[i][11];  // Lista 12 es la columna 11
    }

    // Copiar provincias
    for (i = 0; i < 23; i++)
    {
        vecprovincias[i] = i + 1;
    }

    // Ordenar las provincias según los votos de la lista 12
    ordenar(veclistadoce, vecprovincias, 23);

    printf("\t\t Lista número 12\n\n");
    printf("\tProvincia      Cantidad de votos\n\n");

    for (i = 0; i < 23; i++)
    {
        printf("\t%d\t\t%d\n\n", vecprovincias[i], veclistadoce[i]);
    }

    return 0;
}

int DatoVal(int liminf, int limsup)
{
    int n;
    do
    {
        scanf("%d", &n);
        if (n < liminf || n > limsup)
        {
            printf("Error, vuelva a ingresar\n");
        }
    } while (n < liminf || n > limsup);

    return n;
}

void ordenar(int vecdoce[], int vecprov[], int ce)
{
    int i, j, aux;

    for (i = 0; i < ce-1; i++)
    {
        for (j = 0; j < ce-1-i; j++)
        {
            if (vecdoce[j] < vecdoce[j+1])
            {
                aux = vecdoce[j];
                vecdoce[j] = vecdoce[j+1];
                vecdoce[j+1] = aux;

                aux = vecprov[j];
                vecprov[j] = vecprov[j+1];
                vecprov[j+1] = aux;
            }
        }
    }
}