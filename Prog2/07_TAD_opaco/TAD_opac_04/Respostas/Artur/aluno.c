#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    char *nome;
    int matricula;
    int notas[3];
};


/**
 * @brief Cria um novo aluno vazio. Os atributos inteiros devem receber valor -1, e o ponteiro do nome deve apontar para NULL;
 * 
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno* CriaAluno()
{
    tAluno *a = malloc(sizeof(*a));
    for(int i = 0; i < 3; i++)
        a->notas[i] = -1;
    a->matricula = -1;
    a->nome = NULL;
    return a;
}

/**
 * @brief Função para liberar toda a memória alocada dinamicamente para estrututas do tipo tAluno
 * 
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno)
{
    if(aluno)
    {
        free(aluno->nome);
        aluno->nome = NULL;
        free(aluno);
    }
    aluno = NULL;
}


/**
 * @brief Lê os dados de um aluno.
 * 
 * @param Ponteiro para aluno (alocado dinamicamente), cujos dados serão preenchidos nessa função
 */
void LeAluno(tAluno *aluno)
{
    aluno->nome = malloc(sizeof(char) * 500);
    scanf(" %s %d %d %d %d%*c", aluno->nome, &aluno->matricula, &aluno->notas[0], &aluno->notas[1], &aluno->notas[2]);
}

/**
 * @brief Compara as matrículas de dois alunos.
 * 
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2)
{
    if(aluno1->matricula > aluno2->matricula)
        return 1;
    if(aluno1->matricula < aluno2->matricula)
        return -1;
    return 0;
}

/**
 * @brief Calcula a média das notas de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno* aluno)
{
    return (aluno->notas[0] + aluno->notas[1] + aluno->notas[2]) / 3.0;
}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 * 
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno* aluno)
{
    return CalculaMediaAluno(aluno) >= 7;
}

/**
 * @brief Imprime os dados de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno* aluno)
{
    printf("%s\n", aluno->nome);
}
