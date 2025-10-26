#include <stdio.h>
#include "aluno.h"

int main(void)
{
    int total;
    scanf("%d\n", &total);
    tAluno alunos[total];
    for(int i = 0; i < total; i++)
    {
        alunos[i] = LeAluno();
    }
    for(int i = 0; i < total - 1; i++)
    {
        for(int j = i + 1; j < total; j++)
        {
            if (ComparaMatricula(alunos[i], alunos[j]) == 1)
            {
                tAluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
    for(int i = 0; i < total; i++)
    {
        if(VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
    }
    return 0;
}