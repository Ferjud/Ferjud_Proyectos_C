#include <stdio.h>
#include <stdlib.h>

int busqueda(int vec[], int valor, int n);
void ordenar (int vec [], int vecnota[], int n);

int main()
{    int i,vec[60], vecnota[60], dni,cant,pos;
     i=0;
     printf("Ingrese dni");
     scanf("%d", &dni);
     while (dni >=0 && i < 60)
     {
         pos=busqueda(vec,dni,i);
         if( pos == -1)
         {
            vec[i]= dni;
             printf("Ingrese nota");
             scanf("%d", &vecnota[i]);
            i++;
         }
         printf("Ingrese dni");
         scanf("%d", &dni);
     }
     cant =i;
     ordenar( vec,vecnota,cant);

     printf ( "DNI \t\t NOTA\n");
     for ( i=0; i<cant;i++)
     {
         printf ( "%d \t %d\n", vec[i], vecnota[i]);
     }

    return 0;
}

int busqueda(int vec[], int valor, int n)
{
    int pos=-1, i=0;
    while ( i<n && pos == -1)
    {
        if ( valor == vec[i])
            pos=i;
        else
            i++;
      }
      return( pos);
}
void ordenar (int vec[], int vecnota[], int n)
{
    int i,j,aux;
    for (i=0;i<n-1;i++)
    {
      for (j=0;j<n-1-i;j++)
         if( vecnota[j] < vecnota[j+1])
    {
        aux=vecnota[j];
        vecnota[j]=vecnota[j+1];
        vecnota[j+1]=aux;
        
        aux=vec[j];
        vec[j]=vec[j+1];
        vec[j+1]=aux;
    }
    }
}

 