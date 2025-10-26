#include <stdio.h>
#include <math.h>

int main (void)
{
    float base = 0;

    scanf ("%f", &base);

    int inteiro = (int) base;
    float real = base - inteiro;

    real = round(real * 100) / 100;

    printf ("INTEIRO:%i,REAL:%.2f\n", inteiro, real);
}
