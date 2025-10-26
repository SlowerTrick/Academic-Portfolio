#ifndef _OUTROS_H
#define _OUTROS_H

#define MAX_TAM_DESCRICAO_OUTROS 500
#define MAX_TAM_LOCAL_OUTROS 100

typedef struct Outros Outros;

Outros *criaOutros(char *descricao, char *local, int dificuldade);
Outros *lerOutros();
void setTempoEstimadoOutros(Outros *o);
int getTempoEstimadoOutros(void *dado);
char getTipoOutros();
void desalocaOutros(void *dado);
void notificaOutros(void *dado);

#endif