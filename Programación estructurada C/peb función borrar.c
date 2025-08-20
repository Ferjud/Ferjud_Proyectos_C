BORRADO FISICO

Crear un archivo temporal donde no se copian los registros a eliminar 
y luego sobreescribir el archivo original con el temporal

void borrar (int codaeliminar)
 {
  FILE*archorig;
  FILE*archtemp;
  
archorig=fopen("archorig.dat","rb");
archtemp=fopen("archtemp.dat","wb");

  if(archorig==NULL || archtemp==NULL)
  {
    printf("ERROR ABERTURA");
    exit(1);
   }
   

fread(&prod,sizeof(prod),1,archorig);
 
 while(!=feof(arch))
  {
    if(codaeliminar!=prod.cod)
     {
       fwrite(&prod,sizeof(prod),1,archtemp);
       }
     
     fread(&prod,sizeof(prod),1,archorig);
   }
   
     renove("archorig.dat");
     remove("archtemp.dat","archorig.dat");
     
     fclose(archorig);
     fclose(archtemp);
   
   return 0;
  }    
           
   