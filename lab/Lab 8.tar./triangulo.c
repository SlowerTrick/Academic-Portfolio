#include "triangulo.h"
#include <stdio.h>
#include <stdlib.h>

struct triangulo
{
    double comprimento;
    double largura;
};

Triangulo criaTriangulo()
{
    Triangulo t = malloc(sizeof(struct triangulo));
    if(!t)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    t->comprimento = -1;
    t->largura = -1;
    return t;
}

void leTriangulo(Triangulo t)
{
    scanf(" %lf %lf%*c", &t->comprimento, &t->largura);
}

double retornaAreaTriangulo(Triangulo t)
{
    return t->comprimento * t->largura / 2;
}

void liberaTriangulo(Triangulo t)
{
    if(t)
    {
        free(t);
        t = NULL;
    }
}