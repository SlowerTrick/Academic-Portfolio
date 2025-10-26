#include <stdio.h>

int main (void)
{
    int a = 0, b = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, contador = 0;
    scanf("%i%i%i%i%i%i%i%i", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);

    if (y1 == (a*x1) + (b))
    {
        contador++;
    }
    if (y2 == (a*x2) + (b))
    {
        contador++;
    }
    if (y3 == (a*x3) + (b))
    {
        contador++;
    }
    if (contador == 0)
    {
        printf ("Nenhum");
    }
    if (contador == 1)
    {
        printf ("Um");
    }
    if (contador == 2)
    {
        printf ("Dois");
    }
    if (contador == 3)
    {
        printf ("Todos");
    }
}