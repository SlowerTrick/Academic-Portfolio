#include <stdio.h>

int main (void)
{
    int min = 0, max = 0, i = 0, j = 0;
    int a = 0, b = 0, c = 0, d = 0, ef = 0;
    scanf ("%i%i", &min, &max);

    for (i = min+1; i < max; i++)
    {
        d = i % 10;
        c = (i % 100 - d) / 10;
        b = (i % 1000 - c - d) / 100;
        a = (i % 10000 - b - c - d) / 1000;

        ef = (a * 10 + b) + (c*10 + d);

        if (ef * ef == i)
        {
            printf ("%i\n", i); 
        }

        d = 0;
        c = 0;
        b = 0;
        a = 0;
        ef = 0;
    }
   return 0;
}