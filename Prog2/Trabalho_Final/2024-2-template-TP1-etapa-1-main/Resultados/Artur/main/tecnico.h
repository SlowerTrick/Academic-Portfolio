#ifndef _TECNICO_H
#define _TECNICO_H

#include "data.h"

#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15
#define MAX_TAM_GENERO 10
#define MAX_TAM_TELEFONE 15
#define MAX_TAM_AREA_ATUACAO 6

typedef struct Tecnico Tecnico;

Tecnico *criaTecnico(char *nome, char *cpf, Data *data_nascimento, char *telefone, char *genero, char *area_atuacao, int tempo_disponivel, float salario);
Tecnico *lerTecnico();
int getTempoDisponivelTecnico(void *dado);
int getTempoTrabalhadoTecnico(void *dado);
char *getCpfTecnico(void *dado);
char *getAreaAtuacaoTecnico(void *dado);
void alteraTempoTrabalhoTecnico(void *dado, int tempo);
void desalocaTecnico(void *dado);
void notificaTecnico(void *dado);
int calculaIdadeTecnico(void *dado);
int comparaQtdHorasTrabalhadas(void *dado1, void *dado2);

#endif