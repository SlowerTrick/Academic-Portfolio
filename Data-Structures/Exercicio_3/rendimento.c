/*
    Definir e implementar um TAD que usa o TAD matriz para manter uma matriz de rendimento de uma escola. Deve ser possivel manter o ciclo de vida
    de uma matriz como:

       Portugues | Matemática | Ingles
    6A    6.0    |    5.0     |  10.0
    6B    5.0    |    4.0     |  10.0
    5A    9.0    |    3.0     |  10.0
    3A    4.0    |    5.0     |  10.0
    3B    6.5    |    6.5     |  10.0
*/

#include "rendimento.h"

struct rendimento
{
    Matriz *matriz;
    char **turmas;
    int qtd_turmas;
    char **materias;
    int qtd_materias;
};

Rendimento *cria_rendimento(int n_linhas, int n_colunas)
{
    Rendimento *r = malloc(sizeof(*r));
    if(!r)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    r->matriz = inicializaMatriz(n_linhas, n_colunas);
    r->turmas = malloc(sizeof(char *) * n_linhas);
    if(!r->turmas)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    r->qtd_turmas = 0;
    r->materias = malloc(sizeof(char *) * n_colunas);
    if(!r->materias)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    r->qtd_materias = 0;
    return r;
}

void registrar_turma(Rendimento *r, char *nome)
{
    if(r->qtd_turmas == recuperaNLinhas(r->matriz))
    {
        printf("ERRO! a quantidade de turmas é maior do que a quantidade de linhas da matriz\n");
        return;
    }

    r->turmas[r->qtd_turmas] = malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(r->turmas[r->qtd_turmas++], nome);
}

void registrar_materia(Rendimento *r, char *nome)
{
    if(r->qtd_materias == recuperaNColunas(r->matriz))
    {
        printf("ERRO! a quantidade de materias é maior do que a quantidade de colunas da matriz\n");
        return;
    }

    r->materias[r->qtd_materias] = malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(r->materias[r->qtd_materias++], nome);
}

void preenche_matriz(Rendimento *r, const int *matriz)
{
    int n_linhas = recuperaNLinhas(r->matriz);
    int n_colunas = recuperaNColunas(r->matriz);
    for(int i = 0; i < n_linhas; i++)
        for(int j = 0; j < n_colunas; j++)
            modificaElemento(r->matriz, i, j, matriz[i * n_colunas + j]);
}

void imprime_rendimento(Rendimento *r)
{
    printf("  ");
    for(int i = 0; i < r->qtd_materias; i++)
        printf("%s ", r->materias[i]);
    printf("\n");
    for(int i = 0; i < r->qtd_turmas; i++)
    {
        printf("%s\t", r->turmas[i]);
        imprimeLinha(r->matriz, i);
    }
}

void destroi_rendimento(Rendimento *r)
{
    if(r)
    {
        if(r->materias)
        {
            for(int i = 0; i < r->qtd_materias; i++)
                free(r->materias[i]);
            free(r->materias);
        }
        r->materias = NULL;
        if(r->turmas)
        {
            for(int i = 0; i < r->qtd_turmas; i++)
                free(r->turmas[i]);
            free(r->turmas);
        }
        r->turmas = NULL;
        destroiMatriz(r->matriz);
        free(r);
    }
    r = NULL;
}

