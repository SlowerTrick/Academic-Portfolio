#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "produto.h"

typedef struct Estoque Estoque;

#define MAX_TAM_NOME 200

Estoque *cria_estoque(int qtd);
Estoque *le_estoque();
Produto *encontra_produto_estoque(Estoque *e, char *nome);
int adicionar_produto_estoque(Estoque *e, Produto *p);
int get_tamanho_estoque(Estoque *e);
void altera_estoque(Estoque *e, int qtd);
void imprime_estoque(Estoque *e);
void libera_estoque(Estoque *e);