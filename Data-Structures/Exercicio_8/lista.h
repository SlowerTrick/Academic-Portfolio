//
//  lista.h
//  Prova1ED
//
//  Created by Artur Vitor Cintra Bernardes on 18/06/25.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//


#pragma once

#include "pedido.h"

/* Define o tipo Lista (tipo opaco). Estrutura interna deste tipo é definida na implementação do TAD.
 * Trata-se de uma lista simplesmente encadeada de produtos.
 */
typedef struct lista Lista;

/*----------------------------------------------------------------------
 * Cria e inicializa uma lista vazia de produtos.
 * inputs: nenhum
 * output: ponteiro para a lista criada
 * pre-condicao: nenhuma
 * pos-condicao: lista vazia inicializada
 *----------------------------------------------------------------------*/
Lista *cria_lista();

/*----------------------------------------------------------------------
 * Adiciona um produto ao final da lista.
 * inputs: ponteiro para o produto e para a lista
 * output: nenhum
 * pre-condicao: produto e lista devidamente inicializados
 * pos-condicao: produto inserido ao final da lista
 *----------------------------------------------------------------------*/
void adiciona_lista(TProduto *p, Lista *l);

/*----------------------------------------------------------------------
 * Remove um produto da lista com base no nome.
 * inputs: nome do produto a ser removido, ponteiro para a lista
 * output: ponteiro para o produto removido ou NULL se não encontrado
 * pre-condicao: nome e lista devidamente inicializados
 * pos-condicao: produto removido da lista (sem liberar o produto em si)
 *----------------------------------------------------------------------*/
TProduto *remove_lista(char *nome, Lista *l);

/*----------------------------------------------------------------------
 * Verifica se existe um produto com o nome especificado na lista.
 * inputs: nome do produto, ponteiro para a lista
 * output: 1 se encontrar, 0 caso contrário
 * pre-condicao: nome e lista devidamente inicializados
 * pos-condicao: nenhuma
 *----------------------------------------------------------------------*/
int busca_produto_lista(char *nome, Lista *l);

/*----------------------------------------------------------------------
 * Verifica se há algum produto na lista que contenha o ingrediente informado.
 * inputs: ponteiro para a lista e o nome do ingrediente
 * output: ponteiro para o produto que contém o ingrediente ou NULL se nenhum encontrar
 * pre-condicao: lista e ingrediente devidamente inicializados
 * pos-condicao: nenhuma
 *----------------------------------------------------------------------*/
TProduto *verifica_ingrediente_lista(Lista *l, char *ingrediente);

/*----------------------------------------------------------------------
 * Calcula o total de calorias de todos os produtos da lista.
 * inputs: ponteiro para a lista
 * output: soma total das calorias
 * pre-condicao: lista devidamente inicializada
 * pos-condicao: nenhuma
 *----------------------------------------------------------------------*/
int retorna_calorias_totais(Lista *l);

/*----------------------------------------------------------------------
 * Imprime todos os produtos da lista.
 * inputs: ponteiro para a lista
 * output: nenhum
 * pre-condicao: lista devidamente inicializada
 * pos-condicao: dados da lista exibidos na tela. Se vazia, imprime "Nao ha produtos neste pedido!\n"
 *----------------------------------------------------------------------*/
void imprime_lista(Lista *l);

/*----------------------------------------------------------------------
 * Libera toda a memória alocada para a lista, mas não libera os produtos.
 * inputs: ponteiro para a lista
 * output: nenhum
 * pre-condicao: lista devidamente inicializada
 * pos-condicao: memória da lista liberada
 *----------------------------------------------------------------------*/
void libera_lista(Lista *l);
