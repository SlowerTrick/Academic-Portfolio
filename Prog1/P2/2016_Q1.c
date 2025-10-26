#include <stdio.h>

int EhPar (int x);

int main (void)
{
    int quantidade = 0, x = 0, i = 0, primeiro = 0, contador = 0;
    int total = 0;
    scanf ("%i%i", &quantidade, &primeiro);

    x = primeiro;

    if (EhPar(primeiro))
    {
        while (contador < quantidade)
        {
            if (EhPar(x))
            {
                total++;
            }
            if (contador != quantidade - 1)
            {
                scanf("%i", &x);
            }
            contador++;
        }
    }
    else
    {
        while (contador < quantidade)
        {
            if (!EhPar(x))
            {
                total++;
            }
            if (contador != quantidade - 1)
            {
                scanf("%i", &x);
            }
            contador++;
        }
    }

    if (EhPar(primeiro))
    {
        printf ("QTD PARES:%i", total);
    }
    else
    {
        printf ("QTD IMPARES:%i", total);
    }

    return 0;
}

int EhPar (int x)
{
    if (x % 2 == 0)
    {
        return 1;
    }
    return 0;
}