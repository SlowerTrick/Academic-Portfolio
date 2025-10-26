#include <stdio.h>

int main (void)
{
    int tipo1 = 0, tipo2 = 0;
    scanf("%i%i", &tipo1, &tipo2);

    if (tipo1 > 10 || tipo1 < 1 || tipo2 > 10 || tipo2 < 1)
    {
        printf ("Invalido");
        return 1;
    }

    if (tipo1 == tipo2 && tipo1 <= 5)
    {
        printf ("Um homem");
    }
    if (tipo1 == tipo2 && tipo1 > 5)
    {
        printf ("Uma mulher");
    }
    if (tipo1 != tipo2)
    {
        if ((tipo1 <= 5 && tipo2 > 5) || (tipo2 <= 5 && tipo1 > 5))
        {
            printf ("Um casal");
        }
    }
    if (tipo1 != tipo2 && tipo1 <= 5 && tipo2 <= 5)
    {
        printf ("Par de homens");
    }
    if (tipo1 != tipo2 && tipo1 > 5 && tipo2 > 5)
    {
        printf ("Par de mulheres");
    }
}