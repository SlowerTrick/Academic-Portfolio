/*
 arvore.c
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#include "arvore.h"

struct arvore{
	unsigned char dado;//Nosso byte
	int frequencia;
	Arv* esq;
	Arv* dir;
};

//Cria uma árvore vazia
Arv* arv_criavazia(void){
	return NULL;
}

//cria uma árvore com a informação do nó raiz (dado), e com subárvore esquerda e e subárvore direita d
Arv* arv_cria (unsigned char dado, int freq, Arv* e, Arv* d){
	Arv* raiz = arv_criavazia();

	raiz = malloc(sizeof(*raiz));
	 
	raiz->esq = e;
	raiz->dir = d;
	raiz->dado = dado;
	raiz->frequencia = freq;

	return raiz;
}


//Essa funcao faria uma arvore degenerada, o que nao queremos
Arv* insereNode(Arv* raiz, unsigned char data, int frq){
	if(raiz == NULL){//Entao a arvore esta vazia
		arv_cria(data, frq, NULL, NULL);
	}

	if(raiz->esq == NULL){
		raiz->esq = insereNode(raiz->esq, data, frq);
	}else if(raiz->dir == NULL){
		raiz->dir = insereNode(raiz->dir, data, frq);
	}else{
		insereNode(raiz->esq, data, frq);
	}

	return raiz;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a){
	if(!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
		a = NULL;
	}
	
	return NULL;	
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a){
	return a == NULL;
}

int comparaDado(unsigned char arv_dado, unsigned char key){
	return arv_dado == key;//Compara o char na tabela ASCII com uma chave
}

//indica a ocorrência (1) ou não (0) (pela chave de busca)
int arv_pertence(Arv* a, unsigned char key){
	if(arv_vazia(a)){
		return 0;
	}else{
		return comparaDado(a->dado, key) || arv_pertence(a->esq, key) || arv_pertence(a->dir, key); 
	}
}

//imprime as informações dos nós da árvore
void arv_imprime(Arv* a){
	if(!arv_vazia(a)){
		printf("< ");
		printf("%c", a->dado);
		arv_imprime(a->esq);
		arv_imprime(a->dir);
		printf(" >");			
	}else{
		printf(" <> ");
	}

}

//retorna a mãe/pai de um dado no
Arv* arv_pai(Arv* a, unsigned char key){
	if(arv_vazia(a)){
		return NULL;
	}

	if(comparaDado(a->esq->dado, key) || comparaDado(a->dir->dado, key)){
		return a;
	}

	Arv* arvore = arv_pai(a->esq, key);
	
	if(arvore)
		return arvore;
	


	return arv_pai(a->dir, key);
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a){
	int cont = 0;

	if(arv_vazia(a)){
		return 0;
	}

	if(arv_vazia(a->esq) && arv_vazia(a->dir)){
		return 1;
	}else{
		cont += folhas(a->esq);
		cont += folhas(a->dir);
	}


	return cont;
}

//retorna o numero de ocorrencias de um dado na árvore
int ocorrencias(Arv* a, unsigned char key){
	int cont = 0;

	if(arv_vazia(a)){
		return 0;
	}else{
		if(comparaDado(a->dado, key))
			cont += 1;
		cont += arv_pertence(a->esq, key);
		cont += arv_pertence(a->dir, key); 
	}

	return cont;
}

static int maxH(int a, int b){
	return (a > b) ? a : b;
}
//retorna a altura da árvore a
int altura(Arv* a){
	if(arv_vazia(a)){
		return -1;
	}else{
		return 1 + maxH(altura(a->esq), altura(a->dir));
	}
}

unsigned char retornaByteArv(Arv* arv){
	return arv->dado;
}

int retornaFrequenciaArv(Arv* arv){
	return arv->frequencia;
}

// Funcoes novas

Arv *retornaEsqArv(Arv *arv)
{
	if(arv)
		return arv->esq;
	return NULL;
}

Arv *retornaDirArv(Arv *arv)
{
	if(arv)
		return arv->dir;
	return NULL;
}

int ehFolhaArv(Arv *arv)
{
	return (arv != NULL) &&
		   arv_vazia(arv->esq) &&
		   arv_vazia(arv->dir);
}

// Fim das funcoes novas