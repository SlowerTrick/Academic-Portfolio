#include "biblioteca.h"
#include <stdio.h>

int main(void)
{
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
            listarLivrosDaBiblioteca(biblioteca);
        }
        else if(operacao == 2)
        {
            printf("2");
        }
        else if(operacao == 3)
        {
            printf("3");
        }
    }
}