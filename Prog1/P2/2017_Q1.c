#include <stdio.h>

int main (void)
{
    int tamanho = 0, posicao = 0, menor = -1, atual = 0, i = 0, contador = 0;

    scanf("%i", &tamanho);

    if (tamanho != 0)
    {
        for (i = 0; i < tamanho; i++)
        {
            scanf("%i", &atual);
            if (atual < menor || menor == -1)
            {
                menor = atual;
                posicao = i+1;
            }
            contador++;
        }
    }
    if (menor != -1)
    {
        printf ("POS:%i", posicao);
    }
}