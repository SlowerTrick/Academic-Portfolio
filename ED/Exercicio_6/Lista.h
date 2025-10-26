//
//  Lista.h
//  ListaED
//
//  Created by Artur Vítor Cintra Bernardes on 04/06/25.
//

/* Tipo que define uma lista duplamente encadeada com nós genéricos (tipo opaco)
 * Cada lista contém:
 * - Ponteiro para o primeiro e último nó
 * - Contadores de total de elementos, total de cachorros e total de gatos
 */
typedef struct lista Lista;

#define CACHORRO 1
#define GATO 2

/* Cria uma nova lista vazia
 * Output: ponteiro para lista criada
 * Pré-condição: nenhuma
 * Pós-condição: lista criada e vazia
 */
Lista *cria_lista();

/* Retorna o número total de elementos da lista
 * Inputs: lista
 * Output: número total de elementos
 * Pré-condição: lista válida
 * Pós-condição: nenhuma alteração na lista
 */
int get_total_elementos_lista(Lista *l);

/* Retorna o número total de cachorros da lista
 * Inputs: lista
 * Output: número de cachorros
 * Pré-condição: lista válida
 * Pós-condição: nenhuma alteração na lista
 */
int get_total_cachorros_lista(Lista *l);

/* Retorna o número total de gatos da lista
 * Inputs: lista
 * Output: número de gatos
 * Pré-condição: lista válida
 * Pós-condição: nenhuma alteração na lista
 */
int get_total_gatos_lista(Lista *l);

/* Recupera o ponteiro para o dado de um nó com nome correspondente
 * Inputs: lista e string com o nome do animal
 * Output: ponteiro para o dado encontrado ou NULL
 * Pré-condição: lista válida, nome não nulo
 * Pós-condição: nenhuma alteração na lista
 */
void *recupera_elemento_lista(Lista *l, char *dado);

/* Adiciona um novo elemento (cachorro ou gato) à lista
 * Inputs: lista, ponteiro para o elemento, tipo do animal (CACHORRO ou GATO)
 * Output: nenhum
 * Pré-condição: lista e elemento válidos
 * Pós-condição: elemento adicionado à lista
 */
void adiciona_elemento_lista(Lista *l, void *elemento, int tipo);

/* Remove um elemento da lista a partir de seu nome
 * Inputs: lista e string com nome do elemento
 * Output: nenhum
 * Pré-condição: lista válida e nome não nulo
 * Pós-condição: elemento removido da lista (se encontrado)
 */
void remove_elemento_lista(Lista *l, char *dado);

/* Imprime todos os elementos da lista
 * Inputs: lista
 * Output: nenhum
 * Pré-condição: lista válida
 * Pós-condição: dados impressos na tela
 */
void imprime_lista(Lista *l);

/* Libera toda a memória alocada pela lista (exceto pelos dados dos elementos)
 * Inputs: lista
 * Output: nenhum
 * Pré-condição: lista válida
 * Pós-condição: memória liberada
 */
void libera_lista(Lista *l);