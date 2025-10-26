#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *criaAluno(char *nome);
char *retornaNomeAluno(Aluno *a); 
int retornaPresencaAluno(Aluno *a); 
int retornaFaltasAluno(Aluno *a); 
int insereColisaoAluno(Aluno *a, Aluno *n);
Aluno *retornaProxAluno(Aluno *a);
Aluno *buscaListaAluno(Aluno *a, char *b);
void atualizaPresencaAluno(Aluno *a, char p);
void imprimeAluno(Aluno *a);
void liberaAluno(Aluno *a);