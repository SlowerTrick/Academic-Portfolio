#include <stdio.h>

int main (void)
{
    int min = 0, max = 0, i = 0, j = 0;
    scanf ("%i%i", &min, &max);

    for (i = min; i <= max; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            printf ("%i x %i = %i\n", i, j, i*j);
        }
    }
}