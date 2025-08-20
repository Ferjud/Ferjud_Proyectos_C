#include<stdlib.h>
int valorlistado(int,int);

int main()
{
  int valor,n1,n2,opcion;
  
  printf("ingrese numero 1:");
  scanf(" %d",&n1);
  
  printf("ingrese numero 2:");
  scanf(" %d",&n2);
  
  opcion=valorlistado(n1,n2);
  
  while(opcion!=6)
    {
      switch(opcion)
      {
       case 1: 
               printf("la suma es: %d\n",n1+n2);
               break;
      
       case 2: 
               printf("la resta es: %d\n",n1-n2);
               break;
      
       case 3: 
              printf("la multiplicacion es: %d\n",n1*n2);
              break;
              
       case 4: 
              if(n2!=0)
              {
                printf("la division es: %d\n",n1/n2);
                }
                else
                {
                printf("no puede hacerse la operacion");
                }
       
       case 5:
               printf("ingrese numeros:\n");
               printf("numero 1:");
               scanf(" %d",&n1);
               printf("numero 2:");
               scanf(" %d",&n2);
               break;
        }       
  
        opcion=valorlistado(n1,n2);
  
  
   }
   
  return 0;
  } 
   
  
  int valorlistado(int x, int y)
  {
    int op;
    
    printf("menú de opciones:\n");
    
    printf("numero 1: %d y nunero 2: %d\n",x,y);
    
    printf("1) Suma \n 2) Resta \n 3) Multiplicar \n 4) Dividir \n 5) Ingresar Nuevos Números");
    
    do
    {
    printf("ingrese opcion:\n");
    scanf(" %d",&op);
    if(op<1 || op>6)
    {
      printf("ingrese opcion valida:");
      }
    }while(!(op>=1 && op<=6));

return op;
} 