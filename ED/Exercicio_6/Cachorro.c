//
//  Cachorro.h
//  CachorroED
//
//  Created by Artur Vítor Cintra Bernardes on 04/06/25.
//

#include "Cachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cachorro
{
    char *nome;
    int agressividade;
};

Cachorro *inicCachorro(char *nome, int agressividade)
{
    Cachorro *c = malloc(sizeof(*c));
    if(!c)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    c->nome = strdup(nome);
    c->agressividade = agressividade;
    return c;
}

void imprimeCachorro(Cachorro *c)
{
    printf("Cachorro: Nome: %s Agressividade: %d\n", c->nome, c->agressividade);
}

void atribuiNivelAgressividadeCachorro(Cachorro *c, int agressividade)
{
    c->agressividade = agressividade;
}

char *get_nome_cachorro(Cachorro *c)
{
    return c->nome;
}

int get_agressividade_cachorro(Cachorro *c)
{
    return c->agressividade;
}

void liberaCachorro(Cachorro *c)
{
    if(c)
    {
        free(c->nome);
        free(c);
    }
}