#include <stdio.h>

int main() 
{
    int num, i;
    int divisores, suma;

    for(num = 1; num <= 9000; num++)
    {
        divisores = 0;
        suma = 0;

        for(i = 1; i < num; i++)
        {
            if(num % i == 0)
            {
                divisores++;
                suma += i;
            }
        }
        
        if(num == suma)
        {
            printf("%d ", num);
        }
    }
    
    return 0;
}