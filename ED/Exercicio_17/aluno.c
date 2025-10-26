#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno 
{
    char *nome;
    int presenca;
    int faltas;
};

Aluno *criaAluno(char *nome)
{
    Aluno *a = malloc(sizeof(*a));
    if(!a)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    a->nome = strdup(nome);
    a->faltas = 0;
    a->presenca = 0;
    return a;
}

int retornaPresencasAluno(Aluno *a)
{
    return a->presenca;
}

int retornaFaltasAluno(Aluno *a)
{
    return a->faltas;
}

char *retornaNomeAluno(Aluno *a)
{
    return a->nome;
}

void incrementaPresencasAluno(Aluno *a)
{
    a->presenca++;
}

void incrementaFaltasAluno(Aluno *a)
{
    a->faltas++;
}

void imprimeAluno(Aluno *a, FILE *saida)
{
    fprintf(saida, "%s %dP %dF\n", a->nome, a->presenca, a->faltas);
}

void liberaAluno(Aluno *a)
{
    if(a)
    {
        free(a->nome);
        free(a);
    }
}
