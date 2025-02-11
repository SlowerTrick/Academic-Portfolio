#ifndef _STORE_H_
#define _STORE_H_

#include "product.h"

#define MAX_PRODUCTS 50

typedef struct store{
    tProduct produtos[MAX_PRODUCTS];
    int nmProdutos, nmVendas;
    float faturamento;
} tStore;

/**
 * @brief Inicia uma struct do tipo tLoja, inicializando seus parâmetros.
 * @return loja inicializada
*/
tStore abreLoja();

/**
 * @brief Adiciona um novo produto à loja.
 * @param loja A loja.
 * @param produto O produto.
 * @return A loja atualizada.
*/
tStore adicionaProduto(tStore loja, tProduct produto);

/**
 * @brief Varre a loja em busca do produto com o id desejado.
 * Retorna -1 caso não tenha sido encontrado.
 * @param loja A loja.
 * @param id O id do produto procurado.
 * @return O produto.
*/
int buscaProduto(tStore loja, int id);

/**
 * @brief Aumenta o estoque de um produto da loja.
 * @param loja A loja.
 * @param id O id do produto.
 * @param qtd A quantidade a ser adicionada ao estoque do produto.
 * @return A loja com o produto com o estoque atualizado.
*/
tStore aumentaEstoqueLoja(tStore loja, int id, int qtd);

/**
 * @brief Realiza a venda de um produto de uma loja.
 * @param loja A loja.
 * @param id O id do produto.
 * @param qtd A quantidade a ser retirada do estoque.
 * @return A loja com o produto com o estoque atualizado.
*/
tStore vendeProdutoLoja(tStore loja, int id, int qtd);

/**
 * @brief Atualiza o desconto de um produto de uma loja.
 * @param loja A loja.
 * @param id O id do produto.
 * @param desconto O novo desconto.
 * @return A loja com o produto com o desconto atualizado.
*/
tStore atualizaDescontoLoja(tStore loja, int id, float desconto);

/**
 * @brief Imprime todos os produtos atuais de uma loja
 * @brief Deve possuir quebra de linha ao final
 * @param loja A loja.
*/
void imprimeProdutosLoja(tStore loja);

/**
 * @brief Imprime o relatorio de vendas da loja.
 * @param loja A loja.
*/
void imprimeRelatorio(tStore loja);

/**
 * @brief Obtem a quantidade de produtos total da Loja em estoque.
 * @param loja A loja.
 * @return A quantidade de produtos total da Loja em estoque.
*/
int obtemEstoqueLoja(tStore loja);

/**
 * @brief Imprime o produto mais vendido da loja(em caso de empate no numero de vendas deve ser impresso o produto a mais tempo na loja).
 * @param loja A loja.
*/
void imprimeMaisVendido(tStore loja);

#endif