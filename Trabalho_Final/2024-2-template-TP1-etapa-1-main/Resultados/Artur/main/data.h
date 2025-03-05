#ifndef _DATA_H
#define _DATA_H

typedef struct Data Data;

#define DIA_ATUAL 18
#define MES_ATUAL 2
#define ANO_ATUAL 2025

Data *criaData(int dia, int mes, int ano);
Data *lerData();
void desalocaData(void *dado);
void notificaData(void *dado);
int calculaIdadeData(void *dado);

#endif