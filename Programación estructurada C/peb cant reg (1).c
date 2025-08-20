CANTIDAD DE REGISTROS DE UN ARCHIVO 

abrir el archivo de modo lect/esc.
mover el indicador de posición al final del archivo 
se llama a la función .ftell para conocer
la cantidad de bytes desde el comienzo del archivo y se divide esa cantidad por el tamaño de la estructura 


 fseek(arch,0,seek_end);
 
 bytes=ftell(arch);//retorna la cantidad de bytes desde el comienzo del archivo    
 
 cant_registros=bytes/sizeof(Sprod);
 