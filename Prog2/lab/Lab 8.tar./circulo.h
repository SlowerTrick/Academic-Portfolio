#pragma once
#define PI 3.14
typedef struct circulo *Circulo;

Circulo criaCirculo();
void leCirculo(Circulo c);
double retornaAreaCirculo(Circulo c);
void liberaCirculo(Circulo c);