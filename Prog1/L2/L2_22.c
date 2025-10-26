#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
    int numero = 0, somatorio = 0;
    scanf ("%i", &numero);

    int digitos = floor(log10(abs(numero)) + 1);
    int x = 0;

    while (digitos > 1)
    {
        x += (numero % 10) + ((numero % 100) / 10);
        if (x >= 10)
        {
            x = (x / 10) + (x % 10);
        }
        numero = numero / 100;
        digitos -= 2;
    }

    if (digitos == 1)
    {
        x += numero;
        if (x >= 10)
        {
            x = (x / 10) + (x % 10);
        }
    }

    printf ("RESP:%i", x);
}