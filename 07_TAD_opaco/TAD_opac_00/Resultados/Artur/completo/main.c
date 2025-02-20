#include "circulo.h"
#include <stdio.h>

int main(void)
{
    float x, y, raio, xP, yP;
    scanf("%f %f %f %f %f", &x, &y, &raio, &xP, &yP);
    tCirculo circulo = Circulo_Cria(x, y, raio);
    tPonto ponto = Pto_Cria(xP, yP);
    printf("%d", Circulo_Interior(circulo, ponto));
    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);
    return 0;
}