#pragma once

#include "aluno.h"

typedef struct lista Lista;

Lista *cria_lista(Aluno *a);
Lista *adiciona_lista(Lista *l, Aluno *a);
Lista *remove_lista(Lista *l, Aluno *a);
void imprime_lista(Lista *l);
void libera_lista(Lista *l);