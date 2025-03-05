#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};


Data *criaData(int dia, int mes, int ano)
{
    Data *d = malloc(sizeof(*d));
    if(!d)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return d;
}

Data *lerData()
{
    int dia, mes, ano;
    scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    Data *d = criaData(dia, mes, ano);
    return d;
}

void notificaData(void *dado)
{
    Data *d = (Data *) dado;
    printf("- Data de Nascimento: %d/%d/%d\n", d->dia, d->mes, d->ano);
}

int calculaIdadeData(void *dado)
{
    Data *d = (Data *) dado;
    int idade = ANO_ATUAL - d->ano;
    if(d->mes > MES_ATUAL)
        idade--;
    else if(d->mes == MES_ATUAL && d->dia > DIA_ATUAL)
        idade--;
    return idade;
}

void desalocaData(void *dado)
{
    Data *d = (Data *) dado;
    if(d)
        free(d);
    d = NULL;
}