#include "hash.h"

static void checkMemory(void *p);
static int hashFunction(char *key, int dim);
static void redimensionaHash(Hash *h);
static void insereRedimensionado(Hash *h, Aluno *a);

struct hash
{
    int total;
    int dim;
    Aluno **vet;
};

Hash *criaHash()
{
    Hash *h = malloc(sizeof(*h));
    checkMemory(h);
    h->dim = HASH_DIM;
    h->total = 0;
    h->vet = calloc(HASH_DIM, sizeof(Aluno *));
    checkMemory(h->vet);
    return h;
}

void imprimeHash(Hash *h)
{
    for(int i = 0; i < h->dim; i++)
        if(h->vet[i] != NULL)
            imprimeAluno(h->vet[i]);
}

void insereHash(Hash *h, Aluno *a)
{
    if(h->total >= h->dim * 0.75)
        redimensionaHash(h);

    int idx = hashFunction(retornaNomeAluno(a), h->dim);

    if(h->vet[idx] == NULL)
    {
        h->vet[idx] = a; 
        h->total += 1;
    }
    else
        h->total += insereColisaoAluno(h->vet[idx], a);
}

static int hashFunction(char *key, int dim)
{
    int total = 0;
    for(int i = 0; key[i] != '\0'; i++)
        total += key[i];

    return total % dim;
}

static void redimensionaHash(Hash *h)
{
    int old_dim = h->dim;
    Aluno **vet = h->vet;

    h->dim *= 1.947;
    h->vet = calloc(h->dim, sizeof(Aluno *));
    checkMemory(h->vet);
    
    for(int i = 0; i < old_dim; i++)
        if(vet[i] != NULL)
            insereRedimensionado(h, vet[i]);
    
    free(vet);
}

static void insereRedimensionado(Hash *h, Aluno *a)
{
    int idx = hashFunction(retornaNomeAluno(a), h->dim);

    if(h->vet[idx] == NULL)
        h->vet[idx] = a; 
    else
        insereColisaoAluno(h->vet[idx], a);

}

Aluno *buscaHash(Hash *h, char *nome)
{
    return buscaListaAluno(h->vet[hashFunction(nome, h->dim)], nome);
}

int UnicosHash(Hash *h)
{
    return h->total;
}

void liberaHash(Hash *h)
{
    if(h)
    {   
        for(int i = 0; i < h->dim; i++)
            liberaAluno(h->vet[i]);
        free(h->vet);
        free(h);
    }
}

static void checkMemory(void *p)
{
    if(!p)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
}