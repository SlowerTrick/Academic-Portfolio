#include "matrix_utils.h"
#include <stdio.h>

int main(void)
{
    tMatrix matrix1, matrix2;
    matrix1 = MatrixRead(matrix1);
    matrix2 = MatrixRead(matrix2);
    printf("%d %d %d %d\n", matrix1.cols, matrix2.cols, matrix1.rows, matrix1.rows);

    while(1)
    {
        //printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: ");
        char operacao;
        scanf(" %d", &operacao);

        if(operacao == 1)
        {
            printf("%d %d %d %d\n", matrix1.cols, matrix2.cols, matrix1.rows, matrix1.rows);
            if(PossibleMatrixSum(matrix2, matrix1))
                MatrixAdd(matrix1, matrix2);
            else
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        }
        else if(operacao == 2)
        {
            printf("operacao 2\n");
        }
        else if(operacao == 3)
        {
            printf("operacao 3\n");
        }
        else if(operacao == 4)
        {
            printf("operacao 4\n");
        }
        else if(operacao == 5)
        {
            printf("operacao 5\n");
        }
        else if(operacao == 6)
        {
            break;
        }
    }
}