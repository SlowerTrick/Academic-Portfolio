#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int capacidade_inicial = 10;
    int tamanho_atual = 0;
    Produto** lista_produtos = malloc(capacidade_inicial * sizeof(Produto*));
    
    int opcao;
    do 
    {
        printf("===== Sistema de Registro de Produtos =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Exibir lista de produtos cadastrados\n");
        printf("3 - Salvar lista de produtos em arquivo\n");
        printf("4 - Ler lista de produtos de arquivo\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if(opcao == 1) 
        {
            cadastrarProduto(lista_produtos, &tamanho_atual, &capacidade_inicial);
        } 
        else if(opcao == 2) 
        {
            ordenarLista(lista_produtos, tamanho_atual);
            exibirLista(lista_produtos, tamanho_atual);
        } 
        else if(opcao == 3) 
        {
            salvarLista(lista_produtos, tamanho_atual);
            printf("Lista de produtos salva no arquivo 'produtos.bin'.\n");
        } 
        else if(opcao == 4) 
        {
            desalocaLista(lista_produtos, tamanho_atual);
            lista_produtos = lerLista(&tamanho_atual, &capacidade_inicial);
        } 
        else if(opcao == 5) 
        {
            printf("Encerrando o programa.\n");
        } 
        else 
        {
            printf("Opcao invalida.\n");
        }
        
        printf("\n");
    } 
    while(opcao != 5);
    
    for(int i = 0; i < tamanho_atual; i++) 
    {
        free(lista_produtos[i]);
    }
    free(lista_produtos);
    
    return 0;
}