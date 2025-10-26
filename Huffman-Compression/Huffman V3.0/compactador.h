/*
 compactador.h
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#ifndef COMPACTADOR_H
#define COMPACTADOR_H

#include "listaArvores.h"
#include "bitmap.h"
#include "utils.h"

// Tamanho máximo da tabela de códigos (1 por caractere ASCII)
#define TABELA_MAX_SIZE 256

typedef struct compactador Compactador;

/**
 * @brief Cria e inicializa uma estrutura Compactador a partir de uma árvore de Huffman.
 * Pre_condicao: A árvore deve ter sido construída corretamente.
 * Pos_condicao: Retorna ponteiro para uma estrutura Compactador inicializada.
 * 
 * @param arvore Ponteiro para a árvore de Huffman.
 * @return Ponteiro para Compactador criado.
 */
Compactador *criaCompactador(Arv *arvore);

/**
 * @brief Libera toda a memória ocupada por uma estrutura Compactador.
 * Pre_condicao: Ponteiro para Compactador válido.
 * Pos_condicao: Memória do Compactador é liberada.
 * 
 * @param c Ponteiro para Compactador.
 */
void liberaCompactador(Compactador *c);

/**
 * @brief Serializa a árvore de Huffman do Compactador para um buffer de bits.
 * Pre_condicao: Compactador deve possuir árvore válida.
 * Pos_condicao: Buffer serializado é criado e armazenado na estrutura.
 * 
 * @param c Ponteiro para Compactador.
 */
void serializaArvoreCompactador(Compactador *c);

/**
 * @brief Gera a tabela de códigos de Huffman para cada caractere.
 * Pre_condicao: Compactador deve possuir árvore válida.
 * Pos_condicao: Tabela de códigos é criada e associada ao Compactador.
 * 
 * @param c Ponteiro para Compactador.
 */
void geraTabelaCompactador(Compactador *c);

/**
 * @brief Preenche o bitmap com a codificação do arquivo de entrada usando a tabela.
 * Pre_condicao: Compactador deve possuir tabela válida.
 * Pos_condicao: Bitmap é preenchido com a sequência de bits do arquivo codificado.
 * 
 * @param c Ponteiro para Compactador.
 * @param entrada Arquivo de entrada aberto em modo leitura binária.
 */
void preencheBitmapCompactador(Compactador *c, FILE *entrada);

/**
 * @brief Salva em arquivo binário a árvore serializada e o bitmap codificado.
 * Pre_condicao: Compactador deve possuir árvore serializada e bitmap.
 * Pos_condicao: Arquivo binário contém a árvore e os dados compactados.
 * 
 * @param c Ponteiro para Compactador.
 * @param saida Arquivo de saída aberto em modo escrita binária.
 */
void salvaBinarioCompactador(Compactador *c, FILE *saida);

/**
 * @brief Imprime o buffer da árvore serializada do Compactador.
 * Pre_condicao: Compactador válido com árvore já serializada.
 * Pos_condicao: Informações da árvore serializada são exibidas no terminal.
 * 
 * @param c Ponteiro para Compactador.
 */
void imprimeArvoreCompactador(Compactador *c);

/**
 * @brief Imprime a tabela de códigos de Huffman gerada.
 * Pre_condicao: Compactador válido com tabela já gerada.
 * Pos_condicao: Tabela de códigos é exibida no terminal.
 * 
 * @param c Ponteiro para Compactador.
 */
void imprimeTabelaCompactador(Compactador *c);

/**
 * @brief Imprime o conteúdo do bitmap gerado.
 * Pre_condicao: Compactador válido com bitmap preenchido.
 * Pos_condicao: Informações detalhadas do bitmap são exibidas no terminal.
 * 
 * @param c Ponteiro para Compactador.
 */
void imprimeBitmapCompactador(Compactador *c);

/**
 * @brief Lê e imprime no terminal o conteúdo de um arquivo binário gerado pelo Compactador.
 * Pre_condicao: Arquivo binário existente, válido e espaço suficiente na memória.
 * Pos_condicao: Informações da árvore e bitmap armazenados no arquivo são exibidas.
 * 
 * @param nome_arquivo Caminho para o arquivo binário.
 */
void imprimeBinarioCompactador(const char *nome_arquivo);

#endif