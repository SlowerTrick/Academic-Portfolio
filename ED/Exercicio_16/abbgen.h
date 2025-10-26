#pragma once

#include "aluno.h"

typedef struct arvgen Arvgen;
  
Arvgen *cria_arvegen();
Arvgen *insere_arvgen(Arvgen *a, int (*func)(void *, void *), void *dado);
int percorre_arvgen(Arvgen *arv, int (*func)(void *, void *), void *dado);
void libera_arvgen(Arvgen *arv, void (*libera)(void *));