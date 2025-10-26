
//
//  lista.c
//  Prova1ED
//
//  Created by Artur Vitor Cintra Bernardes on 18/06/25.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//


#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula
{
    TProduto *dado;
    struct celula *next;
}
Celula;

Celula *cria_celula(TProduto *dado)
{
    Celula *c = malloc(sizeof(*c));
    if(!c)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    c->dado = dado;
    c->next = NULL;
    return c;
}

void imprime_celula(Celula *c)
{
    ImprimeIngredientes(c->dado);
}

void libera_celula(Celula *c)
{
    if(c)
    {
        free(c);
    }
}

struct lista
{
    Celula *prim;
    Celula *ult;
};

Lista *cria_lista()
{
    Lista *l = malloc(sizeof(*l));
    if(!l)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void adiciona_lista(TProduto *p, Lista *l)
{
    Celula *c = cria_celula(p);
    if(l->ult != NULL)
        l->ult->next = c;
    else
        l->prim = c;
    l->ult = c;
}

int busca_produto_lista(char *nome, Lista *l)
{
    Celula *temp = l->prim;
    while (temp != NULL)
    {
        if(strcmp(RetornaNome(temp->dado), nome) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int retorna_calorias_totais(Lista *l)
{
    int total = 0;
    Celula *temp = l->prim;
    while (temp != NULL)
    {
        total += Calorias(temp->dado);
        temp = temp->next;
    }
    return total;
}

TProduto *verifica_ingrediente_lista(Lista *l, char *ingrediente)
{
    Celula *temp = l->prim;
    while (temp != NULL)
    {
        if(VerificaIngrediente(temp->dado, ingrediente))
            return temp->dado;
        temp = temp->next;
    }
    return NULL;
}

TProduto *remove_lista(char *nome, Lista *l)
{
    Celula *temp = l->prim;
    Celula *ant = NULL;
    while (temp != NULL)
    {
        if(strcmp(RetornaNome(temp->dado), nome) == 0)
        {
            TProduto *dado = temp->dado;

            if (ant == NULL)
                l->prim = temp->next;
            else
                ant->next = temp->next;

            if (temp->next == NULL)
                l->ult = ant;

            libera_celula(temp);
            return dado;
        }
        ant = temp;
        temp = temp->next;
    }
    return NULL;
}

void imprime_lista(Lista *l)
{
    int count = 0;
    Celula *temp = l->prim;
    while (temp != NULL)
    {
        imprime_celula(temp);
        temp = temp->next;
        count++;
    }
    if(count == 0)
        printf("Nao ha produtos neste pedido!\n");
}

void libera_lista(Lista *l)
{
    if(l)
    {
        Celula *temp = l->prim;
        while (temp != NULL)
        {
            Celula *ant = temp;
            temp = temp->next;
            libera_celula(ant);
        }
        free(l);
    }
}

