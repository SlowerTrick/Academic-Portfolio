/*
 descompactador.h
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#ifndef DESCOMPACTADOR_H
#define DESCOMPACTADOR_H

#include "listaArvores.h"
#include "bitmap.h"
#include "utils.h"

#define TABELA_MAX_SIZE 256

typedef struct descompactador Descompactador;

/**
 * @brief Cria um novo descompactador.
 * Pre_condicao: Espaço na memória.
 * Pos_condicao: Retorna ponteiro para uma estrutura Descompactador inicializada.
 *
 * Aloca e inicializa a estrutura responsável por gerenciar o processo de descompactação.
 *
 * @return Ponteiro para a estrutura Descompactador alocada.
 */
Descompactador *criaDescompactador();

/**
 * @brief Libera a memória associada ao descompactador.
 * Pre_condicao: Ponteiro válido para um descompactador.
 * Pos_condicao: Memória da estrutura Descompactador liberada.
 *
 * Desaloca todos os recursos utilizados pelo descompactador, incluindo memória interna.
 *
 * @param d Ponteiro para a estrutura Descompactador a ser liberada.
 */
void liberaDescompactador(Descompactador *d);

/**
 * @brief Lê o arquivo binário compactado.
 * Pre_condicao: Arquivo e descompactador inicializados.
 * Pos_condicao: Arquivo lido e estrutura descompactador modificada.
 *
 * Processa o arquivo compactado e armazena suas informações na estrutura do descompactador
 *
 * @param d Ponteiro para a estrutura Descompactador que irá armazenar os dados.
 * @param arquivo Ponteiro para o arquivo binário já aberto em modo leitura.
 */
void leBinarioDescompactador(Descompactador *d, FILE *arquivo);

/**
 * @brief Descompacta o arquivo original.
 * Pre_condicao: Arquivo aberto.
 * Pos_condicao: Arquivo descompactado.
 *
 * Utiliza os dados carregados (como a árvore de Huffman) para reconstruir o arquivo
 * normal a partir do binário compactado.
 *
 * @param d Ponteiro para a estrutura Descompactador com os dados necessários.
 * @param arquivo_normal Ponteiro para o arquivo de saída onde será escrito o conteúdo descompactado.
 */
void descompactaArquivo(Descompactador* d, FILE* arquivo_normal);

/**
 * @brief Imprime a árvore de Huffman (debug).
 *
 * Função auxiliar para depuração. Mostra a árvore de Huffman em formato legível,
 * percorrendo seus nós e imprimindo os caminhos até cada caractere.
 *
 * @param arvore Ponteiro para a árvore a ser impressa.
 * @param buffer Vetor de caracteres usado para armazenar temporariamente o caminho percorrido.
 * @param tamanho_buffer Número de elementos válidos no buffer.
 */
void imprimeArvoreDesompactador(Arv *arvore, unsigned char *buffer, int tamanho_buffer);

#endif