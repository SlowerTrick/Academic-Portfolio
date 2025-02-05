#include "tDepartamento.h"
#include "stdio.h"
#include "string.h"

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor )
{
    tDepartamento d;
    strcpy(d.curso1, curso1);
    strcpy(d.curso2, curso2);
    strcpy(d.curso3, curso3);
    strcpy(d.nome, nome);
    strcpy(d.diretor, diretor);
    d.m1 = m1;
    d.m2 = m2;
    d.m3 = m3;
    return d;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto)
{
    printf("\n");
    printf("Departamento: %s\n\t", depto.nome);
    printf("Diretor: %s\n\t", depto.diretor);
    printf("1o curso: %s\n\t", depto.curso1);
    printf("Media do 1o curso: %d\n\t", depto.m1);
    printf("2o curso: %s\n\t", depto.curso2);
    printf("Media do 2o curso: %d\n\t", depto.m2);
    printf("3o curso: %s\n\t", depto.curso3);
    printf("Media do 3o curso: %d\n\t", depto.m3);
    float media = (depto.m1 + depto.m2 + depto.m3) / 3;
    printf("Media dos cursos: %.2f", media);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    for(int i = 0; i < num_deptos - 1; i++)
    {
        for(int j = i+1; j < num_deptos; j++)
        {
            float media1 = (vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3) / 3;
            float media2 = (vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3) / 3;

            if (media2 > media1)
            {
                tDepartamento aux = vetor_deptos[i];
                vetor_deptos[i] = vetor_deptos[j];
                vetor_deptos[j] = aux;
            }
        }
    }
}
