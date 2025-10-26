#pragma once

#include "aluno.h"

typedef struct hash Hash;

#define HASH_DIM 7

Hash *criaHash();
void imprimeHash(Hash *h);
void insereHash(Hash *h, Aluno *a);
Aluno *buscaHash(Hash *h, char *nome);
int UnicosHash(Hash *h);
void liberaHash(Hash *h);