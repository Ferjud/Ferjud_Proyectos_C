void lectura (void)
{
     sAlumnos salu;
     FILE * arch, *arch2 ,* arch3,* arch4;
    arch = fopen("ALUMNOS.DAT", "rb");
    arch2=fopen("Promocionados.DAT", "wb");
    arch3=fopen("Reprobados.DAT", "wb");
    arch4=fopen("Cursados.DAT", "wb");
    
  if(arch==NULL||arch2==NULL||arch3==NULL||arch4==NULL){
     printf("Error al abrir el archivo\n");
     exit(1);}

    fread(&salu,sizeof(salu),1,arch );
while (!feof(arch))
{
    if (salu.nota1>=7 && salu.nota2>=7)
     fwrite(&salu,sizeof(salu),1,arch2 );
    else
      if (salu.nota1>=4 && salu.nota2>=4)
        fwrite(&salu,sizeof(salu),1,arch3 );
       else
    fwrite(&salu,sizeof(salu),1,arch4 );
        
  fread(&salu,sizeof(salu),1,arch );

}
fclose(arch);
fclose(arch2);
fclose(arch3);
fclose(arch4);

}