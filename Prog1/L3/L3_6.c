#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int EhPalindromo(int num);

int main (void)
{
    int numero = 0, infinito = 0;

    while (scanf("%i", &numero) != EOF)
    {
        if (EhPalindromo(numero) == true)
        {
            printf ("S\n");
        }
        else
        {
            printf ("N\n");
        }
    }
    return 0;
}

int EhPalindromo(int num)
{
    int esquerda = 0, direita = 0;
    int tamanho = 0;
    int digitos = floor(log10(abs(num))) + 1;

    while (digitos > 1)
    {
        tamanho = pow (10, digitos - 1);
        esquerda = num / tamanho;
        direita = num % 10;

        if (esquerda != direita)
        {
            return false;
        }

        num = num % tamanho;
        num = num / 10;
        digitos -= 2;
    }
    return true;
}
