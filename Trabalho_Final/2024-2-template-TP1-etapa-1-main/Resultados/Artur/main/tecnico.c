#include "tecnico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tecnico
{
    char nome[MAX_TAM_NOME];
    char cpf[MAX_TAM_CPF];
    char telefone[MAX_TAM_TELEFONE];
    char genero[MAX_TAM_GENERO];
    char area_atuacao[MAX_TAM_AREA_ATUACAO];
    Data *data_nascimento;
    float salario;
    int tempo_disponivel;
    int tempo_trabalhado;
};

Tecnico *criaTecnico(char *nome, char *cpf, Data *data_nascimento, char *telefone, char *genero, char *area_atuacao, int tempo_disponivel, float salario)
{
    Tecnico *t = malloc(sizeof(*t));
    if(!t)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    strcpy(t->nome, nome);
    strcpy(t->cpf, cpf);
    strcpy(t->telefone, telefone);
    strcpy(t->genero, genero);
    strcpy(t->area_atuacao, area_atuacao);
    t->data_nascimento = data_nascimento;
    t->salario = salario;
    t->tempo_disponivel = tempo_disponivel;
    t->tempo_trabalhado = 0;
    return t;
}

Tecnico *lerTecnico()
{
    char nome[MAX_TAM_NOME], cpf[MAX_TAM_CPF], telefone[MAX_TAM_TELEFONE], genero[MAX_TAM_GENERO], area_atuacao[MAX_TAM_AREA_ATUACAO];
    int tempo_disponivel; 
    float salario;
    scanf("%[^\n] %[^\n]%*c", nome, cpf);
    Data *data_nascimento = lerData();
    scanf("%[^\n] %[^\n] %[^\n] %d %f%*c", telefone, genero, area_atuacao, &tempo_disponivel, &salario);
    Tecnico *t = criaTecnico(nome, cpf, data_nascimento, telefone, genero, area_atuacao, tempo_disponivel, salario);
    return t;
}

int getTempoDisponivelTecnico(void *dado)
{
    Tecnico *t = (Tecnico *) dado;
    return t->tempo_disponivel;
}

int getTempoTrabalhadoTecnico(void *dado)
{
    Tecnico *t = (Tecnico *) dado;
    return t->tempo_trabalhado;
}

char *getCpfTecnico(void *dado)
{
    Tecnico *t = (Tecnico *) dado;
    return t->cpf;
}

char *getAreaAtuacaoTecnico(void *dado)
{
    Tecnico *t = (Tecnico *) dado;
    return t->area_atuacao;
}

void alteraTempoTrabalhoTecnico(void *dado, int tempo)
{
    Tecnico *t = (Tecnico *) dado;
    t->tempo_disponivel -= tempo;
    t->tempo_trabalhado += tempo;
}

void desalocaTecnico(void *dado)
{
    Tecnico *t = (Tecnico *) dado;
    if(t)
    {
        desalocaData(t->data_nascimento);
        free(t);
    }
    t = NULL;
}

void notificaTecnico(void *dado)
{
    Tecnico *t = (Tecnico *) dado;
    printf("--------------------\n");
    printf("- Nome: %s\n", t->nome);
    printf("- CPF: %s\n", t->cpf);
    notificaData(t->data_nascimento);
    printf("- Telefone: %s\n", t->telefone);
    printf("- Genero: %s\n", t->genero);
    printf("- Area de Atuacao: %s\n", t->area_atuacao);
    printf("- Salario: %.2f\n", t->salario);
    printf("- Disponibilidade: %dh\n", t->tempo_disponivel);
    printf("- Tempo Trabalhado: %dh\n", t->tempo_trabalhado);
}

int calculaIdadeTecnico(void *dado)
{
    Tecnico *t = (Tecnico *) dado;
    return calculaIdadeData(t->data_nascimento);
}

int comparaQtdHorasTrabalhadas(void *dado1, void *dado2)
{
    Tecnico *t1 = (Tecnico *) dado1;
    Tecnico *t2 = (Tecnico *) dado2;

    if(t1->tempo_trabalhado < t2->tempo_trabalhado) 
        return 1;
    if(strcmp(t1->nome, t2->nome) > 0)
        return 1;
    return 0;
}