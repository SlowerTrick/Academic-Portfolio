#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>

struct circulo
{
    double raio;
};


Circulo criaCirculo()
{
    Circulo c = malloc(sizeof(struct circulo));
    if(!c)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    c->raio = -1;
    return c;
}

void leCirculo(Circulo c)
{
    scanf(" %lf%*c", &c->raio);
}

double retornaAreaCirculo(Circulo c)
{
    return PI * c->raio * c->raio;
}

void liberaCirculo(Circulo c)
{
    if(c)
    {
        free(c);
        c = NULL;
    }
}