#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Manutencao
{
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO_MANUTENCAO];
    char local[MAX_TAM_LOCAL_MANUTENCAO];
    int tempo;
};


Manutencao *criaManutencao(char *nome, char *estado, char *local)
{
    Manutencao *m = malloc(sizeof(*m));
    if(!m)
    {
        printf("ERRO! Falta de memoria");
        exit(1);
    }
    strcpy(m->nome, nome);
    strcpy(m->estado, estado);
    strcpy(m->local, local);
    m->tempo = 0;
    return m;
}
Manutencao *lerManutencao()
{
    char nome[MAX_TAM_NOME_MANUTENCAO], estado[MAX_TAM_ESTADO_MANUTENCAO], local[MAX_TAM_LOCAL_MANUTENCAO];
    int impacto;
    scanf("%[^\n] %[^\n] %[^\n]%*c", nome, estado, local);
    Manutencao *m = criaManutencao(nome, estado, local);
    return m;
}

void setTempoEstimadoManutencao(Manutencao *m, char *setor) 
{
    int tempo = (strcmp(m->estado, "RUIM") == 0) ? TEMPO_ESTIMADO_RUIM :
                (strcmp(m->estado, "REGULAR") == 0) ? TEMPO_ESTIMADO_REGULAR :
                TEMPO_ESTIMADO_BOM;

    int fator = (strcmp(setor, "FINANCEIRO") == 0) ? FATOR_TEMPO_FINANCEIRO :
                (strcmp(setor, "RH") == 0) ? FATOR_TEMPO_RH :
                FATOR_TEMPO_PeD; // P&D, VENDAS e MARKETING possuem fator 1

    m->tempo = tempo * fator;
}

int getTempoEstimadoManutencao(void *dado)
{
    Manutencao *m = (Manutencao *) dado;
    return m->tempo;
}
char getTipoManutencao()
{
    return 'M';
}
void desalocaManutencao(void *dado)
{
    Manutencao *m = (Manutencao *) dado;
    if(m)
        free(m);
    m = NULL;
}
void notificaManutencao(void *dado)
{
    Manutencao *m = (Manutencao *) dado;
    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n", m->nome);
    printf("- Estado de conservacao: %s\n", m->estado);
    printf("- Local: %d\n", m->local);
    printf("- Tempo estimado: %dh\n", m->tempo);
}
