//
//  lista.h
//  TADLista
//
//  Created by Artur Vítor Cintra Bernardes on 28/05/25.
//  Este arquivo define a estrutura e as operações básicas de uma lista duplamente encadeada.
//  Cada nó da lista armazena um ponteiro para um Produto, permitindo inserção, remoção e busca.
//

#pragma once

#include "produto.h"

typedef struct lista tLista;

/* Cria e inicializa uma nova lista vazia.
 * inputs: nenhum.
 * output: ponteiro NULL representando a lista vazia.
 * pre-condicao: nenhuma.
 * pos-condicao: lista inicializada como vazia (NULL).
 */
tLista *cria_lista();

/* Busca um produto pelo nome na lista.
 * inputs: ponteiro para a lista e nome do produto (string).
 * output: ponteiro para o produto encontrado ou NULL se não existir.
 * pre-condicao: lista inicializada.
 * pos-condicao: lista não é modificada.
 */
Produto *get_produto_lista(tLista *l, char *nome);

/* Adiciona um novo produto no início da lista.
 * inputs: ponteiro para a lista e ponteiro para o produto.
 * output: novo ponteiro para o início da lista.
 * pre-condicao: produto válido e lista inicializada.
 * pos-condicao: produto adicionado na lista.
 */
tLista *adiciona_elemento_lista(tLista *l, Produto *p);

/* Remove o primeiro produto com o nome especificado da lista.
 * inputs: ponteiro para a lista e nome do produto a ser removido.
 * output: ponteiro para o novo início da lista.
 * pre-condicao: lista inicializada.
 * pos-condicao: produto removido (se encontrado) e memória do nó liberada.
 */
tLista *remove_elemento_lista(tLista *l, char *nome);

/* Imprime todos os produtos da lista, incluindo anterior e próximo de cada nó.
 * inputs: ponteiro para a lista.
 * output: nenhum (impressão na saída padrão).
 * pre-condicao: lista inicializada.
 * pos-condicao: lista não é modificada.
 */
void imprime_lista(tLista *l);

/* Libera apenas o nó da lista (não o produto).
 * inputs: ponteiro para o nó da lista.
 * output: nenhum.
 * pre-condicao: ponteiro lista válido.
 * pos-condicao: memória do nó liberada.
 */
void libera_elemento_lista(tLista *l);

/* Libera toda a memória alocada para a lista (não os produtos).
 * inputs: ponteiro para o início da lista.
 * output: nenhum.
 * pre-condicao: lista inicializada.
 * pos-condicao: memória de todos os nós liberada.
 */
void libera_lista(tLista *l);
