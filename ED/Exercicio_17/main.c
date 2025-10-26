#include "aluno.h"
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");
    if (entrada == NULL || saida == NULL)
    {
        printf("Arquivo nao encontrado");
        return 0;
    }

    int numero_arquivos;
    fscanf(entrada, "%*c %d%*c", &numero_arquivos);

    Arvore *arvore = criaArvore();
    char nome[100];
    while (fscanf(entrada, "%s%*c", nome) == 1)
    {
        Aluno *aluno = criaAluno(nome);
        arvore = insereArvore(arvore, aluno);
    }

    for (int i = 0; i < numero_arquivos; i++)
    {
        char presenca;
        char buffer[100];
        sprintf(buffer, "entrada%d.txt", i+1);
        FILE *fptr = fopen(buffer, "r");
        if (fptr == NULL)
        {
            printf("Arquivo nao encontrado");
            return 0;
        }

        while (fscanf(fptr, "%s %c%*c", nome, &presenca) == 2)
        {
            Aluno *aluno = buscaArvore(arvore, nome);
            if (aluno)
            {
                if (presenca == 'P')
                    incrementaPresencasAluno(aluno);
                else
                    incrementaFaltasAluno(aluno);
            }
        }
    }
    imprimeArvore(arvore, saida);

    fclose(entrada);
    fclose(saida);
    liberaArvore(arvore);
    return 0;
}
