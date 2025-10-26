#pragma once

typedef struct Filial Filial;

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "produto.h"


#define MAX_TAM_NOME 200

Filial *cria_filial(char *nome, int estoque);
Filial *le_filial();
int adicionar_produto_filial(Filial *f, Produto *p);
int get_estoque_total_filial(Filial *f);
char *get_filial_nome(Filial *f);
void imprime_filial(Filial *f);
void libera_filial(Filial *f);