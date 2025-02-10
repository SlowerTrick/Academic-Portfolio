#include "store.h"
#include <stdio.h>

tStore abreLoja()
{
    tStore store;
    store.faturamento = 0;
    store.nmProdutos = 0;
    store.nmVendas = 0;
    return store;
}

tStore adicionaProduto(tStore loja, tProduct produto)
{
    loja.produtos[loja.nmProdutos++] = produto;
    return loja;
}

int buscaProduto(tStore loja, int id)
{
    for (int i = 0; i < loja.nmProdutos; i++)
    {
        if (ehMesmoId(loja.produtos[i], id))
        {
            return i;
        }
    }
    return -1;
}

tStore aumentaEstoqueLoja(tStore loja, int id, int qtd)
{
    int index = buscaProduto(loja, id);
    if (index != -1)
        loja.produtos[index] = aumentaEstoqueProduto(loja.produtos[index], qtd);
    else
        printf("Produto inexistente ESTOQUE\n");
    return loja;
}

tStore vendeProdutoLoja(tStore loja, int id, int qtd)
{
    int index = buscaProduto(loja, id);
    if(index != -1)
    {
        int estoqueAntigo = obtemEstoque(loja.produtos[index]);
        loja.produtos[index] = vendeProduto(loja.produtos[index], qtd);
        if (estoqueAntigo != obtemEstoque(loja.produtos[index]))
        {
            loja.nmVendas += qtd;
            loja.faturamento += obtemPrecoComDesconto(loja.produtos[index]) * qtd;
        }
    }
    else
        printf("Produto inexistente VENDA\n");
    return loja;
}

tStore atualizaDescontoLoja(tStore loja, int id, float desconto)
{
    int index = buscaProduto(loja, id);
    if(index != -1)
        loja.produtos[index] = atualizaDesconto(loja.produtos[index], desconto);
    else
        printf("Produto inexistente DESCONTO\n");
    return loja;
}

void imprimeProdutosLoja(tStore loja)
{
    for(int i = 0; i < loja.nmProdutos; i++)
    {
        imprimeProduto(loja.produtos[i]);
    }
    printf("\n");
}

void imprimeRelatorio(tStore loja)
{
    printf("RELATORIO DE VENDAS ATUALIZADO:\n");
    printf("TOTAL DE VENDAS: %d\n", loja.nmVendas);
    printf("FATURAMENTO: %.2f\n", loja.faturamento);
    printf("PRODUTOS EM ESTOQUE: %d\n", obtemEstoqueLoja(loja));
    imprimeMaisVendido(loja);
    printf("\n");
}

int obtemEstoqueLoja(tStore loja)
{
    int totalEstoque = 0;
    for (int i = 0; i < loja.nmProdutos; i++)
    {
        totalEstoque += obtemEstoque(loja.produtos[i]);
    }
    return totalEstoque;
}

void imprimeMaisVendido(tStore loja)
{
    tProduct p = loja.produtos[0];
    for(int i = 0; i < loja.nmProdutos; i++)
    {
        if (obtemVendas(loja.produtos[i]) > obtemVendas(p))
            p = loja.produtos[i];
    }
    printf("PRODUTO MAIS VENDIDO:\n");
    imprimeProduto(p);
}
