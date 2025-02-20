#include "brasileirao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _BRA
{
    tTabela *tabela;
    float valor_campeonato;
    int n_times;
    int n_rodadas;
};

/**
 * @brief Construtor do campeonato. Le da entrada padrao numero de times, numero de rodadas e pontuacao.
*/
BRA *CriaCamp()
{
    int n_times, n_rodadas;
    float valor_campeonato;
    printf("Insira o num de times, rodadas e premio total:\n");
    scanf("%d %d %f%*c", &n_times, &n_rodadas, &valor_campeonato);
    BRA *b = malloc(sizeof((*b)));
    if(!b)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    b->n_times = n_times;
    b->n_rodadas = n_rodadas;
    b->valor_campeonato = valor_campeonato;
    b->tabela = CriaTabela(n_times);
    return b;
}

/**
 * @brief Le da entrada padrao as partidas da rodada, computa os resultados e atualiza a tabela.
*/
void RealizaRodada(BRA *br)
{
    int n_times = br->n_times;

    for (int i = 0; i < n_times / 2; i++)
    {
        char time1[MAX_TIME_NOME], time2[MAX_TIME_NOME];
        int gols1, gols2;

        scanf(" %s %d x %d %s", time1, &gols1, &gols2, time2);

        tTime *t1 = ObtemTimeTabela(br->tabela, time1);
        tTime *t2 = ObtemTimeTabela(br->tabela, time2);

        if (t1 == NULL || t2 == NULL) {
            printf("Erro: Time não encontrado na tabela.\n");
            return;
        }
        if (gols1 > gols2) 
        {
            AtualizaVitorias(t1);
            AtualizaDerrotas(t2);
        }
        else if (gols1 < gols2)
        {
            AtualizaVitorias(t2);
            AtualizaDerrotas(t1);
        }
        else
        {
            AtualizaEmpates(t1);
            AtualizaEmpates(t2);
        }
        AtualizaGolsMarcados(t1, gols1);
        AtualizaGolsSofridos(t1, gols2);
        AtualizaGolsMarcados(t2, gols2);
        AtualizaGolsSofridos(t2, gols1);
    }
    OrdenaTabela(br->tabela);
    ImprimeTabela(br->tabela);
}

/**
 * @brief Imprime o menu e trata cada opcao.
*/
void RealizaCamp(BRA *br)
{
    while(br->n_rodadas-- > 0)
    {
        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");
    
        char opacao;
        scanf(" %c", &opacao);
    
        if(opacao == 'C')
            RealizaRodada(br);
        else if(opacao == 'R')
            RemoveTimesCamp(br);
        else if(opacao == 'F')
            return;

    }
}

/**
 * @brief Le 2 nomes da entrada padrao e remove os times correspondentes da competicao.
*/
void RemoveTimesCamp(BRA *br)
{
    char time1_removido[MAX_TIME_NOME], time2_removido[MAX_TIME_NOME];
    printf("Times a serem retirados:\n");
    scanf(" %s %s%*c", time1_removido, time2_removido);

    RemoveTimeTabela(br->tabela, time1_removido);
    RemoveTimeTabela(br->tabela, time2_removido);

    printf("Os times %s e %s se retiraram do campeonato\n", time1_removido, time2_removido);

    char time1[MAX_TIME_NOME], time2[MAX_TIME_NOME];
    int gols1, gols2;

    scanf(" %s %d x %d %s", time1, &gols1, &gols2, time2);

    tTime *t1 = ObtemTimeTabela(br->tabela, time1);
    tTime *t2 = ObtemTimeTabela(br->tabela, time2);
    br->n_times -= 2;


    if (t1 == NULL || t2 == NULL) {
        return;
    }

    // Partida 1
    if(gols1 > gols2) 
    {
        AtualizaVitorias(t1);
        AtualizaDerrotas(t2);
    }
    else if(gols1 < gols2)
    {
        AtualizaVitorias(t2);
        AtualizaDerrotas(t1);
    }
    else
    {
        AtualizaEmpates(t1);
        AtualizaEmpates(t2);
    }
    AtualizaGolsMarcados(t1, gols1);
    AtualizaGolsSofridos(t1, gols2);
    AtualizaGolsMarcados(t2, gols2);
    AtualizaGolsSofridos(t2, gols1);

    OrdenaTabela(br->tabela);
    ImprimeTabela(br->tabela);
}

/**
 * @brief Libera a memoria do campeonato.
*/
void DesalocaCamp(BRA *br)
{
    if(br)
    {
        DesalocaTabela(br->tabela);
        free(br);
    }
    br = NULL;
}

/**
 * @brief Imprime a tabela final, premiacao e desaloca o campeonato.
*/
void FinalizaCamp(BRA *br)
{
    if(br->n_times > 0)
    {
        printf("Esta foi a tabela final:\n");
        ImprimeTabela(br->tabela);   
    }
    ImprimePremiacao(br->tabela, br->valor_campeonato);
    printf("Fim do campeonato\n");
    DesalocaCamp(br);
}
