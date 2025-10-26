#include <stdio.h>

int main (void)
{
    int quantidade = 0, numero = 0, contador = 0, i = 0, somatorio = 0;
    scanf ("%i", &quantidade);

    for (i = 0; i < quantidade; i++)
    {
        scanf ("%i", &numero);
        if (contador % 2 == 0 && numero % 2 == 0)
        {
            somatorio += numero;
        }
        if (contador % 2 != 0 && numero % 2 != 0)
        {
            somatorio += numero;
        }
        contador++;
    }
    printf ("SOMA:%i", somatorio);
    return 0;
}