#include <stdio.h>

int main (void)
{
    int x = 0, y = 0;
    char operacao = 0;

    scanf ("%i %c %i", &x, &operacao, &y);

    if (operacao == '+')
    {
        printf ("SOMA:%i", x + y);
    }
    if (operacao == '-')
    {
        printf ("SUB:%i", x - y);
    }
    if (operacao == '*')
    {
        printf ("MULT:%i", x * y);
    }
    if (operacao == '/')
    {
        printf ("DIV:%i", x / y);
        if ((x % y) != 0)
        {
            printf (", RESTO:%i", x % y);
        }
    }
}