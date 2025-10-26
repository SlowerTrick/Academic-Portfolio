#include "hash.h"

struct hash
{
    int qtd_atual;
    int qtd_total; // Dimensao
    void **lista;
};

static Hash* increaseHash(Hash *h_antigo);
static int HashFunction(int dim, int idx);

#define VALOR_INICIAL 101
#define FATOR_AUMENTO 1.947

Hash *criaHash()
{
    Hash *h = malloc(sizeof(*h));
    if (!h)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    h->lista = calloc(VALOR_INICIAL, sizeof(void *));
    h->qtd_atual = 0;
    h->qtd_total = VALOR_INICIAL; // Primeiro valor primo para teste da realocacao
    return h;
}

void insereHash(Hash *h, void *elemento, int(return_key)(void *), void(collision)(void *, void *))
{
    if(h->qtd_atual >= 0.75 * h->qtd_total)
    {
        h = increaseHash(h);
        printf("Tabela hash expandida com valor atual %d\n", h->qtd_atual);
    }
    int key = return_key(elemento);
    int idx = HashFunction(h->qtd_total, key);

    if(h->lista[idx] == NULL)
    {
        h->lista[idx] = elemento;
        h->qtd_atual++;
    }
    else
        collision(h->lista[idx], elemento);
}

static int HashFunction(int dim, int idx)
{
    return idx % dim;
}

static Hash* increaseHash(Hash *h_antigo)
{
    int tam_antigo = h_antigo->qtd_total;
    void **tabela_antiga = h_antigo->lista;

    // Cria uma nova estrutura de hash com o novo tamanho
    int tam_novo = tam_antigo * FATOR_AUMENTO;
    Hash* h_novo = criaHash();
    free(h_novo->lista); // libera a tabela inicial de criaHash
    h_novo->qtd_total = tam_novo;
    h_novo->lista = calloc(tam_novo, sizeof(void*));
    
    printf("Expandindo tabela hash de %d para %d.\n", tam_antigo, tam_novo);

    // Itera sobre a tabela antiga
    for (int i = 0; i < tam_antigo; i++) {
        if (tabela_antiga[i] != NULL) {
            // Pega o início da lista encadeada
            Palavra *p_atual = (Palavra *)tabela_antiga[i];
            // Itera sobre a lista, reinserindo cada nó na nova tabela
            //while (p_atual != NULL) {
            //    Palavra *proximo = retorna_prox_palavra(p_atual); // Guarda o próximo
            //    reinsere_na_nova_tabela(h_novo, p_atual); // Reinsere o nó atual
            //    p_atual = proximo; // Move para o próximo
            //}
        }
    }
    
    // Libera a estrutura antiga
    free(tabela_antiga);
    free(h_antigo);
    
    return h_novo;
}

void imprimeHash(Hash *h, void(imprime)(void *))
{
    for (int i = 0; i < h->qtd_total; i++)
        if(h->lista[i] != NULL)
            imprime(h->lista[i]);
}

void *buscaHash(Hash *h, void *elemento, int(return_key)(void *), void *(search)(void *, void *))
{
    int key = return_key(elemento);
    int idx = HashFunction(h->qtd_total, key);
    return search(h->lista[idx], elemento);
}

int totalElementosHash(Hash *h, int(return_frequency)(void *))
{
    int total = 0;

    for(int i = 0; i < h->qtd_total; i++)
        if(h->lista[i] != NULL)
            total += return_frequency(h->lista[i]);

    return total;
}

int totalUnicosHash(Hash *h, int(return_node_count)(void *))
{
    int total = 0;

    for(int i = 0; i < h->qtd_total; i++)
        if(h->lista[i] != NULL)
            total += return_node_count(h->lista[i]);

    return total;
}

void liberaHash(Hash *h, void(libera)(void *))
{
    if (h)
    {
        for (int i = 0; i < h->qtd_total; i++)
            if (h->lista[i])
                libera(h->lista[i]);
        free(h->lista);
        free(h);
    }
}

void cria_vetor_palavras(Hash *h, Palavra **vet)
{
    int count = 0;
    for(int i = 0; i < h->qtd_total; i++)
        if(h->lista[i] != NULL)
            adiciona_vetor_palavra(vet, count++, (Palavra *)h->lista[i]);
}
