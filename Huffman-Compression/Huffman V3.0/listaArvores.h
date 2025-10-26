/*
 listaArvores.h
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#ifndef LISTA_ARVORES_H
#define LISTA_ARVORES_H

#include "arvore.h"

typedef struct node tNode;
typedef struct lista_arv tListaArv;

/**
 * @brief Cria uma lista encadeada de árvores.
 * Pre-condicao: Memória suficiente
 * Pos-condicao: Inicializa uma estrutura do tipo tListaArv vazia.
 *
 * @return Ponteiro para uma estrutura tListaArv recém-criada.
 */
tListaArv* criaListaArv();

/**
 * @brief Insere uma árvore no final da lista.
 * Pre-condicao: Ponteiros validos
 * Pos-condicao: Lista modificada
 *
 * Cria um novo nó contendo a árvore fornecida e o adiciona ao final da lista.
 *
 * @param l Ponteiro para a lista onde o elemento será inserido.
 * @param elem Ponteiro para a árvore a ser inserida.
 */
void insereFinalListaArv(tListaArv* l, Arv* elem);

/**
 * @brief Remove uma árvore da lista a partir de sua chave.
 * Pre-condicao: Ponteiros validos
 * Pos-condicao: Lista modificada
 *
 * Busca o nó que contém a árvore cujo byte raiz corresponde à chave fornecida
 * e o remove da lista, retornando o ponteiro para a árvore armazenada.
 *
 * @param l Ponteiro para a lista.
 * @param elem Byte utilizado como chave de busca.
 * @return Ponteiro para a árvore removida, ou NULL se não encontrada.
 */
Arv* retiraListaArv(tListaArv* l, unsigned char elem);

/**
 * @brief Ordena a lista de árvores com QuickSort.
 * Pre-condicao: Ponteiros válidos
 * Pos-condicao: Lista ordenada
 *
 * Ordena os nós da lista em ordem crescente de frequência, utilizando
 * o algoritmo QuickSort adaptado para listas duplamente encadeadas.
 *
 * @param head Ponteiro para o primeiro nó do segmento da lista.
 * @param tail Ponteiro para o último nó do segmento da lista.
 */
void quickSortListaArv(tNode* head, tNode* tail);

/**
 * @brief Retorna o primeiro nó da lista.
 * Pre-condicao: Ponteiro valido
 * Pos-condicao: nenhuma
 *
 * @param l Ponteiro para a lista.
 * @return Ponteiro para o nó inicial da lista.
 */
tNode* retornaHeadListaArv(tListaArv* l);

/**
 * @brief Retorna o último nó da lista.
 * Pre-condicao: Ponteiro valido
 * Pos-condicao: nenhuma
 *
 * @param l Ponteiro para a lista.
 * @return Ponteiro para o nó final da lista.
 */
tNode* retornaTailListaArv(tListaArv* l);

/**
 * @brief Insere uma árvore na lista em ordem crescente de frequência.
 * Pre-condicao: Ponteiros validos e lista previamente ordenada
 * Pos-condicao: Lista modificada, com o elemento em sua posicao correta
 *
 * Percorre a lista até encontrar a posição correta (ordenada por frequência)
 * e insere o novo nó nesse ponto.
 *
 * @param l Ponteiro para a lista.
 * @param elem Ponteiro para a árvore a ser inserida.
 */
void insereOrdenadoListaArv(tListaArv* l, Arv* elem);

/**
 * @brief Transforma a lista de árvores em uma única árvore.
 * Pre-condicao: Ponteiro valido
 * Pos-condicao: Lista com um elemento único, que possui como sub-árvore os antigos elementos da lista
 *
 * Une os dois primeiros elementos da lista em uma nova árvore binária com
 * raiz vazia e frequência igual à soma das frequências das duas subárvores.
 * O processo se repete até restar apenas uma árvore na lista.
 *
 * @param l Ponteiro para a lista de árvores.
 * @return Ponteiro para a árvore resultante ou NULL se a lista estiver vazia.
 */
Arv* transformaListaEmArv(tListaArv* l);

/**
 * @brief Imprime os elementos da lista de árvores.
 * Pre-condicao: Ponteiro valido
 * Pos-condicao: nenhuma
 *
 * Percorre a lista e imprime o byte e a frequência de cada árvore.
 *
 * @param l Ponteiro para a lista.
 */
void imprimeLista(tListaArv* l);

/**
 * @brief Libera toda a memória associada à lista de árvores.
 * Pre-condicao: Lista diferente de NULL
 * Pos-condicao: Memória referete a Lista liberada
 *
 * Percorre a lista, libera cada árvore e em seguida libera a própria lista.
 *
 * @param l Ponteiro para a lista a ser liberada.
 */
void liberaListaArv(tListaArv* l);

/**
 * @brief Retorna a árvore em uma posição específica da lista.
 * Pre-condicao: Ponteiro valido
 * Pos-condicao: nenhuma
 *
 * Percorre a lista até a posição indicada e retorna a árvore armazenada
 * naquele nó.
 *
 * @param l Ponteiro para a lista.
 * @param idx Índice do elemento desejado (0 baseado).
 * @return Ponteiro para a árvore encontrada, ou NULL se índice for inválido.
 */
Arv *retornaArvoreListaArv(tListaArv* l, int idx);


#endif
