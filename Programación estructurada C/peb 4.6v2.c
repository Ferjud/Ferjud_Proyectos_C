#include<stdio.h>
#include<string.h>

 
struct pilotos
{
  char nombre[40];
  char escuderia[40];
  int posicion;
 };
struct carreras
{
  struct pilotos lista[20];
  };
  
  
 void cargapilotos(struct carreras[],struct pilotos[],int,int);
 void infocarrera(struct carreras[]);
 void ordenarPilotos(struct pilotos[],int);
 int busq(struct pilotos[],char[],int,int,int);
 
 
 int main()
 {
   struct carreras v[23];
   struct pilotos lista[20];
   
  cargapilotos(v,lista,23,20);
  ordenarPilotos(lista,20);
  infocarrera(v);
  
  return 0;
  }
  
 
  
  void cargapilotos(struct carreras v[],struct pilotos lista[],int n,int k)
  {
    printf("CARGA DE PILOTOS\n\n");
    int i,j;
    
    for(i=0;i<n;i++)
    {
      printf("CARRERA %d\n\n",i+1);
     for(j=0;j<k;j++)
     {
      printf("piloto %d",j+1);
      
      do{
      printf("\nnombre: ");
      fflush(stdin);
      fgets(v[i].lista[j].nombre,40,stdin);
      v[i].lista[j].nombre[strlen(v[i].lista[j].nombre)-1]='\0';
      printf("posición: ");
      scanf("%d",&v[i].lista[j].posicion);
      getchar();
      if(busq(lista,v[i].lista[j].nombre,v[i].lista[j].posicion,i,j)!=-1)
      {
       printf("dato repetido. Vuelva a ingresar: ");
        }
      }while(busq(lista,v[i].lista[j].nombre,v[i].lista[j].posicion,i,j)!=-1);
     }
    }    
  }  
       
       
  void ordenarPilotos(struct pilotos lista[], int tam)
  {
    int i, j;
    struct pilotos aux;
    
    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - 1 - i; j++)
        {
            if (lista[j].posicion > lista[j + 1].posicion)  // Comparar las posiciones
            {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
  }    
       
       
       
       
  void infocarrera(struct carreras v[])
  {
    int valor,i;
   
    do{
    printf("ingrese número de carrera: ");    
    scanf("%d",&valor);
    if(valor<1 || valor>23)
    {
     printf("número de carrera incorecto. ingrese nuevamente\n");
     }
    }while(valor<1 || valor>23);
    
    while(valor!=0)
    {
     for(i=0;i<10;i++)
     {
       if(v[valor-1].lista[i].posicion<=10)
       {
        printf("%d  %s\n",v[valor-1].lista[i].posicion,v[valor-1].lista[i].nombre);
         }
      }
      
    do{
    printf("ingrese número de carrera: ");    
    scanf("%d",&valor);
    if(valor<1 || valor>23)
    {
     printf("número de carrera incorecto. ingrese nuevamente\n");
     }
    }while(valor<1 || valor>23);
    
   } 
  }
  
   
   
   
  
  int busq(struct pilotos lista[], char nombrebuscar[], int posbuscar, int n, int k) 
  {
    int pos = -1, i = 0, j = 0;

    while (i < n) 
    {
        j = 0; // Reinicia j para cada nueva carrera
      
        while (j < k) 
        {
            if (strcmp(lista[j].nombre, nombrebuscar) == 0 || lista[j].posicion == posbuscar) 
            {
                pos = 0; // Se encontró un duplicado
            }
            j++;
        }
        i++;
    }
    return pos; // Retorna la posición o -1 si no se encontró
}  
     