#include <stdio.h>
#include <stdbool.h>

int Propriedade (int num);

int main (void)
{
    int min = 0, max = 0, i = 0;
    scanf ("%i%i", &min, &max);

    for (i = min+1; i < max; i++)
    {
        if (Propriedade (i) == true)
        {
            printf ("%i\n", i);
        }
    }

    return 0;     
}

int Propriedade (int num)
{
    int ab = 0, cd = 0, ef = 0;

    ab = num / 100;
    cd = num % 100;
    ef = ab + cd;

    if (ef * ef == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}