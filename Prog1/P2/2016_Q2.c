#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int EhPrimo(int num);
int MaiorDigitoPrimo(int num);

int main (void)
{
    int x = 0, somatorio = 0;
    char caracter = 0;

    printf ("SOMA:");

    while (scanf("%i%c", &x, &caracter) != EOF)
    {
        somatorio += MaiorDigitoPrimo(x);
    }
    printf ("%i", somatorio);
    return 0;
}

int EhPrimo(int num)
{
    int i = 2, contador = 0;
    if (num == 0 || num == 1)
    {
        return 0;
    }
    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            contador++;
        }
    }
    if (contador == 0)
    {
        return 1;
    }
    return 0;
}

int MaiorDigitoPrimo(int num)
{
    int digitos = floor(log10(abs(num))) + 1;
    int maior = 0;

    while (digitos > 0)
    {   
        int x = num % 10;
        if (EhPrimo(x))
        {
            if (maior < x)
            {
                maior = x;
            }
        }
        num = num / 10;
        digitos--;
    }
    return maior;
}