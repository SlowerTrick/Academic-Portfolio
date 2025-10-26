#include "fila.h"

int main(void)
{
    Fila *fila = cria_fila();

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
            adiciona_produto_fila(fila, produto);
        }
        else if(opcao == 'R')
        {
            char produto_removido[100];
            scanf(" %s%*c", produto_removido);
            remove_produto_fila(fila, produto_removido);
        }
        else if(opcao == 'I')
        {
            printf("Fila:\n\n");
            imprime_fila(fila);
            printf("\nFim da fila!\n\n");
        }
        else if(opcao == 'E')
        {
            libera_fila(fila);
            break;
        }
    }
    return 0;
}