#include <stdio.h>
#include <ctype.h>

int main (void)
{
    char letra1 = 0, letra2 = 0, letra3 = 0, numero1 = 0, numero2 = 0, numero3 = 0, numero4 = 0;

    scanf("%c%c%c-%c%c%c%c", &letra1, &letra2, &letra3, &numero1, &numero2, &numero3, &numero4);

    if (!(isalpha(letra1)) || !(isalpha(letra2) || !(isalpha(letra3))))
    {
        if (!(isdigit(numero1)) || !(isdigit(numero2)) || !(isdigit(numero3)) || !(isdigit(numero1)))
        {
            printf("Codigo invalido!Problema nas letras e nos numeros!");
        }
        else
        {
            printf ("Codigo invalido!Problema nas letras!");
        }
    }
    else if (!isdigit(numero1) || !isdigit(numero2) || !isdigit(numero3) || !isdigit(numero4))
    {
        printf("Codigo invalido!Problema nos numeros!");
    }
    else
    {
        printf ("Codigo valido!");
    }
}