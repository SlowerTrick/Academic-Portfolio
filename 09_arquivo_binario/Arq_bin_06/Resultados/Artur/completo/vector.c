#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    v->qtd_atual = 0;
    v->qtd_total = 10;
    v->elementos = malloc(sizeof(DataType) * v->qtd_total);
    if(!v->elementos)
    {
        printf("ERRO! falta de memeoria");
        exit(1);
    }
    return v;
}

/**
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if(v->qtd_total == v->qtd_atual)
    {
        v->qtd_total += 10;
        v->elementos = realloc(v->elementos, sizeof(DataType) * v->qtd_total);
        if(!v->elementos)
        {
            printf("ERRO! falta de memeoria");
            exit(1);
        }
    }
    v->elementos[v->qtd_atual++] = val; 
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
