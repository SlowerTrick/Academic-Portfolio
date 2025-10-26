#include "Lista.h"
#include "Gato.h"
#include "Cachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void check_pointer(void *p);

typedef struct node
{
    struct node *prox;
    struct node *ant;
    void *dado;
    char *(*get_nome)(void *);
    int (*get_agressividade)(void *);
    void (*imprime_dado)(void *);
    void (*libera_dado)(void *);
} 
Node;

Node *cria_node(void *dado, char *(*get_nome)(void *), int (*get_agressividade)(void *), void (*imprime_dado)(void *), void (*libera_dado)(void *))
{
    Node *n = malloc(sizeof(*n));
    check_pointer(n);
    n->dado = dado;
    n->get_nome = get_nome;
    n->get_agressividade = get_agressividade;
    n->imprime_dado = imprime_dado;
    n->libera_dado = libera_dado;
    return n;
}

void imprime_node(Node *n)
{
    n->imprime_dado(n->dado);
}

void libera_node(Node *node) 
{
    if(node)
        free(node);
}

char *get_nome_node(Node *n)
{
    return n->get_nome(n->dado);
}

int get_agressividade(Node *n)
{
    return n->get_agressividade(n->dado);
}

void *get_dado_node(Node *n)
{
    return n->dado;
}

// LISTA

struct lista
{
    Node *prim;
    Node *ult;
    int total_elementos;
    int total_cachorros;
    int total_gatos;
};

Lista *cria_lista()
{
    Lista *l = malloc(sizeof(*l));
    l->prim = NULL;
    l->ult = NULL;
    l->total_elementos = 0;
    l->total_cachorros = 0;
    l->total_gatos = 0;
    return l;
}

void adiciona_elemento_lista(Lista *l, void *elemento, int tipo)
{
    Node *new = NULL;
    if(tipo == CACHORRO)
    {
        new = cria_node(
            elemento,
            (char *(*)(void *))get_nome_cachorro,
            (int (*)(void *))get_agressividade_cachorro,
            (void (*)(void *))imprimeCachorro,
            (void (*)(void *))liberaCachorro
        );
        l->total_cachorros++;
    }
    else if(tipo == GATO)
    {
        new = cria_node(
            elemento,
            (char *(*)(void *))get_nome_gato,
            (int (*)(void *))get_agressividade_gato,
            (void (*)(void *))imprimeGato,
            (void (*)(void *))liberaGato
        );
        l->total_gatos++;
    }
    if(l->prim == NULL)
    {
        l->prim = new;
        l->ult = new;
        new->prox = NULL;
        new->ant = NULL;
    }
    else
    {
        new->ant = l->ult;
        new->prox = NULL;
        l->ult->prox = new;
        l->ult = new;
    }
    l->total_elementos++;
}

int get_total_elementos_lista(Lista *l)
{
    return l->total_elementos;
}

int get_total_cachorros_lista(Lista *l)
{
    return l->total_cachorros;
}

int get_total_gatos_lista(Lista *l)
{
    return l->total_gatos;
}

void remove_elemento_lista(Lista *l, char *dado)
{
    Node *temp = l->prim;
    while (temp)
    {
        if (strcmp(get_nome_node(temp), dado) == 0)
        {
            if (temp->ant)
                temp->ant->prox = temp->prox;
            else
                l->prim = temp->prox;

            if (temp->prox)
                temp->prox->ant = temp->ant;
            else
                l->ult = temp->ant;

            if (get_agressividade(temp) == CACHORRO)
                l->total_cachorros--;
            else
                l->total_gatos--;

            l->total_elementos--;
            libera_node(temp);
            break;
        }
        temp = temp->prox;
    }
}

void *recupera_elemento_lista(Lista *l, char *dado)
{
    for(Node *temp = l->prim; temp != NULL; temp = temp->prox)
        if(strcmp(get_nome_node(temp), dado) == 0)
            return get_dado_node(temp);
}

void imprime_lista(Lista *l)
{
    for(Node *temp = l->prim; temp != NULL; temp = temp->prox)
        imprime_node(temp);
}

void libera_lista(Lista *l) 
{

    if(l)
    {
        Node *atual = l->prim;
        while (atual != NULL) {
            Node *prox = atual->prox;
            free(atual);
            atual = prox; 
        }
    
        free(l);
    }
}

static void check_pointer(void *p)
{
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}
