#include "pais.h"

struct pais
{
    char *nome;
    int ouro;
    int prata;
    int bronze;
    int total;
    struct pais *prox;
};

Pais *criaPais(char *nome, int ouro, int prata, int bronze, int total)
{
    Pais *p = malloc(sizeof(*p));
    if(!p)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    p->nome = strdup(nome);
    p->ouro = ouro;
    p->prata = prata;
    p->bronze = bronze;
    p->total = total;
    p->prox = NULL;
    return p;
}

void imprimePais(Pais *p, FILE *saida)
{
    if(p)
    {
        imprimePais(p->prox, saida);
        fprintf(saida, "%s %d %d %d %d\n", p->nome, p->ouro, p->prata, p->bronze, p->total);
    }
}

char *retornaNomePais(Pais *p)
{
    return p->nome;
}

int retornaOuroPais(Pais *p)
{
    return p->ouro;
}

int retornaPrataPais(Pais *p)
{
    return p->prata;
}

int retornaBronzePais(Pais *p)
{
    return p->bronze;
}

int retornaTotalPais(Pais *p)
{
    return p->total;
}

Pais *retornaProxPais(Pais *p)
{
    return p->prox;
}

Pais *retornaListaPais(Pais *p, char *key)
{
    if(p)
    {
        if(strcmp(p->nome, key) == 0)
            return p;
        return retornaListaPais(p->prox, key);
    }
    return NULL;
}

int colisaoPais(Pais *p, Pais *new)
{
    if (strcmp(p->nome, new->nome) == 0)
    {
        p->ouro = new->ouro;
        p->prata = new->prata;
        p->bronze = new->bronze;
        p->total = new->total;
        liberaPais(new);
        return 0;
    }
    
    if (p->prox != NULL)
        return colisaoPais(p->prox, new);

    p->prox = new;
    return 1;
}

void liberaPais(Pais *p)
{
    if(p)
    {
        liberaPais(p->prox);
        free(p->nome);
        free(p);
    }
}