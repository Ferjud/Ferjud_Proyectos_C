#include<stdio.h>
void carga(int,float[],int);
float DatoVal(int,int);
void puntajesnulos(int);
void Listadopuntajes(float[]);


int main()
{
  float vecpuntajes[20]={0};
  int i,cont0=0;
  
  
    carga(1, vecpuntajes,cont0);
    
    carga(2, vecpuntajes,cont0);
    
    carga(3, vecpuntajes,cont0);
    
    carga(4, vecpuntajes,cont0);
    
    carga(5, vecpuntajes,cont0);
    
    puntajesnulos(cont0);
    
    Listadopuntajes(vecpuntajes);
    
  return 0;
  }
  
  
  
  void carga(int discip, float vectorpuntajes[],int contador0 )
  {
    float N1=0,N2=0,N3=0;
    int i;
    
              printf("disciplina %d\n",discip);
      
      for(i=0;i<21;i++)
      {
        printf("deportista %d\n", i+1000);
        
        printf("puntaje 1:");
        N1=DatoVal(0,10);
        
        if(N1==0)
        {
          contador0++;
           }
           else{
             printf("\npuntaje2:");
             N2=DatoVal(0,10);
             
             printf("\npuntaje3:");
             N3=DatoVal(0,10);
             }
         
         vectorpuntajes[i]+=N1+N2+N3;
         
       }
  
    }
    
    
    float DatoVal(int liminf, int limsup)
    {
      float n;
      
      do{
      scanf("%f",&n);          
         if(n<liminf || n>limsup)
         {
           printf("Error.Ingrese dato válido");
           }
        }while(n<liminf || n>limsup);
        
        return n;
     }
     
     void Listadopuntajes(float vectorpuntajes[])
     {
       int i;
       
         for(i=0;i<21;i++)
         {
           printf("puntaje total del deportista %d: %.2f\n",i+1000, vectorpuntajes[i]);
           }
           
       }
       
       void puntajesnulos(int contador0)
       {
         printf("la cantidad de deportistas que no tuvieron puntajes en al menos 1 disciplina es de: %d",contador0); 
                 
                 }  