BORRADO FISICO

void borrar (int codaeliminar)
 {
  FILE*archorig;
  FILE*archtemp;
  Sprod prod;
  
archorig=fopen("archorig.dat","rb");
archtemp=fopen("archtemp.dat","wb");

  if(archorig==NULL || archtemp==NULL)
  {
    printf("ERROR ABERTURA");
    exit(1);
   }
   

fread(&prod,sizeof(prod),1,archorig);
 
 while(!feof(archorig))
  {
    if(codaeliminar!=prod.cod)
     {
       fwrite(&prod,sizeof(prod),1,archtemp);
       }
     
     fread(&prod,sizeof(prod),1,archorig);
   }
   
     remove("archorig.dat");
     rename("archtemp.dat","archorig.dat");
     
     fclose(archorig);
     fclose(archtemp);
     
   }  