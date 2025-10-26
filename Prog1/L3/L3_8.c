#include <stdio.h>
#include <stdlib.h>

int verificaPrimo(int n);
int transformaPrimo(int n);
int verificaNegativo(int n);


int main (void)
{
    int l = 0, c = 0, num = 0;
    int i = 0, j = 0;
    scanf("%i%i", &l, &c);

    for (i = 0; i < l; i++)
    {
        printf("	");
        for (j = 0; j < c; j++)
        {
            scanf("%i", &num);
            verificaNegativo (num);
    
            if (verificaPrimo(num) == 1)
            {
                printf("%i ", num);
            }
            else
            {
                printf("%i ", transformaPrimo(num));
            }
        }
        printf ("\n");
    }
}

int verificaPrimo(int n)
{
    int i = 0;
    int contador = 0;

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            contador++;
        }
    }

    if (contador == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int transformaPrimo(int n)
{
    int x = abs(n);
    int infinito = 1;
    
    while (infinito)
    {
        if (verificaPrimo(x) == 1)
        {
            if (n >= 0)
            {
                return x;
            }
            else
            {
                return (-1) * x;
            }
        }
        else
        {
            if (x < 32000 && (-1) * x > -32000)
            {
                x++;
            }
            else
            {
                return n;
            }
        }
    }
}

int verificaNegativo(int n)
{
    if (n < 0)
    {
        return 1;
    }
    if (n >= 0)
    {
        return 0;
    }
}