#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palavra
{
    char *palavra;
    int frequencia;
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
    return p;
}

int retorna_frequencia_palavra(Palavra *p)
{
    return p->frequencia;
}

void incrementa_frequencia_palavra(Palavra *p)
{
    p->frequencia++;
}

char *retorna_palavra(Palavra *p)
{
    return p->palavra;
}

void libera_palavra(Palavra *p)
{
    if(p)
    {
        free(p->palavra);
        free(p);
    }
}

