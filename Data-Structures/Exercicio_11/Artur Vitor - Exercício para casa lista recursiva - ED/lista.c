#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    Aluno *aluno;
    struct lista *prox;
};

Lista *cria_lista(Aluno *a)
{
    Lista *l = malloc(sizeof(*l));
    if(!l)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    l->aluno = a;
    l->prox = NULL;
    return l;
}

Lista *adiciona_lista(Lista *l, Aluno *a)
{
    if (l == NULL)
        return cria_lista(a);
    else if (l->prox == NULL)
        l->prox = cria_lista(a);
    else
        l->prox = adiciona_lista(l->prox, a);
    return l;
}

Lista *remove_lista(Lista *l, Aluno *a)
{
    if(!l)
        return NULL;

    else if(retorna_matricula(a) == retorna_matricula(l->aluno))
    {
        Lista *aux = l;
        l = l->prox;
        free(aux);
        return l;
    }
    else 
        l->prox = remove_lista(l->prox, a);
    return l;
}

void imprime_lista(Lista *l)
{
    if(l != NULL)
    {
        imprime_aluno(l->aluno);
        imprime_lista(l->prox);
    }
}

void libera_lista(Lista *l)
{
    if(l != NULL)
    {
        Lista *aux = l;
        l = l->prox;
        free(aux);
        libera_lista(l);
    }
}
    