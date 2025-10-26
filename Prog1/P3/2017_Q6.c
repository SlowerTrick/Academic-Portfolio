#include <stdio.h>
#include <string.h>

int EhIgualAoTemplate(char solda[], char template[], int length);

int main(void)
{
    int alturaSolda = 0, larguraSolda = 0;
    scanf("%d%d", &alturaSolda, &larguraSolda);
    char mapaSolda[alturaSolda][larguraSolda + 1];

    int i = 0, j = 0, k = 0;
    for (i = 0; i < alturaSolda; i++)
    {
        scanf("%s", mapaSolda[i]);
    }

    int alturaTemplate = 0, larguraTemplate = 0;
    scanf("%d%d", &alturaTemplate, &larguraTemplate);
    char mapaTemplate[alturaTemplate][larguraTemplate + 1];

    for (i = 0; i < alturaTemplate; i++)
    {
        scanf("%s", mapaTemplate[i]);
    }

    for (i = 0; i <= alturaSolda - alturaTemplate; i++)
    {
        for (j = 0; j <= larguraSolda - larguraTemplate; j++)
        {
            int flag = 1;
            for (k = 0; k < alturaTemplate; k++)
            {
                if (!EhIgualAoTemplate(&mapaSolda[i + k][j], mapaTemplate[k], larguraTemplate))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                printf("%d,%d\n", j, i);
            }
        }
    }

    return 0;
}

int EhIgualAoTemplate(char solda[], char template[], int length)
{
    return strncmp(solda, template, length) == 0;
}
