#include <stdio.h>

int main(void)
{
    int quantidade = 0;
    scanf("%i", &quantidade);

    int i, j, k, a;
    int coluna1, linha1;
    int coluna2, linha2;

    for (i = 0; i < quantidade; i++)
    {
        scanf("%i %i", &coluna1, &linha1);
        int matriz1[linha1][coluna1];
        for (j = 0; j < linha1; j++)
        {
            for (k = 0; k < coluna1; k++)
            {
                scanf("%i", &matriz1[j][k]);
            }
        }

        scanf("%i %i", &coluna2, &linha2);
        int matriz2[linha2][coluna2];
        for (j = 0; j < linha2; j++)
        {
            for (k = 0; k < coluna2; k++)
            {
                scanf("%i", &matriz2[j][k]);
            }
        }

        if (coluna1 == linha2)
        {
            int matrizresultado[linha1][coluna2];
            // Calcula a matriz resultado
            for (j = 0; j < linha1; j++)
            {
                for (k = 0; k < coluna2; k++)
                {
                    matrizresultado[j][k] = 0;
                    for (a = 0; a < coluna1; a++)
                    {
                        matrizresultado[j][k] += matriz1[j][a] * matriz2[a][k];
                    }
                }
            }
            for (j = 0; j < linha1; j++)
            {
                for (k = 0; k < coluna2; k++)
                {
                    printf("%i", matrizresultado[j][k]);
                    if (k != coluna2 - 1)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
        else
        {
            printf("IMPOSSIVEL\n\n");
        }
    }

    return 0;
}