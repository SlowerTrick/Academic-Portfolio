#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila
{
    Vector *vector;
};


/**
 * @brief Cria uma fila vazia
 * 
 * @return A estrutura Fila inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Fila *FilaConstruct()
{
    Fila *f = malloc(sizeof(*f));
    f->vector = VectorConstruct();
    return f;
}

/**
 * @brief Desaloca a memória alocada para a fila
 * 
 * @param f Ponteiro para a fila
 * @param destroy Função que desaloca a memória alocada para cada elemento da fila
*/
void FilaDestroy(Fila *f, void (*destroy)(DataType))
{
    if(f)
    {
        VectorDestroy(f->vector, destroy);
        f->vector = NULL;
        free(f);
    }
    f = NULL;
}

/**
 * @brief Retorna o tamanho da fila
 * 
 * @param f Ponteiro para a fila
 * @return int Tamanho da fila
*/
int FilaSize(Fila *f)
{
    return VectorSize(f->vector);
}

/**
 * @brief Remove o primeiro elemento da fila
 * OBS: Note que a fila é uma estrutura FIFO (First In, First Out), ou seja, o primeiro elemento a ser adicionado é o primeiro a ser removido.
 * Portanto, apesar da fila estar implementada com um vector, ele não é adequado para implementar uma fila, pois a remoção de um elemento do início do vetor é uma operação custosa.
 * @param f Ponteiro para a fila
 * @return DataType Elemento removido
*/
DataType FilaPop(Fila *f)
{
    return VectorPopFront(f->vector);
}

/**
 * @brief Adiciona um elemento no final da fila
 * 
 * @param f Ponteiro para a fila
 * @param val Valor a ser adicionado
*/
void FilaPush(Fila *f, DataType val)
{
    VectorPushBack(f->vector, val);
}

