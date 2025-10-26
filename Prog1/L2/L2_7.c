#include <stdio.h>

int main (void)
{
    int x = 0, contador = 0, i = 0;
    scanf ("%i", &x);

    for (i = 1; i < 9999999; i++)
    {
        if (x % i == 0)
        {
            contador++;
        }
    }

    if (contador == 2)
    {
        printf ("Primo");
    }
    if (contador != 2)
    {
        printf ("Nao primo");
    }
}