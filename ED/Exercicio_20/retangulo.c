#include "retangulo.h"
#include <stdio.h>

struct retangulo
{
    double base;
    double altura;
};

Retangulo *criaRetangulo(double base, double altura)
{
    Retangulo *r = malloc(sizeof(*r));
    if(!r)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    r->base = base;
    r->altura = altura;
    return r;
}

double calculaAreaRetangulo(Retangulo *r)
{
    return r->base * r->altura;
}

double imprimeRetangulo(void *ret, FILE *saida)
{
    Retangulo *r = (Retangulo *) ret;

    fprintf(saida, "RETANGULO\n");
    fprintf(saida, "\tBASE: %.2lf\n", r->base);
    fprintf(saida, "\tALTURA: %.2lf\n", r->altura);
    double area = calculaAreaRetangulo(r);
    fprintf(saida, "\tAREA: %.2lf\n\n", area);
    
    return area;
}

void liberaRetangulo(void *ret)
{
    Retangulo *r = (Retangulo *) ret;
    if(r)
        free(r);
}
