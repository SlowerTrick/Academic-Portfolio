#pragma once

typedef struct arvore Arvore;

#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

Arvore *criaArvore();
Arvore *insereArvore(Arvore *a, Aluno *aluno);
void imprimeArvore(Arvore *a, FILE *saida);
Aluno *buscaArvore(Arvore *a, char *nome);
void liberaArvore(Arvore *a);

