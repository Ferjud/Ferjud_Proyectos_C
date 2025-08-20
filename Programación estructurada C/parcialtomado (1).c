#include<stdio.h>
void funcion_a(int[],int,int);
float funcion_b(int[],int,int[]);
void funcion_c(int[]);
int ingreseDatoVal(int,int);

int main()
{
  int vecdep[29]={0}, nemp,cont=0,cantprod,veccant[29]={0},i;
  float promedio;
    for(i=0;i<=29;i++)
    {
      printf("ingrese depósito dónde trabaja el empleado %d",i+101);
      vecdep[i]=ingreseDatoVal(1,5);
     }
     
       printf("\nregistro de producción diaria\n");  
       
     do{
     printf("ingrese nro de empleado(101-130),0 finaliza:");   
     scanf("%d",&nemp);
      if((nemp<101 || nemp>130) && nemp!=0)
      {
        printf("Error.Ingrese un nro valido\n");
        }
     }while((nemp<101 || nemp>130) && nemp!=0);
     
      
    while(nemp!=0 && cont<30)
    {
       cont++;
       
       do{
       printf("ingrese cantidad producida:");
       scanf("%d",&cantprod);
       }while(cantprod<0);
       
        funcion_a(veccant,cantprod,nemp);
        
        promedio=funcion_b(vecdep,cantprod,veccant);
        
        do{
        printf("ingrese nro de empleado(101-130),0 finaliza:");
        scanf("%d",&nemp);
        if(nemp<101 || nemp>130 && nemp!=0)
        {
          printf("Error.Ingrese un número valido\n");
         }
        }while((nemp<101 || nemp>130) && nemp!=0);
        
     }
     
          if(cont==0)
          {
           printf("no se registraron datos");
           }
           else
           {
           
           for(i=0;i<=29;i++)
           {
             printf("\nempleado %d produjo: %d",i+101,veccant[i]);
             
             }
          
          printf("\npromedio de cantidad de unidades producidas por cada empleado del dep5: %.2f\n",promedio);    
  
          funcion_c(vecdep);
          
          }
          
      return 0;
      }
      
      
      
   int ingreseDatoVal (int liminf, int limsup)
   {
    int num;
    
     do{
      scanf("%d",&num);
      if(num<liminf || num>limsup)
      {
        printf("ingrese nuevamente dentro del rango");
        }
      }while(num<liminf || num>limsup);
      
      return num;
   }   
         
         
   void funcion_a(int vectorcant[],int cantproducida,int nroemp)
   {
     nroemp=nroemp-101;
     
     vectorcant[nroemp]=cantproducida;
     
     }
     
   float funcion_b(int vectordep[],int cantproducida,int vectorcant[])
   {
     int i,acu=0,contemp=0;
     float prom;
     
     for(i=0;i<=29;i++)
     {
       
       if(vectordep[i]==5)
       {
         contemp++;
         acu+=vectorcant[i];
         }
       
       }
       
       prom=(float)acu/contemp;
       
     return prom;
  
  }   
  
  
  
  void funcion_c(int vectordep[])
  {
    int i,cont1=0, cont2=0,cont3=0 ,cont4=0,cont5=0;
    
     for(i=0;i<=29;i++)
     {
       
       if(vectordep[i]==1)
       {
         cont1++;
         }
         
       if(vectordep[i]==2)
       {
         cont2++;
         }
      
       if(vectordep[i]==3)
       {
         cont3++;
         }
      
        
       if(vectordep[i]==4)
       {
         cont4++;
         }
         
       if(vectordep[i]==5)
       {
         cont5++;
         }
                    
     }
     
     printf("cantidad de empleados en cada deposito\n");
     
     printf("deposito1: %d \ndeposito2: %d \ndeposito3: %d \ndeposito4: %d \ndeposito5: %d",cont1,cont2,cont3,cont4,cont5);
     
   }

                         