//
//  Gato.h
//  GatoED
//
//  Created by Artur Vítor Cintra Bernardes on 04/06/25.
//

#pragma once

/* Tipo que define um gato (tipo opaco)
 * Cada gato possui:
 * - Nome (string)
 * - Nível de agressividade (MANSO ou BRAVO)
 */
typedef struct gato Gato;

#define MANSO 1
#define BRAVO 2

/* Inicializa um novo gato com nome e nível de agressividade
 * Inputs: nome (string) e agressividade (MANSO ou BRAVO)
 * Output: ponteiro para o gato criado
 * Pré-condição: nome não nulo
 * Pós-condição: gato alocado e inicializado
 */
Gato *inicGato(char *nome, int agressividade);

/* Retorna o nome do gato
 * Inputs: ponteiro para gato
 * Output: string com o nome
 * Pré-condição: gato válido
 * Pós-condição: nenhuma alteração no gato
 */
char *get_nome_gato(Gato *g);

/* Retorna o nível de agressividade do gato
 * Inputs: ponteiro para gato
 * Output: MANSO ou BRAVO
 * Pré-condição: gato válido
 * Pós-condição: nenhuma alteração no gato
 */
int get_agressividade_gato(Gato *g);

/* Atribui um novo nível de agressividade ao gato
 * Inputs: ponteiro para gato e novo nível de agressividade
 * Output: nenhum
 * Pré-condição: gato válido
 * Pós-condição: nível de agressividade alterado
 */
void atribuiNivelAgressividadeGato(Gato *g, int agressividade);

/* Imprime os dados do gato
 * Inputs: ponteiro para gato
 * Output: nenhum
 * Pré-condição: gato válido
 * Pós-condição: dados impressos na tela
 */
void imprimeGato(Gato *g);

/* Libera a memória alocada para o gato
 * Inputs: ponteiro para gato
 * Output: nenhum
 * Pré-condição: gato válido
 * Pós-condição: memória liberada
 */
void liberaGato(Gato *g);
