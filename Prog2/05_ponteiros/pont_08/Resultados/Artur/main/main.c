#include <stdio.h>
#include "tDepartamento.h"

int main(void)
{
    printf("\n");
    int totalDepartamentos = 0, departamentosAtuais = 0;
    scanf("%d", &totalDepartamentos);
    tDepartamento departamentos[totalDepartamentos];

    for(int i = 0; i < totalDepartamentos; i++)
    {
        while (1)
        {
            char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
            int m1, m2, m3;
            scanf(" %s %s %s %s %s %d %d %d", nome, diretor, curso1, curso2, curso3, &m1, &m2, &m3);
            if (m1 < 0 || m2 < 0 || m3 < 0)
            {
                printf("Digite um departamento com médias válidas");
                continue;
            }
            departamentos[departamentosAtuais++] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
            break;
        }
    }
    OrdenaDepartamentosPorMedia(departamentos, totalDepartamentos);

    for(int i = 0; i < totalDepartamentos; i++)
    {
        ImprimeAtributosDepartamento(departamentos[i]);
    }
    return 0;
}