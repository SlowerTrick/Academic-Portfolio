#include <stdio.h>

int main (void)
{
    int min = 0, max = 0, i = 0, verificador = 0;
    scanf ("%i%i", &min, &max);

    printf("RESP:");

    for (i = min + 1; i < max; i++)
    {
        if((i % 2) == 0)
        {
            printf ("%i ", i);
             verificador = 1; 
        }  
    }
    return 0;
}