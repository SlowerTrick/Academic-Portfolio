#include <stdio.h>

int main (void)
{
    int troco1 = 0, troco2 = 0;
    int valor1 = 0, valor2 = 0;
    scanf("%i%i", &valor1, &valor2);

    while (valor1 > 0)
    {
        if (valor1 >= 5)
        {
            valor1 -= 5;
            troco1++;
        }
        else
        {
            valor1 -= 1;
            troco1++;
        }
    }
    while (valor2 > 0)
    {
        if (valor2 >= 5)
        {
            valor2 -= 5;
            troco2++;
        }
        else
        {
            valor2 -= 1;
            troco2++;
        }
    }
    if (troco1 == troco2)
    {
        printf ("Iguais!");
    }
    else if (troco1 > troco2)
    {
        printf ("QTD troco 1 eh maior!");
    }
    else if (troco2 > troco1)
    {
        printf ("QTD troco 2 eh maior!");
    }
    return 0;
}