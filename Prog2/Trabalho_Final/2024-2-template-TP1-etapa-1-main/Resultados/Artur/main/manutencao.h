#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_ESTADO_MANUTENCAO 25
#define MAX_TAM_LOCAL_MANUTENCAO 100

#define TEMPO_ESTIMADO_RUIM 3
#define TEMPO_ESTIMADO_REGULAR 2
#define TEMPO_ESTIMADO_BOM 1

#define FATOR_TEMPO_FINANCEIRO 3
#define FATOR_TEMPO_RH 2
#define FATOR_TEMPO_PeD 1
#define FATOR_TEMPO_VENDAS 1
#define FATOR_TEMPO_MARKETING 1

typedef struct Manutencao Manutencao;

Manutencao *criaManutencao(char *nome, char *estado, char *local);
Manutencao *lerManutencao();
void setTempoEstimadoManutencao(Manutencao *m, char *setor);
int getTempoEstimadoManutencao(void *dado);
char getTipoManutencao();
void desalocaManutencao(void *dado);
void notificaManutencao(void *dado);

#endif