#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char *nome;
    int mat;
    int cr;
};

static void check_memory(void *p)
{
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}


Aluno *cria_aluno(char *nome, int mat, int cr)
{
    Aluno *a = malloc(sizeof(*a));
    check_memory(a);
    a->nome = strdup(nome);
    a->mat = mat;
    a->cr = cr;
    return a;
}

int retorna_matricula(Aluno *a)
{
    return a->mat;
}

char *retorna_nome(Aluno *a)
{
    return a->nome;
}

void imprime_aluno(Aluno *a)
{
    printf("%d %s %d\n", a->mat, a->nome, a->cr);
}

void libera_aluno(void *a)
{
    Aluno *aluno = (Aluno *) a;
    if(aluno)
    {
        free(aluno->nome);
        free(aluno);
    }
}