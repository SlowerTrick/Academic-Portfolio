#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "filial.h"
#include "estoque.h"

typedef struct Mercado Mercado;

#define MAX_TAM_NOME 200

Mercado *cria_mercado(char *nome);
Mercado *le_mercado();
void adicionar_filial_mercado(Mercado *m, Filial *f);
void adicionar_produto_mercado(Mercado *m, Produto *p);
Filial *encontra_filial_mercado(Mercado *m, char *nome);
Produto *encontra_produto_mercado(Mercado *m, char *nome);
void diminui_estoque_mercado(Mercado *m, int qtd);
void imprime_mercado(Mercado *m);
void libera_mercado(Mercado *m);