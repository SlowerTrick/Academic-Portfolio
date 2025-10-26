#include <stdio.h>

typedef struct
{
    int x;
    int y;
}
tPonto;

tPonto Localizacao();
void ApresentaCoordenadas(tPonto ponto);
tPonto AlteraAbcissa(tPonto ponto);
tPonto AlteraOrdenada(tPonto ponto);
int IdentificaQuadrate(tPonto ponto);
tPonto CalculaSimetrico(tPonto ponto);

int main (void)
{
    tPonto ponto;
    int quantidade = 0, i = 0;
    scanf ("%i", &quantidade);

    for (i = 0; i < quantidade; i++)
    {
        ponto = Localizacao();
        ApresentaCoordenadas(ponto);

        int quadrante1 = IdentificaQuadrate(ponto);
        printf ("%i ", quadrante1);
        tPonto simetrico = CalculaSimetrico(ponto);
        ApresentaCoordenadas(simetrico);
        int quadrante2 = IdentificaQuadrate(simetrico);
        printf ("%i\n", quadrante2);
    }
}

tPonto Localizacao()
{
    tPonto ponto;
    scanf("%i%i", &ponto.x, &ponto.y);
    return ponto;
}

void ApresentaCoordenadas(tPonto ponto)
{
    printf ("(%i,%i) ", ponto.x, ponto.y);
}

int IdentificaQuadrate(tPonto ponto)
{
    if (ponto.x == 0 || ponto.y == 0)
    {
        return 0;
    }
    if (ponto.x > 0 && ponto.y > 0)
    {
        return 1;
    }
    if (ponto.x < 0 && ponto.y > 0)
    {
        return 2;
    }
    if (ponto.x < 0 && ponto.y < 0)
    {
        return 3;
    }
    if (ponto.x > 0 && ponto.y < 0)
    {
        return 4;
    }
}

tPonto CalculaSimetrico(tPonto ponto)
{
    ponto.x = (-1) * ponto.x;
    ponto.y = (-1) * ponto.y;
    return ponto;
}
