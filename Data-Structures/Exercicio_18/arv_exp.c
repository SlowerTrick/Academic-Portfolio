#include "arv_exp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Arv *criaArvore(char *dado, int tipo, Arv *esq, Arv *dir);

#define OPERADOR 1
#define VALOR 2

/*Tipo que define a arvore(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. */
struct arv
{
    char *dado;
    int tipo;
    struct arv *esq;
    struct arv *dir;
};

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
Arv* CriaVazia(void)
{
    return NULL;
}

static Arv *criaArvore(char *dado, int tipo, Arv *esq, Arv *dir)
{
    Arv *a = malloc(sizeof(*a));
    if(!a)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    a->dado = strdup(dado);
    a->tipo = tipo;
    a->esq = esq;
    a->dir = dir;
    return a;
}

/*cria um n� raiz de operador dados o operador e as duas sub-�rvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endere�o do n� raiz criado
*/
Arv* CriaOperador(char c, Arv* esq, Arv* dir)
{
    char dado[2];
    sprintf(dado, "%c", c);
    return criaArvore(dado, OPERADOR, esq, dir);
}

/*cria um n� operando dado o valor do no (como o operando � um n� folha, as sub-arvores da esquerda e da direita s�o nulas
* inputs: o operando
* output: o endere�o do n� raiz criado
*/
Arv* CriaOperando(int valor)
{
    char dado[100];
    sprintf(dado, "%d", valor);
    return criaArvore(dado, VALOR, NULL, NULL);
}

/*Imprime a �rvore em nota��o InOrder (esq, raiz, direita)
* inputs: o endere�o da raiz da �rvore
* output: nenhum
*/
void Imprime(Arv* arv)
{
    if(arv == NULL) return;

    Imprime(arv->esq);
    printf("%s\n", arv->dado);
    Imprime(arv->dir);
}

/* Libera mem�ria alocada pela estrutura da �rvore
as sub-�rvores devem ser liberadas antes de se liberar o n� raiz
* inputs: o endere�o da raiz da �rvore
* output: uma �rvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv)
{
    if(arv)
    {
        Libera(arv->esq);
        Libera(arv->dir);
        free(arv->dado);
        free(arv);
        return NULL;
    }
    return NULL;
}



/* Retorna o valor correspondente � avalia��o da express�o representada na �rvore
* inputs: o endere�o da raiz da �rvore
* output: o valor da express�o
*/
float Avalia(Arv* arv)
{
    if(arv == NULL) return 0;
    else if(arv->tipo == VALOR) return atof(arv->dado);

    char operando = arv->dado[0];
    float esq = Avalia(arv->esq);
    float dir = Avalia(arv->dir);

    if(operando == '+')
        return esq + dir;
    else if(operando == '-')
        return esq - dir;
    else if(operando == '*')
        return esq * dir;
    else if (operando == '/') {
        if (dir == 0) {
            perror("Erro: divisão por zero!\n");
            exit(1);
        }
        return esq / dir;
    }
    return 0;
}


/* Retorna o n�mero de folhas da �rvore
* inputs: o endere�o da raiz da �rvore
* output: o n�mero de folhas
*/
int Folhas(Arv* arv)
{
    if(arv == NULL) return 0;

    else if(arv->dir == NULL && arv->esq == NULL)
        return 1;

    return Folhas(arv->esq) + Folhas(arv->dir);
}

/* Retorna a altura da �rvore
* inputs: o endere�o da raiz da �rvore
* output: a altura da �rvore
*/
int Altura(Arv* arv)
{
    if (arv == NULL) return -1;
    int esq = Altura(arv->esq);
    int dir = Altura(arv->dir);
    return 1 + (esq > dir ? esq : dir);
}
