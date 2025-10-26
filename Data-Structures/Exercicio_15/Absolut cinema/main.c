#include "arvore.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    Arvore *arvore = cria_arvore();
    FILE *entrada = fopen("entrada.txt", "r");
    if (entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    char palavra[1000];
    while (fscanf(entrada, "%s", palavra) != EOF)
    {
        if(palavra[strlen(palavra) - 1] == '.')
            palavra[strlen(palavra) - 1] = '\0';
        //printf("%s ", palavra);
        arvore = insere_arvore(arvore, palavra);
    }
    //printf("\n");

    //imprime_arvore(arvore);
    //printf("\n");

    int total_palavras = total_elementos_arvore(arvore);
    // printf("Total palavras: %d\n", total_palavras);

    int total_palavras_unicas = total_elementos_unicos_arvore(arvore);
    // printf("Total palavras unicas: %d\n", total_palavras_unicas);

    int tamanho = 0;
    char *palavra_mais_frequente = elemento_mais_frequente_arvore(arvore, &tamanho);
    // printf("Palavra mais frequente: %s\nNumero de repeticoes: %d\n", palavra_mais_frequente, tamanho);

    char *vet[total_palavras_unicas];
    for (int i = 0; i < total_palavras_unicas; i++)
        vet[i] = NULL;
    preenche_vetor_arvore(arvore, vet, total_palavras_unicas);

    int *indexes = malloc(total_palavras_unicas * sizeof(int));
    for (int i = 0; i < total_palavras_unicas; i++)
        indexes[i] = i;

    FILE *saida = fopen("saida.txt", "w");
    for (int i = 0; i < total_palavras_unicas; i++)
        fprintf(saida, "%s %d\n", vet[i], ocorrencias_arvore(arvore, vet[i]));
    fprintf(saida, "------------------------\n");
    fprintf(saida, "%d palavras distintas encontradas\n", total_palavras_unicas);
    fprintf(saida, "%d palavras no total\n", total_palavras);
    fprintf(saida, "%s é a palavra de maior frequência (%d)", palavra_mais_frequente, tamanho);

    fclose(entrada);
    fclose(saida);
    libera_arvore(arvore);
    return 0;
}
