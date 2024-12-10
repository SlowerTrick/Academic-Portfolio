#include "livro.h"
#include <stdio.h>

tLivros lerLivro()
{
    tLivros livro;
    scanf(" %s %s %d", livro.titulo, livro.autor, &livro.anoPublicacao);
    return livro;
}

void imprimeLivro(tLivros livro)
{
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
}

