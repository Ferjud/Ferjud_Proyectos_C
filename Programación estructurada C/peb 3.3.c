#include<stdio.h>
#include<string.h>
int buscar(char alumnosNombre[50][100],char nombre[100],int cant);
void ordenar(char alumnosNombre[50][100],long int dni[100],int cant);
void listar(char alumnosNombre[50][100],long int dni[100],int cant);

int main()
{
 char alumnosNombre[50][100];
 long int alumnosDni[50];
 char nombre[100];
 int i=0, cant,x;

printf ("Apellido y Nombre:");
fgets(nombre,100,stdin);

nombre[strlen(nombre)-1]='\0';

while(strcmpi(nombre,"FIN")!=0 && i<50)
    {
        strcpy(alumnosNombre[i],nombre);
        printf("Ingrese Dni:");
        scanf("%ld",&alumnosDni[i]);fflush(stdin);
        printf ("\nApellido y Nombre:");
        fgets(nombre,100,stdin);
        fflush(stdin);
        nombre[strlen(nombre)-1]='\0';
        i++;
    }
    cant=i;

 for(i=0;i<cant;i++)
 printf("\n%s",alumnosNombre[i]);

 printf("\nIngrese Apellido y Nombre completo a buscar (para finalizar ingresar NOBUSCARMAS):");
 fgets(nombre,100,stdin);
 nombre[strlen(nombre)-1]='\0';

while(strcmpi(nombre,"NOBUSCARMAS")!=0)
      {
          x=buscar(alumnosNombre,nombre,cant);
          if(x==-1)
          {
            printf("\n No existe alumno con ese nombre");
            }
          else
           {
            printf("%ld  %s\n",alumnosDni[x],nombre);
             }
            printf("\nIngrese Apellido y Nombre completo a buscar (para finalizar ingresar NOBUSCARMAS):");
            fgets(nombre,100,stdin);
            nombre[strlen(nombre)-1]='\0';

      }
ordenar(alumnosNombre,alumnosDni,cant);
listar(alumnosNombre,alumnosDni,cant);
return 1;
}






int buscar(char alumnosNombre[50][100],char nombre[100],int cant)
{
   
   printf("\El resultado de la busqueda es:");
   
    int i=0,pos=-1;
    
    while(i<cant && pos==-1)
    {
        if(strcmpi(alumnosNombre[i],nombre)==0)
         {
            pos=i;
            }
        else
          {
            i++;
            }
    }
    return pos;
}


void ordenar(char alumnosNombre[50][100],long int dni[100],int cant)
{
    int i,j;
    long int AuxDNI;
    char AuxNombre[100];
    for (i=0;i<cant-1;i++)
        for(j=0;j<cant-1-i;j++)
    {
        if (strcmpi(alumnosNombre[j],alumnosNombre[j+1])>=0)
        { 
          strcpy(AuxNombre,alumnosNombre[j]);
          strcpy(alumnosNombre[j], alumnosNombre[j+1]);
          strcpy(alumnosNombre[j+1],AuxNombre);
          AuxDNI=dni[j];
          dni[j]=dni[j+1];
          dni[j+1]=AuxDNI;
        }
    }
}

void listar (char alumnosNombre[50][100],long int dni[100],int cant)
{
    int i;
    printf("Listado por Orden Alfabetico\n");
    for(i=0;i<cant;i++)
    {
        printf("%s %ld\n",alumnosNombre[i],dni[i]);
    }
}