#include <stdio.h>
#include <math.h>

 int CalculaValorPalavra(char c);
 int EhPrimo(int n);
 int ProximoPrimo(int n);

int main (void)
{
    char letra = 0;
    int somatorio = 0;

    while (scanf("%c", &letra) != EOF)
    {
        while (1)
        {
            if (letra == '\n')
            {
                break;
            }
            somatorio += CalculaValorPalavra(letra);
            scanf("%c", &letra);
        }

        if (EhPrimo(somatorio) == 1)
        {
            printf ("E primo\n");
        }
        else
        {
            printf ("Nao e primo ");
            printf ("%i\n", ProximoPrimo(somatorio));
        }
        somatorio = 0;
    }
    return 0;
}

int CalculaValorPalavra(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 1;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 27;
    }
    return 0;
}

int EhPrimo(int n)
{
    int i = 0;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int ProximoPrimo(int n)
{
    int i = 2;
    n++;

    while (1)
    {
        int EhPrimo = 1;
        for (i = 2; i * i <= n; i++)
        {
            if ((n % i) == 0)
            {
                EhPrimo = 0;
                break;
            }
        }
        if (EhPrimo)
        {
            return n;
        }
        else
        {
            n++;
        }
    }
}