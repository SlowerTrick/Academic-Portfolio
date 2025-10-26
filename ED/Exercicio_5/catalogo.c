#include "catalogo.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct catalogo
{
    Produto **lista_produtos;
    int qtd_atual;
    int qtd_total;
};


tCatalogo *cria_catalogo()
{
    tCatalogo *c = malloc(sizeof(*c));
    if(!c)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    c->qtd_atual = 0;
    c->qtd_total = 10;
    c->lista_produtos = malloc(sizeof(Produto *) * c->qtd_total);
    return c;
}

void *adiciona_produto_catalogo(tCatalogo *c, Produto *p)
{
    if(c->qtd_atual == c->qtd_total)
    {
        c->qtd_total *= 2;
        c->lista_produtos = realloc(c->lista_produtos, sizeof(Produto *) * c->qtd_total);
    }
    c->lista_produtos[c->qtd_atual++] = p;
}

void libera_catalogo(tCatalogo *c)
{
    for(int i = 0; i < c->qtd_atual; i++)
    {
        printf("%s removido do catalogo\n", get_nome_produto(c->lista_produtos[i]));
        libera_produto(c->lista_produtos[i]);
    }
    free(c->lista_produtos);
    free(c);
}
