#include <stdio.h>
#include <math.h>

int main (void)
{
    int n = 0, i = 0, k = 0;
    float pi = 0;

    scanf("%i", &n);

    for (i = 0, k = 1; i < n; i++, k++)
    {
       pi = pi + (6/pow(k, 2));
    }

    pi = sqrt(pi);

    printf ("%.6f", pi);
}