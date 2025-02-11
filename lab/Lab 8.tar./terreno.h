#pragma once
#include "triangulo.h"
#include "circulo.h"
#include "retangulo.h"

enum TERRENO
{
    CIRCULO=0,
    RETANGULO=1,
    TRIANGULO=2,
};

//Contem um vetor para cada tipo de forma, alem de armazenar o espaço

typedef struct terreno Terreno;

//Renomeando um ponteiro de Terreno
typedef Terreno * Terreno_pt;
/**
* Inicializa o struct terreno, atribuindo os parametros aos membros
internos do Terreno_pt
*/
typedef struct terrenos Terrenos;

typedef Terrenos * Terrenos_pt;

Terreno_pt InicializaTerreno(void * terreno, enum TERRENO tipo);
/**
* Calcula a área do terreno.
*/
double Area(Terreno_pt t);
/**
* Libera todas as posições da memória
*/
void liberaTerreno(Terreno_pt t);