#ifndef PRISAO_H
#define PRISAO_H

#include "cela.h"
#include "prisioneiro.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAXTAM_NOME 100

typedef struct
{
    char nome[MAXTAM_NOME];
    int dia;
    int nCelas;
    int capacidadeCelas;
    tCela celas[MAXTAM_CELAS];
}tPrisao;

/**
 * @brief Construtor do tipo prisão
 * @param nome Nome da prisão
 * @param nCelas Número de celas ocupadas
 * @param capacidadeCelas Número total de celas
*/

tPrisao criaPrisao(char* nome, int nCelas, int capacidadeCelas);

/**
 * @brief Contém o loop do programa que deve imprimir o menu e selecionar opção
*/
void executaPrisao(tPrisao* prisao);

/**
 * @brief Imprime o menu
*/
void imprimeDiaEMenuPrisao(tPrisao* prisao);

/**
 * @brief Faz a leitura e adiciona o prisioneiro na prisão
*/
void inserePrisioneiroPrisao(tPrisao* prisao);
/**
 * @brief Passa o dia em cada uma das celas da prisão
*/
void passaDiaPrisao(tPrisao* prisao);

/**
 * @brief Le da entrada padrão o índice da cela no qual ocorreu a fuga
*/
void registraFugaCelaPrisao(tPrisao* prisao);

/**
 * @brief Finaliza o programa, havendo diferença na finalização caso tenha ou nao prisioneiros na prisao
*/
void finalizaPrograma(tPrisao* prisao);
/**
 * @brief Obtém o total de prisioneiros
*/
int obtemNumeroPrisioneirosPrisao(tPrisao* prisao);

/**
 * @brief Imprime mensagem de rebelião e realiza fuga de todos os prisioneiros
*/
void rebeliaoGeralPrisao(tPrisao* prisao);
#endif