#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector
{
    DataType *data;
    int qtd_elementos_atual;
    int qtd_elementos_total;
};


/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = malloc(sizeof(*v));
    if(!v)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    v->qtd_elementos_total = 10;
    v->qtd_elementos_atual = 0;
    v->data = malloc(sizeof(DataType) * v->qtd_elementos_total);
    if(!v->data)
    {
        free(v);
        printf("ERRO! falta de memoria");
        exit(1);
    }
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
    if(v->qtd_elementos_atual == v->qtd_elementos_total)
    {
        v->qtd_elementos_total += 10;
        v->data = realloc(v->data, sizeof(DataType) * v->qtd_elementos_total);
        if(!v->data)
        {
            free(v);
            printf("ERRO! falta de memoria");
            exit(1);
        }
    }
    v->data[v->qtd_elementos_atual++] = val;
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
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->qtd_elementos_atual;
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
        if(v->data)
        {
            for(int i = 0; i < v->qtd_elementos_atual; i++)
                destroy(v->data[i]);
            free(v->data);
            v->data = NULL;
        }
        free(v);
    }
    v = NULL;
}
