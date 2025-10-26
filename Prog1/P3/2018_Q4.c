#include <stdio.h>
#include <string.h>

int main(void)
{
    char palavra1[10000];
    char palavra2[10000];
    char maiorpalavra[10000];

    int i = 0;
    while(scanf(" %s %s", &palavra1, &palavra2) == 2)
    {   
        int tamanho1 = strlen(palavra1);
        int tamanho2 = strlen(palavra2);
        
        if (tamanho1 > tamanho2)
        {
            printf("%s\n", palavra1);
            if (strlen(maiorpalavra) < tamanho1)
            {
                for (i = 0; i < tamanho1; i++)
                {
                    maiorpalavra[i] = palavra1[i];
                }
            }
        }
        else if (tamanho2 > tamanho1)
        {
            printf("%s\n", palavra2);
            if (strlen(maiorpalavra) < tamanho1)
            {
                for (i = 0; i < tamanho2; i++)
                {
                    maiorpalavra[i] = palavra2[i];
                }
            }
        }
    }
    if (strlen(maiorpalavra) == 0)
    {
        printf ("MAX:--\n");
    }
    else
    {
        printf ("MAX:%s\n", maiorpalavra);
    }
}