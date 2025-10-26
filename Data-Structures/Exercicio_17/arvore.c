#include "arvore.h"
#include "aluno.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct arvore
{
    Aluno *aluno;
    struct arvore *esq;
    struct arvore *dir;
};

Arvore *criaArvore()
{
    return NULL;
}

Arvore *insereArvore(Arvore *a, Aluno *aluno)
{
    if (!a)
    {
        Arvore *a = malloc(sizeof(*a));
        if (!a)
        {
            printf("ERRO! falta de memoria");
            exit(1);
        }
        a->aluno = aluno;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }
    int comparacao = strcmp(retornaNomeAluno(a->aluno), retornaNomeAluno(aluno));

    if (comparacao < 0)
        a->esq = insereArvore(a->esq, aluno);
    else if (comparacao > 0)
        a->dir = insereArvore(a->dir, aluno);
    return a;
}

Aluno *buscaArvore(Arvore *a, char *nome)
{
    if (a == NULL)
        return NULL;

    int comparacao = strcmp(retornaNomeAluno(a->aluno), nome);

    if (comparacao == 0)
        return a->aluno;
    else if (comparacao < 0)
        return buscaArvore(a->esq, nome);
    else
        return buscaArvore(a->dir, nome);
}

void imprimeArvore(Arvore *a, FILE *saida)
{
    if (a)
    {
        imprimeAluno(a->aluno, saida);
        imprimeArvore(a->esq, saida);
        imprimeArvore(a->dir, saida);
    }
}

void liberaArvore(Arvore *a)
{
    if (a)
    {
        liberaAluno(a->aluno);
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
}
