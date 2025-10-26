#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pacote
{
    void *conteudo;
    Type tipo;
    int tamanho;
    int soma;
};


/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem)
{
    tPacote *p = malloc(sizeof(*p));
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    if(type == INT)
    {
        p->conteudo = malloc(sizeof(int) * numElem);
        if(!p->conteudo)
        {
            free(p);
            printf("ERRO! falta de memoria");
            exit(1);
        }
        for(int i = 0; i < numElem; i++)
            ((int *)p->conteudo)[i] = 0;

    }
    else if(type == CHAR)
    {
        p->conteudo = malloc(sizeof(char) * (numElem + 1));
        if(!p->conteudo)
        {
            free(p);
            printf("ERRO! falta de memoria");
            exit(1);
        }
        for(int i = 0; i < numElem; i++)
            ((char*)p->conteudo)[i] = '0';
        ((char*)p->conteudo)[numElem] = '\0';
    }
    p->tamanho = numElem;
    p->tipo = type;
    p->soma = 0;
    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac)
{
    if(pac)
    {
        free(pac->conteudo);
        pac->conteudo = NULL;
        free(pac);
    }
    pac = NULL;
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac)
{
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    if(pac->tipo == INT)
    {
        for(int i = 0; i < pac->tamanho; i++)
            scanf("%d", &((int *)pac->conteudo)[i]);
    }
    else if(pac->tipo == CHAR)
    {
        scanf(" %[^\n]", ((char *)pac->conteudo));
    }
    scanf("%*c");
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac)
{
    CalculaSomaVerificacaoPacote(pac);
    if(pac->tipo == INT)
    {
        printf("%d ", pac->soma);
        for(int i = 0; i < pac->tamanho; i++)
        {
            printf("%d", ((int *)pac->conteudo)[i]);
            if(i < pac->tamanho - 1)
                printf(" ");
        }
        printf("\n");
    }
    else if(pac->tipo == CHAR)
        printf("%d %s\n", pac->soma, ((char*)pac->conteudo));       
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac)
{
    int soma = 0;
    if(pac->tipo == INT)
        for(int i = 0; i < pac->tamanho; i++)
            soma += ((int*)pac->conteudo)[i];
    else if(pac->tipo == CHAR)
        for(int i = 0; i < pac->tamanho; i++)
            soma += ((char *)pac->conteudo)[i];
    pac->soma = soma;
}
