//
//  matriz_2.c
//  TADMatriz
//
//  Created by Artur Vítor Cintra Bernardes on 14/05/25.
//

#include "matriz.h"
#include <stdlib.h>
#include <string.h>

struct matriz
{
    int rows;
    int cols;
    int *matriz;
};


/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz *m = malloc(sizeof(*m));
    if(!m)
    {
        printf("ERRO! falta de memoria");
        exit(1);   
    }
    m->matriz = malloc(sizeof(int) * nlinhas * ncolunas);
    if(!m->matriz)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    m->cols = ncolunas;
    m->rows = nlinhas;
    return m;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    mat->matriz[linha * mat->cols + coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    return mat->matriz[linha * mat->cols + coluna];
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas (Matriz* mat)
{
    return mat->cols;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas (Matriz* mat)
{
    return mat->rows;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat)
{
    int n_linhas = mat->rows;
    int n_colunas = mat->cols;
    Matriz *t = inicializaMatriz(n_colunas, n_linhas);

    for(int i = 0; i < n_linhas; i++)
        for(int j = 0; j < n_colunas; j++)
            t->matriz[j * t->cols + i] = mat->matriz[i * mat->cols + j];
    
    return t;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
    int n_linhas1 = mat1->rows;
    int n_colunas1 = mat1->cols;
    int n_linhas2 = mat2->rows;
    int n_colunas2 = mat2->cols;
    Matriz *mult = inicializaMatriz(n_linhas1, n_colunas2);

    for(int i = 0; i < n_linhas1; i++)
    {
        for(int j = 0; j < n_colunas2; j++)
        {
            mult->matriz[i * mult->cols + j] = 0;
            for(int k = 0; k < n_colunas1; k++)
            {
                mult->matriz[i * mult->cols + j] += 
                    mat1->matriz[i * mat1->cols + k] * 
                    mat2->matriz[k * mat2->cols + j];
            }
        }
    }
    
    return mult;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat)
{
    for(int i = 0; i < mat->rows; i++)
    {
        for(int j = 0; j < mat->cols; j++)
            printf("%d ", mat->matriz[i * mat->cols + j]);
        printf("\n");
    }
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha (Matriz* mat, int indice)
{
    for(int i = 0; i < mat->cols; i++)
        printf("%d ", mat->matriz[indice * mat->cols + i]);
    printf("\n");
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz (Matriz* mat)
{
    if(mat)
    {
        if(mat->matriz)
            free(mat->matriz);
        mat->matriz = NULL;
        free(mat);
    }
    mat = NULL;
}