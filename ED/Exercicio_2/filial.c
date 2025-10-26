#include "filial.h"

struct Filial
{
    char *nome;
    int estoque_total;
    int estoque_atual;
    Produto **produtos;
    int qtd_produtos_total;
    int qtd_produtos_atual;
};

Filial *cria_filial(char *nome, int estoque)
{
    Filial *f = malloc(sizeof(*f));
    if(!f)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    f->nome = malloc(sizeof(char) * (strlen(nome) + 1));
    f->nome = strcpy(f->nome, nome);
    f->qtd_produtos_total = 10;
    f->produtos = malloc(sizeof(Produto *) * f->qtd_produtos_total);
    f->qtd_produtos_atual = 0;
    f->estoque_total = estoque;
    f->estoque_atual = estoque;
    return f;
}

Filial *le_filial()
{
    char nome[MAX_TAM_NOME];
    int estoque;
    scanf(" %[^,], %d%*c", nome, &estoque);
    return cria_filial(nome, estoque);
}

int adicionar_produto_filial(Filial *f, Produto *p)
{
    int qtd_novo_produto = get_qtd_produto(p);

    if(f->estoque_atual >= qtd_novo_produto)
    {
        if(f->qtd_produtos_atual == f->qtd_produtos_total)
        {
            f->qtd_produtos_total *= 2;
            f->produtos = realloc(f->produtos ,sizeof(Produto *) * f->qtd_produtos_total);
            if(!f)
            {
                printf("ERRO! falta de memoria");
                exit(1);
            }
        }
        f->produtos[f->qtd_produtos_atual++] = p;
        f->estoque_atual -= qtd_novo_produto;
        return qtd_novo_produto;
    }
    else
    {
        printf("Estoque insuficiente para cadastrar %s na filial %s!\n", get_item_produto(p), f->nome);
        return 0;
    }
}

void imprime_filial(Filial *f)
{
    printf("\tFilial: %s\n", f->nome);
    printf("\tEstoque Total: %d\n", f->estoque_total);
    printf("\tEstoque Atual: %d\n", f->estoque_atual);
    printf("\tProdutos:\n");
    for(int i = 0; i < f->qtd_produtos_atual; i++)
        imprime_catalogo_filial_produto(f->produtos[i]);
}

int get_estoque_total_filial(Filial *f)
{
    return f->qtd_produtos_total;
}

char *get_filial_nome(Filial *f)
{
    return f->nome;
}

void libera_filial(Filial *f)
{
    if(f)
    {
        if(f->nome)
            free(f->nome);
        f->nome = NULL;
        if(f->produtos)
            free(f->produtos);
        f->produtos = NULL;
        free(f);
    }
    f = NULL;
}