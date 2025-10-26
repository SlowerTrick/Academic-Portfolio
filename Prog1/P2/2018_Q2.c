#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int EhIgual(int a, int b);
int MaiorDigito(int num);

int main (void)
{
    int a = 0, b = 0, contador = 0;
    char c = 0;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '(')
        {
            scanf ("%i,%i", &a, &b);
            if (EhIgual(MaiorDigito(a), MaiorDigito(b)))
            {
                contador++;
            }
        }
    }
    printf ("COUNT:%i", contador);
    return 0;
}

int EhIgual(int a, int b)
{
    if (a == b)
    {
        return 1;
    }
    return 0;
}

int MaiorDigito(int num)
{
    int maior = 0;
    int digitos = floor(log10(abs(num))) + 1;

    while (digitos > 0)
    {
        int atual = num % 10;
        num = num / 10;
        if (maior < atual)
        {
            maior = atual;
        }
        digitos--;
    }
    return maior;
}