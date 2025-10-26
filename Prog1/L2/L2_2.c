#include <stdio.h>

int main (void)
{
    int min = 0, max = 0, i = 0;
    scanf ("%i%i", &min, &max);

    for (i = min + 1; i < max; i++)
    {
        if((i % 3) == 0 || (i % 4) == 0 || (i % 7) == 0)
        {
            printf ("%i ", i);
        }  
    }
    return 0;
}