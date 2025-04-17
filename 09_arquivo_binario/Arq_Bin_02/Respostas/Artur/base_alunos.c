#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BaseAlunos
{
    tAluno **alunos;
    int qtd_total;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos *b = malloc(sizeof(*b));
    b->qtd_total = 0;
    b->alunos = NULL;
    return b;
}
/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{
    if(baseAlunos)
    {
        if(baseAlunos->alunos)
        {
            for (int i = 0; i < baseAlunos->qtd_total; i++)
                DestruirAluno(baseAlunos->alunos[i]);
            free(baseAlunos->alunos);
            baseAlunos->alunos = NULL;
        }
        free(baseAlunos);
    }
    baseAlunos = NULL;
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    FILE *file = fopen(nomeArquivo, "rb");

    int total;
    fread(&total, sizeof(int), 1, file);

    baseAlunos->alunos = malloc(sizeof(tAluno *) * total);
    baseAlunos->qtd_total = total;
    
    for(int i = 0; i < total; i++)
        baseAlunos->alunos[i] = LeAluno(file);
    fclose(file);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{
    float media = 0;

    for(int i = 0; i < baseAlunos->qtd_total; i++)
        media += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    return media / baseAlunos->qtd_total;
}
