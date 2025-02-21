#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "relatorio.h"

int main(void)
{
    int total;
    scanf("%d", &total);

    Vector *vector = VectorConstruct();

    for(int i = 0; i < total; i++)
    {
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vector, aluno);
    }

    ImprimeRelatorio(vector);
    VectorDestroy(vector, DestroiAluno);
    return 0;
}