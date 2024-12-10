#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <stdbool.h>

#define MAX_NOME 100

typedef struct Product{
    char nome[MAX_NOME];
    float desconto, preco;
    int estoque, vendas, id;
} tProduct;

/**
 * @brief Lê um novo produto da entrada padrão.
 * @param nome Nome do produto.
 * @param desconto Desconto atual do produto.
 * @param preco Preço integral do produto.
 * @param estoque Quantidade disponível do produto.
 * @param id Identificador de cada produto.
 * @return Produto criado.
 */
tProduct leProduto();

/**
 * @brief Cria um novo produto.
 * @param nome Nome do produto.
 * @param desconto Desconto atual do produto.
 * @param preco Preço integral do produto.
 * @param estoque Quantidade disponível do produto.
 * @param id Identificador de cada produto.
 * @return Produto criado.
 */
tProduct criaProduto(char* nome, float desconto, float preco, int estoque, int id);

/**
 * @brief Retorna o desconto atual de um produto
 * @param produto O produto.
 * @return O desconto.
*/
float obtemDesconto(tProduct produto);

/**
 * @brief Retorna o preço de um produto
 * @param produto O produto.
 * @return O preço.
*/
float obtempreco(tProduct produto);

/**
 * @brief Retorna o preço de um produto com o desconto aplicado.
 * @param produto O produto.
 * @return O preço com desconto.
*/
float obtemPrecoComDesconto(tProduct produto);

/**
 * @brief Retorna o estoque atual de um produto
 * @param produto O produto.
 * @return O estoque.
*/
int obtemEstoque(tProduct produto);

/**
 * @brief Retorna as vendas atual de um produto
 * @param produto O produto.
 * @return As vendas.
*/
int obtemVendas(tProduct produto);

/**
 * @brief Retorna o id de um produto
 * @param produto O produto.
 * @return O id.
*/
int obtemId(tProduct produto);

/**
 * @brief Aumenta o estoque de um produto, caso qtd seja válido (>0).
 * @param produto O produto.
 * @param qtd A quantidade a ser adicionada ao estoque do produto.
 * @return Produto com o estoque atualizado.
*/
tProduct aumentaEstoqueProduto(tProduct produto, int qtd);

/**
 * @brief Realiza a venda de um produto, caso o estoque seja válido (>0) (>=qtd).
 * @param produto O produto.
 * @param qtd A quantidade a ser retirada do estoque.
 * @return Produto com o estoque atualizado.
*/
tProduct vendeProduto(tProduct produto, int qtd);

/**
 * @brief Atualiza o desconto de um produto, caso válido (>=0 && <=1).
 * @param produto O produto.
 * @param desconto O novo desconto.
 * @return Produto com o desconto atualizado.
*/
tProduct atualizaDesconto(tProduct produto, float desconto);

/**
 * @brief Checa se um id dado é o igual ao id de um produto
 * @param produto O produto.
 * @param id O id.
 * @return retorna true se o id for o mesmo do produto
*/
bool ehMesmoId(tProduct produto, int id);

/**
 * @brief Imprime as informações do produto na forma:
 * Produto: <nome>, Preco atual: <preco>, Qtd no estoque: <estoque>, Qtd vendida: <vendas>
 * @brief Deve possuir quebra de linha ao final
 * @param produto O produto a ser impresso.
*/
void imprimeProduto(tProduct produto);

#endif