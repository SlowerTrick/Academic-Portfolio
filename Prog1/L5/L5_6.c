#include <stdio.h>

int VerificaCorrespondencia (int v1[], int q1, int v2[], int q2);
void VerificaTipo (int tipo);

int main (void)
{
    int quantidade1 = 0, quantidade2 = 0, i = 0;

    scanf("%i", &quantidade1);
    int vetor1[quantidade1];

    for (i = 0; i < quantidade1; i++)
    {
        scanf("%i", &vetor1[i]);
    }

    scanf("%i", &quantidade2);
    int vetor2[quantidade2];

    for (i = 0; i < quantidade2; i++)
    {
        scanf("%i", &vetor2[i]);
    }

    int tipo = VerificaCorrespondencia (vetor1, quantidade1, vetor2, quantidade2);
    VerificaTipo(tipo);

    return 0;

}

int VerificaCorrespondencia (int v1[], int q1, int v2[], int q2)
{
    int i = 0, j = 0, contador = 0;

    for (i = 0; i < q1; i++)
    {
        for (j = 0; j < q2; j++)
        {
            if (v1[i] == v2[j])
            {
                contador++;
            }
        }
    }

    if (contador == q1)
    {
        return 2;
    }
    else if (contador > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void VerificaTipo (int tipo)
{
    if (tipo == 0)
    {
        printf ("NENHUM");
    }

    if (tipo == 1)
    {
        printf ("PARCIAL");
    }

    if (tipo == 2)
    {
        printf ("TODOS");
    }
    return;
}