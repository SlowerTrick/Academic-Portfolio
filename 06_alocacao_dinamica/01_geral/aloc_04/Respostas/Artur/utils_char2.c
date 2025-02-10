#include "utils_char2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao()
{
    char *v = malloc(sizeof(char) * (TAM_PADRAO + 1));
    if(!v)
    {
        printf("Erro! falta de memória");
        exit(1);
    }
    memset(v, '_', TAM_PADRAO);
    v[TAM_PADRAO] = '\0';
    return v;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 * 
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo)
{
    int novo_tamanho = tamanhoantigo + TAM_PADRAO;
    char *v = realloc(vetor, sizeof(char) * (novo_tamanho + 1));
    if(!v)
    {
        printf("Erro! falta de memória");
        exit(1);
    }
    for(int i = tamanhoantigo; i < novo_tamanho; i++)
    {
        v[i] = '_';
    }
    v[novo_tamanho] = '\0';
    return v;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
*/
char* LeVetor(char *vetor, int *tamanho)
{
    int posicao_atual = 0, tamanho_atual = *tamanho;
    while (1)
    {
        char c;
        scanf("%c", &c);
        if(c == '\n')
            return vetor;
        else if(posicao_atual == tamanho_atual)
        {
            vetor = AumentaTamanhoVetor(vetor, tamanho_atual);
            tamanho_atual = strlen(vetor);
        }
        vetor[posicao_atual] = c;
        posicao_atual++;
    }
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser imprimido.
*/
void ImprimeString(char *vetor)
{
    printf("%s\n",  vetor);
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
