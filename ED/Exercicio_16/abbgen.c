#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abbgen.h"

struct arvgen
{
    void *dado;
    struct arvgen *dir;
    struct arvgen *esq;
};

Arvgen *cria_arvegen()
{
    return NULL;
}

Arvgen *insere_arvgen(Arvgen *a, int (*func)(void *, void *), void *dado)
{
    if(!a)
    {
        Arvgen *arv = malloc(sizeof(*arv));
        if(!arv)
        {
            printf("Erro! falta de memoria");
            exit(1);
        }
        arv->dado = dado;
        arv->esq = NULL;
        arv->dir = NULL;
        return arv;
    }
    int cmp = func(a->dado, dado);
    if(cmp > 0)
        a->esq = insere_arvgen(a->esq, func, dado);
    else if(cmp < 0)
        a->dir = insere_arvgen(a->dir, func, dado);
    return a;
}

int percorre_arvgen(Arvgen *arv, int (*func)(void *, void *), void *dado)
{
    if(arv)
    {
        int flag = percorre_arvgen(arv->esq, func, dado);
        if(flag) return flag;

        flag = func(arv->dado, dado);
        if(flag) return flag;

        flag = percorre_arvgen(arv->dir, func, dado);
        if(flag) return flag;
    }
    return 0;
}

void libera_arvgen(Arvgen *arv, void (*libera)(void *))
{
    if(arv)
    {
        libera_arvgen(arv->esq, libera);
        libera_arvgen(arv->dir, libera);
        libera(arv->dado);
        free(arv);
    }
}
