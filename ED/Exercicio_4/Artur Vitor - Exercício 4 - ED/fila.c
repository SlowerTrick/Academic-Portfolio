//
//  fila.c
//  TADFila
//
//  Created by Artur Vítor Cintra Bernardes on 21/05/25.
//  Este arquivo define a estrutura e as operações básicas para manipulação de uma fila de produtos.
//  A fila é implementada como uma lista encadeada.
//

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct celula

typedef struct celula
{
    Produto *produto;
    struct celula *prox;
}
Celula;

Celula *cria_celula(Produto *p)
{
    Celula *c = malloc(sizeof(*c));
    if(!c)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    c->produto = p;
    c->prox = NULL;
    return c;
}
Celula *get_prox_celula(Celula *c)
{
    return c->prox;
}
void adiciona_prox_celula(Celula *c, Celula *prox)
{
    c->prox = prox;
}
void imprime_celula(Celula *c)
{
    imprime_produto(c->produto);
}
int compara_nome_celula(Celula *c, char *nome)
{
    return strcmp(get_item_produto(c->produto), nome) == 0;
}
void libera_celula(Celula *c)
{
    if(c)
    {
        libera_produto(c->produto);
        free(c);
    }
    c = NULL;
}

// Struct fila

struct fila
{
    Celula *prim;
    Celula *ult;
};

Fila *cria_fila()
{
    Fila *f = malloc(sizeof(*f));
    if (!f)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    f->prim = NULL;
    f->ult = NULL;
    return f;
}

void adiciona_produto_fila(Fila *f, Produto *p)
{
    Celula *c = cria_celula(p);
    if (f->ult)
        adiciona_prox_celula(f->ult, c);
    else
        f->prim = c;

    f->ult = c;
}
void remove_produto_fila(Fila *f, char *nome)
{
    Celula *ant = NULL;
    for(Celula *temp = f->prim; temp != NULL; temp = temp->prox)
    {
        if(compara_nome_celula(temp, nome))
        {
            if(ant && temp->prox)
            {
                ant->prox = temp->prox;
            }
            else if(ant && !temp->prox)
            {
                f->ult = ant;
                ant->prox = NULL;
            }
            else if(!ant && temp->prox)
            {
                f->prim = temp->prox;
            }
            else if(!ant && !temp->prox)
            {
                f->prim = NULL;
                f->ult = NULL;
            }
            libera_celula(temp);
            return;
        }
        ant = temp;
    }
    printf("Produto %s nao encontrado!\n", nome);
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
        Celula *ant = NULL, *temp = f->prim;
        while (temp)
        {
            ant = temp;
            temp = temp->prox;
            libera_celula(ant);
        }
        free(f);
    }
    f = NULL;
}