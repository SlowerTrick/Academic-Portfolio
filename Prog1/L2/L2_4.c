#include <stdio.h>

int main(void) 
{
    float media = 0; 
    int numeros[100] = {0};
    int maior = 0, total = 0;
    int atual = -1, i = 0, j = 0, k = 0;

    while (atual != 0)
    {
        scanf("%i", &atual);
        if (atual == 0)
        {
            break;
        }

        numeros[i] = atual;

        if (maior < numeros[i])
        {
            maior = numeros[i];
        }
        
        for (j = 0; j <= i; j++)
        {
            total += numeros[j];
        }
        
        if (i >= 0)
        {
            media = (float)total / (i+1);
        }

        printf ("%i ", maior);
        printf ("%.6f", media);
        printf ("\n");

        i++;
        j = 0;
        media = 0;
        total = 0;
    }
    return 0;
}