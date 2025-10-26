#include <stdio.h>

int main (void)
{
    int linha = 0, coluna = 0, maior = 0, i = 0, j = 0, maiorlinha = 0, maiorcoluna = 0;
    scanf("%i%i", &linha, &coluna);
    int matriz[linha][coluna];

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            scanf("%i", &matriz[i][j]);
            if (maior < matriz[i][j])
            {
                maior = matriz[i][j];
                maiorlinha = i;
                maiorcoluna = j;
            }
        }
    }
    printf ("%i (%i, %i)", maior, maiorlinha+1, maiorcoluna+1);
}