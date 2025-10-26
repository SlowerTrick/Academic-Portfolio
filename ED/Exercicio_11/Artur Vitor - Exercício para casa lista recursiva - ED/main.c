#include "lista.h"
#include <stdio.h>

int main(void)
{
    Aluno *a1 = cria_aluno("A", 1);
    Aluno *a2 = cria_aluno("B", 2);
    Aluno *a3 = cria_aluno("C", 3);

    Lista *l = cria_lista(a1);
    l = adiciona_lista(l, a2);
    l = adiciona_lista(l, a3);
    imprime_lista(l);
    printf("\n");

    l = remove_lista(l, a1);
    imprime_lista(l);
    printf("\n");
    l = remove_lista(l, a3);
    imprime_lista(l);
    printf("\n");

    l = adiciona_lista(l, a1);
    l = adiciona_lista(l, a3);
    imprime_lista(l);
    printf("\n");
    l = remove_lista(l, a1);
    imprime_lista(l);
    printf("\n");
    
    libera_aluno(a1);
    libera_aluno(a2);
    libera_aluno(a3);
    libera_lista(l);
}