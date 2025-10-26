#ifndef _TIME_H
#define _TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TIME_NOME 33

typedef struct _Time tTime;

/** 
 * @brief Construtor do tipo time. Deve ler um nome pela entrada padrao.
*/
tTime* LeTime();

/**
 * @brief Retona o numero de vitorias do time.
*/
int ObtemVitorias(tTime *t);

/**
 * @brief Retona o numero de partidas.
*/
int ObtemPartidas(tTime *t);

/**
 * @brief Retona o numero de derrotas do time.
*/
int ObtemDerrotas(tTime *t);

/**
 * @brief Retona a string do nome do time.
*/
char* ObtemNomeTime(tTime *t);

/**
 * @brief Retona o saldo de gols da equipe.
*/
int ObtemSaldo(tTime *t);

/**
 * @brief Aumenta o numero de vitorias em 1.
*/
void AtualizaVitorias(tTime *t);

/**
 * @brief Aumenta o numero de empates em 1.
*/
void AtualizaEmpates(tTime *t);

/**
 * @brief Aumenta o numero de derrotas em 1.
*/
void AtualizaDerrotas(tTime *t);

/**
 * @brief Aumenta a quantidade de gols marcados.
*/
void AtualizaGolsMarcados(tTime *t, int gols);

/**
 * @brief Aumenta a quantidade de gols sofridos.
*/
void AtualizaGolsSofridos(tTime *t, int gols);

/**
 * @brief Retorna a pontuacao do time.
*/
int ObtemPontos(tTime* t);

/**
 * @brief Usa os criterios de classificacao para indicar qual time possui melhor colocacao. Retorna -1 para t1, 1 para t2.
*/
int DesempataTimes(tTime *t1, tTime *t2);

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
*/
void ImprimeTime(tTime *t);

/**
 * @brief Libera a memoria alocada para time.
*/
void DesalocaTime(tTime *t);

#endif