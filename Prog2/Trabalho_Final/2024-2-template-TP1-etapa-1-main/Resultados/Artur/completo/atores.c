#include "atores.h"
#include "usuario.h"
#include "tecnico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Atores
{
    void **elementos;
    int qtd_total;
    int qtd_atual;
    func_ptr_notifica notifica;
    func_ptr_desaloca desaloca;
};

Atores *criaAtores(func_ptr_notifica notifica, func_ptr_desaloca desaloca)
{
    Atores *a = malloc(sizeof(*a));
    if(!a)
    {
        printf("ERRO! Falta de memoria");
        exit(1);
    }
    a->qtd_total = 10;
    a->qtd_atual = 0;
    a->elementos = malloc(sizeof(void *) * a->qtd_total);
    a->notifica = notifica;
    a->desaloca = desaloca;
    return a;
}

void desalocaAtores(Atores *a)
{
    if(a)
    {
        if(a->elementos)
            for(int i = 0; i < a->qtd_atual; i++)
                a->desaloca(a->elementos[i]);
        free(a->elementos);
        free(a);
    }
    a = NULL;
}

void insereAtor(Atores *a, void *dado)
{
    if(a->qtd_atual == a->qtd_total)
    {
        a->qtd_total += 10;
        a->elementos = realloc(a->elementos, sizeof(void *) * a->qtd_total);
        if(!a->elementos)
        {
            printf("ERRO! falta de memoria");
            exit(1);
        }
    }
    a->elementos[a->qtd_atual] = dado;
    a->qtd_atual++; 
}

int getQtdAtores(Atores *a)
{
    return a->qtd_atual;
}

void *getElementoCaracteristica(Atores *a, char *caracteristica, func_ptr_compara_caracteristica compara)
{
    for(int i = 0; i < a->qtd_atual; i++)
    {
        if(compara(a->elementos[i], caracteristica))
            return a->elementos[i];
    }
    return NULL;
}

void *getAtorNaFila(Atores *a, int i)
{
    return a->elementos[i];
}

int getMediaCaracteristicaAtores(Atores *a, func_ptr_calcula_caracteristica calcula_caracteristica)
{
    int total = 0;
    for(int i = 0; i < a->qtd_atual; i++)
        total += calcula_caracteristica(a->elementos[i]);
    return total / a->qtd_atual;
}

void notificaAtores(Atores *a)
{
    for(int i = 0; i < a->qtd_atual; i++)
        a->notifica(a->elementos[i]);
}

void notificaRankingAtores(Atores *a, func_ptr_compara_ranking compara)
{
    int array_index[a->qtd_atual];
    for(int i = 0; i < a->qtd_atual; i++)
        array_index[i] = i;

    for (int i = 0; i < a->qtd_atual - 1; i++) 
    {
        for (int j = i + 1; j < a->qtd_atual; j++) 
        {
            if (compara(a->elementos[array_index[i]], a->elementos[array_index[j]])) 
            {
                int temp = array_index[i];
                array_index[i] = array_index[j];
                array_index[j] = temp;
            }
        }
    }

    for(int i = 0; i < a->qtd_atual; i++)
        a->notifica(a->elementos[array_index[i]]);
}