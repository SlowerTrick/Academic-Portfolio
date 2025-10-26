#include "outros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Outros
{
    char descricao[MAX_TAM_DESCRICAO_OUTROS];
    char local[MAX_TAM_LOCAL_OUTROS];
    int dificuldade;
    int tempo;
};

Outros *criaOutros(char *descricao, char *local, int dificuldade)
{
    Outros *o = malloc(sizeof(*o));
    if(!o)
    {
        printf("ERRO! Falta de memoria");
        exit(1);
    }
    strcpy(o->descricao, descricao);
    strcpy(o->local, local);
    o->dificuldade = dificuldade;
    o->tempo = 0;
    return o;
}

Outros *lerOutros()
{
    char descricao[MAX_TAM_DESCRICAO_OUTROS], local[MAX_TAM_LOCAL_OUTROS];
    int dificuldade;
    scanf("%[^\n] %[^\n] %d%*c", descricao, local, &dificuldade);
    Outros *o = criaOutros(descricao, local, dificuldade);
    return o;
}   

void setTempoEstimadoOutros(Outros *o)
{
    o->tempo = o->dificuldade;
}

int getTempoEstimadoOutros(void *dado)
{
    Outros *o = (Outros *) dado;
    return o->tempo;
}

char getTipoOutros()
{
    return 'O';
}

void desalocaOutros(void *dado)
{
    Outros *outros = (Outros *) dado;
    if(outros)
        free(outros);
    outros = NULL;
}

void notificaOutros(void *dado)
{
    Outros *o = (Outros *) dado;
    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n", o->descricao);
    printf("- Local: %s\n", o->local);
    printf("- Nivel de Dificuldade: %d\n", o->dificuldade);
    printf("- Tempo Estimado: %dh\n", o->tempo);
}