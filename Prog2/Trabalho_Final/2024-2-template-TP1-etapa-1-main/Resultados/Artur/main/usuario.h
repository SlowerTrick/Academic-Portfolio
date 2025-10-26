#ifndef _USUARIO_H
#define _USUARIO_H

#include "data.h"

#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15
#define MAX_TAM_GENERO 10
#define MAX_TAM_TELEFONE 15
#define MAX_TAM_SETOR 11

typedef struct Usuario Usuario;

Usuario *criaUsuario(char *nome, char *cpf, Data *data_nascimento, char *telefone, char *genero, char *setor);
Usuario *lerUsuario();
int getTicketsSolicitadosUsuario(void *dado);
char *getCpfUsuario(void *dado);
char *getSetorUsuario(void *dado);
void aumentaQtdTicketsSolicitados(void *dado);
void desalocaUsuario(void *dado);
void notificaUsuario(void *dado);
int calculaIdadeUsuario(void *dado);
int comparaCpfcomCpfUsuario(void *dado, char *cpf);
int comparaQtdTicketsSolicitados(void *dado1, void *dado2);

#endif