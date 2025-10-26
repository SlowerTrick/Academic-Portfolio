#include "tabela.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _Tabela{
    tTime **times;
    int numTimes;
};

/**
 * @brief Construtor do tipo tabela. Deve criar os times.
 * @param numTimes Numero de times a serem criados.
*/
tTabela* CriaTabela(int numTimes)
{
    tTabela *t = malloc(sizeof(*t));
    if(!t)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    t->times = malloc(sizeof(tTime *) * numTimes);
    if(!t->times)
    {
        free(t);
        printf("Erro! falta de memoria");
        exit(1);
    }
    t->numTimes = numTimes;

    for(int i = 0 ; i < numTimes; i++)
        t->times[i] = LeTime();

    return t;
}

/**
 * @brief Libera a memoria alocada para a tabela e seus times.
*/
void DesalocaTabela(tTabela* tabela)
{
    if(tabela)
    {
        for(int i = 0; i < tabela->numTimes; i++)
            if(tabela->times[i])
                DesalocaTime(tabela->times[i]);
        free(tabela->times);
        free(tabela);
    }
    tabela = NULL;
}

/**
 * @brief Ordena a tabela de acordo com os criterios definidos.
*/
void OrdenaTabela(tTabela* tabela)
{
    for(int i = 0; i < tabela->numTimes - 1; i++)
    {
        for(int j = i+1; j < tabela->numTimes; j++)
        {
            if(DesempataTimes(tabela->times[i], tabela->times[j]) == 1 || DesempataTimes(tabela->times[i], tabela->times[j]) == 0)
            {
                tTime *aux = tabela->times[i];
                tabela->times[i] = tabela->times[j];
                tabela->times[j] = aux;
            }
        }
    }
}

/**
 * @brief Dado um nome, retorna o time correspondente.
*/
tTime* ObtemTimeTabela(tTabela* tabela, char* time)
{
    for(int i = 0; i < tabela->numTimes; i++)
    {
        if(strcmp(ObtemNomeTime(tabela->times[i]), time) == 0)
            return tabela->times[i];
    }
    return NULL;
}

/**
 * @brief Dado um nome, desaloca e remove o time correspondente da tabela.
*/
void RemoveTimeTabela(tTabela* tabela, char* time)
{
    int index_time = -1;
    for(int i = 0; i < tabela->numTimes; i++)
    {
        if(strcmp(ObtemNomeTime(tabela->times[i]), time) == 0)
        {
            index_time = i;
            break;
        }    
    }

    if(index_time != -1)
    {
        DesalocaTime(tabela->times[index_time]);
        tabela->times[index_time] = NULL;
        for(int i = index_time; i < tabela->numTimes - 1; i++)
            tabela->times[i] = tabela->times[i+1];
        tabela->numTimes -= 1;
        if(tabela->numTimes > 0)
            tabela->times = realloc(tabela->times, sizeof(tTime *) * tabela->numTimes);
        else
        {
            free(tabela->times);
            tabela->times = NULL;
        }
    }
}

/**
 * @brief Imprime a tela de premiacao no final do campeonato.
*/
void ImprimePremiacao(tTabela* tabela, float valorPremio)
{
    int total_participantes = tabela->numTimes;

    if(total_participantes == 0)
        printf("Premio de R$%.2f acumulado para a proxima edicao\n", valorPremio);
    else if(total_participantes == 2)
    {
        if(tabela->times[0] && tabela->times[1])
        {
            printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[0]), valorPremio * 0.6);
            printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[1]), valorPremio * 0.4);
        }
    }
    else
    {
        if(tabela->times[0] && tabela->times[1] && tabela->times[2])
        {
            printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[0]), valorPremio * 0.5);
            printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[1]), valorPremio * 0.3);
            printf("3º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[2]), valorPremio * 0.2);
        }
    }
}

/**
 * @brief Imprime todos os times da tabela.
*/
void ImprimeTabela(tTabela* tabela)
{
    OrdenaTabela(tabela);
    printf("Classificação:\n");
    printf("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo\n");
    for(int i = 0; i < tabela->numTimes; i++)
        ImprimeTime(tabela->times[i]);
    printf("\n");
}
