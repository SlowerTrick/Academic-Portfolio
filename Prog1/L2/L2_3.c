#include <stdio.h>

int main(void) 
{
    int i = 0, j = 0, aux = 0, total = 0, pares = 0, impares = 0;
    float media = 0; 

    scanf("%i", &total);

    int numeros[total];

    for (i = 0; i < total; i++)
    {
        scanf("%i", &numeros[i]);
    }

    for (i = 0; i < total; i++)
    {
        for (j = i + 1; j < total; j++)
        {
            if (numeros[i] > numeros[j])
            {
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }

    for (i = 0; i < total; i++)
    {
        if ((numeros[i] % 2) == 0)
        {
            pares++;
        }
        else
        impares++;

        media = media + numeros[i];
    }

    media = media / total;

    printf ("%i %i", numeros[total - 1], numeros[0]);
    printf (" %i %i %.6f", pares, impares, media);

    return 0;
}