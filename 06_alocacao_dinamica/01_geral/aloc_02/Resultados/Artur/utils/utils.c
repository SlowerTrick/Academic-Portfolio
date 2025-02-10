#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Função que cria uma matriz de inteiros, alocada dinamicamente. Se a alocação falhar, o programa é encerrado.
 * 
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz. 
 * @return Ponteiro para a matriz alocada.
*/
int **CriaMatriz(int linhas, int colunas)
{
    int **m = malloc(sizeof(int *) * linhas); // Aloca espaço para os ponteiros das linhas
    if (m == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        m[i] = malloc(colunas * sizeof(int)); // Aloca espaço para cada linha
        if (m[i] == NULL) {
            printf("Erro na alocação de memória\n");
            exit(1);
        }
    }

    return m;
}

/**
 * Função que libera a memória alocada para uma matriz de inteiros.
 * 
 * @param matriz Ponteiro para a matriz a ser liberada.
 * @param linhas Número de linhas da matriz.
*/
void LiberaMatriz(int **matriz, int linhas)
{
    if (matriz == NULL || *matriz == NULL) 
        return;

    for(int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
        matriz[i] = NULL;
    }
    free(matriz);
    matriz = NULL;
}

/**
 * Função que lê uma matriz de inteiros da entrada padrão.
 * 
 * @param matriz Ponteiro para a matriz a ser lida.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void LeMatriz(int **matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

/**
 * Imprime a matriz transposta da matriz dada.
 * 
 * @param matriz Ponteiro para a matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 */
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)  // Itera sobre as colunas da matriz original
    {
        for (int i = 0; i < linhas; i++) // Itera sobre as linhas da matriz original
        {
            printf("%d ", matriz[i][j]);  // Acessa [linha][coluna] da original
        }
        printf("\n");
    }
}
