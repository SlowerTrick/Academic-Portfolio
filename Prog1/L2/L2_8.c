#include <stdio.h>

int main (void)
{
    int min = 0, max = 0, contador = 0, i = 0, j = 0;
    scanf ("%i%i", &min, &max);

    printf ("RESP:");
    
    for (i = min + 1; i < max; i++)
    {
        for (j = 1; j < max; j++)
        {
            if (i % j == 0)
            {
                contador++;
            }
        }
        if (contador == 2)
        {
            printf ("%i ", i);
        }
        contador = 0;
    }
   return 0;
}
