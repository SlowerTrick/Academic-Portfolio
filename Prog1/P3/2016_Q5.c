#include <stdio.h>
#include <string.h>
#include <ctype.h>

int VerificaValidade(char fonte[], char alvo[]);

int main (void)
{
    int total = 0;
    scanf("%d", &total);
    getchar();

    int i = 0;
    for (i = 0; i < total; i++)
    {
        char fonte[400];
        char alvo[400];
        scanf("%s %s", &alvo, &fonte);
        if (VerificaValidade(fonte, alvo))
        {
            printf ("PODE!\n");
        }
        else
        { 
            printf("NAO PODE!\n");
        }
    }
    return 0;
}

int VerificaValidade(char fonte[], char alvo[])
{
    int tamanhoFonte = strlen(fonte);
    int tamanhoAlvo = strlen(alvo);
    
    int i = 0, contadorAlvo = 0;
    for (i = 0; i < tamanhoFonte; i++)
    {
        if (toupper(alvo[contadorAlvo]) == toupper(fonte[i]))
        {
            contadorAlvo++;
        }
    }

    if (contadorAlvo == tamanhoAlvo)
    {
        return 1;
    }
    return 0;
}