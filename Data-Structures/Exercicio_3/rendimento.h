/*
    Definir e implementar um TAD que usa o TAD matriz para manter uma matriz de rendimento de uma escola. Deve ser possivel manter o ciclo de vida
    de uma matriz como:

       Portugues | Matemática | Ingles
    6A    6.0    |    5.0     |  10.0
    6B    5.0    |    4.0     |  10.0
    5A    9.0    |    3.0     |  10.0
    3A    4.0    |    5.0     |  10.0
    3B    6.5    |    6.5     |  10.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

//Tipo rendimento (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct rendimento Rendimento;

/*Inicializa a estrutura de rendimento com um número de turmas (linhas) e disciplinas (colunas)
 * inputs: número de linhas (turmas) e número de colunas (disciplinas)
 * output: ponteiro para a estrutura Rendimento inicializada
 * pre-condicao: n_linhas e n_colunas maiores que zero
 * pos-condicao: estrutura Rendimento criada com espaço para nomes e notas
 */
Rendimento *cria_rendimento(int n_linhas, int n_colunas);

/*Registra o nome de uma turma (linha) na estrutura de rendimento
 * inputs: ponteiro para estrutura Rendimento e nome da turma
 * output: nenhum
 * pre-condicao: estrutura Rendimento existe e ainda possui espaço para uma nova turma
 * pos-condicao: nome da turma registrado na próxima linha disponível
 */
void registrar_turma(Rendimento *r, char *nome);

/*Registra o nome de uma disciplina (coluna) na estrutura de rendimento
 * inputs: ponteiro para estrutura Rendimento e nome da disciplina
 * output: nenhum
 * pre-condicao: estrutura Rendimento existe e ainda possui espaço para uma nova disciplina
 * pos-condicao: nome da disciplina registrado na próxima coluna disponível
 */
void registrar_materia(Rendimento *r, char *nome);

/*Preenche a matriz de rendimento com os valores informados
 * inputs: ponteiro para estrutura Rendimento e ponteiro para vetor com os valores da matriz
 * output: nenhum
 * pre-condicao: estrutura Rendimento existe e vetor contém elementos suficientes (n_linhas * n_colunas)
 * pos-condicao: matriz preenchida com os valores fornecidos
 */
void preenche_matriz(Rendimento *r, const int *matriz);

/*Imprime a matriz de rendimento formatada com nomes de turmas e disciplinas
 * inputs: ponteiro para estrutura Rendimento
 * output: nenhum
 * pre-condicao: estrutura Rendimento existe e está preenchida
 * pos-condicao: nenhuma (somente exibição)
 */
void imprime_rendimento(Rendimento *r);

/*Libera toda a memória alocada para a estrutura de rendimento
 * inputs: ponteiro para estrutura Rendimento
 * output: nenhum
 * pre-condicao: estrutura Rendimento existe
 * pos-condicao: toda a memória utilizada é liberada
 */
void destroi_rendimento(Rendimento *r);