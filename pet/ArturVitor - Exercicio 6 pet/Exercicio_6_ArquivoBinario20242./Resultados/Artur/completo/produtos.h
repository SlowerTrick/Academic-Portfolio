#ifndef _PRODUTOS_H
#define _PRODUTOS_H

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

/** 
 * @brief Cadastra um novo produto no vetor de produtos.
*/
void cadastrarProduto(Produto** vetorProdutos, int* tamanho, int* alocado);

/** 
 * @brief Exibe a lista de produtos ordenada.
*/
void exibirLista(Produto** vetorProdutos, int tamanho);

/** 
 * @brief Compara dois produtos.
*/
int compararProduto(const void* a, const void* b);

/** 
 * @brief Ordena a lista de produtos.
*/
void ordenarLista(Produto** vetorProdutos, int tamanho);

/** 
 * @brief Desaloca a lista de produtos e todos os seus produtos.
*/
void desalocaLista(Produto** vetorProdutos, int tamanho);

/** 
 * @brief Escreve a lista em um arquivo binário.
*/
void salvarLista(Produto** vetorProdutos, int tamanho);

/** 
 * @brief Le uma lista de produtos salva em formato binário e a retorna.
*/
Produto** lerLista(int* tamanho, int* alocado);

#endif