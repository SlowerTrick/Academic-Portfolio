#ifndef RETANGULO_H
#define RETANGULO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct retangulo Retangulo;

Retangulo *criaRetangulo(double base, double altura);
double calculaAreaRetangulo(Retangulo *r);
double imprimeRetangulo(void *ret, FILE *saida);
void liberaRetangulo(void *ret);

#endif
