#include <stdio.h>

int VerificaBorda(char bloco[3][4]);

int main(void)
{
    int altura = 0, largura = 0;
    scanf ("%d%d", &largura, &altura);
    char mapa[altura][largura];    

    int i = 0, j = 0;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            scanf (" %c", &mapa[i][j]);
        }
    }
    int contador = 0;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            char bloco[3][4];
            if (mapa[i][j] == '0')
            {
                bloco[0][0] = mapa[i-1][j-1];
                bloco[0][1] = mapa[i-1][j];
                bloco[0][2] = mapa[i-1][j+1];
                bloco[1][0] = mapa[i][j-1];
                bloco[1][1] = mapa[i][j];
                bloco[1][2] = mapa[i][j+1];
                bloco[2][0] = mapa[i+1][j-1];
                bloco[2][1] = mapa[i+1][j];
                bloco[2][2] = mapa[i+1][j+1];
                if (VerificaBorda(bloco))
                {
                    contador++;
                }
            }
        }
    }
    printf("%d\n", contador);
}

int VerificaBorda(char bloco[3][4])
{
    int i = 0, j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (bloco[i][j] == '1' && (i != 1 && j != 1))
            {
                return 1;
            }
        }
    }
    return 0;
}