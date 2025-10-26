#include "arvore.h"
#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int comparador(const void *a, const void *b);
static void preenche_vetor(Arvore *a,Palavra **vet, int *indice);

struct arvore
{
    Palavra *palavra;
    struct arvore *esq;
    struct arvore *dir;
};

Arvore *cria_arvore()
{
    return NULL;
}

Arvore *insere_arvore(Arvore *a, Palavra *p)
{
    if (!a)
    {
        Arvore *arv = malloc(sizeof(*arv));
        if (!arv)
        {
            printf("ERRO! falta de memoria");
            exit(1);
        }
        arv->palavra = p;
        arv->esq = NULL;
        arv->dir = NULL;
        return arv;
    }
    int value = strcmp(retorna_palavra(a->palavra), retorna_palavra(p));
    if (value > 0)
        a->esq = insere_arvore(a->esq, p);
    else if (value < 0)
        a->dir = insere_arvore(a->dir, p);
    else
        incrementa_frequencia_palavra(a->palavra);
    return a;
}

void imprime_arvore(Arvore *a)
{
    if (!a)
    {
        printf("<>");
        return;
    }
    printf("<%s", retorna_palavra(a->palavra));
    imprime_arvore(a->esq);
    imprime_arvore(a->dir);
}

void libera_arvore(Arvore *a)
{
    if (!a)
        return;

    libera_palavra(a->palavra);
    libera_arvore(a->esq);
    libera_arvore(a->dir);
    free(a);
}

int total_palavras(Arvore *a)
{
    if (!a)
        return 0;
    int total = retorna_frequencia_palavra(a->palavra);
    total += total_palavras(a->esq);
    total += total_palavras(a->dir);
    return total;
}

int total_palavras_unicas(Arvore *a)
{
    if (!a)
        return 0;
    int total = 1;
    total += total_palavras_unicas(a->esq);
    total += total_palavras_unicas(a->dir);
    return total;
}

Palavra *descobre_maior_frequencia(Arvore *a)
{
    if (!a)
        return NULL;

    Palavra *pal = a->palavra;
    Palavra *pal_esq = descobre_maior_frequencia(a->esq);
    Palavra *pal_dir = descobre_maior_frequencia(a->dir);

    if (pal_esq && retorna_frequencia_palavra(pal) < retorna_frequencia_palavra(pal_esq))
        pal = pal_esq;
    if (pal_dir && retorna_frequencia_palavra(pal) < retorna_frequencia_palavra(pal_dir))
        pal = pal_dir;
    return pal;
}

Palavra **cria_vetor(Arvore *a, int total_unicas)
{
    Palavra **vetor = malloc(sizeof(Palavra *) * total_unicas);
    if (!vetor)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    int indice = 0;
    preenche_vetor(a, vetor, &indice);
    return vetor;
}

void organiza_vetor(Palavra **vetor, int total_unicas)
{
    qsort(vetor, total_unicas, sizeof(Palavra *), comparador);
}

static int comparador(const void *a, const void *b)
{
    return retorna_frequencia_palavra(*(Palavra **)a) - retorna_frequencia_palavra(*(Palavra **)b);
}

static void preenche_vetor(Arvore *a, Palavra **vet, int *indice)
{
    if(a)
    {
        vet[*indice] = a->palavra;
        (*indice)++;
        preenche_vetor(a->esq, vet, indice);
        preenche_vetor(a->dir, vet, indice);
    }
}

void libera_vetor(Palavra **vetor, int total_unicas)
{
    if (vetor)
        free(vetor);
}