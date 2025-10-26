//
//  fila.c
//  Fila
//
//  Created by Artur Vitor Cintra Bernardes on 11/06/25.
//

#include "fila.h"

static void memory_check(void *p);

typedef struct celula
{
    Amostra *dado;
    struct celula *prox;
    struct celula *ant;
}
Celula;

Celula *cria_celula(Amostra *a)
{
    Celula *c = malloc(sizeof(*c));
    memory_check(c);
    c->dado = a;
    c->ant = NULL;
    c->prox = NULL;
    return c;
}

void imprime_celula(Celula *c)
{
    imprimeAmostra(c->dado);
}

void libera_celula(Celula *c)
{
    if(c != NULL)
        free(c);
}


struct fila
{
    Celula *prim;
    Celula *ult;
};


Fila *cria_fila()
{
    Fila *f = malloc(sizeof(*f));
    memory_check(f);
    f->prim = NULL;
    f->ult = NULL;
    return f;
}

void insere_fila(Fila *f, Amostra *a)
{
    Celula *c = cria_celula(a);
    int idade = retornaIdade(c->dado);
    if(f->prim == NULL)
    {
        f->prim = c;
        f->ult = c;
        c->ant = NULL;
        c->prox = NULL;
    }
    else if(idade >= 60)
    {
        c->prox = f->prim;
        f->prim->ant = c;
        f->prim = c;
        c->ant = NULL;
        
    }
    else if(idade <= 60)
    {
        c->ant = f->ult;
        f->ult->prox = c;
        f->ult = c;
        c->prox = NULL;
    }
}

Amostra *remove_elemento_fila(Fila *f)
{
    if(f->prim == NULL)
        return NULL;

    Celula *temp = f->prim;
    f->prim = NULL;
    if(temp->prox)
    {
        f->prim = temp->prox;
        f->prim->ant = NULL;
    }
    else
    {
        f->prim = NULL;
        f->ult = NULL;
    } 

    Amostra *a = temp->dado;
    libera_celula(temp);
    return a;
} 

void imprime_fila(Fila *f)
{
    for(Celula *temp = f->prim; temp != NULL; temp = temp->prox)
        imprime_celula(temp);
}

void libera_fila(Fila *f)
{
    if(f)
    {
        Celula *temp = f->prim, *c;
        while (temp != NULL)
        {
            c = temp;
            temp = temp->prox;
            libera_celula(c);
        }
        
        free(f);
    }
}


static void memory_check(void *p)
{
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}