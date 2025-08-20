#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dni;
    char nomApe[81];
    int nota1;
    int nota2;
    float notaProm;
}sAlumnos;

void lectura(void);


int main(){
     sAlumnos salu;
     FILE * arch;
    arch = fopen("ALUMNOS.DAT", "wb");
  if(arch==NULL){
     printf("Error al abrir el archivo alumnos.dat\n");
     exit(1);}

   printf("Ingngrese dni");
      scanf("%d", &salu.dni);

   while(salu.dni!=0)   {
      printf("Nombre");
       fflush(stdin);
       gets(salu.nomApe);
        printf("Nota 1:");
      scanf("%d", &salu.nota1);
     printf("Nota 2:");
      scanf("%d", &salu.nota2);
    salu.notaProm=(salu.nota1 + salu.nota2)/2.0;

     fwrite(&salu,sizeof(salu),1,arch );

   printf("Ingngrese dni");
    scanf("%d", &salu.dni);

    }
    fclose(arch);
   lectura();

   return 0;
   }
void lectura (void)
{
     sAlumnos salu;
     FILE * arch;
    arch = fopen("ALUMNOS.DAT", "rb");
  if(arch==NULL){
     printf("Error al abrir el archivo alumnos.dat\n");
     exit(1);}

    fread(&salu,sizeof(salu),1,arch );
while (!feof(arch))
{ printf("%d %s %d %d %.2f\n",salu.dni,salu.nomApe,salu.nota1,salu.nota2,salu.notaProm);
  fread(&salu,sizeof(salu),1,arch );

}
fclose(arch);