#include<stdio.h>
int diasmes(int,int);
int validarfechas(int,int,int);
void sumardiafecha(int,int,int);
void listados(int[],float[],int[],int,float,int,int);
void vecimpvendido(float[],float,int,int);
void vecfacemitidas(int[],int,int);



int main()
{
   int factura,cod,cont=0,i;
   float importe;
   int vectorcod[12]={1,2,3,4,5,6,7,8,9,10,11,12};
   float vectorimpvend[12]={0};
   int vectorcantfac[12]={0};
   int dias, meses, años,sumaimportes=0,fecha_valida;

 printf("ingrese fecha\n");
 do
 {
 
   do
   {
   printf("dia:");
   scanf(" %d",&dias);
   if(!(dias>=1 && dias<=31))
   {
    printf("error.ingrese dia valido");
   }
   }while(!(dias>=1 && dias<=31));
  
 
   do
   {
   printf("mes:");
   scanf(" %d",&meses);
   if(!(meses>=1 && meses<=12))
   {
    printf("error.ingrese mes valido");
   }
   }while(!(meses>=1 && meses<=12));
 
 
   do
   {
   printf("año:");
   scanf(" %d",&años);
   if(!(años>=1582 && años<=2024))
   {
   printf("error.ingrese año valido");
   }
   }while(!(años>=1582 && años<=2024));
 
       fecha_valida = validarfechas(dias, meses, años);
       
        if (fecha_valida==1) 
        {
            printf("Fecha: %02d/%02d/%04d\n", dias, meses, años);
            
        } 
      
        else 
        {
            printf("La fecha es incorrecta. Por favor, intente de nuevo.\n");
        }
    } while (fecha_valida==0);
   
   
    do{
    printf("ingrese numero de factura(entero mayor que 0):");
    scanf(" %d",&factura);
     if(factura<0)
     {
        printf("ingrese factura valida");
        }
    }while(factura<0);

   
   
   
      while(factura!=0)
      {
        cont++;
        
        do{
        printf("ingrese codigo de vendedor(entero de 1 a 12):");
        scanf(" %d",&cod);
        if(!(cod>=1 && cod<=12) )
         {
          printf("ingrese codigo valido");
           }
       }while((!(cod>=1 && cod<=12) ));
       
       do{
       printf("ingrese importe de venta(mayor a 0):");
       scanf(" %f",&importe);
        if(importe<0)
        {
          printf("ingrese importe valido");
          }
       }while(importe<0);
       
       sumaimportes+=importe;
            
            listados(vectorcod,vectorimpvend,vectorcantfac,cod,importe,factura,12);
       
       do{
       printf("ingrese numero de factura(entero mayor que 0):");
       scanf(" %d",&factura);
       if(factura<0)
      {
        printf("ingrese factura valida");
        }
      }while(factura<0);
    
       
     }         
      
          if(cont>0)  
          {
              printf("nro de vendedor\t importe vendido\t cantidad de facturas\n");
              
              for(i=0;i<12;i++)
              {
                
                printf("%d\t %.2f\t %d\n", vectorcod[i],vectorimpvend[i],vectorcantfac[i]);
                
                printf("TOTAL\t %.2f\t %d",sumaimportes,cont);
                
                 
                 }
              
              }
                
            else
            {
             printf("no se registraron ventas");
              }  
     
    
    
   return 0;
   }
    
        
       
       
 void listados(int veccod[],float vecimpv[],int veccantfac[],int codigo,float imp,int facturas,int ce)
    {
       int i;
         
         
       vecimpvendido(vecimpv,imp,codigo,ce);
      
       vecfacemitidas(veccantfac,codigo,ce);
           
        
       } 
        
        
        
  void vecimpvendido(float vecimpv[],float imp,int codigo,int ce)
  {
    int i;
    
         codigo=codigo-1;
         
         for(i=0;i<ce;i++)
         {
            if(codigo==i)
            {
              vecimpv[i]+=imp;
              }
         
          }
        
        }   
           

 void vecfacemitidas(int veccantfac[],int codigo,int ce)
   {
     int i;
     
     codigo=codigo-1;
     
      for(i=0;i<ce;i++)
      {
        if(codigo==i)
        {
          veccantfac[i]++;
          }
       }   
       
     }   
     
     
  int validarfechas(int diaa,int mess,int añoo)
  {
    int retorno;
       
       if(diaa<=diasmes(mess,añoo))
       {
        retorno=1;
        }
        else
        {
        retorno=0;
        }
      
      return retorno;
      }  
   
  
  int diasmes(int mes,int año)
  {
 
  int dia;
  
   if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
   {
     dia=31;
     }
   
    else
    if(mes==4 || mes==6 || mes==9 || mes==11)
    {
     dia=30;
     }
  
    else
    if (mes == 2) 
    {
        if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) 
        {
            dia = 29;  // Año bisiesto
        } 
        else 
        {
            dia = 28;  // Año no bisiesto
        }
     }
     
     return dia;
     }
     
  
      
        