//
//  fila.h
//  TADFila
//
//  Created by Artur Vítor Cintra Bernardes on 21/05/25.
//  Este arquivo define a estrutura e as operações básicas para manipulação de uma fila de produtos.
//  A fila é implementada como uma lista encadeada.
//

#include "produto.h"

typedef struct fila Fila;

/* Cria uma fila vazia.
 * inputs: nenhum.
 * output: ponteiro para a fila inicializada.
 * pre-condicao: nenhuma.
 * pos-condicao: fila vazia criada e alocada na memória.
 */
Fila *cria_fila();

/* Adiciona um produto ao final da fila.
 * inputs: ponteiro para a fila e ponteiro para o produto.
 * output: nenhum.
 * pre-condicao: fila e produto existem e são válidos.
 * pos-condicao: produto é adicionado ao final da fila.
 */
void adiciona_produto_fila(Fila *f, Produto *p);

/* Remove um produto da fila com base no nome.
 * inputs: ponteiro para a fila e nome do produto (string).
 * output: nenhum.
 * pre-condicao: fila existe e nome não é nulo.
 * pos-condicao: se encontrado, produto é removido da fila e sua memória liberada; 
 *               caso contrário, mensagem de erro é exibida.
 */
void remove_produto_fila(Fila *f, char *nome);

/* Imprime todos os produtos da fila em ordem.
 * inputs: ponteiro para a fila.
 * output: nenhum (exibe informações na saída padrão).
 * pre-condicao: fila existe.
 * pos-condicao: fila não é modificada.
 */
void imprime_fila(Fila *f);

/* Libera toda a memória alocada para a fila e seus produtos.
 * inputs: ponteiro para a fila.
 * output: nenhum.
 * pre-condicao: fila existe (pode ser NULL).
 * pos-condicao: memória da fila e de todos os produtos liberada (se não for NULL).
 */
void libera_fila(Fila *f);