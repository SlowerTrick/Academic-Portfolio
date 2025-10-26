#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palavra
{
    char *palavra;
    int frequencia;
    struct palavra *prox;
};

Palavra *cria_palavra(char *palavra)
{
    Palavra *p = malloc(sizeof(*p));
    if(!p)
    {
        printf("ERRO! Falta de memoria");
        exit(1);
    }
    p->palavra = strdup(palavra);
    p->frequencia = 1;
    p->prox = NULL;
    return p;
}

void imprime_palavra(void *p)
{
    Palavra *pal = (Palavra *) p;
    printf("Palavra %s, Frequencia: %d\n", pal->palavra, pal->frequencia);
    if(pal->prox)
        imprime_palavra(pal->prox);
}

int soma_caracter_palavra(void *p)
{
    Palavra *pal = (Palavra *) p;
    int total = 0;
    char *palavra = pal->palavra;
    
    for(int i = 0; palavra[i] != '\0'; i++)
        total += palavra[i]; 

    return total;
}

void insere_palavra_lista(void *p, void *nova)
{
    Palavra *pal = (Palavra *) p;
    Palavra *new_pal = (Palavra *) nova;
    if(pal->prox == NULL && strcmp(pal->palavra, new_pal->palavra) != 0)
        pal->prox = new_pal;
    else
    {
        if(strcmp(pal->palavra, new_pal->palavra) == 0)
            incrementa_frequencia_palavra(pal);
        else
            insere_palavra_lista(pal->prox, new_pal);
    }
}

void *busca_palavra_lista(void *p, void *key)
{
    if(p == NULL || key == NULL)
        return NULL;
    Palavra *pal = (Palavra *) p;
    Palavra *obj = (Palavra *) key;

    if(strcmp(pal->palavra, obj->palavra) == 0)
        return pal;
    return busca_palavra_lista(pal->prox, key);
}

int total_palavras_lista(void *p)
{
    int total = 1;
    Palavra *pal = (Palavra *)p;

    if(pal->prox)
        total += total_palavras_lista(pal->prox);

    return total;
}

int retorna_frequencia_palavra(void *p)
{
    Palavra *pal = (Palavra *)p;
    int total = pal->frequencia;
    if(pal->prox)
        total += retorna_frequencia_palavra(pal->prox);
    return total;
}

void incrementa_frequencia_palavra(Palavra *p)
{
    p->frequencia++;
}

char *retorna_palavra(Palavra *p)
{
    return p->palavra;
}

void adiciona_vetor_palavra(Palavra **vet, int count, Palavra *p)
{
    if(p == NULL) return;

    vet[count++] = p;
    adiciona_vetor_palavra(vet, count, p->prox);
}

void libera_palavra(void *p)
{
    Palavra *pal = (Palavra *) p;
    if(pal)
    {
        libera_palavra(pal->prox);
        free(pal->palavra);
        free(pal);
    }
}
