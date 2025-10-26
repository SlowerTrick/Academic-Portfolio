#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}
tPonto;

typedef struct 
{
    tPonto pontoinicial;
    tPonto pontofinal;
}
tReta;

tPonto Localizacao();
void ApresentaPonto(tReta pontoreta);
void VerificaPosicao (tPonto ponto, tReta pontoreta);

int main (void)
{
    tPonto ponto;
    tReta pontoreta;
    int quantidade = 0, i = 0;
    scanf ("%i", &quantidade);

    for (i = 0; i < quantidade; i++)
    {
        ponto = Localizacao();
        pontoreta.pontoinicial = Localizacao();
        pontoreta.pontofinal = Localizacao();
        VerificaPosicao(ponto, pontoreta);
    }
}

tPonto Localizacao()
{
    tPonto ponto;
    scanf("%i%i", &ponto.x, &ponto.y);
    return ponto;
}

void ApresentaPonto(tReta pontoreta)
{
    printf ("[(%i,%i):(%i,%i)]\n", pontoreta.pontoinicial.x, pontoreta.pontoinicial.y, pontoreta.pontofinal.x, pontoreta.pontofinal.y);
    return;
}

void VerificaPosicao (tPonto ponto, tReta pontoreta)
{
    float distancia1 = sqrt(pow(fabs(ponto.x - pontoreta.pontoinicial.x), 2) + (pow(fabs(ponto.y - pontoreta.pontoinicial.y), 2)));
    float distancia2 = sqrt(pow(fabs(ponto.x - pontoreta.pontofinal.x), 2) + (pow(fabs(ponto.y - pontoreta.pontofinal.y), 2)));

    if (distancia1 == distancia2)
    {
        printf ("EQUIDISTANTE\n");
    }
    else if (distancia1 < distancia2)
    {
        printf ("INICIO\n");
    }
    else if (distancia2 < distancia1)
    {
        printf ("FIM\n");
    }
    return;
}
