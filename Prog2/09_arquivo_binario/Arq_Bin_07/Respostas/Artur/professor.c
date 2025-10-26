#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

#pragma pack(push, 1)
struct Professor
{
    char nome[50];
    char dataNascimento[12]; 
    char departamento[50];
};
#pragma pack(pop)

/**
 * @brief Cria um novo professor.
 * @param nome Nome do professor.
 * @param dataNascimento Data de nascimento do professor.
 * @param departamento Departamento do professor.
 * @return Um ponteiro para a estrutura do professor criada. Caso a alocação falhe, a função termina o programa.
 */
tProfessor *CriaProfessor(char *nome, char *dataNascimento, char *departamento)
{
    tProfessor *p = calloc(1, sizeof(*p));
    strcpy(p->nome, nome);
    strcpy(p->dataNascimento, dataNascimento);
    strcpy(p->departamento, departamento);
    return p;
}

/**
 * @brief Destroi um professor.
 * @param prof Ponteiro para a estrutura do professor a ser destruída.
 */
void DestroiProfessor(tProfessor *prof)
{
    if(prof)
        free(prof);
    prof = NULL;
}

/**
 * @brief Lê um professor da entrada padrão.
 * @return Um ponteiro para a estrutura do professor lida.
 */
tProfessor *LeProfessor()
{
    char nome[50], dataNascimento[11], departamento[45];
    scanf(" %[^\n] %[^\n] %[^\n]%*c", nome, dataNascimento, departamento);
    return CriaProfessor(nome, dataNascimento, departamento);
}

/**
 * @brief Compara o nome de dois professores.
 * @param prof1 Ponteiro para a estrutura do primeiro professor.
 * @param prof2 Ponteiro para a estrutura do segundo professor.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeProfessor(tProfessor *prof1, tProfessor *prof2)
{
    return strcmp(prof1->nome, prof2->nome);
}

/**
 * @brief Salva um professor em um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser salva.
 * @param file Ponteiro para o arquivo onde o professor será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste professor.
 */
int SalvaProfessor(tProfessor *prof, FILE *file)
{
    fwrite(prof, 1, sizeof(*prof), file);
    return sizeof(*prof);
}

/**
 * @brief Carrega um professor de um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser carregada.
 * @param file Ponteiro para o arquivo de onde o professor será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste professor.
 */
int CarregaProfessor(tProfessor *prof, FILE *file)
{
    fread(prof, 1, sizeof(*prof), file);
    return sizeof(*prof);
}

/**
 * @brief Imprime o nome de um professor.
 * @param prof Ponteiro para a estrutura do professor cujo nome será impresso.
 */
void ImprimeNomeProfessor(tProfessor *prof)
{
    printf("%s\n", prof->nome);
}
