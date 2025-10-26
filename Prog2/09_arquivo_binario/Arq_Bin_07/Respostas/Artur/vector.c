#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_SIZE_GROWTH 10

struct Vector
{
    DataType *elementos;
    int qtd_total;
    int qtd_atual;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = malloc(sizeof(*v));
    v->qtd_total = VECTOR_SIZE_GROWTH;
    v->qtd_atual = 0;
    v->elementos = malloc(sizeof(DataType) * v->qtd_total);
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if(v->qtd_atual >= v->qtd_total)
    {
        v->qtd_total += VECTOR_SIZE_GROWTH;
        v->elementos = realloc(v->elementos, sizeof(DataType) * v->qtd_total);
    }
    v->elementos[v->qtd_atual++] = val;
}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i)
{
    for(int j = i; j < v->qtd_atual - 1; j++)
        v->elementos[j] = v->elementos[j+1];
    v->qtd_atual--;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
{
    return v->elementos[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->qtd_atual;
}


/**
 * @brief Troca os elementos i e j do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do primeiro elemento
 * @param j Índice do segundo elemento
*/
void VectorSwap(Vector *v, int i, int j)
{
    DataType aux = v->elementos[i];
    v->elementos[i] = v->elementos[j];
    v->elementos[j] = aux;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    if(v)
    {
        for(int i = 0; i < v->qtd_atual; i++)
            destroy(v->elementos[i]);
        free(v->elementos);
        free(v);
    }
    v = NULL;
}
