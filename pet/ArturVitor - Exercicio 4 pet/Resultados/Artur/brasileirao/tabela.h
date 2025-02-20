#ifndef _TABELA_H
#define _TABELA_H

#include "time.h"

typedef struct _Tabela tTabela;

/**
 * @brief Construtor do tipo tabela. Deve criar os times.
 * @param numTimes Numero de times a serem criados.
*/
tTabela* CriaTabela(int numTimes);

/**
 * @brief Libera a memoria alocada para a tabela e seus times.
*/
void DesalocaTabela(tTabela* tabela);

/**
 * @brief Ordena a tabela de acordo com os criterios definidos.
*/
void OrdenaTabela(tTabela* tabela);

/**
 * @brief Dado um nome, retorna o time correspondente.
*/
tTime* ObtemTimeTabela(tTabela* tabela, char* time);

/**
 * @brief Dado um nome, desaloca e remove o time correspondente da tabela.
*/
void RemoveTimeTabela(tTabela* tabela, char* time);

/**
 * @brief Imprime a tela de premiacao no final do campeonato.
*/
void ImprimePremiacao(tTabela* tabela, float valorPremio);

/**
 * @brief Imprime todos os times da tabela.
*/
void ImprimeTabela(tTabela* tabela);

#endif
