#include "arvore.h"
#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

void imprime_arvore(Arv *a)
{
    arv_imprime(a);
    printf("\n");
}

void imprime_desejado(Arv *a, char *nome)
{
    printf("Aluno %s encontrado: %d\n", nome, arv_pertence(a, nome));
}

int main(void)
{
    // Cria alunos
    Aluno *a1 = cria_aluno("A", 1);
    Aluno *a2 = cria_aluno("B", 2);
    Aluno *a3 = cria_aluno("C", 3);
    Aluno *a4 = cria_aluno("D", 4);
    Aluno *a5 = cria_aluno("E", 5);
    Aluno *a6 = cria_aluno("F", 6);

    // Teste arvore vazia
    Arv *arvore_vazia = arv_criavazia();
    arv_imprime(arvore_vazia);
    printf("\n");
    arv_libera(arvore_vazia);

    // Teste arvore complexa
    Arv *arvoreA = arv_cria(a1, NULL, NULL);
    Arv *arvoreB = arv_cria(a2, NULL, NULL);
    Arv *arvoreC = arv_cria(a3, arvoreA, arvoreB);
    Arv *arvoreD = arv_cria(a4, NULL, NULL);
    Arv *arvoreE = arv_cria(a5, arvoreD, NULL);
    Arv *arvoreF = arv_cria(a6, arvoreC, arvoreE);
    
    // Imprime alguns segmentos da arvore
    imprime_arvore(arvoreA);
    imprime_arvore(arvoreC);
    imprime_arvore(arvoreE);
    imprime_arvore(arvoreF);

    // Teste de busca na arvore
    imprime_desejado(arvoreA, "B");
    imprime_desejado(arvoreC, "A");
    imprime_desejado(arvoreF, "D");
    imprime_desejado(arvoreF, "H");

    // Teste retorna pai
    imprime_arvore(arv_pai(arvoreF, "A"));
    imprime_arvore(arvoreF);
    
    // imprime o numero de folhas
    printf("Total folhas: %d\n", folhas(arvoreF));

    // imprime ocorrencias
    printf("Total de ocorrencias: %d\n", ocorrencias(arvoreF, "A"));

    // imprime altura
    printf("Altura da arvore: %d\n", altura(arvoreF));
    
    // Liberacao dos dados;
    libera_aluno(a1);
    libera_aluno(a2);
    libera_aluno(a3);
    libera_aluno(a4);
    libera_aluno(a5);
    libera_aluno(a6);
    return 0;
}