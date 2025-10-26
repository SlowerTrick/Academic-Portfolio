#include "arvore.h"
#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
    FILE *fin = fopen("entrada.txt", "r");
    FILE *fout = fopen("saida.txt", "w");
    Arvore *arvore = cria_arvore();

    char palavra[1000];
    while (fscanf(fin, "%s ", palavra) != EOF)
    {
        if (palavra[strlen(palavra) - 1] == '.')
            palavra[strlen(palavra) - 1] = '\0';
        Palavra *p = cria_palavra(palavra);
        arvore = insere_arvore(arvore, p);
    }
    imprime_arvore(arvore);
    printf("\n");

    int total = total_palavras(arvore);
    int total_unicas = total_palavras_unicas(arvore);

    printf("Total: %d\nTotal unicas: %d\n", total, total_unicas);

    Palavra *mais_frequente = descobre_maior_frequencia(arvore);
    printf("Mais frequente: %s %d\n", retorna_palavra(mais_frequente), retorna_frequencia_palavra(mais_frequente));

    Palavra **vetor = cria_vetor(arvore, total_unicas);
    organiza_vetor(vetor, total_unicas);

    for (int i = 0; i < total_unicas; i++)
        fprintf(fout, "%s %d\n", retorna_palavra(vetor[i]), retorna_frequencia_palavra(vetor[i]));
    fprintf(fout, "------------------------\n");
    fprintf(fout, "%d palavras distintas encontradas\n", total_unicas);
    fprintf(fout, "%d palavras no total\n", total);
    fprintf(fout, "%s é a palavra de maior frequência (%d)", retorna_palavra(mais_frequente), retorna_frequencia_palavra(mais_frequente));

    libera_vetor(vetor, total_unicas);
    libera_arvore(arvore);
}
