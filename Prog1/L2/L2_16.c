#include <stdio.h>

int main (void)
{
    int numeros1[100000];
    int numeros2[100000];
    int infinito = 0, i1 = 0, i2 = 0, menor = 32001, x = 0, j = 0, contador = 0, ultimavez = 0, primeiroprint = 0;

    while(infinito == 0)
    {
        if(scanf("%i", &x) != 1)
        {
            infinito++;
        }
        else
        {
            numeros1[i1] = x;
            i1++;
        }
    }

    getchar();
    infinito = 0;

    while(infinito == 0)
    {
        if(scanf("%i", &x) != 1)
        {
            infinito++;
        }
        if (infinito == 0)
        {
            numeros2[i2] = x;
            i2++;
        }
    }

    for (j = 0; j < i1; j++)
    {
        if (menor > numeros1[j])
        {
            menor = numeros1[j];
        }
    }
    printf ("%i ", menor);

    for (j = 0; j < i2; j++)
    {
        if (menor == numeros2[j] && contador == 1)
        {
            ultimavez = j;
        }

        if (menor == numeros2[j] && contador == 0)
        {
            printf ("%i ", j);
            primeiroprint = j;
            contador++;
        }

        if (j == i2 - 1 && contador == 0)
        {
            printf ("%i %i", i2, i2);
        }

        if (j == i2 - 1 && contador != 0 && ultimavez > 0)
        {
            printf ("%i", ultimavez);
        }
        
        if (j == i2 - 1 && contador != 0 && ultimavez == 0)
        {
            printf ("%i", primeiroprint);
        }
    }

    return 0;
}