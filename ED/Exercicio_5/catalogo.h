//
//  catalogo.h
//  TADCatalogo
//
//  Created by Artur Vítor Cintra Bernardes on 21/05/25.
//  Este arquivo define a estrutura e as operações básicas para manipulação de um catálogo de produtos.
//  O catálogo é responsável por armazenar e gerenciar produtos por meio de uma lista.
//

#pragma once

#include "produto.h"

typedef struct catalogo tCatalogo;

/* Cria e inicializa um novo catálogo vazio.
 * inputs: nenhum.
 * output: ponteiro para o catálogo inicializado.
 * pre-condicao: nenhuma.
 * pos-condicao: catálogo criado com lista interna vazia.
 */
tCatalogo *cria_catalogo();

/* Adiciona um produto ao catálogo.
 * inputs: ponteiro para o catálogo e ponteiro para o produto.
 * output: nenhum (produto adicionado à lista interna).
 * pre-condicao: catálogo e produto válidos.
 * pos-condicao: produto adicionado ao catálogo.
 */
void *adiciona_produto_catalogo(tCatalogo *c, Produto *p);

/* Libera toda a memória associada ao catálogo (estrutura interna e produtos)
 * inputs: ponteiro para o catálogo.
 * output: nenhum.
 * pre-condicao: catálogo válido.
 * pos-condicao: memória do catálogo e dos produtos liberada.
 */
void libera_catalogo(tCatalogo *c);
