#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Produto Produto;

#define MAX_TAM_NOME 200

Produto *cria_produto(char *item, int valor, int qtd);
Produto *le_produto();
char *get_item_produto(Produto *p);
int get_valor_produto(Produto *p);
int get_qtd_produto(Produto *p);
void imprime_catalogo_filial_produto(Produto *p);
void imprime_estoque_produto(Produto *p);
void libera_produto(Produto *p);