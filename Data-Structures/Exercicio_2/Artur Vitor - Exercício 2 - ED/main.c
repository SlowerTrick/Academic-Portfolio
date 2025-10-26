#include <stdio.h>
#include "mercado.h"

int main(void)
{
    Mercado *mercado = le_mercado();
    

    while (1)
    {
        char opcao;
        scanf(" %c%*c", &opcao);

        if(opcao == 'F') // Adicionar filial ao mercado
        {
            Filial *filial = le_filial();
            adicionar_filial_mercado(mercado, filial);
        }
        else if(opcao == 'E') // Adicionar produto ao estoque
        {
            Produto *produto = le_produto();
            adicionar_produto_mercado(mercado, produto);
        } 
        else if(opcao == 'P') // Adicionar produto a filial
        {
            char nome_filial[MAX_TAM_NOME], nome_produto[MAX_TAM_NOME];
            scanf(" %[^\n] %[^\n]%*c", nome_filial, nome_produto);
            Filial *filial = encontra_filial_mercado(mercado, nome_filial);
            Produto *produto = encontra_produto_mercado(mercado, nome_produto);
            if(filial != NULL && produto != NULL)
            {
                diminui_estoque_mercado(mercado, adicionar_produto_filial(filial, produto));
            }
            else
            {
                if(!filial)
                    printf("Filial %s nao encontrada!\n", nome_filial);
                if(!produto)
                    printf("Produto %s nao encontrado!\n", nome_produto);
            }
        }  
        else if(opcao == 'I') // Imprimir mercado
        {
            imprime_mercado(mercado);
        }
        else if(opcao == 'K') // Encerrar programa
        {
            libera_mercado(mercado);
            break;
        }
    }
    return 0;
}