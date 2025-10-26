#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro
{
    char titulo[MAXTAM_STRINGS];
    char autor[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char editora[MAXTAM_STRINGS];
    int ano;
};

// Aloca dinamicamente uma nova estrutura Livro e realiza a leitura dos dados
// de entrada associados ao livro. Retorna o ponteiro para o objeto Livro.
// Retorna: Ponteiro para o Livro recém-criado, com os dados carregados.
Livro* livro_construct()
{
    Livro *l = malloc(sizeof(*l));
    if(!l)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    l->ano = 0;
    scanf("%s %s %s %s %d%*c", l->titulo, l->autor, l->genero, l->editora, &l->ano);
    return l;
}

// Imprime os dados do livro. Recebe um ponteiro genérico para o livro
// e exibe suas informações relevantes, como título, autor, etc.
// Parâmetros:
//  l - Ponteiro para o Livro a ser impresso.
void livro_print(void* l)
{
    Livro *livro = (Livro *) l;
    printf("LIVRO\n");
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Genero: %s\n", livro->genero);
    printf("Editora: %s\n", livro->editora);
    printf("Ano: %d\n", livro->ano);
}

// Libera a memória alocada para o livro, desalocando a estrutura Livro
// e seus dados associados de forma adequada.
// Parâmetros:
//  l - Ponteiro para o Livro a ser destruído.
void livro_destroy(void* l)
{
    Livro *livro = (Livro *) l;
    if(livro)
        free(livro);
    livro = NULL;
}
