#include<stdio.h>

void funcion_a(int[], float[], int);
void funcion_b(int[], int[], int);
void funcion_c(int[]);
void funcion_d(float[], int[]);
int DatoVal(int, int);
int DatoVal2(int);
float DatoVal3(int);

int main()
{
   int cont = 0, codred, codstr, cantseg, veccodstr[1500] = {0}, vecseg[1500] = {0};
   int vecred[30] = {0}, veccontredes[30] = {0};
   float costoxseg, vecimp[1500] = {0}, vecpagos[30] = {0};

   printf("ingrese codigo de streamer(1000-9999), 999 finaliza:");
   codstr = DatoVal(999, 9999);

   while (codstr != 999 && cont < 1500)
   {
      printf("ingrese codigo de la red social en la que trabaja(5001-5030):");
      codred = DatoVal(5001, 5030);

      printf("ingrese cantidad de seguidores que tiene en la red social(mayor o igual a 0):");
      cantseg = DatoVal2(0);

      printf("ingrese costo pagado x seguidor por la colaboración (mayor a 0):");
      costoxseg = DatoVal3(0);

      veccodstr[cont] = codstr;
      vecimp[cont] = cantseg * costoxseg;
      vecseg[cont] = cantseg;
      vecred[codred - 5001] += cantseg;
      vecpagos[codred - 5001] += costoxseg * cantseg;
      veccontredes[codred - 5001]++;

      cont++;
      
      printf("ingrese codigo de streamer(1000-9999), 999 finaliza:");
      codstr = DatoVal(999, 9999);
   }

   if (cont > 0)
   {
      funcion_a(veccodstr, vecimp, cont);
      funcion_b(veccodstr, vecseg, cont);
      funcion_c(vecred);
      funcion_d(vecpagos, veccontredes);
   }
   else
   {
      printf("no se cargaron datos");
   }

   return 0;
}

int DatoVal(int liminf, int limsup)
{
   int n;
   do {
      scanf("%d", &n);
      if (n < liminf || n > limsup)
      {
         printf("Error. Ingrese valor valido\n");
      }
   } while (n < liminf || n > limsup);
   return n;
}

int DatoVal2(int lim)
{
   int num;
   do {
      scanf("%d", &num);
      if (num < lim)
      {
         printf("Error. Ingrese valor valido\n");
      }
   } while (num < lim);
   return num;
}

float DatoVal3(int limite)
{
   float numero;
   do {
      scanf("%f", &numero);
      if (numero <= limite)
      {
         printf("Error. Ingrese valor valido\n");
      }
   } while (numero <= limite);
   return numero;
}

void funcion_a(int vectorcodstr[], float vectorimp[], int cont1)
{
   for (int i = 0; i < cont1; i++)
   {
      printf("streamer %d\t importe: %.2f\n", vectorcodstr[i], vectorimp[i]);
   }
}

void funcion_b(int vectorcodstr[], int vectorseg[], int cont1)
{
   int vectormayorseg[1500] = {0}, mayorcant = 0, band = 0;
   
   for (int i = 0; i < cont1; i++)
   {
      if (band == 0 || vectorseg[i] >= mayorcant)
      {
         mayorcant = vectorseg[i];
         band = 1;
      }
   }

   for (int i = 0; i < cont1; i++)
   {
      if (mayorcant == vectorseg[i])
      {
         vectormayorseg[i] = vectorcodstr[i];
      }
   }

   for (int i = 0; i < cont1; i++)
   {
      if (vectormayorseg[i] != 0)
      {
         printf("codigo de streamer/s con mayor cantidad de seguidores en transmisiones: %d\n", vectormayorseg[i]);
      }
   }
}

void funcion_c(int vecredes[])
{
   int contredes = 0;

   for (int i = 0; i < 30; i++)
   {
      if (vecredes[i] < 100000)
      {
         contredes++;
      }
   }

   if (contredes > 0)
   {
      printf("porcentaje de redes con menos de 100k seguidores: %.2f\n", ((float)contredes / 30) * 100);
   }
}

void funcion_d(float vectorpagos[], int vectorcontredes[])
{
   float vectorprom[30] = {0};

   for (int i = 0; i < 30; i++)
   {
      if (vectorcontredes[i] > 0)
      {
         vectorprom[i] = vectorpagos[i] / vectorcontredes[i];
      }
      else
      {
         vectorprom[i] = 0;
      }
   }

   for (int i = 0; i < 30; i++)
   {
      printf("promedio de dinero pagado por la red social %d: %.2f\n", i + 5001, vectorprom[i]);
   }
}