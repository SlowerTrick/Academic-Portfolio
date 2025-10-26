//
//  Gato.h
//  GatoED
//
//  Created by Artur Vítor Cintra Bernardes on 04/06/25.
//

#include "Gato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gato
{
    char *nome;
    int agressividade;
};


Gato *inicGato(char *nome, int agressividade)
{
    Gato *g = malloc(sizeof(*g));
    if(!g)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    g->nome = strdup(nome);
    g->agressividade = agressividade;
    return g;
}

char *get_nome_gato(Gato *g)
{   
    return g->nome;
}

int get_agressividade_gato(Gato *g)
{
    return g->agressividade;
}

void imprimeGato(Gato *g)
{
    printf("Gato: Nome: %s Agressividade: %d\n", g->nome, g->agressividade);
}

void atribuiNivelAgressividadeGato(Gato *g, int agressividade)
{
    g->agressividade = agressividade;
}

void liberaGato(Gato *g)
{
    if(g)
    {
        free(g->nome);
        free(g);
    }
}