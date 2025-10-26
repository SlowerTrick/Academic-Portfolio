#pragma once

#include "pais.h"

#define HASH_SIZE 103

typedef struct hash Hash;

Hash *criaHash();
void insereHash(Hash *h, Pais *p);
void imprimeHash(Hash *h, FILE *saida);
void liberaHash(Hash *h);

int retornaUnicosHash(Hash *h);
void preencheVetor(Hash *h, Pais **vet);