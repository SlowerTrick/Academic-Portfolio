#include "hash.h"

static void checkMemory(void *p);
static int hashFunction(char *key, int dim);
static void redimensionaHash(Hash *h);
static void insereRedimensionadoHash(Hash *h, Pais *p);

struct hash
{
    int total;
    int dim;
    Pais **vet;
};

Hash *criaHash()
{
    Hash *h = malloc(sizeof(*h));
    checkMemory(h);

    h->total = 0;
    h->dim = HASH_SIZE;
    h->vet = calloc(HASH_SIZE, sizeof(Pais *));
    checkMemory(h->vet);

    return h;
}

static int hashFunction(char *key, int dim)
{
    int total = 0;
    for (int i = 0; key[i] != '\0'; i++)
        total += key[i];
    return total % dim;
}

void insereHash(Hash *h, Pais *p)
{
    if (h->total >= h->dim * 0.75)
        redimensionaHash(h);

    int idx = hashFunction(retornaNomePais(p), h->dim);
    if (h->vet[idx] == NULL)
    {
        h->vet[idx] = p;
        h->total++;
    }
    else
        h->total += colisaoPais(h->vet[idx], p);
}

static void redimensionaHash(Hash *h)
{
    int old_dim = h->dim;
    Pais **old_vet = h->vet;

    h->dim *= 1.947;
    h->vet = calloc(h->dim, sizeof(Pais *));
    checkMemory(h->vet);

    for (int i = 0; i < old_dim; i++)
        if (old_vet[i] != NULL)
            insereRedimensionadoHash(h, old_vet[i]);

    free(old_vet);
}

static void insereRedimensionadoHash(Hash *h, Pais *p)
{
    int idx = hashFunction(retornaNomePais(p), h->dim);
    if (h->vet[idx] == NULL)
        h->vet[idx] = p;
    else
        colisaoPais(h->vet[idx], p);    
}

void liberaHash(Hash *h)
{
    if (h)
    {
        for (int i = 0; i < h->dim; i++)
            liberaPais(h->vet[i]);
        free(h->vet);
        free(h);
    }
}

void imprimeHash(Hash *h, FILE *saida)
{
    for (int i = 0; i < h->dim; i++)
        if (h->vet[i] != NULL)
            imprimePais(h->vet[i], saida);
}

int retornaUnicosHash(Hash *h)
{
    return h->total;
}

void preencheVetor(Hash *h, Pais **vet)
{
    int count = 0;
    for(int i = 0; i < h->dim; i++)
    {
        Pais *p = h->vet[i];
        while (p)
        {
            vet[count++] = p;
            p = retornaProxPais(p);   
        }
    }
}

static void checkMemory(void *p)
{
    if (!p)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
}