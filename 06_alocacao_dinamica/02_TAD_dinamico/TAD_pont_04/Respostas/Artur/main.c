#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int total;
    scanf("%d%*c", &total);
    tAluno *alunos[total];

    for(int i = 0; i < total; i++)
    {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);  
    }
    for(int i = 0; i < total - 1; i++)
    {
        for(int j = i+1; j < total; j++)
        {
            int matricula = ComparaMatricula(alunos[i], alunos[j]);

            if(matricula == 1)
            {
                tAluno *aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
    for(int i = 0; i < total; i++)
    {
        if(VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
        ApagaAluno(alunos[i]);
    }
    return 0;
}