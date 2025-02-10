#include "product.h"
#include <stdio.h>
#include <string.h>

tProduct leProduto()
{
    char nome[MAX_NOME];
    float desconto, preco;
    int estoque, id;
    printf("Nome do Produto: ");
    scanf(" %100[^\n]", nome);
    printf("ID: ");
    scanf(" %d", &id);
    printf("Preco: ");
    scanf(" %f", &preco);
    printf("Desconto: ");
    scanf(" %f", &desconto);
    printf("Estoque: ");
    scanf(" %d",&estoque);
    getchar();
    tProduct product = criaProduto(nome, desconto, preco, estoque, id);
    product.vendas = 0;
    return product;
}

tProduct criaProduto(char* nome, float desconto, float preco, int estoque, int id)
{
    tProduct product;
    strncpy(product.nome, nome, MAX_NOME);
    product.desconto = desconto;
    product.preco = preco;
    product.estoque = estoque;
    product.id = id;
    return product;
}

float obtemDesconto(tProduct produto)
{
    return produto.desconto;
}

float obtempreco(tProduct produto)
{
    return produto.preco;
}

float obtemPrecoComDesconto(tProduct produto)
{
    return produto.preco - (produto.preco * produto.desconto);
}

int obtemEstoque(tProduct produto)
{
    return produto.estoque;
}

int obtemVendas(tProduct produto)
{
    return produto.vendas;
}

int obtemId(tProduct produto)
{
    return produto.id;
}

tProduct aumentaEstoqueProduto(tProduct produto, int qtd)
{
    if (qtd > 0)
    {
        produto.estoque += qtd;
    }
    else
    {
        printf("Quantidade inválida.\n");
    }
    return produto;
}

tProduct vendeProduto(tProduct produto, int qtd)
{
    if (produto.estoque >= qtd && qtd > 0)
    {
        produto.estoque -= qtd;
        produto.vendas += qtd;
    }
    else
    {
        printf("Quantidade inválida.\n");
    }
    return produto;
}

tProduct atualizaDesconto(tProduct produto, float desconto)
{
    if (desconto >= 0 && desconto <= 1)
    {
        produto.desconto = desconto;
        produto.preco = obtemPrecoComDesconto(produto);
        produto.desconto = 0;
    }
    else
    {
        printf("Quantidade inválida.\n");
    }
    return produto;
}

bool ehMesmoId(tProduct produto, int id)
{
    return produto.id == id;
}

void imprimeProduto(tProduct produto)
{
    printf("Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", produto.nome, obtemPrecoComDesconto(produto), obtemEstoque(produto), obtemVendas(produto));
}
