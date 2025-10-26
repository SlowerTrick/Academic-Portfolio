#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

typedef struct hash Hash;

Hash *criaHash();
void insereHash(Hash *h, void *elemento, int(return_key)(void *), void(collision)(void *, void *));
void imprimeHash(Hash *h, void(imprime)(void *));
void *buscaHash(Hash *h, void *elemento, int(return_key)(void *), void *(search)(void *, void *));
int totalElementosHash(Hash *h, int(return_frequency)(void *));
int totalUnicosHash(Hash *h, int(return_node_count)(void *));
void liberaHash(Hash *h, void(libera)(void *));
void cria_vetor_palavras(Hash *h, Palavra **vet);
