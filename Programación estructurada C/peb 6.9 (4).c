#include<stdio.h>
#include<stdlib.h>

typedef struct
{
 int dni;
 char nomyap[21];
 int pagado;
 }Sanot;
 
typedef struct
{
 int telefono;
 int dni;
 char nomyap[21];
 }Sfut;
 
 
 
 int main()
 {
  Sanot anotados;
  Sfut futuros;
  FILE*archreg,*archfut;
  
  archreg=fopen("INSCRIPTOS.dat","r+b");
  
  if(archreg==NULL)
  {
   printf("error al abrir el archivo");
   exit(1);
   }
   
   archfut=fopen("interesados.dat","r+b");
   
   if(archfut==NULL)
   {
    printf("error al abrir el archivo");
    exit(1);
    }
    
   
   printf("ingrese DNI:");
   scanf("%d",&numdni);
   
   while(numdni>=0)
   {
     band=0;
     rewind(archint);
   
     fseek(archint,0,seek_end);
 
     bytes=ftell(archint);//retorna la cantidad de bytes desde el comienzo del archivo    
 
     cant_registros=bytes/sizeof(anotados);
 
     
     while(fread(&anotados,sizeof(anotados),1,archint)==1 && band=0)
     {
       if(anotados.dni==numdni)
       {
        if(anotados.pagado==0)
        {
         printf("¿desea registrar el pago?(S-si,N-no): ");
         scanf("%c",&op);
         if(op=='S')
         {
          anotados.pagado=1;
           }
         }
        }
        else
        if(cant_registros<=60)
        {
         printf("¿quiere ser inscripto ahora?(S-si,N-no): ");
         scanf("%d",&op);
         if(op=='S')
         {
          anotados.dni=numdni;
          }
         }
         else{
           printf("curso lleno. ¿Desea ser anotado a la lista de espera de proximos cursos?(S-si,N-no): ");
           scanf("%d",&op);
           if(op=='S')
           {
            printf("ingrese su teléfono:");
            scanf("%d",&futuros.telefono);
            
            printf("ingrese nombre y apellido: ");
            fflush(stdin);
            fgets(futuros.nomyap,21,stdin);
            //controlar
            
            futuros.dni=numdni;
            
            fseek(archfut,-sizeof(archfut),SEEK_CUR);
            fwrite(&futuros,sizeof(futuros),1,archfut);
            fflush(archfut);
             }
           }   
        } 
        fseek(archint,-sizeof(archint),SEEK_CUR);
        fwrite(&anotados,sizeof(anotados),1,archint);
        fflush(archint);
       
         
            
            
             
             
            
                
          
   
 
  