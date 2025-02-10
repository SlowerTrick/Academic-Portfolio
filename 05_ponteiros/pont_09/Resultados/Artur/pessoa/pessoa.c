#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa p;
    p.mae = NULL;
    p.pai = NULL;
    return p;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{
    scanf(" %100[^\n]%*c", pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    return (pessoa->pai != NULL || pessoa->mae != NULL);
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    if (VerificaSeTemPaisPessoa(pessoa))
    {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        if (pessoa->pai != NULL)
            printf("PAI: %s\n", pessoa->pai->nome);
        else
            printf("PAI: NAO INFORMADO\n");
        if (pessoa->mae != NULL)
            printf("MAE: %s\n", pessoa->mae->nome);
        else
            printf("MAE: NAO INFORMADO\n");
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int total = 0;
    scanf("%d", &total);

    for(int i = 0; i < total; i++)
    {
        char linha[1000];
        int maeIndex = -1, paiIndex = -1, filhoIndex = -1;
        scanf(" mae: %d, pai: %d, filho: %d%*c", &maeIndex, &paiIndex, &filhoIndex);
    
        if (maeIndex != -1)
            pessoas[filhoIndex].mae = &pessoas[maeIndex];
        if (paiIndex != -1)
            pessoas[filhoIndex].pai = &pessoas[paiIndex];
    }
}
