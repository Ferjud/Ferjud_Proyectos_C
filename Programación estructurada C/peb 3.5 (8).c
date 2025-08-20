#include<stdio.h>
#include<string.h>
int diasmes(int,int);
int validarfechas(int,int,int);
int incrementarDia(int,int,int,int);

int main()
{
 char vecpatentes[30][8];
 char patente[8];
 int dia,mes,anio,diasalq[30]={0},j,i,fechadevolucion[30]={0};
 float cotdol,precioalq[30]={0};
 float rec_pesos=0;
 
 
 do
 {
  printf("ingrese día: ");
  scanf("%d",&dia);
  printf("ingrese mes: ");
  scanf("%d",&mes);
  printf("ingrese anio: ");
  scanf("%d",&anio);
  
  
  if(validarfechas(dia,mes,anio) == 0)
   {
    printf("fecha incorrecta. Ingrese nuevamente\n");
     }
    }while(validarfechas(dia,mes,anio) == 0);
    
   
   printf("ingrese cotización del dólar hoy: "); 
   scanf("%f",&cotdol);
   getchar();
   
   printf("VENTAS DEL DIA\n\n");
   
   printf("ingrese patente(FINDIA para finalizar): ");
   fgets(patente,8,stdin);
   
   patente[strlen(patente)-1]="\0";
   
   
   
   while(strcmp(patente,"FINDIA")!=0 && i<30)
   {
   
     strcpy(vecpatentes[i],patente);
   
     do
     {
     printf("cantidad de días del alquiler: ");
     scanf("%d",&diasalq[i]);
     if(diasalq[i]<0)
     {
      printf("días incorrectos. ingrese nuevamente\n");
      }
     }while(diasalq[i]<0);
     
     fechadevolucion[i]=incrementarDia(dia,mes,anio,diasalq[i]);
     
     
     
     do
     {
     printf("ingrese precio diario del alquiler en dólares: ");
     scanf("%f",&precioalq[i]);
     if(precioalq[i]<0)
     {
      printf("precio incorrecto. ingrese nuevamente\n");
      }
     }while(precioalq[i]<0);
     
     rec_pesos+=precioalq[i]*diasalq[i];
     
     i++;
    
    printf("ingrese patente(FINDIA para finalizar): ");
    fgets(patente,8,stdin);
    fflush(stdin);
    patente[strlen(patente)-1]="\0";
   }
   
   printf("porcentaje de autos alquilados: %.2f",(i/30)*100);
   
   printf("\t\tALQUILER DE AUTOS DEL DIA: %d/%d/%d",dia,mes,anio);
   printf("\n\t\t COTIZACIÓN DEL DÓLAR: %.2f\n",cotdol);
   
   
   printf("NRO. DE AUTO\t DIAS DE ALQUILER\t PRECIO PESOS\t FECHA DEVOLUCIÓN\n\n");
   
   for(j=0;j<i;j++)
   {
        dia = fechadevolucion[j] % 100;
        fechadevolucion[j] /= 100;
        mes = fechadevolucion[j] % 100;
        fechadevolucion[j] /= 100;
        anio = fechadevolucion[j];
   
    printf("\t%s\t\t %d\t\t %.2f\t\t %d/%d/%d",vecpatentes[j],diasalq[j],precioalq[j],dia,mes,anio); 
     }
     
   printf("total recaudado x alquiler en pesos:\t%.2f",rec_pesos);  
   printf("total recaudado x alquiler en dólares:\t%.2f",rec_pesos/cotdol); 
   
   return 0;
   } 
   
   
   
   
   
   
   
   
   
   
   
 int validarfechas(int diaa, int mess, int añoo) 
 {
    int retorno;
    if ((diaa>= 1 && diaa <= diasmes(mess, añoo)) && (mess>=1 && mess<=12) && (añoo>=2024))
    {
        retorno = 1;
    }
     else
     {
        retorno = 0;
    }
    return retorno;
  }

 int diasmes(int mes, int año) 
 {
    int dia;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) 
    {
        dia = 31;
    } 
   
    else
     if (mes == 4 || mes == 6 || mes == 9 || mes == 11) 
     {
      
        dia = 30;
    } 
    else
     if (mes == 2) 
    {
        if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) 
        {
            dia = 29; // Año bisiesto
        } 
        else 
        {
            dia = 28; // Año no bisiesto
        }
    }

    return dia;
  }




int incrementarDia(int dia, int mes, int anio, int n)
{
    for (int i = 0; i < n; i++)
    {
        dia++;
        if (dia > diasmes(anio, mes))
        {
            dia = 1;
            mes++;
            if (mes > 12)
            {
                mes = 1;
                anio++;
            }
        }
    }

    // Combinar día, mes y año en un solo número para devolver
    return anio * 10000 + mes * 100 + dia;
}