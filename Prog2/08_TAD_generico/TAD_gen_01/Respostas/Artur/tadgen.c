#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct generic
{
    void *vetor;
    int num_elementos;
    int tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem)
{
    tGeneric *g = malloc(sizeof(*g));
    if (!g) 
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    if(type == INT)
    {
        g->vetor = malloc(sizeof(int) * numElem);
        if(!g->vetor)
        {
            free(g);
            printf("ERRO! falta de memoria");
            exit(1);
        }
        for(int i = 0; i < numElem; i++)
            ((int *)g->vetor)[i] = -1;
    }
    else if(type == FLOAT)
    {
        g->vetor = malloc(sizeof(float) * numElem);
        if(!g->vetor)
        {
            free(g);
            printf("ERRO! falta de memoria");
            exit(1);
        }
        for(int i = 0; i < numElem; i++)
            ((float *)g->vetor)[i] = -1;
    }
    g->num_elementos = numElem;
    g->tipo = type;
    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen)
{
    if(gen)
    {
        free(gen->vetor);
        gen->vetor = NULL;
        free(gen);
    }
    gen = NULL;
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen)
{
    printf("\nDigite o vetor:");
    for(int i = 0; i < gen->num_elementos; i++)
    {
        if(gen->tipo == INT)
            scanf("%d", &((int*)gen->vetor)[i]);
        else if(gen->tipo == FLOAT)
            scanf("%f", &((float*)gen->vetor)[i]);
    }
    printf("\n");
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen)
{
    if(gen->tipo == INT)
    {
        int *vector = (int *) gen->vetor;
        for(int i = 0; i < gen->num_elementos; i++)
        {
            printf("%d", vector[i]);
            if(i < gen->num_elementos - 1)
                printf(" ");
        }
    }
    else if(gen->tipo == FLOAT)
    {
        float *vector = (float *) gen->vetor;
        for(int i = 0; i < gen->num_elementos; i++)
        {
            printf("%.2f", vector[i]);
            if(i < gen->num_elementos - 1)
                printf(" ");
        } 
    }
    printf("\n");
}

