#include "aluno.h"
#include "base_alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char nome_arquivo[100];
    scanf("%s%*c", nome_arquivo);
    tBaseAlunos *base_alunos = CriarBaseAlunos();
    LerBaseAlunos(base_alunos, nome_arquivo);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base_alunos));
    DestruirBaseAlunos(base_alunos);
    return 0;
}