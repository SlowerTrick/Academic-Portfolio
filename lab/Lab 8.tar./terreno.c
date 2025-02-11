#include "terreno.h"
#include <stdio.h>
#include <stdlib.h>

struct terreno
{
    void *terreno;
    int tipo;
};


/**
* Inicializa o struct terreno, atribuindo os parametros aos membros
internos do Terreno_pt
*/
Terreno_pt InicializaTerreno(void * terreno, enum TERRENO tipo)
{
    Terreno_pt t = malloc(sizeof(struct terreno));

    t->tipo = tipo;
    t->terreno = terreno;
    
    return t;
}

/**
* Calcula a área do terreno.
*/
double Area(Terreno_pt t)
{
    if(t->tipo == CIRCULO)
        return retornaAreaCirculo(t->terreno);
    else if(t->tipo == RETANGULO)
        return retornaAreaRetangulo(t->terreno);
    else if(t->tipo == TRIANGULO)
        return retornaAreaTriangulo(t->terreno);
    return -1;
}

/**
* Libera todas as posições da memória
*/
void liberaTerreno(Terreno_pt t)
{
    if(t)
    {
        if(t->tipo == CIRCULO)
            liberaCirculo(t->terreno);
        else if(t->tipo == RETANGULO)
            liberaRetangulo(t->terreno);
        else if(t->tipo == TRIANGULO)
            liberaTriangulo(t->terreno);
        free(t);
    }
    t = NULL;
}