#pragma once

typedef struct arvore Arvore;

Arvore *cria_arvore();
Arvore *insere_arvore(Arvore *a, char *palavra);
int busca_arvore(Arvore *a, char *palavra);
int total_elementos_arvore(Arvore *a);
int total_elementos_unicos_arvore(Arvore *a);
char *elemento_mais_frequente_arvore(Arvore *a, int *qtd_repeticoes);
void preenche_vetor_arvore(Arvore *a, char **vet, int size_vet);
int ocorrencias_arvore(Arvore *a, char *palavra);
void imprime_arvore(Arvore *a);
void libera_arvore(Arvore *a);
