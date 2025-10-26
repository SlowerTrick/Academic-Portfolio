#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

// Força o alinhamento de 1 byte para evitar padding
#pragma pack(push, 1)
struct Aluno
{
    char nome[50];
    char dataNascimento[11];
    char curso[45];
    float prctConclusao;
    float cfRendimento;
};
#pragma pack(pop)

tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento)
{
    tAluno *a = calloc(1, sizeof(*a));
    if (a == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o aluno.\n");
        exit(1);
    }
    strcpy(a->nome, nome);
    strcpy(a->dataNascimento, dataNascimento);
    strcpy(a->curso, curso);
    a->prctConclusao = prctConclusao;
    a->cfRendimento = cfRendimento;
    return a;
}

void DestroiAluno(tAluno *aluno)
{
    if(aluno)
        free(aluno);
    aluno = NULL;
}

tAluno *LeAluno()
{
    char nome[50], dataNascimento[11], curso[45];
    float prctConclusao, cfRendimento;

    scanf(" %[^\n] %[^\n] %[^\n] %f %f%*c", nome, dataNascimento, curso, &prctConclusao, &cfRendimento);
    return CriaAluno(nome, dataNascimento, curso, prctConclusao, cfRendimento);
}

int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2)
{
    return strcmp(aluno1->nome, aluno2->nome);
}

int SalvaAluno(tAluno *aluno, FILE *file)
{
    int num = fwrite(aluno, sizeof(*aluno), 1, file);
    printf("%d\n", num);
    return sizeof(*aluno);
}

int CarregaAluno(tAluno *aluno, FILE *file)
{
    fread(aluno, sizeof(*aluno), 1, file);
    return sizeof(*aluno);
}

void ImprimeNomeAluno(tAluno *aluno)
{
    printf("%s\n", aluno->nome);
}