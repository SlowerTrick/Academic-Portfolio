#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

struct Vector
{
    data_type *data_type;
    int tamanho_total;
    int elementos_atuais;
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
    v->data_type = malloc(sizeof(data_type) * v->tamanho_total);
    v->elementos_atuais = 0;
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
    if(v->tamanho_total == ++v->elementos_atuais)
    {
        v->tamanho_total += 10;
        v->data_type = realloc(v->data_type, sizeof(data_type) * v->tamanho_total);
    }
    v->data_type[v->elementos_atuais - 1] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)
{
    return v->data_type[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->elementos_atuais;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    if(v)
    {
        for(int i = 0; i < v->elementos_atuais; i++)
            destroy(v->data_type[i]);
        free(v->data_type);
        v->data_type = NULL;
        free(v);
    }
    v = NULL;
}

