#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void checkMemory(void *p);

/*TipoItem Aluno (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD. Devem ser definidos campos:
 - nome (string)
 - matricula (int) */
struct aluno
{
    char *nome;
    int matricula;
};

TAluno *InicializaAluno(char* nome, int matricula)
{
    TAluno *a = malloc(sizeof(*a));
    checkMemory(a);
    a->nome = strdup(nome);
    a->matricula = matricula;
    return a;
}

void imprimeAluno(TAluno *a)
{
    printf("Nome:%s Matricula: %d\n", a->nome, a->matricula);
}

int getMatriculaAluno(TAluno *a)
{
    return a->matricula;
}

void LiberaAluno(TAluno *a)
{
    if(a)
    {
        free(a->nome);
        free(a);
    }
}

typedef struct celula
{
    TAluno *aluno;
    struct celula *prox;
}
Celula;

Celula *criaCelula(TAluno *a)
{
    Celula *c = malloc(sizeof(*c));
    checkMemory(c);
    c->aluno = a;
    c->prox = NULL;
    return c;
}

void imprimeCelula(Celula *c)
{
    imprimeAluno(c->aluno);
}

int getMatriculaCelula(Celula *c)
{
    return getMatriculaAluno(c->aluno);
}

void liberaCelula(Celula *c)
{
    if(c)
    {
        //liberaAluno(c->aluno);
        free(c);
    }
}

/*Tipo que define a lista (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD.
 Usar lista COM Sentinela */
struct lista
{
    Celula *prim;
    Celula *ult;
};

/*Inicializa o sentinela de uma lista
 * inputs: nenhum
 * output: Sentinela inicializado (lista vazia)
 * pre-condicao: nenhuma
 * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL */
TLista* CriaLista()
{
    TLista *l = malloc(sizeof(*l));
    checkMemory(l);
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno (TLista* lista, TAluno* aluno)
{
    Celula *c = criaCelula(aluno);
    c->prox = lista->prim;

    if(lista->prim == NULL)
        lista->ult = c;
    lista->prim = c;
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno* Retira (TLista* lista, int mat)
{
    Celula *temp = lista->prim;
    Celula *ant = NULL;

    while(temp != NULL && getMatriculaCelula(temp) != mat)
    {
        ant = temp;
        temp = temp->prox;
    }
    
    if(temp == NULL) return NULL;

    if(ant == NULL)
    {
        lista->prim = temp->prox;
    }
    if(temp->prox == NULL)
    {
        lista->ult = ant; 
        if(ant->prox)
            ant->prox = NULL;
    }
    if(ant && temp->prox)
        ant->prox = temp->prox;
    
    TAluno *a = temp->aluno;
    liberaCelula(temp);
    return a;
}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos(TLista* lista) 
{
    Celula *temp1 = lista->prim;
    while (temp1 != NULL) 
    {
        Celula *temp2 = temp1->prox;
        Celula *anterior = temp1;
        while (temp2 != NULL) 
        {
            if (getMatriculaCelula(temp1) == getMatriculaCelula(temp2)) 
            {
                Celula *paraRemover = temp2;
                temp2 = temp2->prox;
                anterior->prox = temp2;
                liberaCelula(paraRemover);
            } 
            else 
            {
                anterior = temp2;
                temp2 = temp2->prox;
            }
        }
        temp1 = temp1->prox;
    }
}

/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista* Merge (TLista* turma1, TLista* turma2)
{
    TLista *result = CriaLista();
    Celula *temp1 = turma1->prim;
    Celula *temp2 = turma2->prim;

    while (temp1 != NULL && temp2 != NULL)
    {
        if(temp1)
            InsereAluno(result, temp1->aluno);
        if(temp2)
            InsereAluno(result, temp2->aluno);
        temp1 = temp1->prox;
        temp2 = temp2->prox;
    }
    return result;
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime (TLista* lista)
{
    Celula *temp = lista->prim;

    while (temp != NULL)
    {
        imprimeCelula(temp);
        temp = temp->prox;
    }
}

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista (TLista* lista)
{
    if(lista)
    {
        Celula *temp = lista->prim;
    
        while (temp != NULL)
        {
            Celula *aux = temp;
            temp = temp->prox;
            liberaCelula(aux);
        }
        free(lista);
    }

}

static void checkMemory(void *p)
{
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}
