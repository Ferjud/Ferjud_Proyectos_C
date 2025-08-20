#include<stdio.h>

 struct alumno
 {
   int dni;
   char apnom[81];
   float n1;
   float n2;
   float prom;
   }
 
 int ingreso(struct alumno[],int);
 
 void informe_promo(struct alumno[],int);
 
 void resultado(struct alumno[],int);
 
 int main()
 {
  struct alumno v[80],int cant;
  
  cant=ingreso(v,80);
  
     //funciones
  
  int ingreso(struct alumno v[],int n)
  {
   int i=0;dni;
   
   printf("ing dni:"); 
   scanf("%d",&dni); 
   
   while(dni>0 && i<n)
   {
     v[i].dni=dni;
     printf("ing apnombre:");
     fflush(stdin);
     gets(v[i],apnom);
     printf("ing las notas:");
     scanf("%d %d",&v[i].n1,&v[i].n2);
     v[i].prom=(float)v[i].n1+v[i].n2)/2;
     
     i++;
     printf("ing dni:");
     scanf("%d",&dni);
     }
     
     return i;
   }  
   
   void resultado(struct alumno v[],int cat)
   {
     int i, cantap=0, cantdesap=0;
     
     for(i=0;i<cant;i++)
     {
       if(v[i].n1>=4 && v[i].n2>=4)
       {
       contap++;
        }
       else{
          contdesap++;
           }
         }  
   
     printf("cant aprobada: %d\n",contap);
     printf("cant desaprobada: %d\n",contdesap);
   }
   
   
   
   
   void informe_promo(struct alumno v[],int cont)    
   {
     int i;
     
     printf("alumnos promocionados:\n"); 
     
        for(i=0;i<cont;i++)
        {
          if(v[i].n1>=7 && v[i].n2>=7)
          {
            printf("%d  %s  %.2f\n",v[i],v[i].apnom,v[i].prom);
            }
          }   
   }