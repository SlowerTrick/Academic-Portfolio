#include "aluno.h"

struct aluno
{
    char *nome;
    int presencas;
    int faltas;
    struct aluno *prox;
};


Aluno *criaAluno(char *nome)
{
    Aluno *a = malloc(sizeof(*a));
    if(!a)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    a->nome = strdup(nome);
    a->presencas = 0;
    a->faltas = 0;
    a->prox = NULL;
    return a;
}

char *retornaNomeAluno(Aluno *a)
{
    return a->nome;
}

int retornaPresencaAluno(Aluno *a)
{
    return a->presencas;
}

int retornaFaltasAluno(Aluno *a)
{
    return a->faltas;
}

void imprimeAluno(Aluno *a)
{
    if(a)
    {
        printf("%s %dP %dF\n", a->nome, a->presencas, a->faltas);
        imprimeAluno(a->prox);
    }
}

int insereColisaoAluno(Aluno *a, Aluno *n)
{
    if(a->prox != NULL)
        return insereColisaoAluno(a->prox, n);
    a->prox = n;
    return 1;
}

Aluno *retornaProxAluno(Aluno *a)
{
    return a->prox;
}

Aluno *buscaListaAluno(Aluno *a, char *b)
{
    if(a == NULL)
        return NULL;
    if(strcmp(a->nome, b) == 0)
        return a;
    return buscaListaAluno(a->prox, b);
}

void atualizaPresencaAluno(Aluno *a, char p)
{
    if(a)
        (p == 'P') ? a->presencas++ : a->faltas++;
}

void liberaAluno(Aluno *a)
{
    if(a)
    {
        liberaAluno(a->prox);
        free(a->nome);
        free(a);
    }
}