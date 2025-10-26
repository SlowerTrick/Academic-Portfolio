#include <stdio.h>
#include <string.h>

int EhIgual(char mapa[], char template[], int larguraTemplate);

int main(void)
{
    int alturaMapa = 0, larguraMapa = 0;
    scanf("%d%d", &alturaMapa, &larguraMapa);
    char mapa[alturaMapa][larguraMapa + 1];

    int i = 0, j = 0, k = 0;
    for (i = 0; i < alturaMapa; i++)
    {
        scanf("%s", mapa[i]);
    }

    int alturaTemplate = 0, larguraTemplate = 0;
    scanf("%d%d", &alturaTemplate, &larguraTemplate);
    char mapaTemplate[alturaTemplate][larguraTemplate + 1];

    for (i = 0; i < alturaTemplate; i++)
    {
        scanf("%s", mapaTemplate[i]);
    }

    int contador = 0, erros = 0;

    for (i = 0; i <= alturaMapa - alturaTemplate; i++)
    {
        for (j = 0; j <= larguraMapa - larguraTemplate; j++)
        {
            int ehErro = 1;
            for (k = 0; k < alturaTemplate; k++)
            {
                if (!EhIgual(&mapa[i + k][j], mapaTemplate[k], larguraTemplate))
                {
                    ehErro = 0;
                    break;
                }
            }
            if (ehErro)
            {
                erros++;
            }
        }
    }
    printf("RESP:%d", erros);
}


int EhIgual(char mapa[], char template[], int larguraTemplate)
{
    return strncmp(mapa, template, larguraTemplate) == 0;
}