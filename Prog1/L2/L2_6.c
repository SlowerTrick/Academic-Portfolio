#include <stdio.h>
#include <math.h>

int main (void)
{
    int i = 0, j = 0, k = 0, n = 0;
    double solucao1 = 0.0;
    double solucao2 = 0.0;
    double solucao3 = 0.0;
    scanf("%i", &n);

    if (n == 1)
    {
        for (i = 1, j = 1; i <= 50; i++, j = j + 2)
        {
            solucao1 = solucao1 + j/(float)i;
        }
        printf ("%.6lf", solucao1);
    }

    else if (n == 2)
    {
        for (i = 50, j = 1; i >= 1; i--, j++)
        {
            solucao2 = solucao2 + pow(2, j)/(float)i;
        }
        printf ("%.6lf", solucao2);
    }

    else if (n == 3)
    {

        for (i = 1, j = 1; j <= 10; j++)
        {   
            i = k + j + j-1;
            solucao3 = solucao3 + j/(float)i;
            k = i;
        }
        printf ("%.6lf", solucao3);
    }

    return 0;
}

chefe de sessão
nada