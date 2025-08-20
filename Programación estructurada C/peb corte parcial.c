#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int cod_suc;
int cod_sec;
int nro_emp;
float sueldo;
}banco;

typedef struct
{
int cod_suc;
float prom;
}promedio;

int main()
{
    FILE *arch1,*arch2;
    banco info;
    promedio info2;
    int cod_aux=0,min,cod_min,band;
    float sueldo_total=0,sueldo_suc;

    arch1=fopen("registros.dat","rb");
    if(arch1==NULL)
    {
        printf("Error al abrir archivo");
        exit(1);
    }

    arch2=fopen("promedios.dat","wb");
    if(arch2==NULL)
    {
      printf("Error al abrir archivo");
      exit(1);
    }

    while(fread(&info,sizeof(info),1,arch1))
    {
        cod_aux=info.cod_suc;
        int cant_empleados=0;
        float sueldo_suc=0;

        do{
            cant_empleados++;
            sueldo_total+=info.sueldo;
            sueldo_suc+=info.sueldo;
            fread(&info,sizeof(info),1,arch1);
        }while(fread(&info,sizeof(info),1,arch1)&&(cod_aux==info.cod_suc));

        printf("Cantidad de empleados de la sucursal %d: %d",cod_aux,cant_empleados);

        info2.cod_suc=cod_aux;
        info2.prom=sueldo_suc/cant_empleados;

        if(band=0 || cant_empleados<min)
        {
            min=cant_empleados;
            band=1;
            cod_min=cod_aux;
        }
    }
    printf("Sueldo total de los empleados: %f",sueldo_total);
    printf("La sucursal con menor cantidad de empleados es: %d",cod_min);
    fwrite(&info2,sizeof(info2),1,arch2);
    fclose(arch1);
    fclose(arch2);
  return 0;
}