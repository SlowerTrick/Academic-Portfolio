#include "departamento.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor)
{
    tDepartamento d;
    strncpy(d.c1, c1, STRING_MAX);
    strncpy(d.c2, c2, STRING_MAX);
    strncpy(d.c3, c3, STRING_MAX);
    strncpy(d.nome, nome, STRING_MAX);
    strncpy(d.diretor, diretor, STRING_MAX);
    d.m1 = m1;
    d.m2 = m2;
    d.m3 = m3;
    d.media_geral = calculaMediaGeralDepartamento(d);
    return d;
}

void imprimeAtributosDepartamento (tDepartamento depto)
{
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2lf\n", depto.media_geral);
    printf("desvio padrao => %.2lf\n", calculaDesvioPadraoDepartamento(depto));
}

int validaMediaDepartamento (int media)
{
    return !(media < 0 || media > 10);
}

double calculaDesvioPadraoDepartamento(tDepartamento depto)
{
    double media = calculaMediaGeralDepartamento(depto);
    double somatorio = 0;
    somatorio += pow(depto.m1 - media, 2);
    somatorio += pow(depto.m2 - media, 2);
    somatorio += pow(depto.m3 - media, 2);
    return sqrt(somatorio / 3);
}

double calculaMediaGeralDepartamento(tDepartamento depto)
{
    return (depto.m1 + depto.m2 + depto.m3) / 3.0;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho)
{
    for(int i = 0; i < tamanho - 1; i++)
    {
        for(int j = i + 1; j < tamanho; j++)
        {
            if(d[i].media_geral < d[j].media_geral)
            {
                tDepartamento temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}
