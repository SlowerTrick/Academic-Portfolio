#include <stdio.h>
#include <math.h>

int main (void)
{
    float x, y, soma;
    scanf ("%f%f", &x, &y);

    soma = (x + y) / 2;

    if (soma >= 7.0)
    {
        printf ("%.1f - Aprovado\n", soma);
    }
    else if (soma < 5.0)
    {
        printf ("%.1f - Reprovado\n", soma);
    }
    else
    printf ("%.1f - De Recuperacao\n", soma);

    return 0;
}
