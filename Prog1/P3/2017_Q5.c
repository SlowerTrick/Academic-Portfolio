#include <stdio.h>

void AtualizaSequencia(int seq[], int totalElemetos, int coeficiente);

int main (void)
{
    int total = 0;
    while (scanf("%d", &total) == 1)
    {
        int seq[total];

        int i = 0;
        for (i = 0; i < total; i++)
        {
            scanf ("%d", &seq[i]);
        }

        int coeficiente = 0;
        while (coeficiente != -1)
        {
            scanf("%d", &coeficiente);
            if (coeficiente != -1)
            {
                AtualizaSequencia(seq, total, coeficiente);
                for (i = 0; i < total; i++)
                {
                    printf ("%d", seq[i]);
                    if (i != total - 1)
                    {
                        printf(" ");
                    }
                }
                printf ("\n");
            }
        }
    }
    return 0;
}

void AtualizaSequencia(int seq[], int totalElemetos, int coeficiente)
{
    int novoArray[totalElemetos];

    int i = 0;
    for (i = 0; i < totalElemetos; i++)
    {
        if (i + coeficiente < totalElemetos)
        {
            int novaPosicao = i + coeficiente;
            novoArray[novaPosicao] = seq[i];
        }
        else
        {
            int novaPosicao = (i + coeficiente) - totalElemetos;
            novoArray[novaPosicao] = seq[i];
        }
    }
    for (i = 0; i < totalElemetos; i++)
    {
        seq[i] = novoArray[i];
    }
    return;
}