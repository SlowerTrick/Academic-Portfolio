//
//  produto.h
//  TADProduto
//
//  Created by Artur Vítor Cintra Bernardes on 21/05/25.
//  Este arquivo define a estrutura e as operações básicas para manipulação de produtos.
//  Um produto é caracterizado por um nome (item), valor e quantidade disponível.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Produto Produto;

#define MAX_TAM_NOME 200  // Tamanho máximo para o nome do produto

/* Cria e inicializa um novo produto.
 * inputs: nome do item (string), valor (int) e quantidade (int).
 * output: ponteiro para o produto inicializado.
 * pre-condicao: nome não nulo, valor e quantidade >= 0.
 * pos-condicao: produto criado e alocado na memória.
 */
Produto *cria_produto(char *item, int valor, int qtd);

/* Lê os dados de um produto a partir da entrada padrão.
 * inputs: nenhum (lê interativamente do usuário).
 * output: ponteiro para o produto lido.
 * pre-condicao: entrada válida fornecida pelo usuário.
 * pos-condicao: produto criado e alocado na memória.
 */
Produto *le_produto();

/* Obtém o nome (item) de um produto.
 * inputs: ponteiro para o produto.
 * output: string contendo o nome do produto.
 * pre-condicao: produto existe e é válido.
 * pos-condicao: produto não é modificado.
 */
char *get_nome_produto(Produto *p);

/* Obtém o valor de um produto.
 * inputs: ponteiro para o produto.
 * output: valor (int) do produto.
 * pre-condicao: produto existe e é válido.
 * pos-condicao: produto não é modificado.
 */
int get_valor_produto(Produto *p);

/* Obtém a quantidade disponível de um produto.
 * inputs: ponteiro para o produto.
 * output: quantidade (int) do produto.
 * pre-condicao: produto existe e é válido.
 * pos-condicao: produto não é modificado.
 */
int get_qtd_produto(Produto *p);

/* Imprime as informações do produto no formato de catálogo (estilo filial).
 * inputs: ponteiro para o produto.
 * output: nenhum (exibe informações na saída padrão).
 * pre-condicao: produto existe e é válido.
 * pos-condicao: produto não é modificado.
 */
void imprime_catalogo_filial_produto(Produto *p);

/* Imprime as informações básicas do produto.
 * inputs: ponteiro para o produto.
 * output: nenhum (exibe informações na saída padrão).
 * pre-condicao: produto existe e é válido.
 * pos-condicao: produto não é modificado.
 */
void imprime_produto(Produto *p);

/* Libera a memória alocada para um produto.
 * inputs: ponteiro para o produto.
 * output: nenhum.
 * pre-condicao: produto existe (pode ser NULL).
 * pos-condicao: memória do produto liberada (se não for NULL).
 */
void libera_produto(Produto *p);