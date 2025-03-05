#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario
{
    char nome[MAX_TAM_NOME];
    char cpf[MAX_TAM_CPF];
    char telefone[MAX_TAM_TELEFONE];
    char genero[MAX_TAM_GENERO];
    char setor[MAX_TAM_SETOR];
    Data *data_nascimento;
    int tickets_solicitados;
};

Usuario *criaUsuario(char *nome, char *cpf, Data *data_nascimento, char *telefone, char *genero, char *setor)
{
    Usuario *u = malloc(sizeof(*u));
    if(!u)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    strcpy(u->nome, nome);
    strcpy(u->cpf, cpf);
    strcpy(u->telefone, telefone);
    strcpy(u->genero, genero);
    strcpy(u->setor, setor);
    u->data_nascimento = data_nascimento;
    u->tickets_solicitados = 0;
    return u;
}

Usuario *lerUsuario()
{
    char nome[MAX_TAM_NOME], cpf[MAX_TAM_CPF], telefone[MAX_TAM_TELEFONE], genero[MAX_TAM_GENERO], setor[MAX_TAM_SETOR];
    scanf("%[^\n] %[^\n]%*c", nome, cpf);
    Data *data_nascimento = lerData();
    scanf("%[^\n] %[^\n] %[^\n]%*c", telefone, genero, setor);
    Usuario *u = criaUsuario(nome, cpf, data_nascimento, telefone, genero, setor);
    return u;
}

int getTicketsSolicitadosUsuario(void *dado)
{
    Usuario *u = (Usuario *) dado;
    return u->tickets_solicitados;
}

char *getCpfUsuario(void *dado)
{
    Usuario *u = (Usuario *) dado;
    return u->cpf;
}

char *getSetorUsuario(void *dado)
{
    Usuario *u = (Usuario *) dado;
    return u->setor;
}

void aumentaQtdTicketsSolicitados(void *dado)
{
    Usuario *u = (Usuario *) dado;
    u->tickets_solicitados++;
}

void desalocaUsuario(void *dado)
{
    Usuario *u = (Usuario *) dado;
    if(u)
    {
        desalocaData(u->data_nascimento);
        free(u);
    }
    u = NULL;
}

void notificaUsuario(void *dado)
{
    Usuario *u = (Usuario *) dado;
    printf("--------------------\n");
    printf("- Nome: %s\n", u->nome);
    printf("- CPF: %s\n", u->cpf);
    notificaData(u->data_nascimento);
    printf("- Telefone: %s\n", u->telefone);
    printf("- Genero: %s\n", u->genero);
    printf("- Setor: %s\n", u->setor);
    printf("- Tickets solicitados: %d\n", u->tickets_solicitados);
}

int calculaIdadeUsuario(void *dado)
{
    Usuario *u = (Usuario *) dado;
    return calculaIdadeData(u->data_nascimento);
}

int comparaCpfcomCpfUsuario(void *dado, char *cpf)
{
    Usuario *u = (Usuario *) dado;
    return strcmp(u->cpf, cpf) == 0;
}

int comparaQtdTicketsSolicitados(void *dado1, void *dado2) 
{
    Usuario *u1 = (Usuario *)dado1;
    Usuario *u2 = (Usuario *)dado2;

    if(u1->tickets_solicitados < u2->tickets_solicitados) 
        return 1;
    if(strcmp(u1->nome, u2->nome) > 0)
        return 1;
    return 0;
}