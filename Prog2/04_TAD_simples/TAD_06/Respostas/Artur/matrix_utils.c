#include "matrix_utils.h"
#include <stdio.h>

tMatrix MatrixCreate(int rows, int cols)
{
    tMatrix m;
    m.rows = rows;
    m.cols = cols;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int num;
            scanf("%d", &num);
            m.data[i][j] = num;
        }
    }
    return m;
}

tMatrix MatrixRead(tMatrix matrix)
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    matrix = MatrixCreate(rows, cols);
    return matrix;
}

void MatrixPrint(tMatrix matrix)
{
    for(int i = 0; i < matrix.rows; i++)
    {
        printf("|");
        for(int j = 0; j < matrix.cols; j++)
        {
            printf("%d", matrix.data[i][j]);
            if(i != matrix.cols - 1)
            {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2)
{
    printf("%d %d %d %d\n", matrix1.cols, matrix2.cols, matrix1.rows, matrix2.rows);
    return ((matrix1.cols == matrix2.cols) && (matrix1.rows == matrix2.rows));
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2)
{
    return ((matrix1.cols == matrix2.cols) && (matrix1.rows == matrix2.rows));
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2)
{
    return matrix1.cols == matrix2.rows;
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2)
{
    tMatrix resultMatrix;
    resultMatrix.cols = matrix1.cols;
    resultMatrix.rows = matrix1.rows;

    for(int i = 0; i < matrix1.rows; i++)
    {
        for(int j = 0; j < matrix1.cols; j++)
        {
            resultMatrix.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    MatrixPrint(resultMatrix);
    return resultMatrix;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix);

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar);
