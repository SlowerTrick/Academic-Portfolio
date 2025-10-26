#include "matrizgenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matrizgenerica
{
    void *elemento;
    int linhas;
    int colunas;
    int num_byte_elemento;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Número de linhas da matriz
 * @param colunas - Número de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem)
{
    tMatrizGenerica *matriz = malloc(sizeof(*matriz));
    if (!matriz)
    {
        printf("ERRO! falta de memória");
        exit(1);
    }

    matriz->elemento = malloc(linhas * colunas * numByteElem); // Aloca memória contínua para todos os elementos
    if (!matriz->elemento)
    {
        printf("ERRO! falta de memória");
        exit(1);
    }

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->num_byte_elemento = numByteElem;

    return matriz;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica *mat)
{
    if (mat)
    {
        if (mat->elemento)
            free(mat->elemento); // Libera a memória alocada para os elementos
        free(mat); // Libera a memória da estrutura da matriz
    }
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat->linhas;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat->colunas;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna)
{
    // Acessa o elemento considerando o deslocamento adequado na memória contínua
    return (char *)mat->elemento + (linha * mat->colunas + coluna) * mat->num_byte_elemento;
}


/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna, void *elem) 
{
    if (!mat || !elem || linha >= mat->linhas || coluna >= mat->colunas) {
        printf("Erro: Posição inválida ou matriz nula!\n");
        return;
    }
    void *destino = (char *)mat->elemento + (linha * mat->colunas + coluna) * mat->num_byte_elemento;
    memcpy(destino, elem, mat->num_byte_elemento);
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */


 void ImprimirMatrizGenerica(tMatrizGenerica *mat, void (*imprime_elemento)(void *)) 
 {
    if (!mat || !imprime_elemento) {
        printf("Erro: Matriz ou função de impressão inválida!\n");
        return;
    }
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            void *elemento = (char *)mat->elemento + (i * mat->colunas + j) * mat->num_byte_elemento;
            imprime_elemento(elemento);
            printf(" ");
        }
        printf("\n");
    }
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */

 tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat) 
 {
    if (!mat) {
        printf("Erro: Matriz nula!\n");
        return NULL;
    }
    tMatrizGenerica *transposta = CriaMatrizGenerica(mat->colunas, mat->linhas, mat->num_byte_elemento);
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            void *origem = (char *)mat->elemento + (i * mat->colunas + j) * mat->num_byte_elemento;
            void *destino = (char *)transposta->elemento + (j * transposta->colunas + i) * mat->num_byte_elemento;
            memcpy(destino, origem, mat->num_byte_elemento);
        }
    }
    return transposta;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante 
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void *(*multi_elem)(void *, void *), void *(*soma_elem)(void *, void *)) 
{
    if (!mat1 || !mat2 || mat1->colunas != mat2->linhas || !multi_elem || !soma_elem) {
        printf("Erro: Matrizes incompatíveis ou funções inválidas!\n");
        return NULL;
    }
    tMatrizGenerica *resultado = CriaMatrizGenerica(mat1->linhas, mat2->colunas, numByteTarget);
    void *tempSoma = malloc(numByteTarget);
    for (int i = 0; i < mat1->linhas; i++) {
        for (int j = 0; j < mat2->colunas; j++) {
            memset(tempSoma, 0, numByteTarget);
            for (int k = 0; k < mat1->colunas; k++) {
                void *a = (char *)mat1->elemento + (i * mat1->colunas + k) * mat1->num_byte_elemento;
                void *b = (char *)mat2->elemento + (k * mat2->colunas + j) * mat2->num_byte_elemento;
                void *produto = multi_elem(a, b);
                void *novaSoma = soma_elem(tempSoma, produto);
                memcpy(tempSoma, novaSoma, numByteTarget);
                free(produto);
                free(novaSoma);
            }
            AtribuiElementoMatrizGenerica(resultado, i, j, tempSoma);
        }
    }
    free(tempSoma);
    return resultado;
}


/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat, int novoNumByteElem, void *(*converte_elem)(void *)) 
{
    if (!mat || !converte_elem) {
        printf("Erro: Matriz ou função de conversão inválida!\n");
        return NULL;
    }
    tMatrizGenerica *convertida = CriaMatrizGenerica(mat->linhas, mat->colunas, novoNumByteElem);
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            void *origem = (char *)mat->elemento + (i * mat->colunas + j) * mat->num_byte_elemento;
            void *convertido = converte_elem(origem);
            AtribuiElementoMatrizGenerica(convertida, i, j, convertido);
            free(convertido);
        }
    }
    return convertida;
}