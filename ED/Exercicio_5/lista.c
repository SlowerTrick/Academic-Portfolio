#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lista.h"

struct lista
{
    Produto *prod;
    tLista *prox;
    tLista *ant;
};

static void check_memory(tLista *l);

tLista *cria_lista()
{
    return NULL;
}

Produto *get_produto_lista(tLista *l, char *nome)
{
    for(tLista *temp = l; temp != NULL; temp = temp->prox)
        if(strcmp(nome, get_nome_produto(temp->prod)) == 0)
            return temp->prod;
    return NULL;
}

tLista *adiciona_elemento_lista(tLista *l, Produto *p)
{
    if(l == NULL)
    {
        l = malloc(sizeof(tLista));
        check_memory(l);
        l->prod = p;
        l->prox = NULL;
        l->ant = NULL;
        printf("Produto: '%s' adicionado!\n", get_nome_produto(p));
        return l;
    }
    tLista *new = malloc(sizeof(*new));
    check_memory(new);
    new->prod = p;
    new->ant = NULL;
    new->prox = l;
    l->ant = new;
    printf("Produto: '%s' adicionado!\n", get_nome_produto(p));
    return new;
}

tLista *remove_elemento_lista(tLista *l, char *nome)
{
    for(tLista *temp = l; temp != NULL; temp = temp->prox)
    {
        if(strcmp(nome, get_nome_produto(temp->prod)) == 0)
        {
            if(temp->ant)
                temp->ant->prox = temp->prox;
            if(temp->prox)
                temp->prox->ant = temp->ant;
            if(!temp->ant)
                l = temp->prox;
            libera_elemento_lista(temp);
            printf("Produto: '%s' removido da lista!\n", nome);
            return l;
        }
    }
    return l;
}

void imprime_lista(tLista *l)
{
    for(tLista *temp = l; temp != NULL; temp = temp->prox)
    {
        if(temp->ant)
        {
            printf("Anterior:\n");
            imprime_produto(temp->ant->prod);
        }
        printf("Atual:\n");
        imprime_produto(temp->prod);
        if(temp->prox)
        {
            printf("Proximo:\n");
            imprime_produto(temp->prox->prod);
        }
        printf("\n");
    }
}

void libera_elemento_lista(tLista *l)
{
    free(l);
}

void libera_lista(tLista *l)
{
    tLista *aux, *temp = l;
    while (temp)
    {
        aux = temp;
        temp = temp->prox;
        free(aux);
    }
}

static void check_memory(tLista *l)
{
    if(!l)
    {
        printf("ERRO! falta de memoria\n");
        exit(1);
    }
}