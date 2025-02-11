#include "terrenos.h"
#include <stdio.h>
#include <stdlib.h>

struct terrenos 
{
    Terreno_pt *terrenos;
    int qtde;
};

Terrenos_pt InicializaTerrenos(int qtde)
{
    Terrenos_pt t = malloc(sizeof(struct terrenos));
    t->terrenos = malloc(sizeof(Terreno_pt) * qtde);
    t->qtde = 0;
    return t;
}

/***
* Adiciona no Terreno uma forma f descrita pelo enum TERRENO
*/
void adicionarArea(Terrenos_pt t, Terreno * f)
{
    t->terrenos[t->qtde++] = f; 
}

/**
* Calcula a área dos terrenos.
*/
double AreaTotal(Terrenos_pt t)
{
    double total = 0;
    for(int i = 0; i < t->qtde; i++)
    {
        total += Area(t->terrenos[i]);
    }
    return total;
}

/**
* Calcula a média total de desmatamento
*/
double Media(Terrenos_pt terrenos)
{
    double total = 0;
    for(int i = 0; i < terrenos->qtde; i++)
    {
        total += Area(terrenos->terrenos[i]);
    }
    return total / terrenos->qtde;
}

/**
* Calcula o desvio padrão de desmatamento
*/
double DesvioPadrao(Terrenos_pt terrenos)
{
    double media = Media(terrenos);

    double somatorio = 0;
    for(int i = 0; i < terrenos->qtde; i++)
    {
        somatorio += Area(terrenos->terrenos[i]) - media;
    }
    somatorio *= somatorio;
    return somatorio / terrenos->qtde;
}

/**
* Libera todas as posições da memória
*/

void liberaTerrenos(Terrenos_pt t)
{
    if(t)
    {
        for(int i = 0; i < t->qtde; i++)
        {
            liberaTerreno(t->terrenos[i]);
        }
        free(t->terrenos);
        free(t);
    }
    t = NULL;
}