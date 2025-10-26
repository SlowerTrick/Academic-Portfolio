#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void check_memory(void *p);
static void conta_elementos_unicos(Arvore *a, Arvore *temp, int *total);
static void descobre_mais_frequente(Arvore *a, Arvore *original, char **mais_frequente, int *tamanho_mais_frequente);
static void preenche_vetor(Arvore *a, char **vet, int size_vet, int *actual_size_vet);

struct arvore
{
    char *palavra;
    struct arvore *esq;
    struct arvore *dir;
};

Arvore *cria_arvore() { return NULL; }

Arvore *insere_arvore(Arvore *a, char *palavra)
{
    if (!a)
    {
        Arvore *arv = malloc(sizeof(*arv));
        check_memory(arv);
        arv->dir = NULL;
        arv->esq = NULL;
        arv->palavra = strdup(palavra);
        return arv;
    }
    int compare_word = strcmp(a->palavra, palavra);
    if (compare_word > 0)
        a->esq = insere_arvore(a->esq, palavra);
    else if (compare_word <= 0)
        a->dir = insere_arvore(a->dir, palavra);
    return a;
}

int busca_arvore(Arvore *a, char *palavra)
{
    if (a)
        return strcmp(a->palavra, palavra) == 0 || busca_arvore(a->esq, palavra) ||
               busca_arvore(a->dir, palavra);
    return 0;
}

int total_elementos_arvore(Arvore *a)
{
    int total = 0;
    if (a)
    {
        total++;
        total += total_elementos_arvore(a->esq);
        total += total_elementos_arvore(a->dir);
    }
    return total;
}

int total_elementos_unicos_arvore(Arvore *a)
{
    int total = 0;
    Arvore *temp = cria_arvore();
    conta_elementos_unicos(a, temp, &total);
    libera_arvore(temp);
    return total;
}

static void conta_elementos_unicos(Arvore *a, Arvore *temp, int *total)
{
   if(a)
   {
       if(!busca_arvore(temp, a->palavra)) 
       {
            temp = insere_arvore(temp, a->palavra);
            *total += 1;
       }
       conta_elementos_unicos(a->esq, temp, total);
       conta_elementos_unicos(a->dir, temp, total);
   } 
}

char *elemento_mais_frequente_arvore(Arvore *a, int *qtd_repeticoes)
{
    char *mais_frequente = NULL;
    int tamanho_mais_frequente = 0;

    descobre_mais_frequente(a, a, &mais_frequente, &tamanho_mais_frequente);

    *qtd_repeticoes = tamanho_mais_frequente;
    return mais_frequente;
}

static void descobre_mais_frequente(Arvore *a, Arvore *original, char **mais_frequente, int *tamanho_mais_frequente)
{
    if(a)
    {
        int tamanho_atual = ocorrencias_arvore(original, a->palavra);
        if(tamanho_atual > *tamanho_mais_frequente)
        {
            *mais_frequente = a->palavra;
            *tamanho_mais_frequente = tamanho_atual;
        }
        descobre_mais_frequente(a->esq, original, mais_frequente, tamanho_mais_frequente);
        descobre_mais_frequente(a->dir, original, mais_frequente, tamanho_mais_frequente);
    }
}

int ocorrencias_arvore(Arvore *a, char *palavra)
{
    int total = 0;
    if (a)
    {
        if (strcmp(a->palavra, palavra) == 0)
            total++;
        total += ocorrencias_arvore(a->esq, palavra);
        total += ocorrencias_arvore(a->dir, palavra);
    }
    return total;
}

void preenche_vetor_arvore(Arvore *a, char **vet, int size_vet)
{
    int actual_count = 0;
    preenche_vetor(a, vet, size_vet, &actual_count);
}

static void preenche_vetor(Arvore *a, char **vet, int size_vet, int *actual_size_vet)
{
    if(a)
    {
        int flag = 0;
        for(int i = 0; i < size_vet; i++)
            if(vet[i] && strcmp(vet[i], a->palavra) == 0)
                flag = 1;
        if(!flag)
            vet[(*actual_size_vet)++] = a->palavra;
        preenche_vetor(a->esq, vet, size_vet, actual_size_vet);
        preenche_vetor(a->dir, vet, size_vet, actual_size_vet);
    }
}

void imprime_arvore(Arvore *a)
{
    if (a)
    {
        printf("<%s", a->palavra);
        imprime_arvore(a->esq);
        imprime_arvore(a->dir);
    }
    else
        printf("<>");
}

void libera_arvore(Arvore *a)
{
    if (a)
    {
        libera_arvore(a->esq);
        libera_arvore(a->dir);
        free(a->palavra);
        free(a);
    }
}

static void check_memory(void *p)
{
    if (!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}
