#include<stdio.h>

int DatoVal(int, int);
void ordenar(int [], int [], int);

int main()
{
int mat[23][15]={{0}}, votos, vecprovincias[23]={0}, veclistadoce[23]={0};
int lista, i, j, band=0, vecvotxprov[23]={0}, vecvotxlista[15]={0};
int menorcant, mayorvotos, ganadora, prov;

printf("ingrese numero de provincia\n");
printf("1-23, con 0 finaliza:");
prov=DatoVal(0,23);

while(prov!=0)
{
    printf("ingrese numero de lista (1-15), con 0 finaliza: ");
    lista=DatoVal(1,15);
    
    do
    {
    printf("ingrese cantidad de votos: ");
    scanf("%d", &votos);
    
    if (votos<=0)
        {
            printf("cantidad incorrecta. Vuelva a ingresar");
        }
    }while(votos<=0);
    
    mat[prov-1][lista-1]=votos;
    
    printf("ingrese numero de provincia: ");
    printf("1-23, con 0 finaliza");
    prov=DatoVal(0,23);
}

for(i=0;i<23;i++)
{
    for(j=0;j<15;j++)
    {
        if(band==0 || (mat[i][j]<menorcant && mat[i][j]>0))
        {
            menorcant=mat[i][j];
            band=1;
        }
    }        
}
printf("datos de quienes tienen menor cantidad de votos: %d", menorcant);
printf("numero de provincia\t numero de lista\n");
for(i=0;i<23;i++)
{
    for(j=0;j<15;j++)
    {
        if(mat[i][j]==menorcant)
        {
            printf("%d\t    %d\n", i+1, j+1);
        }    
    }      
}

for (i=0;i<23;i++)
{
    for(j=0;j<15;j++)
    {
        vecvotxprov[i]+=mat[i][j];
    }
printf("\nvotos de la provincia %d: %d\n", i+1, vecvotxprov[i]);
}
    
 for (j=0;j<15;j++)
 {
     for(i=0;i<23;i++)
     {
         vecvotxlista[j]+=mat[i][j];
     }
     band=0;
     if(band==0 || vecvotxlista[j]>mayorvotos)
     {
     mayorvotos=vecvotxlista[j];
     ganadora=j+1;
     }
 }
 printf("\nla lista ganadora es: %d", ganadora);
 
 
 for(i=0;i<23;i++)
 {
   veclistadoce[i]=mat[i][11];
   }
   
   for(i=0;i<23;i++)
   {
     vecprovincias[i]=i+1;
     }
     
   ordenar(veclistadoce,vecprovincias,23);
   
   printf("\t\t lista numero 12\n\n");
   printf("\tprovincia      cantidad de votos\n\n");
   
   for(i=0;i<23;i++)
   {
     printf("\t%d\t\t%d\n\n",vecprovincias[i],veclistadoce[i]);
     }
     
   return 0;
 }    
 
 int DatoVal(int liminf, int limsup)
 {
 int n;
 do
 {
 scanf("%d", &n);
 if (n<liminf || n>limsup)
 {
     printf("error, vuelva a ingresar");
 }
 }while(n<liminf || n>limsup);
 
 return n;
 }
 
 void ordenar(int vecdoce[], int vecprov[], int ce)
 {
 int i, j, aux;
 
 for (i=0;i<ce-1;i++)
 {
     for(j=0;j<ce-1-i;j++)
     {
         if(vecdoce[j]<vecdoce[j+1])
         {
             aux=vecdoce[j];
             vecdoce[j]=vecdoce[j+1];
             vecdoce[j+1]=aux;
             
             aux=vecprov[j];
             vecprov[j]=vecprov[j+1];
             vecprov[j+1]=aux;
         }
     }
 }
 }