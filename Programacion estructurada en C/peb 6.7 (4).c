#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codart;
    char descripcion[51];
    int stock;
} Sprod;

typedef struct {
    int codart;
    int cantidad_faltante;
} SFaltante;

int main() {
    Sprod prod;
    SFaltante faltante_prod;
    int cod, cantvend, faltante;
    int encontrado;
    FILE *archstock, *archfalta;

    archstock = fopen("stock.dat", "r+b"); // Abrir en modo lectura y escritura binaria
    if (archstock == NULL) 
    {
        printf("Error al abrir el archivo stock.dat\n");
        exit(1);
     }

    archfalta = fopen("faltantes.dat", "a+b"); // Abrir en modo añadir y lectura binaria
    if (archfalta == NULL) 
    {
        printf("Error al abrir el archivo faltantes.dat\n");
        fclose(archstock);
        exit(1);
     }

    printf("VENTAS\n\n");
    printf("Ingrese código de artículo (0 para terminar): ");
    scanf("%d", &cod);

    while (cod != 0) 
    {
        // Reiniciar band y buscar el artículo
        encontrado = 0; // Variable para saber si se encontró el artículo
        fseek(archstock, 0, SEEK_SET); // Ir al principio del archivo

        while (fread(&prod, sizeof(prod), 1, archstock) == 1 && encontrado==0) 
        {
            if (prod.codart == cod) 
            {
                encontrado = 1; // Se encontró el artículo
                printf("Ingrese cantidad vendida: ");
                scanf("%d", &cantvend);

                if (cantvend <= prod.stock) 
                {
                    prod.stock -= cantvend; // Restar la cantidad vendida
                 } 
                else 
                 {
                    faltante = cantvend - prod.stock; // Calcular faltante
                    prod.stock = 0; // Agregar a faltante y vaciar stock

                    // Verificar si ya existe un registro de faltante para este artículo
                    
                    int registro_existe = 0;
                    
                    fseek(archfalta, 0, SEEK_SET); // Ir al principio del archivo de faltantes

                    while (fread(&faltante_prod, sizeof(faltante_prod), 1, archfalta) == 1 && registro_existe==0) 
                    {
                        if (faltante_prod.codart == cod) 
                        {
                            faltante_prod.cantidad_faltante += faltante; // Incrementar cantidad faltante
                            registro_existe = 1;
                        }
                     }

                    // Si no existe el registro, crearlo
                    if (registro_existe==0) 
                    {
                        faltante_prod.codart = cod;
                        faltante_prod.cantidad_faltante = faltante;
                     }

                    // Escribir el registro de faltante
                    fseek(archfalta, 0, SEEK_END); // Ir al final del archivo para añadir
                    fwrite(&faltante_prod, sizeof(faltante_prod), 1, archfalta);
                }

                // Volver a posicionar en el archivo para actualizar el stock
                fseek(archstock, -sizeof(prod), SEEK_CUR); // Regresar a la posición del producto
                fwrite(&prod, sizeof(prod), 1, archstock); // Escribir el producto actualizado
                
            }
        }

        if (encontrado==0) 
        {
            printf("Código de artículo no encontrado.\n");
         }

        printf("Ingrese código de artículo (0 para terminar): ");
        scanf("%d", &cod);
    }

    fclose(archstock); // Cerrar archivos
    fclose(archfalta); // Cerrar archivos
    printf("Proceso de ventas finalizado.\n");
    return 0;
}