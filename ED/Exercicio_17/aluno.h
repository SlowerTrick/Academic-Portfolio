#pragma once

typedef struct aluno Aluno;

#include <stdio.h>

Aluno *criaAluno(char *nome);
int retornaPresencasAluno(Aluno *a);
int retornaFaltasAluno(Aluno *a);
char *retornaNomeAluno(Aluno *a);
void incrementaPresencasAluno(Aluno *a);
void incrementaFaltasAluno(Aluno *a);
void imprimeAluno(Aluno *a, FILE *saida);
void liberaAluno(Aluno *a);
