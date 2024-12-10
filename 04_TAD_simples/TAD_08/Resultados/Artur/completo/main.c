#include "departamento.h"
#include <stdio.h>

int main(void)
{
    int total;
    scanf("%d", &total);
    tDepartamento departamento[total];

    for(int i = 0; i < total; i++)
    {
        char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
        int m1, m2, m3;
        scanf(" %s %s %s %s %s %d %d %d", nome, diretor, c1, c2, c3, &m1, &m2, &m3);
        departamento[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }
    
    ordenaPorMediaDepartamentos(departamento, total);

    for(int i = 0; i < total; i++)
    {
        imprimeAtributosDepartamento(departamento[i]);
        printf("\n");
    }
}