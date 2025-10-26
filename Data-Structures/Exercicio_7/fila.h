//
//  fila.h
//  Fila
//
//  Created by Artur Vitor Cintra Bernardes on 11/06/25.
//

#ifndef fila_h
#define fila_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amostra.h"

/* Tipo que define uma Fila de Amostras (tipo opaco)
 * A fila deve manter a ordem de inserção das amostras,
 * respeitando prioridade para idosos (idade >= 60), que
 * devem ser inseridos no início da fila.
 */
typedef struct fila Fila;

/* Cria uma fila vazia de amostras
 * inputs: nenhum
 * output: fila alocada e vazia
 * pre-condicao: nenhuma
 * pos-condicao: fila alocada, com ponteiros de início e fim nulos
 */
Fila *cria_fila();

/* Insere uma amostra na fila, considerando prioridade
 * inputs: ponteiro para a fila e ponteiro para a amostra
 * output: nenhum
 * pre-condicao: fila e amostra válidas
 * pos-condicao: amostra inserida na fila; se for idoso (idade >= 60), inserida no início; caso contrário, no fim
 */
void insere_fila(Fila *f, Amostra *a);

/* Remove a primeira amostra da fila
 * inputs: ponteiro para a fila
 * output: ponteiro para a amostra removida ou NULL se fila vazia
 * pre-condicao: fila válida
 * pos-condicao: primeiro elemento removido da fila e retornado; memória da célula liberada
 */
Amostra *remove_elemento_fila(Fila *f);

/* Imprime todas as amostras da fila, do início ao fim
 * inputs: ponteiro para a fila
 * output: nenhum
 * pre-condicao: fila válida
 * pos-condicao: estado da fila não é alterado
 */
void imprime_fila(Fila *f);

/* Libera toda a memória alocada para a fila e suas células
 * inputs: ponteiro para a fila
 * output: nenhum
 * pre-condicao: fila válida
 * pos-condicao: memória das células e da estrutura da fila liberadas
 */
void libera_fila(Fila *f);

#endif
