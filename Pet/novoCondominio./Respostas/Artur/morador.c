#include "morador.h"
#include <stdio.h>
#include <string.h>

/*
 *  Função que lê um morador de acordo com o formato de entrada descrito na
 *  especificação
 *  Retorna o Morador lido
 */
Morador lerMorador()
{
    Morador m;
    scanf(" %100[^\n] %s", m.nome, m.cpf);
    m.dataNasc = lerData();
    scanf("%s", m.idResidencia);
    getchar();
    return m;
}

/**
 * Função que imprime todas as informações de uma Morador conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeMorador(Morador m)
{
    printf("Nome: %s\n", m.nome);
    printf("CPF: %s\n", m.cpf);
    printf("Data de Nascimento: ");
    imprimeData(m.dataNasc);
    printf("Residencia: %s\n", m.idResidencia);
}

/**
 * Verifica se dois moradores são iguais. A comparação é feita usando apenas o CPF.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int comparaMorador(Morador m1, Morador m2)
{
    return strcmp(m1.cpf, m2.cpf) == 0;
}

/**
 * Verifica se um dado CPF pertence ao morador.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int verificaCPFMorador(Morador m1, char *cpf)
{
    return strcmp(m1.cpf, cpf) == 0;
}

/*
 *  Função que calcula a idade de um morador em relação a uma data de referência
 *  Retorna a idade do morador em anos
 */
int calculaIdadeMorador(Morador m, Data dataRef)
{
    return calcularDiffAnosData(m.dataNasc, dataRef);
}
