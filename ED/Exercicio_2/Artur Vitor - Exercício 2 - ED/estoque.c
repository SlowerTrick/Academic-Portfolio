#include "estoque.h"

struct Estoque
{
    Produto **produtos;
    int qtd_produtos_total;
    int qtd_produtos_atual;
    int estoque_total;
    int estoque_atual;
};

Estoque *cria_estoque(int qtd)
{
    Estoque *e = malloc(sizeof(*e));
    if (!e)
    {
        printf("ERRO! falta de memoria\n");
        exit(1);
    }

    e->qtd_produtos_total = 10;
    e->produtos = malloc(sizeof(Produto *) * e->qtd_produtos_total);
    if (!e->produtos)
    {
        printf("ERRO! falta de memoria ao criar vetor de produtos\n");
        free(e);
        exit(1);
    }

    e->qtd_produtos_atual = 0;
    e->estoque_total = qtd;
    e->estoque_atual = qtd;
    return e;
}

Estoque *le_estoque()
{
    int qtd;
    scanf(" %d%*c", &qtd);
    return cria_estoque(qtd);
}

int adicionar_produto_estoque(Estoque *e, Produto *p)
{
    int qtd_novo_produto = get_qtd_produto(p);

    if (e->estoque_atual >= qtd_novo_produto)
    {
        if (e->qtd_produtos_atual == e->qtd_produtos_total)
        {
            e->qtd_produtos_total *= 2;
            Produto **temp = realloc(e->produtos, sizeof(Produto *) * e->qtd_produtos_total);
            if (!temp)
            {
                printf("ERRO! falta de memoria ao realocar produtos\n");
                exit(1);
            }
            e->produtos = temp;
        }

        e->produtos[e->qtd_produtos_atual++] = p;
        e->estoque_atual -= qtd_novo_produto;
        return qtd_novo_produto;
    }
    else
    {
        printf("Estoque insuficiente para cadastrar %s no estoque!\n", get_item_produto(p));
        return 0;
    }
}

int get_tamanho_estoque(Estoque *e)
{
    return e->estoque_atual;
}

void imprime_estoque(Estoque *e)
{
    printf("Estoque Total: %d\n", e->estoque_total);
    printf("Estoque Atual: %d\n\n", e->estoque_atual);
    printf("Catalogo de Produtos:\n");
    for (int i = 0; i < e->qtd_produtos_atual; i++)
        imprime_estoque_produto(e->produtos[i]);
    printf("\n");
}

void altera_estoque(Estoque *e, int qtd)
{
    e->estoque_atual += qtd;
    if (e->estoque_atual > e->estoque_total)
        e->estoque_atual = e->estoque_total;
    if (e->estoque_atual < 0)
        e->estoque_atual = 0;
}

Produto *encontra_produto_estoque(Estoque *e, char *nome)
{
    Produto *p = NULL;
    for(int i = 0; i < e->estoque_atual; i++)
    {
        if(strcmp(nome, get_item_produto(e->produtos[i])) == 0)
        {
            p = e->produtos[i];
            break;
        }
    }
    return p;
}

void libera_estoque(Estoque *e)
{
    if (e)
    {
        for (int i = 0; i < e->qtd_produtos_atual; i++)
            libera_produto(e->produtos[i]);
        free(e->produtos);
        free(e);
    }
}
