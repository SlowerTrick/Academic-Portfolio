#include "aluno.h"
#include <stdio.h>

int main() {
    int numAlunos = 0;
    Aluno **vetorAlunos;
    printf("Digite o numero de alunos: ");
    scanf("\n%d",&numAlunos);
    vetorAlunos = CriaVetorAlunos(numAlunos);
    LeAlunos(vetorAlunos,numAlunos);
    // ImprimeAlunos(vetorAlunos,numAlunos);
    SalvaAlunosBinario(vetorAlunos,"alunos.bin",numAlunos);
    LiberaAlunos(vetorAlunos,numAlunos);

    vetorAlunos = CriaVetorAlunos(numAlunos);
    CarregaAlunosBinario(vetorAlunos,"alunos.bin");
    ImprimeAlunos(vetorAlunos,numAlunos);
    LiberaAlunos(vetorAlunos,numAlunos);



}
