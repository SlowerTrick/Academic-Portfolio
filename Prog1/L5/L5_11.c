#include <stdio.h>

typedef struct
{
    int numero;
    char origem;
}
numero;


void OrdenaCrescente(int vet[], int qtd);
void OrdenaCrescente2(numero vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main (void)
{
    int quantidade1 = 0, quantidade2 = 0, i = 0, j = 0;
    scanf ("%i", &quantidade1);
    int numero1[quantidade1];

    for (i = 0; i < quantidade1; i++)
    {
        scanf("%i", &numero1[i]);
    }

    OrdenaCrescente(numero1, quantidade1);
    
    scanf("%i", &quantidade2);
    int numero2[quantidade2];

    for (i = 0; i < quantidade2; i++)
    {
        scanf("%i", &numero2[i]);
    }

    OrdenaCrescente(numero2, quantidade2);

    int quantidadetotal = quantidade1 + quantidade2;
    numero numeros[quantidadetotal];

    for (i = 0; i < quantidade1; i++)
    {
        numeros[i].numero = numero1[i];
        numeros[i].origem = 'A';
    }

    int contador = 0;

    for (i = quantidade1; i < quantidadetotal; i++)
    {
        numeros[i].numero = numero2[contador];
        numeros[i].origem = 'B';
        contador++;
    }

    OrdenaCrescente2(numeros, quantidadetotal);

    for (i = 0; i < quantidadetotal; i++)
    {
        printf ("%c", numeros[i].origem);
    }
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

void OrdenaCrescente2(numero vet[], int qtd)
{
    int i = 0, j = 0;

    for (i = 0; i < qtd; i++)
    {
        for (j = i+1; j < qtd; j++)
        {
            if (vet[i].numero > vet[j].numero)
            {
                int aux = vet[i].numero;
                vet[i].numero = vet[j].numero;
                vet[j].numero = aux;

                char aux2 = vet[i].origem;
                vet[i].origem = vet[j].origem;
                vet[j].origem = aux2;
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

    printf ("}\n");
    return;
}