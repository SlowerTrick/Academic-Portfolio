#include <stdio.h>

int EhFinalDaLista(int buraco);
int EncontraMaiorBuraco();
int ContaEsferasGrandes(int maiorBuraco);

int main (void)
{
    int esferas = 0, diametro = 0;

    diametro = EncontraMaiorBuraco();
    esferas = ContaEsferasGrandes(diametro);

    printf ("QTD:%i\n", esferas);
    return 0;
}

int EhFinalDaLista(int buraco)
{
    if (buraco == -1)
    {
        return 1;
    }
    return 0;
}

int EncontraMaiorBuraco()
{
    int maior = 0, atual = 0;
    while (1)
    {
        scanf("%i", &atual);
        if (atual == -1)
        {
            break;
        }

        if (maior < atual)
        {
            maior = atual;
        }
    }

    return maior;
}

int ContaEsferasGrandes(int maiorBuraco)
{
    int total = 0, atual = 0;

    while (1)
    {
        scanf("%i", &atual);
        if (atual == -1)
        {
            break;
        }

        if (atual >= maiorBuraco)
        {
            total++;
        }
    }
    return total;
}