#include <stdio.h>

void OrdenaCrescente(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main (void)
{
    int quantidade = 0, i = 0;
    scanf ("%i", &quantidade);
    int numero[quantidade];

    for (i = 0; i < quantidade; i++)
    {
        scanf("%i", &numero[i]);
    }
    OrdenaCrescente(numero, quantidade);
    ImprimeDadosDoVetor(numero, quantidade);
    return 0;
}

void OrdenaCrescente(int vet[], int qtd)
{
    int i = 0, j = 0;

    for (i = 0; i < qtd; i++)
    {
        for (j = i+1; j < qtd; j++)
        {
            if (vet[i] > vet[j])
            {
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    return;
}

void ImprimeDadosDoVetor(int vet[], int qtd)
{
    int i = 0;
    printf ("{");

    for (i = 0; i < qtd; i++)
    {
        printf ("%i", vet[i]);

        if (i < qtd - 1)
        {
            printf (", ");
        }
    }

    printf ("}");
    return;
}