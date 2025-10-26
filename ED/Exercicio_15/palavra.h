#pragma once

typedef struct palavra Palavra;

Palavra *cria_palavra(char *palavra);
int retorna_frequencia_palavra(Palavra *p);
void incrementa_frequencia_palavra(Palavra *p);
char *retorna_palavra(Palavra *p);
void libera_palavra(Palavra *p);
