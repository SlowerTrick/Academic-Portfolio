/*
 listaArvores.c
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#include "listaArvores.h"
#include "arvore.h"
#include "utils.h"

struct node{
    Arv* arv;
    tNode* prox;
    tNode* ant;
};

struct lista_arv{
    tNode* prim;
    tNode* ult;
};

tListaArv* criaListaArv(){
    tListaArv* l = malloc(sizeof(*l));
    l->prim = l->ult = NULL;

    return l;
}

void insereFinalListaArv(tListaArv* l, Arv* elem){
    tNode* nova = malloc(sizeof(*nova));
    nova->arv  = elem;
    nova->prox = NULL;
    nova->ant = l->ult;

    if(l->prim == NULL){
        l->prim = nova;
    }else{
        l->ult->prox = nova;
    }

    l->ult = nova;
}

static tNode* buscaElem(tListaArv* l, unsigned char key){
    tNode* p = l->prim;

    while(p != NULL){
        if(retornaByteArv(p->arv) == key){
            return p;
        }
        p = p->prox;
    }

    return NULL;
}

Arv* retiraListaArv(tListaArv* l, unsigned char key){
    tNode* p = buscaElem(l, key);

    if(p == NULL){
        return NULL;
    }

    if(p == l->prim){
        l->prim = p->prox;
    }else{
        p->ant->prox = p->prox;
    }

    if(p == l->ult){
        l->ult = p->ant;
    }else{
        p->prox->ant = p->ant;
    }

    Arv* aux = p->arv;
    free(p);
    p = NULL;

    return aux;
}

/*
    Troca os dados entre dois nós da lista, sem alterar a estrutura da lista em si, só altera os dados.
    Fonte de inspiração: https://www.geeksforgeeks.org/dsa/quicksort-for-linked-list/
*/
static void swap(tNode* a, tNode* b){
    Arv* tmp = a->arv;
    a->arv = b->arv;
    b->arv = tmp;
}

/*
    Corrije a posição do pivô
    Fonte de inspiração: https://www.geeksforgeeks.org/dsa/quicksort-for-linked-list/
*/
static tNode* partition(tNode* head, tNode* tail){
    tNode* pivot = tail;//Utilizando pivô como último elemento por facilidade
    tNode* i = head->ant;//Começa uma posição antes do j

    for(tNode* j = head; j != tail; j = j->prox){
        if(retornaFrequenciaArv(j->arv) <= retornaFrequenciaArv(pivot->arv)){
            i = (i == NULL) ? head : i->prox;

            swap(i, j);
        }
    }
    
    i = (i == NULL) ? head : i->prox;

    swap(i, tail);

    return i;
}

void quickSortListaArv(tNode* head, tNode* tail){
    /*
        Checa se a lista está vazia, um único elemento, ou left < right
    */
    if(head == NULL || tail == NULL || head == tail || head == tail->prox){
        return;
    }

    tNode* pivot = partition(head, tail);
    
    quickSortListaArv(head, pivot->ant);
    quickSortListaArv(pivot->prox, tail);
}

tNode* retornaHeadListaArv(tListaArv* l){
    return l->prim;
}

tNode* retornaTailListaArv(tListaArv* l){
    return l->ult;
}

void insereOrdenadoListaArv(tListaArv* l, Arv* elem){
    tNode* aux = l->prim;
    tNode* nova = malloc(sizeof(*nova));
    check(nova != NULL, "Erro de alocacao de memoria!");
    nova->arv = elem;

    if(l->prim == NULL){
        nova->ant = NULL;
        nova->prox = NULL;
        l->prim = l->ult = nova;
        return;
    }

    while(aux != NULL && retornaFrequenciaArv(aux->arv) <= retornaFrequenciaArv(elem)){
        aux = aux->prox;
    }

    if(aux == l->prim){
        aux->ant = nova;
        nova->prox = aux;
        nova->ant = NULL;
        l->prim = nova;
        return;
    }

    if(aux == NULL){
        nova->prox = NULL;
        nova->ant = l->ult;
        l->ult->prox = nova;
        l->ult = nova;
        return;
    }

    nova->prox = aux;
    nova->ant = aux->ant;
    aux->ant->prox = nova;
    aux->ant = nova;
}

Arv* transformaListaEmArv(tListaArv* l){
    if(l->prim == l->ult || l->prim == NULL){
        return NULL;
    }

    Arv* arv_esq = retiraListaArv(l, retornaByteArv(l->prim->arv));
    Arv* arv_dir = retiraListaArv(l, retornaByteArv(l->prim->arv));
    int soma_frequencias = retornaFrequenciaArv(arv_esq) + retornaFrequenciaArv(arv_dir);
    Arv* raiz = arv_cria('\0', soma_frequencias, arv_esq, arv_dir);
    insereOrdenadoListaArv(l, raiz);

    return transformaListaEmArv(l);
}

void imprimeLista(tListaArv* l){
    tNode* p = l->prim;

    while(p != NULL){
        printf("Byte: %c apareceu %d vezes\n", retornaByteArv(p->arv), retornaFrequenciaArv(p->arv));
        p = p->prox;
    }
}

void liberaListaArv(tListaArv* l){
    if(l != NULL){
        tNode* p = l->prim;
        while(p != NULL){
            tNode* aux = p->prox;
            arv_libera(p->arv);
            free(p);
            p = aux;
        }
        free(l);
        l = NULL;
    }
}


Arv *retornaArvoreListaArv(tListaArv* l, int idx){
    if (l == NULL || l->prim == NULL || idx < 0) {
        return NULL;
    }

    tNode* atual = l->prim;
    int contador = 0;

    while (atual != NULL && contador < idx) {
        atual = atual->prox;
        contador++;
    }

    if (atual == NULL) {
        return NULL;
    }

    return atual->arv;
}

