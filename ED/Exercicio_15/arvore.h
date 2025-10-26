#pragma once

#include "palavra.h"

typedef struct arvore Arvore;

Arvore *cria_arvore();
Arvore *insere_arvore(Arvore *a, Palavra *p);
void imprime_arvore(Arvore *a);
void libera_arvore(Arvore *a);
int total_palavras(Arvore *a);
int total_palavras_unicas(Arvore *a);
Palavra *descobre_maior_frequencia(Arvore *a);
Palavra **cria_vetor(Arvore *a, int total_unicas);
void organiza_vetor(Palavra **vetor, int total_unicas);
void libera_vetor(Palavra **vetor, int total_unicas);