#include <stdio.h>

int main (void)
{
    int contador = 0;
    char c = 0;
    printf ("RESP:");

    while (scanf("%c", &c) != EOF)
    {
        if (c == '.' && contador == 0)
        {
            break;
        }

        if (c == '(' && contador == 0)
        {
            contador++;
            continue;
        }

        if (c == '(' && contador > 0)
        {
            contador++;
            printf ("%c", c);
            continue;
        }
        
        if (c == ')' && contador == 1)
        {
            contador--;
            continue;
        }

        if (c == ')' && contador > 1)
        {
            contador--;
            printf ("%c", c);
            continue;
        }

        if (contador >= 1)
        {
            printf ("%c", c);
        }

    }
}