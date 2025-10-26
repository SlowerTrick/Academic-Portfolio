#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

void cadastrarProduto(Produto** vetor_produtos, int* tamanho, int* alocado) 
{
    if(*tamanho == *alocado) 
    {
        *alocado *= 2;
        vetor_produtos = realloc(vetor_produtos, *alocado * sizeof(Produto*));
    }

    Produto* produto = malloc(sizeof(Produto));

    scanf("%s %f %d%*c", produto->nome, &produto->preco, &produto->quantidade);

    for(int i = 0; i < *tamanho; i++) 
    {
        if(strcmp(produto->nome, vetor_produtos[i]->nome) == 0) 
        {
            vetor_produtos[i]->preco = produto->preco;
            vetor_produtos[i]->quantidade += produto->quantidade;
            free(produto);
            return;
        }
    }

    vetor_produtos[*tamanho] = produto;
    (*tamanho)++;
}

void exibirLista(Produto** vetor_produtos, int tamanho) 
{
    printf("\nLista de produtos cadastrados:\n");
    for(int i = 0; i < tamanho; i++) 
    {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", vetor_produtos[i]->nome);
        printf("Preco: %.2f\n", vetor_produtos[i]->preco);
        printf("Quantidade em estoque: %d\n\n", vetor_produtos[i]->quantidade);
    }
}

int compararProduto(const void* a, const void* b) 
{
    Produto* produto_a = *(Produto**)a;
    Produto* produto_b = *(Produto**)b;
    
    float valor_total_a = produto_a->preco * produto_a->quantidade;
    float valor_total_b = produto_b->preco * produto_b->quantidade;

    if (valor_total_a > valor_total_b)
        return -1;
    else if (valor_total_a < valor_total_b)
        return 1;
    else
        return strcmp(produto_a->nome, produto_b->nome);
}

void ordenarLista(Produto** vetor_produtos, int tamanho) 
{
    qsort(vetor_produtos, tamanho, sizeof(Produto*), compararProduto);
}

void desalocaLista(Produto** vetor_produtos, int tamanho) 
{
    for (int i = 0; i < tamanho; i++) 
    {
        free(vetor_produtos[i]);
    }
    free(vetor_produtos);
}

void salvarLista(Produto** vetor_produtos, int tamanho) 
{
    FILE* arquivo = fopen("produtos.bin", "wb");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (tamanho == 0) 
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    fwrite(&tamanho, sizeof(int), 1, arquivo);
    
    for (int i = 0; i < tamanho; i++) 
    {
        fwrite(vetor_produtos[i], sizeof(*vetor_produtos[i]), 1, arquivo);
    }
    
    fclose(arquivo);
}

Produto** lerLista(int* tamanho, int* alocado) 
{
    FILE* arquivo = fopen("produtos.bin", "rb");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo 'produtos.bin'.\n");
        return NULL;
    }
    
    fread(tamanho, sizeof(int), 1, arquivo);
    *alocado = *tamanho * 2;
    Produto** novo_vetor_produtos = (Produto**) malloc(*alocado * sizeof(Produto*));
    
    for (int i = 0; i < *tamanho; i++) 
    {
        Produto* produto = (Produto*) malloc(sizeof(Produto));
        fread(produto, sizeof(*produto), 1, arquivo);
        novo_vetor_produtos[i] = produto;
    }
    
    fclose(arquivo);

    return novo_vetor_produtos;
}