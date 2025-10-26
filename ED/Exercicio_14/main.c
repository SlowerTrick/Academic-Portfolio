#include <stdio.h>
#include "abb.h"

int main(void)
{
    Aluno *a1 = cria_aluno("A", 10);
    Aluno *a2 = cria_aluno("B", 20);
    Aluno *a3 = cria_aluno("C", 2);
    Aluno *a4 = cria_aluno("D", 300);
    Aluno *a5 = cria_aluno("E", 5);

    Abb *arvore = cria_abb();
    arvore = insere_abb(arvore, a1);
    arvore = insere_abb(arvore, a2);
    arvore = insere_abb(arvore, a3);
    arvore = insere_abb(arvore, a4);
    arvore = insere_abb(arvore, a5);

    imprime_abb(arvore);
    printf("\n");
    
    imprime_abb(busca_abb(arvore, 5));
    printf("\n");

    imprime_abb(retira_abb(arvore, 5));
    printf("\n");
    
    libera_aluno(a1);
    libera_aluno(a2);
    libera_aluno(a3);
    libera_aluno(a4);
    libera_aluno(a5);
    libera_abb(arvore);

    printf("Hello")
}
