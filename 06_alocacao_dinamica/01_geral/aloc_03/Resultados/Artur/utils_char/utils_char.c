#include "utils_char.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Cria um vetor de caracteres de tamanho especificado, alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas posições com "_"
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetor(int tamanho)
{
    char *v = malloc(sizeof(char) * (tamanho + 1));
    if (!v)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    memset(v, '_', tamanho);
    v[tamanho] = '\0';
    return v;
}


/**
 * Lê uma string do tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(char *vetor, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        char c;
        scanf("%c", &c);
        if(c != '\n') 
            vetor[i] = c;
    }
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
void ImprimeString(char *vetor, int tamanho)
{
    printf("%s\n", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor)
{
    free(vetor);
}
