#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char *nome;
    int mat;
};

static void check_memory(void *p)
{
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}


Aluno *cria_aluno(char *nome, int mat)
{
    Aluno *a = malloc(sizeof(*a));
    check_memory(a);
    a->nome = strdup(nome);
    a->mat = mat;
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
    printf("%s\n", a->nome);
}

void libera_aluno(Aluno *a)
{
    if(a)
    {
        free(a->nome);
        free(a);
    }
}