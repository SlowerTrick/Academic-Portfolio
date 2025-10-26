//
//  produto.h
//  TADProduto
//
//  Created by Artur Vítor Cintra Bernardes on 21/05/25.
//  Este arquivo define a estrutura e as operações básicas para manipulação de produtos.
//  Um produto é caracterizado por um nome (item), valor e quantidade disponível.
//

#include "produto.h"

struct Produto
{
    char *item;
    int valor;
    int qtd;
};


Produto *cria_produto(char *item, int valor, int qtd)
{
    Produto *p = malloc(sizeof(*p));
    p->item = malloc(sizeof(char) * (strlen(item) + 1));
    strcpy(p->item, item);
    p->valor = valor;
    p->qtd = qtd;
    return p;
}
Produto *le_produto()
{
    char item[MAX_TAM_NOME];
    int valor, qtd;
    scanf(" %[^,], %d, %d%*c", item, &valor, &qtd);
    return cria_produto(item, valor, qtd);
}
 
char *get_item_produto(Produto *p)
{
    return p->item;
}

int get_valor_produto(Produto *p)
{
    return p->valor;
}

int get_qtd_produto(Produto *p)
{
    return p->qtd;
}

void imprime_catalogo_filial_produto(Produto *p)
{
    printf("\t\tItem: %s, valor unitário: %d, quantidade: %d\n", p->item, p->valor, p->qtd);
}

void imprime_produto(Produto *p)
{
    printf("Item: %s, valor unitário: %d, quantidade: %d\n", p->item, p->valor, p->qtd);
}

void libera_produto(Produto *p)
{
    if(p)
    {
        if(p->item)
            free(p->item);
        p->item = NULL;
        free(p);
    }
    p = NULL;
}