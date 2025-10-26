#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

#include <stdio.h>
#include <stdlib.h>

Lista *criaLista();
void insereLista(Lista *l, void *dado);
double percorreLista(Lista *l, FILE *saida, double (func)(void *, FILE *));
void liberaLista(Lista *l, void (libera)(void *dado));

#endif
