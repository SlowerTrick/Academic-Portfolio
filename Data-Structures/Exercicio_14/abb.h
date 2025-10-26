#pragma once

#include "aluno.h"
typedef struct abb Abb;

Abb *cria_abb();
Abb *busca_abb(Abb *a, int mat);
Abb *retira_abb(Abb *a, int mat);
void imprime_abb(Abb *a);
Abb *insere_abb(Abb *a, Aluno *aluno);
void libera_abb(Abb *a);
