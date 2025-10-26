#include <stdio.h>

int main (void)
{
    int quantidade = 0, procurado = 0, contador = 0, i = 0;
    scanf ("%i%i", &procurado, &quantidade);
    int numeros[quantidade];

    for (i = 0; i < quantidade; i++)
    {
        scanf ("%i", &numeros[i]);
        if (procurado == numeros[i])
        {
            printf ("RESP:%i", i);
            return 0;
        }
        contador++;
    }
    printf ("RESP:%i", contador);
    return 0;
}