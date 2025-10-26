#include <stdio.h>

int EhPar (int x);
void PrintaPares (int N);
void PrintaImpares (int N);

int main (void)
{
    int tipo = 0, numero = 0, i = 0, contador = 0;
    scanf ("%i%i", &tipo, &numero);

    if (tipo == 0)
    {
        PrintaPares(numero);
    } 
    if (tipo == 1)
    {
        PrintaImpares(numero);
    }
    return 0;
}   

int EhPar (int x)
{
    if ((x % 2) == 0)
    {
        return 1;
    }
    return 0;
}

void PrintaPares (int N)
{
    int i = 0, contador = 0;
    for (i = 2; i <= 900000; i++)
    {
        if (EhPar(i))
        {
            printf ("%i ", i);
            contador++;
        }
        if (contador == N)
        {
            break;
        }
    }
}

void PrintaImpares (int N)
{
    int i = 0, contador = 0;
    for (i = 0; i <= 900000; i++)
    {
        if (!EhPar(i))
        {
            printf ("%i ", i);
            contador++;
        }
        if (contador == N)
        {
            break;
        }
    }
}