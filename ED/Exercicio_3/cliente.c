#include "matriz.h"
#include "rendimento.h"

int main(void)
{
    int n_linhas = 5, n_colunas = 3;
    Rendimento *rendimento = cria_rendimento(n_linhas, n_colunas);

    registrar_materia(rendimento, "Portugues");
    registrar_materia(rendimento, "Matematica");
    registrar_materia(rendimento, "Ingles");

    registrar_turma(rendimento, "6A");
    registrar_turma(rendimento, "6B");
    registrar_turma(rendimento, "5A");
    registrar_turma(rendimento, "3A");
    registrar_turma(rendimento, "3B");

    const int matrix[15] = {6, 5, 10, 5, 4, 10, 9, 3, 10, 4, 5, 10, 6, 6, 10};

    preenche_matriz(rendimento, matrix);
    imprime_rendimento(rendimento);
    destroi_rendimento(rendimento);

    /* int n_linhas1 = 2;
    int n_colunas1 = 3;
    int n_linhas2 = 3;
    int n_colunas2 = 2;
    Matriz *matriz1 = inicializaMatriz(n_linhas1, n_colunas1);
    Matriz *matriz2 = inicializaMatriz(n_linhas2, n_colunas2);

    int count = 0;
    for(int i = 0; i < n_linhas1; i++)
        for(int j = 0; j < n_colunas1; j++)
            modificaElemento(matriz1, i, j, count++);

    for(int i = 0; i < n_linhas2; i++)
        for(int j = 0; j < n_colunas2; j++)
            modificaElemento(matriz2, i, j, n_colunas2 - j + i);

    printf("Matriz1 original:\n");
    imprimeMatriz(matriz1);
    printf("\n");

    printf("Matriz2 original:\n");
    imprimeMatriz(matriz2);
    printf("\n");
    
    Matriz *t1 = transposta(matriz1);
    printf("Matriz1 transposta:\n");
    imprimeMatriz(t1);
    printf("\n");

    Matriz *t2 = transposta(matriz2);
    printf("Matriz2 transposta:\n");
    imprimeMatriz(t2);
    printf("\n");

    Matriz *mult = multiplicacao(matriz1, matriz2);
    printf("Matriz multiplicacao:\n");
    imprimeMatriz(mult);
    printf("\n");

    destroiMatriz(matriz1);
    destroiMatriz(matriz2);
    destroiMatriz(t1);
    destroiMatriz(t2);
    destroiMatriz(mult); */
}