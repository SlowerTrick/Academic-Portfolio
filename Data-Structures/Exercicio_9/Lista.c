#include "Lista.h"
#include "ComidaVegana.h"
#include "ComidaNaoVegana.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void checkMemory(void *p);

typedef struct celula
{
    void *dado;
    int tipo;
    struct celula *prox;
    struct celula *ant;
}
Celula;

Celula *criaCelula(void *dado, int tipo)
{
    Celula *c = malloc(sizeof(*c));
    checkMemory(c);
    c->ant = NULL;
    c->prox = NULL;
    c->dado = dado;
    c->tipo = tipo;
    return c;
}

void imprimeCelula(Celula *c)
{
    if(c->tipo == VEGANA)
        imprimeComidaVegana(c->dado);
    else
        imprimeComidaNaoVegana(c->dado);
}

char *retornaNomeCelula(Celula *c)
{
    if(c->tipo == VEGANA)
        return retornaNomeComidaVegana(c->dado);
    return retornaNomeComidaNaoVegana(c->dado);
}

float retornaValorCelula(Celula *c)
{
    if(c->tipo == N_VEGANA)
        return retornaValorComidaNaoVegana(c->dado);
    return 0;
}

void liberaCelula(Celula *c)
{
    if(c)
        free(c);
}

struct lista
{
    Celula *prim;
    Celula *ult;
    int total_elementos;
    int total_veganas;
    int total_n_veganas;
};

Lista *criaLista()
{
    Lista *l = malloc(sizeof(*l));
    checkMemory(l);
    l->prim = NULL;
    l->ult = NULL;
    l->total_elementos = 0;
    l->total_veganas = 0;
    l->total_n_veganas = 0;
    return l;
}

void adicionaLista(Lista *l, void *dado, int tipo)
{
    Celula *c = criaCelula(dado, tipo);
    if(l->ult != NULL)
        l->ult->prox = c;
    else
        l->prim = c;

    c->ant = l->ult;
    l->ult = c;
    c->prox = NULL;
    l->total_elementos++;
    if(tipo == VEGANA)
        l->total_veganas++;
    else
        l->total_n_veganas++;
}

float calculaValorLista(Lista *l)
{
    float total = 0;
    Celula *temp = l->prim;

    while (temp != NULL)
    {
        total += retornaValorCelula(temp);
        temp = temp->prox;
    }
    return total;
}

int obtemTotalElementosLista(Lista *l)
{
    return l->total_elementos;
}

int obtemTotalVeganosElementosLista(Lista *l)
{
    return l->total_veganas;
}
int obtemTotalNVeganosElementosLista(Lista *l)
{
    return l->total_n_veganas;
}

void *obtemLista(Lista *l, char *nome)
{
    Celula *temp = l->prim;
    while (temp != NULL && strcmp(retornaNomeCelula(temp), nome) != 0)
        temp = temp->prox;
    
    if(temp == NULL) return NULL;
    return temp->dado;
}

void removeLista(Lista *l, char *nome)
{
    Celula *temp = l->prim;
    while (temp != NULL && strcmp(retornaNomeCelula(temp), nome) != 0)
        temp = temp->prox;
    
    if(temp == NULL) return;

    if(temp->ant == NULL)
    {
        l->prim = temp->prox;
        if(temp->prox)
            temp->prox->ant = NULL;
    }
    else if(temp->prox == NULL)
    {
        l->ult = temp->ant;
        if(temp->ant)
            temp->ant->prox = NULL;
    }
    else
    {
        if(temp->ant)
            temp->ant->prox = temp->prox;
        if(temp->prox)
            temp->prox->ant = temp->ant;
    }
    
    l->total_elementos--;
    if (temp->tipo == VEGANA)
        l->total_veganas--;
    else
        l->total_n_veganas--;

    liberaCelula(temp);
}


void imprimeLista(Lista *l)
{
    Celula *temp = l->prim;

    while (temp != NULL) 
    {
        imprimeCelula(temp);
        temp = temp->prox;
    }
    
}

void liberaLista(Lista *l)
{
    if(l)
    {
        Celula *temp = l->prim;
    
        while (temp != NULL) 
        {
            Celula *aux = temp;
            temp = temp->prox;
            liberaCelula(aux);
        }
        free(l);
    }
}

static void checkMemory(void *p)
{
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}