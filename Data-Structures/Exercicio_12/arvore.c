#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"

static void check_memory(void *p);

struct arvore
{
    Aluno *aluno;
    Arv *sae;
    Arv *sad;
};

// Cria uma árvore vazia
Arv *arv_criavazia(void)
{
    return NULL;
}

// cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e e subárvore direita d
Arv *arv_cria(Aluno *c, Arv *e, Arv *d)
{
    Arv *a = malloc(sizeof(*a));
    check_memory(a);
    a->aluno = c;
    a->sae = e;
    a->sad = d;
    return a;
}

// libera o espaço de memória ocupado pela árvore a
Arv *arv_libera(Arv *a)
{
    if (a)
    {
        arv_libera(a->sae);
        arv_libera(a->sad);
        free(a);
    }
    return NULL;
}

// retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia(Arv *a)
{
    return a == NULL;
}

// indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence(Arv *a, char *nome)
{
    if (a)
        return ((strcmp(retorna_nome(a->aluno), nome) == 0) || arv_pertence(a->sae, nome) || arv_pertence(a->sad, nome));
    return 0;
}

// imprime as informações dos nós da árvore
void arv_imprime(Arv *a)
{
    if (a)
    {
        printf("<%s ", retorna_nome(a->aluno));
        arv_imprime(a->sae);
        arv_imprime(a->sad);
        printf(" >");
    }
    else
    {
        printf("<>");
    }
}

// retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv *arv_pai(Arv *a, char *nome)
{
    if (a)
    {
        if ((a->sae && strcmp(retorna_nome(a->sae->aluno), nome) == 0) ||
           (a->sad && strcmp(retorna_nome(a->sad->aluno), nome) == 0))
            return a;
        else if (arv_pertence(a->sae, nome))
            return arv_pai(a->sae, nome);
        else if (arv_pertence(a->sad, nome))
            return arv_pai(a->sad, nome);
    }
    return NULL;
}

// retorna a quantidade de folhas de uma arvore binaria
int folhas(Arv *a)
{
    if (a)
    {
        if (a->sae == NULL && a->sad == NULL)
           return 1;
        return folhas(a->sae) + folhas(a->sad);
    }
    return 0;
}

// retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias(Arv *a, char *nome)
{
    int total = 0;
    if (a)
    {
        if(strcmp(retorna_nome(a->aluno), nome) == 0)
            total++;
        total += ocorrencias(a->sae, nome);
        total += ocorrencias(a->sad, nome);
    }
    return total;  
}

// retorna a altura da árvore a
int altura(Arv *a)
{
    if (a == NULL) return -1;  // árvore vazia tem altura -1

    int altura_esq = altura(a->sae);
    int altura_dir = altura(a->sad);

    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

static void check_memory(void *p)
{
    if (!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}