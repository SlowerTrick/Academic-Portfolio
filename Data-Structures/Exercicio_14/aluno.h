#pragma once

typedef struct aluno Aluno;

Aluno *cria_aluno(char *nome, int mat);
int retorna_matricula(Aluno *a);
char *retorna_nome(Aluno *a);
void imprime_aluno(Aluno *a);
void libera_aluno(Aluno *a);