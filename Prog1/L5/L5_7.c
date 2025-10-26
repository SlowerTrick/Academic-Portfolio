#include <stdio.h>

int main (void)
{
    int quantidade = 0, i = 0;
    scanf("%i", &quantidade);

    if (quantidade == 1)
    {
        printf ("NAO");
        return 0;
    }

    int numero[quantidade];

    for (i = 0; i < quantidade; i++)
    {
        scanf("%i", &numero[i]);
    }

    int coeficiente = numero[1] - numero[0];

    for (i = 0; i < quantidade - 1; i++)
    {
        if (!(numero[i] + coeficiente == numero[i+1]))
        {
            printf ("NAO");
            return 0;
        }
    }
    printf ("RESP:%i", coeficiente);
}