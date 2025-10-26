#include "lista.h"
#include "catalogo.h"

int main(void)
{
    tLista *lista = cria_lista();
    tCatalogo *catalogo_produtos = cria_catalogo();

    while(1)
    {
        char opcao;
        scanf(" %c%*c", &opcao);

        if(opcao == 'P')
        {
            char nome[100];
            int valor, qtd;
            scanf(" %[^,], %d, %d%*c", nome, &valor, &qtd);
            Produto *produto = cria_produto(nome, valor, qtd);
            adiciona_produto_catalogo(catalogo_produtos, produto);
            lista = adiciona_elemento_lista(lista, produto);
        }
        else if(opcao == 'R')
        {
            char produto_removido[100];
            scanf(" %[^\n]%*c", produto_removido);
            lista = remove_elemento_lista(lista, produto_removido);
        }
        else if(opcao == 'I')
        {
            printf("\nLista:\n\n");
            imprime_lista(lista);
            printf("Fim da lista!\n\n");
        }
        else if(opcao == 'E')
        {
            libera_catalogo(catalogo_produtos);
            libera_lista(lista);
            break;
        }
    }
    return 0;
}