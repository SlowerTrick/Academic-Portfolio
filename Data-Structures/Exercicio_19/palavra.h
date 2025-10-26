#pragma once

typedef struct palavra Palavra;

Palavra *cria_palavra(char *palavra);
int retorna_frequencia_palavra(void *p);
void incrementa_frequencia_palavra(Palavra *p);
char *retorna_palavra(Palavra *p);
void imprime_palavra(void *p);
int soma_caracter_palavra(void *p);
void insere_palavra_lista(void *p, void *nova);
void *busca_palavra_lista(void *p, void *key);
int total_palavras_lista(void *p);

void libera_palavra(void *p);
void adiciona_vetor_palavra(Palavra **vet, int count, Palavra *p);
