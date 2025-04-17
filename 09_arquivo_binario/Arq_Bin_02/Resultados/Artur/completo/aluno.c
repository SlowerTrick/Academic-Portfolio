#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 100
#define DATE_SIZE 11
#define CURSO_SIZE 50

struct Aluno
{
    char nome[NAME_SIZE];
    char dataNascimento[DATE_SIZE];
    char curso[CURSO_SIZE];
    int periodo;
    float coeficienteRendimento;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento)
{
    tAluno *a = malloc(sizeof(*a));
    strcpy(a->nome, nome);
    strcpy(a->dataNascimento, dataNascimento);
    strcpy(a->curso, curso);
    a->periodo = periodo;
    a->coeficienteRendimento = coeficienteRendimento;
    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno)
{
    if(aluno)
        free(aluno);
    aluno = NULL;
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    char nome[NAME_SIZE], dataNascimento[DATE_SIZE], curso[CURSO_SIZE];
    int periodo;
    float coeficienteRendimento;

    fread(nome, sizeof(char), NAME_SIZE, arquivo_binario);
    fread(dataNascimento, sizeof(char), DATE_SIZE, arquivo_binario);
    fread(curso, sizeof(char), CURSO_SIZE, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&coeficienteRendimento, sizeof(float), 1, arquivo_binario);

    return CriarAluno(nome, dataNascimento, curso, periodo, coeficienteRendimento);
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno)
{
    return aluno->coeficienteRendimento;
}
