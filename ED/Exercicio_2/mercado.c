#include "mercado.h"
#include "estoque.h"

struct Mercado
{
    char *nome;
    Filial **filiais;
    Estoque *estoque;
    int qtd_filiais_total;
    int qtd_filiais_atual;
};

Mercado *cria_mercado(char *nome)
{
    Mercado *m = malloc(sizeof(*m));
    if(!m)
            {
                printf("ERRO! falta de memoria");
                exit(1);
            }
    m->nome = malloc(sizeof(char) * (strlen(nome) + 1));
    m->nome = strcpy(m->nome, nome);
    m->qtd_filiais_total = 10;
    m->filiais = malloc(sizeof(Produto *) * m->qtd_filiais_total);
    m->qtd_filiais_atual = 0;
    m->estoque = le_estoque();
    return m;
}

Mercado *le_mercado()
{
    char nome[MAX_TAM_NOME];
    scanf(" %[^,],", nome);
    return cria_mercado(nome);
}

void adicionar_filial_mercado(Mercado *m, Filial *f)
{
    int qtd_nova_filial = get_estoque_total_filial(f);

    if(get_tamanho_estoque(m->estoque) >= qtd_nova_filial)
    {
        if(m->qtd_filiais_atual == m->qtd_filiais_total)
        {
            m->qtd_filiais_total *= 2;
            m->filiais = realloc(m->filiais ,sizeof(Produto *) * m->qtd_filiais_total);
            if(!m)
            {
                printf("ERRO! falta de memoria");
                exit(1);
            }
        }
        m->filiais[m->qtd_filiais_atual++] = f;
        altera_estoque(m->estoque, qtd_nova_filial);
    }
    else
    {
        printf("Estoque insuficiente para cadastrar no mercado!\n");
    }
}

void adicionar_produto_mercado(Mercado *m, Produto *p)
{
    adicionar_produto_estoque(m->estoque, p);
}

void imprime_mercado(Mercado *m)
{
    printf("Mercado: %s\n", m->nome);
    imprime_estoque(m->estoque);
    printf("Filiais:\n");
    for(int i = 0; i < m->qtd_filiais_atual; i++)
    {
        imprime_filial(m->filiais[i]);
        printf("\n");
    }
    printf("\n");
}

Filial *encontra_filial_mercado(Mercado *m, char *nome)
{
    Filial *f = NULL;
    for(int i = 0; i < m->qtd_filiais_atual; i++)
    {
        if(strcmp(nome, get_filial_nome(m->filiais[i])) == 0)
        {
            f = m->filiais[i];
            break;
        }
    }
    return f;
}

Produto *encontra_produto_mercado(Mercado *m, char *nome)
{
    return encontra_produto_estoque(m->estoque, nome);
}

void diminui_estoque_mercado(Mercado *m, int qtd)
{
    altera_estoque(m->estoque, qtd);
}

void libera_mercado(Mercado *m)
{
    if(m)
    {
        if(m->nome)
            free(m->nome);
        m->nome = NULL;
        if(m->estoque)
            libera_estoque(m->estoque);
        for(int i = 0; i < m->qtd_filiais_atual; i++)
            libera_filial(m->filiais[i]);
        free(m->filiais);
        m->filiais = NULL;
        free(m);
    }
    m = NULL;
}