#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dni;
    char nomyap[21];
    int pagado;
} Sanot;

typedef struct 
{
    int telefono;
    int dni;
    char nomyap[21];
} Sfut;

int main() 
{
    int op, band = 0, numdni, bytes, cant_registros;
    Sanot anotados;
    Sfut futuros;
    FILE *archint, *archfut;

    archint = fopen("INSCRIPTOS.dat", "r+b");
    if (archint == NULL) 
    {
        printf("error al abrir el archivo");
        exit(1);
    }

    archfut = fopen("interesados.dat", "r+b");
    if (archfut == NULL) 
    {
        printf("error al abrir el archivo");
        exit(1);
    }

    printf("ingrese DNI:");
    scanf("%d", &numdni);

    while (numdni >= 0) 
    {
        band = 0;
        rewind(archint);

        fseek(archint, 0, SEEK_END);
        bytes = ftell(archint); // Retorna la cantidad de bytes desde el comienzo del archivo
        cant_registros = bytes / sizeof(anotados);

        rewind(archint);
        while (fread(&anotados, sizeof(anotados), 1, archint) == 1 && band == 0) 
        {
            if (anotados.dni == numdni) 
            {
                if (anotados.pagado == 0) 
                {
                    printf("¿desea registrar el pago? (S-si, N-no): ");
                    getchar(); // Limpia el buffer
                    scanf("%c", &op);
                    if (op == 'S') 
                    {
                        anotados.pagado = 1;
                        fseek(archint, -sizeof(anotados), SEEK_CUR);
                        fwrite(&anotados, sizeof(anotados), 1, archint);
                        fflush(archint);
                    }
                }
                band = 1; // Para salir del while al encontrar el DNI
            }
        }

        if (band == 0) 
        { // No encontrado en INSCRIPTOS.dat
            if (cant_registros <= 60) 
            {
                printf("¿quiere ser inscripto ahora? (S-si, N-no): ");
                getchar();
                scanf("%c", &op);
                if (op == 'S') 
                {
                    anotados.dni = numdni;
                    printf("ingrese nombre y apellido: ");
                    getchar();
                    fgets(anotados.nomyap, 21, stdin);
                    anotados.pagado = 0;
                    fseek(archint, 0, SEEK_END);
                    fwrite(&anotados, sizeof(anotados), 1, archint);
                    fflush(archint);
                }
            } 
            else 
             {
                printf("Curso lleno. ¿Desea ser anotado a la lista de espera de próximos cursos? (S-si, N-no): ");
                getchar();
                scanf("%c", &op);
                if (op == 'S') 
                {
                    printf("ingrese su teléfono: ");
                    scanf("%d", &futuros.telefono);
                    printf("ingrese nombre y apellido: ");
                    getchar();
                    fgets(futuros.nomyap, 21, stdin);
                    futuros.dni = numdni;
                    fseek(archfut, 0, SEEK_END);
                    fwrite(&futuros, sizeof(futuros), 1, archfut);
                    fflush(archfut);
                }
            }
        }

        printf("Ingrese DNI (negativo para terminar): ");
        scanf("%d", &numdni);
    }

    fclose(archint);
    fclose(archfut);
    printf("Proceso de inscripción finalizado.\n");
    return 0;
}