#include "aluno.h"
#include <stdio.h>
#include <string.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3)
{
    tAluno aluno;
    strncpy(aluno.nome, nome, 50);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;
    return aluno;
}

tAluno LeAluno()
{
    char nome[50];
    int matricula, notas[3];
    scanf("%s %d %d %d %d\n", nome, &matricula, &notas[0], &notas[1], &notas[2]);
    tAluno aluno = CriaAluno(nome, matricula, notas[0], notas[1], notas[2]);
    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2)
{
    if (aluno1.matricula > aluno2.matricula)
        return 1;
    else if (aluno1.matricula < aluno2.matricula)
        return -1;
    return 0;
}

int CalculaMediaAluno(tAluno aluno)
{
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3.0;
}

int VerificaAprovacao(tAluno aluno)
{
    float media = CalculaMediaAluno(aluno);
    if (media >= 7)
        return 1;
    return 0;
}

void ImprimeAluno(tAluno aluno)
{
    printf("%s\n", aluno.nome);
    return;
}
