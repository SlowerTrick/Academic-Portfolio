#include "estabelecimento.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento
{
    Vector *produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{
    tEstabelecimento *e = malloc(sizeof(*e));
    if(!e)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    e->produtos = VectorConstruct();
    return e;
}

void DestroiProdutoEstabelecimento(void *produto)
{
    tProduto *p = (tProduto *) produto; 
    DestroiProduto(p);
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{
    if(estabelecimento)
    {
        VectorDestroy(estabelecimento->produtos, DestroiProdutoEstabelecimento);
        estabelecimento->produtos = NULL;
        free(estabelecimento);
    }
    estabelecimento = NULL;
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto)
{
    VectorPushBack(estabelecimento->produtos, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento)
{
    char caminho[100];
    scanf("%s", caminho);

    FILE *arquivo = fopen(caminho, "rb");
    int total_produtos;
    fread(&total_produtos, sizeof(int), 1, arquivo);

    for(int i = 0; i < total_produtos; i++)
    {
        tProduto *produto = LeProduto(arquivo);
        AdicionaProdutoEstabelecimento(estabelecimento, produto);
    }
    fclose(arquivo);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento)
{
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");

    int tamanho_vetor = VectorSize(estabelecimento->produtos), total_produtos = 0;
    for(int i = 0; i < tamanho_vetor; i++)
    {
        tProduto *produto = VectorGet(estabelecimento->produtos, i);
        if(!TemEstoqueProduto(produto))
        {
            ImprimeProduto(produto);
            total_produtos++;
        }
    }
    if(!total_produtos)
        printf("Nao ha produtos em falta!\n");
}
