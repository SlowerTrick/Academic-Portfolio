#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int largura = 0, altura = 0;
    scanf("%i%i", &largura, &altura);
    int matriz[altura][largura];

    int i = 0, j = 0;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            matriz[i][j] = 0;
        }
    }

    int localx = 0, localy = 0;
    int atualx = 0, atualy = 0;
    while (scanf("%i%i", &localx, &localy) != EOF)
    {
        if (abs(atualx - localx) <= abs(atualy - localy))
        {
            while (atualx != localx)
            {
                if (atualx < localx)
                {
                    atualx++;
                    matriz[atualy][atualx] = 1;
                }
                if (atualx > localx)
                {
                    atualx--;
                    matriz[atualy][atualx] = 1;
                }
            }
            while (atualy != localy)
            {
                if (atualy < localy)
                {
                    atualy++;
                    matriz[atualy][atualx] = 1;
                }
                if (atualy > localy)
                {
                    atualy--;
                    matriz[atualy][atualx] = 1;
                }
            }
        }
        else 
        {
            while (atualy != localy)
            {
                if (atualy < localy)
                {
                    atualy++;
                    matriz[atualy][atualx] = 1;
                }
                if (atualy > localy)
                {
                    atualy--;
                    matriz[atualy][atualx] = 1;
                }
            }
            while (atualx != localx)
            {
                if (atualx < localx)
                {
                    atualx++;
                    matriz[atualy][atualx] = 1;
                }
                if (atualx > localx)
                {
                    atualx--;
                    matriz[atualy][atualx] = 1;
                }
            }
        }
    }

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}