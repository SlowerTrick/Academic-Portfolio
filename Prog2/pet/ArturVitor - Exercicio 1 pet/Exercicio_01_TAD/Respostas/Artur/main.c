#include <stdio.h>
#include "store.h"

int main(void)
{
    tStore loja = abreLoja();
    while(1)
    {
        printf("Menu:\n C - Cadastrar Produto\n E - Estocar Produto\n V - Vender Produto\n D - Atualizar desconto de Produto\n I - Imprimir Produtos\n R - Imprimir Relatorio de Vendas\n F - Finalizar Programa\n");
        char operacao;
        scanf(" %c", &operacao);
        getchar();
        if (operacao == 'C')
        {
            tProduct product = leProduto();
            loja = adicionaProduto(loja, product);
            printf("\n");
        }
        else if (operacao == 'E')
        {
            int id, qtd;
            printf("Digite o id do Produto: ");
            scanf("%d", &id);
            printf("Digite o numero de unidades: ");
            scanf("%d", &qtd);
            loja = aumentaEstoqueLoja(loja, id, qtd);
            printf("\n");
        }
        else if (operacao == 'V')
        {
            int id, qtd;
            printf("Digite o id do Produto: ");
            scanf("%d", &id);
            printf("Digite o numero de unidades: ");
            scanf("%d", &qtd);
            loja = vendeProdutoLoja(loja, id, qtd);
            printf("\n");
        }
        else if (operacao == 'D')
        {
            int id;
            float desconto;
            printf("Digite o id do Produto: ");
            scanf("%d", &id);
            printf("Digite o novo desconto: ");
            scanf("%f", &desconto);
            loja = atualizaDescontoLoja(loja, id, desconto);
            printf("\n");
        }
        else if (operacao == 'I')
        {
            imprimeProdutosLoja(loja);
        }
        else if (operacao == 'R')
        {
            imprimeRelatorio(loja);
        }
        else if (operacao == 'F')
        {
            break;
        }
    }
}