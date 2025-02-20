#ifndef _BRASILEIRAO_H
#define _BRASILEIRAO_H

#include "time.h"
#include "tabela.h"
#define MAX_TIMES 20

typedef struct _BRA BRA;

/**
 * @brief Construtor do campeonato. Le da entrada padrao numero de times, numero de rodadas e pontuacao.
*/
BRA *CriaCamp();

/**
 * @brief Le da entrada padrao as partidas da rodada, computa os resultados e atualiza a tabela.
*/
void RealizaRodada(BRA *br);

/**
 * @brief Imprime o menu e trata cada opcao.
*/
void RealizaCamp(BRA *br);

/**
 * @brief Le 2 nomes da entrada padrao e remove os times correspondentes da competicao.
*/
void RemoveTimesCamp(BRA *br);

/**
 * @brief Libera a memoria do campeonato.
*/
void DesalocaCamp(BRA *br);

/**
 * @brief Imprime a tabela final, premiacao e desaloca o campeonato.
*/
void FinalizaCamp(BRA *br);

#endif