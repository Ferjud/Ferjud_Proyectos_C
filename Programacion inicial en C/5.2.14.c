#include <stdio.h>
#include <stlib.h>
#include <ctype.h>

int main() {
  
    float sueldo;
    float sueldofinal = 0, mayorsueldo = 0;
    int legajo, antiguedad, categoria, conth = 0, contm = 0, contant = 0, legajomayorsueldo = -1, sumaleg = 0;
    char sexo;

    do {
        printf("Ingrese legajo entre 1000 y 5000 (0 para terminar): ");
        scanf("%d", &legajo);
    } while (legajo != 0 && (legajo < 1000 || legajo > 5000));

    sumaleg += legajo;

    while (legajo != 0) {
        do {
            printf("Ingrese sueldo basico (mayor a 1000): ");
            scanf("%f", &sueldo);
        } while (sueldo <= 1000);

        do {
            printf("Ingrese años de antiguedad (mayor o igual a 0): ");
            scanf("%d", &antiguedad);
        } while (antiguedad < 0);

        do {
            printf("Ingrese sexo (m o f): ");
            fflush(stdin);
            scanf(" %c", &sexo);
            sexo = toupper(sexo);
        } while (sexo != 'M' && sexo != 'F');

        if (sexo == 'M') {
            contm++;
        } else {
            conth++;
        }

        do {
            printf("Ingrese categoria (1-5): ");
            scanf("%d", &categoria);
        } while (categoria < 1 || categoria > 5);

        switch (categoria) {
            case 1:
                sueldofinal = sueldo;
                break;
            case 2:
            case 3:
                sueldofinal = sueldo + 500;
                break;
            case 4:
                sueldofinal = sueldo + ((sueldo * 10) / 100);
                break;
            case 5:
                sueldofinal = sueldo + ((sueldo * 30) / 100);
                break;
        }

        if (antiguedad > 10) {
            contant++;
            sueldofinal += ((sueldo * 10) / 100);
        }

        printf("El sueldo final es: %.2f\n", sueldofinal);

        if (sueldofinal > mayorsueldo) {
            mayorsueldo = sueldofinal;
            legajomayorsueldo = legajo;
        }

        do {
            printf("Ingrese legajo entre 1000 y 5000 (0 para terminar): ");
            scanf("%d", &legajo);
        } while (legajo != 0 && (legajo < 1000 || legajo > 5000));

        sumaleg += legajo;
    }

    if (sumaleg == 0) {
        printf("No se ingresaron empleados\n");
    } else {
        printf("Cantidad de mujeres: %d\n", contm);
        printf("Cantidad de hombres: %d\n", conth);
        printf("El empleado legajo %d tiene el mayor sueldo: %.2f\n", legajomayorsueldo, mayorsueldo);
        printf("Empleados con más de 10 años de antigüedad: %d\n", contant);
    }

    return 0;
}