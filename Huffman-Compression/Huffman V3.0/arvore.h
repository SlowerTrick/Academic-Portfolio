/*
 arvore.h
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arv;
typedef Arv* tArvorePtr;

/**
 * @brief Inicializa com NULL uma estrutura do tipo Arvore.
 * Pre_condicao: nenhuma
 * Pos_condicao: Nenhuma
 * 
 * 
 * @return Ponteiro nulo para uma estrutura do Arv*
 */
Arv* arv_criavazia(void);

/**
 * @brief Cria uma árvore com a informação do nó raiz dado, e com subárvore esquerda e subárvore direita d
 * Pre_condicao: Parâmetros corretamente passados
 * Pos_condicao: Uma estrutura do tipo Arv* alocada caso tenha memória suficiente
 * 
 * @param dado O byte que o é o dado da nossa árvore
 * @param freq Frequência com que o dado aparece
 * @param e Sub-árvore a esquerda
 * @param d Sub-árvore a direita
 * @return Ponteiro não nulo para uma estrutura do Arv*
 */
Arv* arv_cria(unsigned char dado, int freq, Arv* e, Arv* d);

/**
 * @brief Libera o espaço de memória ocupado pela árvore.
 * Pre_condicao: árvore diferente de NULL.
 * Pos_condicao: toda memória da árvore é liberada.
 * 
 * @param a Ponteiro para a árvore a ser liberada.
 * @return NULL (após liberar toda a memória).
 */
Arv* arv_libera(Arv* a);

/**
 * @brief Verifica se a árvore está vazia.
 * Pre_condicao: árvore corretamente inicializada.
 * Pos_condicao: nenhuma.
 * 
 * @param a Ponteiro para a árvore.
 * @return 1 se a árvore for vazia, 0 caso contrário.
 */
int arv_vazia(Arv* a);

/**
 * @brief Verifica se um dado byte está presente na árvore.
 * Pre_condicao: árvore corretamente inicializada.
 * Pos_condicao: nenhuma.
 * 
 * @param a Ponteiro para a árvore.
 * @param key O byte a ser procurado.
 * @return 1 se o byte estiver presente, 0 caso contrário.
 */
int arv_pertence(Arv* a, unsigned char key);

/**
 * @brief Imprime as informações de todos os nós da árvore.
 * Pre_condicao: árvore corretamente inicializada.
 * Pos_condicao: nenhuma
 * 
 * @param a Ponteiro para a árvore.
 */
void arv_imprime(Arv* a);

/**
 * @brief Retorna o pai de um nó cujo dado é fornecido.
 * Pre_condicao: árvore corretamente inicializada.
 * Pos_condicao: nenhuma.
 * 
 * @param a Ponteiro para a árvore.
 * @param key O byte cujo pai deve ser encontrado.
 * @return Ponteiro para o nó pai, ou NULL se não existir.
 */
Arv* arv_pai(Arv* a, unsigned char key);

/**
 * @brief Conta a quantidade de folhas da árvore binária.
 * Pre_condicao: árvore corretamente inicializada.
 * Pos_condicao: nenhuma.
 * 
 * @param a Ponteiro para a árvore.
 * @return Número de folhas da árvore.
 */
int folhas(Arv* a);

/**
 * @brief Conta o número de ocorrências de um dado byte na árvore.
 * Pre_condicao: árvore corretamente inicializada.
 * Pos_condicao: nenhuma.
 * 
 * @param a Ponteiro para a árvore.
 * @param key O byte a ser contado.
 * @return Número de ocorrências do byte na árvore.
 */
int ocorrencias(Arv* a, unsigned char key);

/**
 * @brief Calcula a altura da árvore.
 * Pre_condicao: árvore corretamente inicializada.
 * Pos_condicao: nenhuma.
 * 
 * @param a Ponteiro para a árvore.
 * @return Altura da árvore (-1 se vazia).
 */
int altura(Arv* a);

/**
 * @brief Retorna o dado armazenado no nó raiz da árvore.
 * Pre_condicao: ponteiro válido para a árvore.
 * Pos_condicao: nenhuma.
 * 
 * @param arv Ponteiro para a árvore.
 * @return O byte armazenado no nó.
 */
unsigned char retornaByteArv(Arv* arv);

/**
 * @brief Retorna a frequência armazenada no nó da árvore.
 * Pre_condicao: ponteiro válido para a árvore.
 * Pos_condicao: nenhuma.
 * 
 * @param arv Ponteiro para a árvore.
 * @return Frequência do nó.
 */
int retornaFrequenciaArv(Arv* arv);

/**
 * @brief Retorna a subárvore à esquerda de um nó.
 * Pre_condicao: ponteiro válido para a árvore.
 * Pos_condicao: nenhuma.
 * 
 * @param arv Ponteiro para a árvore.
 * @return Ponteiro para a subárvore esquerda, ou NULL se não existir.
 */
Arv *retornaEsqArv(Arv *arv);

/**
 * @brief Retorna a subárvore à direita de um nó.
 * Pre_condicao: ponteiro válido para a árvore.
 * Pos_condicao: nenhuma.
 * 
 * @param arv Ponteiro para a árvore.
 * @return Ponteiro para a subárvore direita, ou NULL se não existir.
 */
Arv *retornaDirArv(Arv *arv);

/**
 * @brief Verifica se um nó da árvore é folha.
 * Pre_condicao: ponteiro válido para a árvore.
 * Pos_condicao: nenhuma.
 * 
 * @param arv Ponteiro para a árvore.
 * @return 1 se o nó for folha, 0 caso contrário.
 */
int ehFolhaArv(Arv *arv);


#endif
