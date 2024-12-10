#include "biblioteca.h"
#include <stdio.h>

int main(void)
{
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    int total;
    scanf("%d", &total);
    tBiblioteca biblioteca = inicializarBiblioteca();
    for(int i = 0; i < total; i++)
    {
        int operacao;
        scanf("%d", &operacao);
        if(operacao == 1)
        {
            tLivros livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if(operacao == 2)
        {
            char titulo[100];
            scanf("%s", titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
        }
        else if(operacao == 3)
        {
            printf("\n");
            listarLivrosDaBiblioteca(biblioteca);
        }
    }
}