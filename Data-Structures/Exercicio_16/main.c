#include <stdio.h>
#include <string.h>
#include "abbgen.h"

int compara_nome(void *aluno1, void *aluno2)
{
    return strcmp(retorna_nome((Aluno *)aluno1), retorna_nome((Aluno *)aluno2));
}

int compara_matricula(void *aluno1, void *aluno2)
{
    return retorna_matricula((Aluno *)aluno1) - retorna_matricula((Aluno *)aluno2);
}

int imprime_aluno_arvore(void *aluno, void *none)
{
    imprime_aluno((Aluno *)aluno);
    return 0;
}

int main(void)
{
    FILE *entrada = fopen("entrada.txt", "r");
    Arvgen *arvore = cria_arvegen();

    int mat, cr;
    char nome[1000];

    // Impressao por nome
    while (fscanf(entrada, "%d %s %d%*c", &mat, nome, &cr) == 3)
    {
        Aluno *aluno = cria_aluno(nome, mat, cr);
        arvore = insere_arvgen(arvore, compara_nome, aluno);
    }
    printf("\n");
    printf("Arvore organizada por Matricula\n");
    percorre_arvgen(arvore, imprime_aluno_arvore, NULL);

    // Impressao por matricula
    fseek(entrada, 0, SEEK_SET);
    libera_arvgen(arvore, libera_aluno);
    arvore = cria_arvegen();

    while (fscanf(entrada, "%d %s %d%*c", &mat, nome, &cr) == 3)
    {
        Aluno *aluno = cria_aluno(nome, mat, cr);
        arvore = insere_arvgen(arvore, compara_matricula, aluno);
    }

    printf("\n");
    printf("Arvore organizada por Nome\n");
    percorre_arvgen(arvore, imprime_aluno_arvore, NULL);
    printf("\n");

    libera_arvgen(arvore, libera_aluno);
    fclose(entrada);
}
