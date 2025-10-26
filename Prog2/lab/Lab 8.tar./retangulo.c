#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>

struct retangulo
{
    double comprimento;
    double largura;
};


Retangulo criaRetangulo()
{  
    Retangulo r = malloc(sizeof(struct retangulo));
    if(!r)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    r->comprimento = -1;
    r->largura = -1;
    return r;
}

void leRetangulo(Retangulo r)
{
    scanf(" %lf %lf%*c", &r->comprimento, &r->largura);
}

double retornaAreaRetangulo(Retangulo r)
{
    return r->comprimento * r->largura;
}

void liberaRetangulo(Retangulo r)
{
    if(r)
    {
        free(r);
        r = NULL;
    }
}