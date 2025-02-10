#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa()
{
    tPessoa p;
    p.mae = NULL;
    p.pai = NULL;
    p.irmao = NULL;
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
        if (pessoa->irmao != NULL)
            printf("IRMAO: %s\n", pessoa->irmao->nome);
        else
            printf("IRMAO: NAO INFORMADO\n");
        printf("\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    // Verifica se os ponteiros são válidos
    if (pessoa1 == NULL || pessoa2 == NULL) {
        return 0; // Se uma das pessoas for NULL, não são irmãos
    }

    // Verifica se as mães existem e se os nomes são iguais
    if (pessoa1->mae != NULL && pessoa2->mae != NULL &&
        strcmp(pessoa1->mae->nome, pessoa2->mae->nome) == 0) {
        return 1; // São irmãos pela mãe
    }

    // Verifica se os pais existem e se os nomes são iguais
    if (pessoa1->pai != NULL && pessoa2->pai != NULL &&
        strcmp(pessoa1->pai->nome, pessoa2->pai->nome) == 0) {
        return 1; // São irmãos pelo pai
    }

    return 0; // Não são irmãos
}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
{
    int total;
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
    for(int i = 0; i < numPessoas-1; i++)
    {
        for(int j = i+1; j < numPessoas; j++)
        {
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]))
            {
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}   