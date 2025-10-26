#include <stdio.h>

int EhPonta (int cima, int baixo, int esquerda, int direita, int valor); 

int main (void)
{
    int horas = 0, altura = 0, largura = 0;
    scanf ("%i%i%i", &horas, &largura, &altura);
    char matriz[altura][largura];
    getchar();

    int i = 0, j = 0;

    for (i = 0; i <= altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            scanf("%c", &matriz[i][j]);
        }
        getchar();
    }

    int terra = 0, previsao = 0;

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (matriz[i][j] == '0')
            {
                terra++;
            }
        }
    }

    while (horas != 0)
    {
        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                if (matriz[i][j] == '0')
                {
                    if (EhPonta(matriz[i-1][j], matriz[i+1][j], matriz[i][j-1], matriz[i][j+1], matriz[i][j]))
                    {
                        matriz[i][j] = '2';
                    }
                }
            }
        }
        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                if (matriz[i][j] == '2')
                {
                    matriz[i][j] = '1';
                }
            }
        }
        horas--;
    }

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (matriz[i][j] == '0')
            {
                previsao++;
            }
        }
    }
    printf("%i %i", terra, previsao);
}

int EhPonta (int cima, int baixo, int esquerda, int direita, int valor)
{
    if (cima == '1' || baixo == '1' || direita == '1' || esquerda == '1')
    {
        return 1;
    }
    return 0;
}
