#include <stdio.h>

int main() {
    int count_numeros = 0;
    int count_mayusculas = 0;
    int count_minusculas = 0;
    int count_simbolos= 0;
    char caracter;
    
    printf("Ingrese caracteres (* para finalizar el programa):\n");
    scanf(" %c", &caracter);
   
    while (caracter != '*')
    {
        if (caracter >= '0' && caracter <= '9') {
            count_numeros++; 
        } else if (caracter >= 'A' && caracter <= 'Z') {
            count_mayusculas++;
        } else if (caracter >= 'a' && caracter <= 'z') {
            count_minusculas++; 
        } else {
            count_simbolos++; 
        }
        scanf(" %c", &caracter);
    }
    
    printf("Cantidad de números: %d\n", count_numeros);
    printf("Cantidad de letras mayúsculas: %d\n", count_mayusculas);
    printf("Cantidad de letras minúsculas: %d\n", count_minusculas);
    printf("Cantidad de otros símbolos: %d\n", count_simbolos);
    
    return 0;
}