#include "biblioteca.h"
#include <stdio.h>

tBiblioteca inicializarBiblioteca()
{
    tBiblioteca bilioteca;
    bilioteca.tamanho = 0;
    return bilioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro)
{
    if (biblioteca.tamanho > MAX_LIVROS)
    {
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
        return biblioteca;
    }
    biblioteca.livros[biblioteca.tamanho++] = livro;
    printf("Livro adicionado com sucesso!\n");
    return biblioteca;
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo);

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo);

void listarLivrosDaBiblioteca(tBiblioteca biblioteca)
{
    if(biblioteca.tamanho == 0)
    {
        printf("A biblioteca esta vazia!\n");
        return;
    }
    printf("Lista de Livros na Biblioteca:\n");
    for(int i = 0; i < biblioteca.tamanho; i++)
    {
        imprimeLivro(biblioteca.livros[i]);
    }
}
