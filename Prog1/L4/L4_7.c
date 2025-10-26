#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}
tPonto;

#include <stdio.h>

typedef struct 
{
    tPonto pontoinicial;
    tPonto pontofinal;
}
tReta;

tPonto Localizacao();
void ApresentaPonto(tReta pontoreta);
int EncontraQuadrante (tPonto ponto);
void VerificaQuadrante (tReta pontoreta);

int main (void)
{
    tReta pontoreta;
    int quantidade = 0, i = 0;
    scanf ("%i", &quantidade);

    for (i = 0; i < quantidade; i++)
    {
        pontoreta.pontoinicial = Localizacao();
        pontoreta.pontofinal = Localizacao();
        VerificaQuadrante(pontoreta);
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

int EncontraQuadrante(tPonto ponto)
{
    if (ponto.x == 0 || ponto.y == 0) return 0;
    if (ponto.x > 0 && ponto.y > 0)  return 1;
    if (ponto.x < 0 && ponto.y > 0) return 2;
    if (ponto.x < 0 && ponto.y < 0) return 3;
    if (ponto.x > 0 && ponto.y < 0) return 4;
}


void VerificaQuadrante (tReta ponto)
{
    int pontoinicial = EncontraQuadrante(ponto.pontoinicial);
    int pontofinal = EncontraQuadrante(ponto.pontofinal);

    if (pontoinicial == 0 || pontofinal == 0)
    {
        printf ("DIFERENTE\n");
        return;
    }

    if (pontoinicial != pontofinal)
    {
        printf ("DIFERENTE\n");
        return;
    }
    else
    {
        printf ("MESMO\n");
        return;
    }
}