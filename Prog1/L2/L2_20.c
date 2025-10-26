#include <stdio.h>
#include <math.h>

void verificaPicoVale (float a, float b, float c, float d, int limiteinferior, int limitesuperior);

int main (void)
{
    float a = 0, b = 0, c = 0, d = 0;
    int limitesuperior = 0, limiteinferior = 0;
    scanf ("%f%f%f%f%i%i", &a, &b, &c, &d, &limiteinferior, &limitesuperior);

    verificaPicoVale (a, b, c, d, limiteinferior, limitesuperior);

    return 0;
}

void verificaPicoVale (float a, float b, float c, float d, int limiteinferior, int limitesuperior)
{
    int i = 0;
    double ponto1 = 0, ponto2 = 0, ponto3 = 0;
    int haPico = 0, haVale = 0;

    for (i = limiteinferior; i <= limitesuperior; i++)
    {
        ponto1 = a * pow(i-1, 3) + b * pow(i-1, 2) + c * (i-1) + d;
        ponto2 = a * pow(i, 3) + b * pow(i, 2) + c * (i) + d;
        ponto3 = a * pow(i+1, 3) + b * pow(i+1, 2) + c * (i+1) + d;

        if (haPico == 0 && ponto2 > ponto3 && ponto2 > ponto1)
        {
            printf ("Pico em x=%i\n", i);
            haPico = 1;
        }

        if (haVale == 0 && ponto2 < ponto3 && ponto2 < ponto1)
        {
            printf ("Vale em x=%i\n", i);
            haVale = 1;
        }

        if (haPico == 1 && haVale == 1)
        {
            break;
        }
    }

    if (haPico == 0)
    {
        printf ("Nao ha pico\n");
    }

    if (haVale == 0)
    {
        printf ("Nao ha vale");
    }
}