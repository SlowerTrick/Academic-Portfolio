#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Agencia
{
    tConta **contas;
    int total_contas;
    int conta_atual;
    int id;
    char nome[1000];
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *a = malloc(sizeof(*a));
    a->id = 0;
    a->total_contas = 10;
    a->conta_atual = 0;
    a->contas = malloc(sizeof(tConta *) * a->total_contas);
    a->nome[0] = '\0';
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia *a = (tAgencia *) agencia;
    if(a)
    {
        if(a->contas)
        {
            for(int i = 0; i < a->conta_atual; i++)
                DestroiConta(a->contas[i]);
            free(a->contas);
        }
        a->contas = NULL;
        free(a);
    }
    a = NULL;
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf("%d;%[^\n]%*c", &agencia->id, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    if(agencia->conta_atual == agencia->total_contas)
    {
        agencia->total_contas += 10;
        agencia->contas = realloc(agencia->contas, sizeof(tConta *) * agencia->total_contas);
    }
    agencia->contas[agencia->conta_atual++] = conta;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    return numAgencia == agencia2->id;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    float media = 0;
    for(int i = 0; i < agencia->conta_atual; i++)
        media += GetSaldoConta(agencia->contas[i]);

    return media / agencia->conta_atual;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->id);
    printf("\tNumero de contas cadastradas: %d\n", agencia->conta_atual);
    printf("\tSaldo médio: R$%.2f\n\n", GetSaldoMedioAgencia(agencia));
}
