#ifndef CELA_H_
#define CELA_H_

#include "prisioneiro.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAXTAM_CELAS 100

typedef struct
{
    int capacidade;
    int nPresidiarios;
    tPrisioneiro prisioneiros[MAXTAM_PRISIONEIRO];
}tCela;

/**
 * @brief Cria uma cela da prisão a partir do parâmetro da capacidade das celas.
 * @param capacidade numero máximo de presidiários na cela
*/
tCela criaCela(int capacidade);

/**
 * @brief Retorna valor diferente de zero caso haja uma vaga na cela, e 0 caso contrario.
 * @param cela Cela que se deseja saber se há vaga
*/
int possuiVagaCela(tCela* cela);

/**
 * @brief Retorna o numero atual de prisioneiros na cela
*/
int obtemNumeroPrisioneirosCela(tCela* cela);

/**
 * @brief Insere o prisioneiro na cela, após já ter garantido que há vaga na cela
*/
void inserePrisioneiroCela(tCela* cela, tPrisioneiro prisioneiro);

/**
 * @brief Retorna o presidiário da cela na posição fornecida
 * @param cela Cela que se deseja obter o prisioneiro
 * @param i Posição do prisioneiro desejado no vetor de prisioneiros da cela
*/
tPrisioneiro obtemPrisioneiroCela(tCela* cela, int i);

/**
 * @brief Chama a função individual de fuga para cada prisioneiro da cela
 * @param cela Cela onde ocorre a fuga
*/
void fogePrisioneirosCela(tCela* cela);

/**
 * @brief Chama a função individual de passar o dia para cada prisioneiro da cela
 * @param cela cela fornecida para o passar do dia
*/
void passaDiaCela(tCela* cela);

#endif