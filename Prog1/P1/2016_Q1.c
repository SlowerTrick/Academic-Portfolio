#include <stdio.h>

int main (void)
{
    int x = 0;
    scanf ("%i", &x);

    if (x == 1)
    {
        printf ("Domingo");
    }
    if (x == 2)
    {
        printf ("Segunda");
    }
    if (x == 3)
    {
        printf ("Terca");
    }
    if (x == 4)
    {
        printf ("Quarta");   
    }
    if (x == 5)
    {
        printf ("Quinta");  
    }
    if (x == 6)
    {
        printf ("Sexta");
    }
    if (x == 7)
    {
        printf ("Sabado");
    }
    if (x < 1 || x > 7)
    {
        printf ("Invalido");
    }
}