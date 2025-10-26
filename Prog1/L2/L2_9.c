#include <stdio.h>

int main (void)
{
    int min = 0, max = 0, contador = 0, i = 0, j = 0, k = 0, contador2 = 0;
    scanf ("%i%i", &min, &max);

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
            printf ("%i\n", i);
            for (k = 2, contador2 = 0; k < max; k++)
            {
                if (i * k < max)
                {
                    printf ("%i ", i*k);
                    contador2++;
                }

                if (contador2 == 0 && k == max - 1)
                {
                    printf ("*\n");
                    contador2 = -1;
                }
                if (contador2 != -1 && k == max - 1)
                {
                    printf ("\n");
                }
            }

        }
        contador = 0;
        contador2 = 0;
    }
   return 0;
}
