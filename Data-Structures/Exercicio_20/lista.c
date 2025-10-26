#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void *dado;
    struct node *prox;
    struct node *ant;
}
Node;

Node *criaNode(void *dado)
{
    Node *n = malloc(sizeof(*n));
    if(!n)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    n->dado = dado;
    n->prox = NULL;
    n->ant = NULL;
    return n;
}

void liberaNode(Node *n, void (libera)(void *dado))
{
    if(n)
    {
        libera(n->dado);
        free(n);
    }
}

struct lista
{
    Node *prim;
    Node *ult;
};

Lista *criaLista()
{
    Lista *l = malloc(sizeof(*l));
    if (!l)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void insereLista(Lista *l, void *dado)
{
    Node *n = criaNode(dado);
    if(!l->prim)
    {
        l->prim = n;
        l->ult = n;
        return;
    }

    l->ult->prox = n;
    n->ant = l->ult;
    l->ult = n;
}

double percorreLista(Lista *l, FILE *saida, double (func)(void *, FILE *))
{
    Node *temp = l->prim;
    int total = 0;
    double media = 0;
    while(temp)
    {
        media += func(temp->dado, saida);
        total++;
        temp = temp->prox;
    }
    return media / total;
}

void liberaLista(Lista *l, void (libera)(void *dado))
{
    if(l)
    {
        Node *temp = l->prim;
        while(temp)
        {
            Node *aux = temp;
            temp = temp->prox;
            liberaNode(aux, libera);
        }
        free(l);
    }
}
