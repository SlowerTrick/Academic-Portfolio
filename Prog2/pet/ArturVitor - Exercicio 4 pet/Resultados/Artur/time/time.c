#include "time.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _Time
{
    char nome[MAX_TIME_NOME];
    int vitorias;
    int derrotas;
    int empates;
    int partidas;
    int saldo_gols;
    int gols_marcados;
    int gols_sofridos;
    int pontuacao;
};


/** 
 * @brief Construtor do tipo time. Deve ler um nome pela entrada padrao.
*/
tTime* LeTime()
{
    char nome[MAX_TIME_NOME];
    scanf(" %s%*c", nome);

    tTime *t = malloc(sizeof(*t));
    strcpy(t->nome, nome);
    t->vitorias = 0;
    t->derrotas = 0;
    t->empates = 0;
    t->gols_sofridos = 0;
    t->gols_marcados = 0;
    t->partidas = 0;
    t->pontuacao = 0;
    t->saldo_gols = 0;
    return t;
}

/**
 * @brief Retona o numero de vitorias do time.
*/
int ObtemVitorias(tTime *t)
{
    return t->vitorias;
}

/**
 * @brief Retona o numero de partidas.
*/
int ObtemPartidas(tTime *t)
{
    return t->partidas;
}

/**
 * @brief Retona o numero de derrotas do time.
*/
int ObtemDerrotas(tTime *t)
{
    return t->derrotas;
}

/**
 * @brief Retona a string do nome do time.
*/
char* ObtemNomeTime(tTime *t)
{
    return t->nome;
}

/**
 * @brief Retona o saldo de gols da equipe.
*/
int ObtemSaldo(tTime *t)
{
    return t->saldo_gols;
}

/**
 * @brief Aumenta o numero de vitorias em 1.
*/
void AtualizaVitorias(tTime *t)
{
    t->vitorias++;
    t->pontuacao += 3;
}

/**
 * @brief Aumenta o numero de empates em 1.
*/
void AtualizaEmpates(tTime *t)
{
    t->empates++;
    t->pontuacao++;
}

/**
 * @brief Aumenta o numero de derrotas em 1.
*/
void AtualizaDerrotas(tTime *t)
{
    t->derrotas++;
}

/**
 * @brief Aumenta a quantidade de gols marcados.
*/
void AtualizaGolsMarcados(tTime *t, int gols)
{
    t->gols_marcados += gols;
    t->saldo_gols = t->gols_marcados - t->gols_sofridos;
}

/**
 * @brief Aumenta a quantidade de gols sofridos.
*/
void AtualizaGolsSofridos(tTime *t, int gols)
{
    t->gols_sofridos += gols;
    t->saldo_gols = t->gols_marcados - t->gols_sofridos;
}

/**
 * @brief Retorna a pontuacao do time.
*/
int ObtemPontos(tTime* t)
{
    return t->pontuacao;
}

/**
 * @brief Usa os criterios de classificacao para indicar qual time possui melhor colocacao. Retorna -1 para t1, 1 para t2.
*/
int DesempataTimes(tTime *t1, tTime *t2)
{
    if(t1->pontuacao != t2->pontuacao)
        return (t1->pontuacao > t2->pontuacao) ? -1 : 1;
    if(t1->vitorias != t2->vitorias)
        return (t1->vitorias > t2->vitorias) ? -1 : 1;
    if(t1->saldo_gols != t2->saldo_gols)
        return (t1->saldo_gols > t2->saldo_gols) ? -1 : 1;
    return -1;
}

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
*/
void ImprimeTime(tTime *t)
{
    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n", t->nome, t->pontuacao, t->vitorias, t->derrotas, t->empates, t->saldo_gols);
}

/**
 * @brief Libera a memoria alocada para time.
*/
void DesalocaTime(tTime *t)
{
    free(t);
    t = NULL;
}
