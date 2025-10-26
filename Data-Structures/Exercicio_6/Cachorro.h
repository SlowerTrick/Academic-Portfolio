//
//  Cachorro.h
//  CachorroED
//
//  Created by Artur Vítor Cintra Bernardes on 04/06/25.
//

#pragma once

/* Tipo que define um cachorro (tipo opaco)
 * Cada cachorro possui:
 * - Nome (string)
 * - Nível de agressividade (MANSO ou BRAVO)
 */
typedef struct cachorro Cachorro;

#define MANSO 1
#define BRAVO 2

/* Inicializa um novo cachorro com nome e nível de agressividade
 * Inputs: nome (string) e agressividade (MANSO ou BRAVO)
 * Output: ponteiro para o cachorro criado
 * Pré-condição: nome não nulo
 * Pós-condição: cachorro alocado e inicializado
 */
Cachorro *inicCachorro(char *nome, int agressividade);

/* Retorna o nome do cachorro
 * Inputs: ponteiro para cachorro
 * Output: string com o nome
 * Pré-condição: cachorro válido
 * Pós-condição: nenhuma alteração no cachorro
 */
char *get_nome_cachorro(Cachorro *c);

/* Retorna o nível de agressividade do cachorro
 * Inputs: ponteiro para cachorro
 * Output: MANSO ou BRAVO
 * Pré-condição: cachorro válido
 * Pós-condição: nenhuma alteração no cachorro
 */
int get_agressividade_cachorro(Cachorro *c);

/* Atribui um novo nível de agressividade ao cachorro
 * Inputs: ponteiro para cachorro e novo nível de agressividade
 * Output: nenhum
 * Pré-condição: cachorro válido
 * Pós-condição: nível de agressividade alterado
 */
void atribuiNivelAgressividadeCachorro(Cachorro *c, int agressividade);

/* Imprime os dados do cachorro
 * Inputs: ponteiro para cachorro
 * Output: nenhum
 * Pré-condição: cachorro válido
 * Pós-condição: dados impressos na tela
 */
void imprimeCachorro(Cachorro *c);

/* Libera a memória alocada para o cachorro
 * Inputs: ponteiro para cachorro
 * Output: nenhum
 * Pré-condição: cachorro válido
 * Pós-condição: memória liberada
 */
void liberaCachorro(Cachorro *c);
