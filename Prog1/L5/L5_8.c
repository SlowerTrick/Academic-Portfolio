#include <stdio.h>

void TrocaParEImpar(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main (void)
{
    int quantidade = 0, i = 0;
    scanf ("%i", &quantidade);
    int numeros[quantidade];

    for (i = 0; i < quantidade; i++)
    {
        scanf("%i", &numeros[i]);
    }
    TrocaParEImpar(numeros, quantidade);
    ImprimeDadosDoVetor(numeros, quantidade);
    return 0;
}

void TrocaParEImpar(int vet[], int qtd)
{
    if (qtd == 1)
    {
        return;
    }

    int i = 0;

    for (i = 1; i < qtd; i++)
    {
        if (i % 2 != 0)
        {
            int aux = 0;
            aux = vet[i - 1];
            vet[i - 1] = vet[i];
            vet[i] = aux;
        }
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd)
{
    int i = 0;

    printf("{");

    for (i = 0; i < qtd; i++)
    {
        printf("%i", vet[i]);
        if (i != qtd - 1)
        {
            printf (", ");
        }
    }    

    printf("}");
    return;
}