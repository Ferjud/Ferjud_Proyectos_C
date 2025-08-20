#include<stdio.h>

typedef struct
{
 char cod_evento[11];
 int num_puerta;
 int cant_espec;
 }original;
 
 typedef struct 
 {
  int vespec[15]={0};
  }grabado;
 
 
int main()
{
 FILE *archinfo,*arch2;
 original info;
 grabado info2;
 
 archinfo=fopen("registros.dat","rb");
 if(archinfo==NULL)
 {
  printf("error al abrir el archivo");
  exit(1);
   }
   
  arch2=fopen("grabados.dat","wb");
  if(arch2==NULL)
  {
   printf("error al abrir el archivo"); 
   exit(1);
    }
    
   while(fread(&info,sizeof(info),1,archinfo);
   {
     strcpy(nombre_evento,info.cod_evento);
     espec_evento=0;
     
     do{
      espec_evento+=info.cant_espec;
      info2.vespec[(info.num_puerta)-1]+=info.cant_espec;
      fread(&info,sizeof(info),1,archinfo);
     }while(fread(&info,sizeof(info),1,archinfo) && strcmp(nombre_evento,cod_evento)==0); 
     
   
     printf("cantidad de espectadores en el evento %s:%d",nombre_evento,espec_evento);
     
     
     if(band==0 || espec_evento<min)
     {
      band=1;
      min=espec_evento;
      eventomin=nombre_evento;
       }
     
      cont_eventos++;
    }  
     
    printf("el evento con menor cantidad de espectadores es:%s con %d",evento_min,min); 
    
    for(i=0;i<15;i++)
    {
     info2.vespec[i]=vespec[i]/cont_eventos;
      }
    
    fwrite(&info2,sizeof(info2),1,arch2);
    
    for(i=0;i<15;i++)
    {
     printf("puerta %d: %d espectadores", i+1,info2.vespec[i]);
      }
      
    fclose(archinfo);
    fclose(arch2);
   
   return 0;
  }  
    
      
      
      