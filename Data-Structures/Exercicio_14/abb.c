#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "aluno.h"

struct abb
{
	Aluno *dado;
	struct abb *esq;
	struct abb *dir;
};


Abb *cria_abb()
{
    return NULL;
}

Abb *busca_abb(Abb *a, int mat)
{
    if(a)
    {
        if(retorna_matricula(a->dado) > mat)
            return busca_abb(a->esq, mat);
        else if(retorna_matricula(a->dado) < mat)
            return busca_abb(a->dir, mat);
        return a;
    }
    return NULL;
}


Abb *retira_abb(Abb *a, int mat)
{
    if (a == NULL)
        return NULL;

    if (retorna_matricula(a->dado) > mat)
        a->esq = retira_abb(a->esq, mat);
    else if (retorna_matricula(a->dado) < mat)
        a->dir = retira_abb(a->dir, mat);
    else
    {
        if (a->esq == NULL && a->dir == NULL)
        {
            free(a); 
            return NULL;
        }
        else if (a->esq == NULL)
        {
            Abb *temp = a->dir;
            free(a);
            return temp;
        }
        else if (a->dir == NULL)
        {
            Abb *temp = a->esq;
            free(a);
            return temp;
        }
        else
        {
            Abb *f = a->esq;
            while (f->dir != NULL)
                f = f->dir;
            a->dado = f->dado;
            f->dado = NULL; 
            a->esq = retira_abb(a->esq, retorna_matricula(a->dado));
        }
    }
    return a;
}

void imprime_abb(Abb *a)
{
	if(a)
	{
		printf("<%s", retorna_nome(a->dado));
		imprime_abb(a->esq);
		imprime_abb(a->dir);
		printf(">");
	}
	else
	{
		printf("<>");
	}
}

Abb *insere_abb(Abb *a, Aluno *aluno)
{
    if(!a)
    {
        Abb *arv = malloc(sizeof(*arv));
        if(!arv)
        {
            printf("Erro! falta de memoria");
            exit(1);
        }
        arv->dado = aluno;
        arv->esq = NULL;
        arv->dir = NULL;
        return arv;
    }
    if(retorna_matricula(a->dado) > retorna_matricula(aluno))
        a->esq = insere_abb(a->esq, aluno);
    else if(retorna_matricula(a->dado) < retorna_matricula(aluno))
        a->dir = insere_abb(a->dir, aluno);
    return a;
}

void libera_abb(Abb *a)
{
    if(a)
    {
        libera_abb(a->esq);
        libera_abb(a->dir);
        free(a);
    }
}