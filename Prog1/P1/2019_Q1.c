#include <stdio.h>

int main (void)
{
    int x = 0, y = 0, z = 0;
    scanf("%i%i%i", &x, &y, &z);

    if (x > y && y > z)
    {
        printf ("DECRESCENTE");
    }
    else if (x < y && y < z)
    {
        printf ("CRESCENTE");
    }
    else
    {
        printf ("TUDO DOIDO");
    }
}