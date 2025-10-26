#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector
{
    int tamanho_total;
    int tamanho_atual;
    DataType *elementos;
};


/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = malloc(sizeof(*v));
    v->tamanho_total = 10;
    v->tamanho_atual = 0;
    v->elementos = malloc(sizeof(DataType) * v->tamanho_total);
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
    if(v->tamanho_atual == v->tamanho_total)
    {
        v->tamanho_total += 10;
        v->elementos = realloc(v->elementos, sizeof(DataType) * v->tamanho_total);
    }
    v->elementos[v->tamanho_atual] = val;
    v->tamanho_atual++; 
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v)
{
    if(v->tamanho_atual > 0)
    {
        DataType deleted = v->elementos[0];
        for(int i = 0; i < v->tamanho_atual - 1; i++)
            v->elementos[i] = v->elementos[i+1];
        v->tamanho_atual--;
        return deleted;
    }
    return NULL;
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
    return v->tamanho_atual;
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
        if(v->elementos)
        {
            for(int i = 0; i < v->tamanho_atual; i++)
                destroy(v->elementos[i]);
            free(v->elementos);
        }
        v->elementos = NULL;
        free(v);
    }
    v = NULL;
}
