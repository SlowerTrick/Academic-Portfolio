#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "relatorio.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos)
{
    printf("aaa");
    /* float media = 0;
    int total_alunos = 0, total_masculino = 0, total_feminino = 0, total_outros = 0; 
    int total_aprovados = 0, total_reprovados = 0;

    for(int i = 0; i < VectorSize(alunos); i++)
    {
        data_type d = VectorGet(alunos, i);

        char genero = GetGeneroAluno(d);
        if(d == 'M')
            total_masculino++;
        else if(d == 'F')
            total_feminino++;
        else if(d == 'O')
            total_outros++;

        media += GetNotaAluno(d);
        if(media >= 6)
            total_aprovados++;
        else
            total_reprovados++;

        total_alunos++;
    }
    
    media = media / total_alunos;

    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (float)total_aprovados / total_reprovados * 100);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (float)total_masculino / total_alunos * 100);
    printf("Feminino: 25.00%%\n", (float)total_feminino / total_alunos * 100);
    printf("Outro: 50.00%%\n", (float)total_outros / total_alunos * 100); */
}

