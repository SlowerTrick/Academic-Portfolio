#pragma once
typedef struct triangulo *Triangulo;

Triangulo criaTriangulo();
void leTriangulo(Triangulo t);
double retornaAreaTriangulo(Triangulo t);
void liberaTriangulo(Triangulo t);