#include <stdio.h>

int main (void)
{
    int quantidade = 0, i = 0, inferior = 0, superior = 0;
    scanf ("%i", &quantidade);
    int numero[quantidade];
    
    for (i = 0; i < quantidade; i++)
    {
        scanf ("%i", &numero[i]);
    }
    scanf ("%i%i", &inferior, &superior);

    int dentro = 0, fora = 0;

    for (i = 0; i < quantidade; i++)
    {
        if (numero[i] >= inferior && numero[i] <= superior)
        {
            dentro++;
        }
        else
        {
            fora++;
        }
    }
    printf ("%i %i", dentro, fora);
}