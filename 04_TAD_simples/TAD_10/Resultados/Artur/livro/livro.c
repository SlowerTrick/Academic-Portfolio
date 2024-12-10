#include "livro.h"
#include <stdio.h>
#include <string.h>

tLivros lerLivro()
{
    tLivros livro;
    char titulo[100], autor[100];
    int ano;
    scanf(" %s %s %d", titulo, autor, ano);
    strncpy(livro.autor, autor, 100);
    strncpy(livro.titulo, titulo, 100);
    livro.anoPublicacao = ano;
    return livro;
}

void imprimeLivro(tLivros livro)
{
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
}

