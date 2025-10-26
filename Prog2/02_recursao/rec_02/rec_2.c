#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);
int EhPar(int numero);

int main(void)
{
    int totalVetores = 0;
    scanf("%d", &totalVetores);

    for(int i = 0; i < totalVetores; i++)
    {
        int totalElementos = 0;
        scanf("%d", &totalElementos);
        int vetor[totalElementos];
        for (int j = 0; j < totalElementos; j++)
        {
            scanf("%d", &vetor[j]);
        }
        printf("%d\n", SomaElementosPares(vetor, totalElementos));
    }
    return 0;
}

int SomaElementosPares(int* vet, int numElementos)
{
    if (numElementos == 0)
    {
        return 0;
    }
    return EhPar(vet[numElementos - 1]) + SomaElementosPares(vet, numElementos - 1);
}

int EhPar(int numero)
{
    if (numero % 2 == 0)
    {
        return numero;
    }
    return 0;
}
