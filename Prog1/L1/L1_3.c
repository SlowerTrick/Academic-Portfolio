#include <stdio.h>
#include <math.h>

int main (void)
{
    float x1, y1, x2, y2;

    scanf ("%f%f%f%f", &x1, &y1, &x2, &y2);

    float largura = fabs(x2 - x1);
    float altura = fabs(y2 - y1);

    float soma = (largura + largura) + (altura + altura);

    printf ("%.2f\n", soma);
}
