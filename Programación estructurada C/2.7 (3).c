#include<stdio.h>
int leeyvalida(int,int);
int busq(int[],int,int);
int rectrimestre(int[][12],int,int);

int main()
{
 int vcodigo[20], mcant[20][12]={{0}},mrec,cod,cp,día;
 float mpr[20][12]={{0}}, vprecio[20],precio;
 int cu,mes,s,dia,i,j;
 float rectrimestral0_3,rectrimestral3_6, rectrimestral6_9, rectrimestral9_12,s1;
 int cprec,x;
 float mayor_recaudacion;
 int trimestre_mayor;

 
 
 for(i=0;i<20;i++)
 {
  printf("ingrese codigo de producto: ");
  do
  {
   scanf("%d",&cod);
   }while(cod<100 || cod>999);
   
   vcodigo[i]=cod;
  }  
  
   printf("ing precio:");
   
   do
   {
    scanf("%d",&precio);
    }while(precio<=0);
    
    vprecio[i]=precio;
    
    printf("ing código: ");
    scanf("%d",&cp);
    
 while(cp!=0)
 {
   x=busq(vcodigo,cp,20);
   
   if(x!=-1)
   {
    mes=leeyvalida(1,12);
    printf("ing dia");
    scanf("%d",&dia);
    printf("ing unidades:");
    
    do
    {
     scanf("%d",&cu);
     }while(cu<0);
     
    mcant[x][mes-1]+=cu;
    mpr[x][mes-1]+=cu*vprecio[x];
      }
      else{
        printf("código de producto inexistente");
        }
        
        printf("ing código:");
        scanf("%d",&cp);
     }    
        
     
   printf("producto \t unid.vend\n");  
   
   for(i=0;i<20;i++)
   {
    s=0;
    for(j=0;j<12;j++)
    {
     s+=mcant[i][j];
     }
     
     printf("%d\t %d\n", vcodigo[i],s);
    }
    
    
    printf("producto con mayor recaudación: "); 
    
    for(i=0;i<20;i++)
    {
     s1=0;
     for(j=0;j<12;j++)
     {
      s1+=mpr[i][j];
      }
     if(i==0 || s1>mrec)
     {
      mrec=s1;
      cprec=vcodigo[i];
      }
     }   
    
      printf("%d",cprec);
   
     rectrimestral0_3=rectrimestre(mpr,0,3);
     
     rectrimestral3_6=rectrimestre(mpr,3,6);
     
     rectrimestral6_9=rectrimestre(mpr,6,9);
     
     rectrimestral9_12=rectrimestre(mpr,9,12);
     
   
     // Inicializa la mayor recaudación con el primer trimestre
mayor_recaudacion = rectrimestral0_3;
trimestre_mayor = 1;

// Compara con los demás trimestres
if (rectrimestral3_6 > mayor_recaudacion) 
{
    mayor_recaudacion = rectrimestral3_6;
    trimestre_mayor = 2;
}
if (rectrimestral6_9 > mayor_recaudacion) 
{
    mayor_recaudacion = rectrimestral6_9;
    trimestre_mayor = 3;
}
if (rectrimestral9_12 > mayor_recaudacion) 
{
    mayor_recaudacion = rectrimestral9_12;
    trimestre_mayor = 4;
}

// Mostrar el resultado
printf("La mayor recaudación fue en el trimestre %d con: %.2f\n", trimestre_mayor, mayor_recaudacion);

       
       return 0;
    }   
  
  
 int rectrimestre(matpr[][12],int n,int k)
 {
  int i,j;
  float rec=0;
  
  for(i=0;i<20;i++)
    {
     for(j=n;j<k;j++)
     {
      rec+=matpr[i][j];
      }
     }
  return rec;
  }     
  
  
  int leeyvalida(int min, int max) 
  {
    int valor;
    do {
        printf("Ingrese un valor entre %d y %d: ", min, max);
        scanf("%d", &valor);
        if (valor < min || valor > max) 
        {
            printf("Valor fuera de rango. Intente nuevamente.\n");
        }
    } while (valor < min || valor > max);
    
    return valor;
}

int busq(int vcod[],int cod,int n)
{
 int pos=-1, i=0;
 
 while(i<n && pos==-1)
 {
  if(vcod[i]==cod)
  {
   pos=i;
   }
   else{
    i++;
      }
     }
     return pos;
  }     