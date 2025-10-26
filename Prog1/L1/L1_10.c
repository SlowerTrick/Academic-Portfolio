#include <stdio.h>
#include <math.h>

int main (void)
{
    int x = 0;
    int resto = 0;
    scanf("%i", &x);

    resto = x % 2;

    if (resto > 0 || resto == -1)
    {
        printf ("Impar\n");
    }
    else
    printf ("Par\n");

    return 0;
}
