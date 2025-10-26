#pragma once

typedef struct pais Pais;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pais *criaPais(char *nome, int ouro, int prata, int bronze, int total);
void imprimePais(Pais *p, FILE *saida);
char *retornaNomePais(Pais *p);
int retornaOuroPais(Pais *p);
int retornaPrataPais(Pais *p);
int retornaBronzePais(Pais *p);
int retornaTotalPais(Pais *p);
Pais *retornaProxPais(Pais *p);
int colisaoPais(Pais *p, Pais *new);
void liberaPais(Pais *p);