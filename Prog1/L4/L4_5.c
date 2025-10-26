#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}
tPonto;

tPonto Localizacao();
float DistanciaDosPontos(tPonto ponto1, tPonto ponto2);

int main (void)
{
    tPonto pontoatual, pontoanterior;
    int quantidade = 0, i = 0;
    scanf ("%i", &quantidade);

    printf ("-\n");

    for (i = 0; i < quantidade; i++)
    {
        pontoatual = Localizacao();
        if (i > 0)
        {
            printf ("%.2f\n", DistanciaDosPontos(pontoatual, pontoanterior));
        }
        pontoanterior = pontoatual;
    }
}

tPonto Localizacao()
{
    tPonto ponto;
    scanf("%i%i", &ponto.x, &ponto.y);
    return ponto;
}

float DistanciaDosPontos(tPonto ponto1, tPonto ponto2)
{
    float a = fabs(ponto1.x - ponto2.x);
    float b = fabs(ponto1.y - ponto2.y);

    return sqrt(pow(a, 2) + pow(b, 2));
}