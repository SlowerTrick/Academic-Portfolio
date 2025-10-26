#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somadosdigitos(int n);
void parImpar(int n);
void valorPrimo(int n);

int main (void)
{
    int numero = 0;
    scanf ("%i", &numero);

    do
    {
        numero = somadosdigitos(numero);
        printf ("%i ", numero);
        parImpar(numero);
        valorPrimo(numero);
    }
    while (numero > 9);

    return 0;
}

int somadosdigitos(int n)
{
    int total = 0;
    while (n != 0)
    {
        total += n % 10;
        n = n / 10;
    }
    return total;
}

void parImpar(int n)
{
    if ((n % 2) == 0)
    {
        printf ("Par ");
    }
    else
    {
        printf ("Impar ");
    }
    return;
}

void valorPrimo(int n)
{
    int i = 2;

    if (n <= 1)
    {
        printf("Nao e primo\n");
        return;
    }

    for (i = 2; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            printf("Nao e primo\n");
            return;
        }
    }
    printf("Primo\n");
}