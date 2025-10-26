#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct aluno Aluno;

struct aluno  
{
    char *nome;
    char *dtNasc;
    char *cursoUfes;
    char *periodoIngresso;
    int percConclusao;
    float CRA;
};

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA) {
    Aluno *a = malloc(sizeof(*a));
    a->nome = (char*) malloc(sizeof(char)*100);
    a->dtNasc = (char*) malloc(sizeof(char)*30);
    a->cursoUfes = (char*) malloc(sizeof(char)*100);
    a->periodoIngresso = (char*) malloc(sizeof(char)*10);
    strcpy(a->nome,nome);
    strcpy(a->dtNasc,dtNasc);
    strcpy(a->cursoUfes,cursoUfes);
    strcpy(a->periodoIngresso,periodoIngresso);
    a->percConclusao = percConclusao;
    a->CRA = CRA;
    return a;
}

Aluno** CriaVetorAlunos(int numeroAlunos) {
    Aluno** a = malloc(sizeof(Aluno*)*numeroAlunos);
    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos) {
    for (int i=0; i < numeroAlunos; i++) {
        char bufName[100], buffdtNasc[30], buffCurso[100], buffPeriodo[10];
        int percConclusao;
        float cra;
        scanf("\n%100[^\n]",bufName);
        scanf("\n%30[^\n]",buffdtNasc);
        scanf("\n%100[^\n]",buffCurso);
        scanf("\n%10[^\n]",buffPeriodo);
        scanf("\n%d",&percConclusao);
        scanf("\n%f",&cra);
        vetorAlunos[i] = CriaAluno(bufName,buffdtNasc,buffCurso,buffPeriodo,percConclusao,cra);
    }
    
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos) {
    for (int i=0; i < numeroAlunos; i++) {
        free(alunos[i]->nome);
        free(alunos[i]->dtNasc);
        free(alunos[i]->cursoUfes);
        free(alunos[i]->periodoIngresso);
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numAlunos) {
    FILE *p = fopen(fileName,"wb");
    int numBytes = 0;
    numBytes += sizeof(int)*fwrite(&numAlunos,sizeof(int),1,p);
    int aux;

    for (int i = 0; i< numAlunos;i++) {
        aux = strlen(alunos[i]->nome);
        numBytes += sizeof(int)*fwrite(&aux,sizeof(int),1,p);
        numBytes += sizeof(char)*fwrite(alunos[i]->nome,sizeof(char),strlen(alunos[i]->nome),p);
        aux = strlen(alunos[i]->dtNasc);
        numBytes += sizeof(int)*fwrite(&aux,sizeof(int),1,p);
        numBytes += sizeof(char)*fwrite(alunos[i]->dtNasc,sizeof(char),strlen(alunos[i]->dtNasc),p);
        aux =strlen(alunos[i]->cursoUfes);
        numBytes += sizeof(int)*fwrite(&aux,sizeof(int),1,p);
        numBytes += sizeof(char)*fwrite(alunos[i]->cursoUfes,sizeof(char),strlen(alunos[i]->cursoUfes),p);
        aux = strlen(alunos[i]->periodoIngresso);
        numBytes += sizeof(int)*fwrite(&aux,sizeof(int),1,p);
        numBytes += sizeof(char)*fwrite(alunos[i]->periodoIngresso,sizeof(char),strlen(alunos[i]->periodoIngresso),p);
        numBytes += sizeof(int)*fwrite(&(alunos[i]->percConclusao),sizeof(int),1,p);
        numBytes += sizeof(float)*fwrite(&(alunos[i]->CRA),sizeof(float),1,p);
    }
    printf("Numero de bytes salvos: %d\n",numBytes);
    fclose(p);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
    FILE *p = fopen(fileName,"rb");
    int numAlunos, aux;
    char bufName[100], buffdtNasc[30], buffCurso[100], buffPeriodo[10];
    memset(bufName,0,100);
    memset(buffdtNasc,0,30);
    memset(buffCurso,0,100);
    memset(buffPeriodo,0,10);
    int percConclusao;
    float cra;
    fread(&numAlunos,sizeof(int),1,p);
    for(int i=0; i< numAlunos; i++) {
        fread(&aux,sizeof(int),1,p);
        fread(bufName,sizeof(char),aux,p);
        fread(&aux,sizeof(int),1,p);
        fread(buffdtNasc,sizeof(char),aux,p);
        fread(&aux,sizeof(int),1,p);
        fread(buffCurso,sizeof(char),aux,p);
        fread(&aux,sizeof(int),1,p);
        fread(buffPeriodo,sizeof(char),aux,p);
        fread(&percConclusao,sizeof(int),1,p);
        fread(&cra,sizeof(float),1,p);
        alunos[i] = CriaAluno(bufName,buffdtNasc,buffCurso,buffPeriodo,percConclusao,cra);
    }
    fclose(p);

}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos) {
    for (int i=0;i<numeroAlunos;i++) {
        printf("Aluno %d:\n",i);
        printf("Nome: %s\n",alunos[i]->nome);
        printf("Data Nascimento: %s\n",alunos[i]->dtNasc);
        printf("Curso: %s\n",alunos[i]->cursoUfes);
        printf("Periodo Ingresso: %s\n",alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n",alunos[i]->percConclusao);
        printf("CRA: %.2f\n",alunos[i]->CRA);
    }
}
