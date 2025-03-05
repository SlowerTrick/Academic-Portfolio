#ifndef _ATORES_H
#define _ATORES_H

typedef void (*func_ptr_desaloca)(void *dado);
typedef void (*func_ptr_notifica)(void *dado);
typedef void *(*func_ptr_adiciona)(void *dado);
typedef int (*func_ptr_compara_caracteristica)(void *dado, char *caracteristica);
typedef int (*func_ptr_compara_ranking)(void *dado1, void *dado2);
typedef int (*func_ptr_calcula_caracteristica)(void *dado);

typedef struct Atores Atores;

Atores *criaAtores(func_ptr_notifica notifica, func_ptr_desaloca desaloca);
void desalocaAtores(Atores *a);
void insereAtor(Atores *a, void *dado);
int getQtdAtores(Atores *a);
int getMediaCaracteristicaAtores(Atores *a, func_ptr_calcula_caracteristica calcula_caracteristica);
void *getElementoCaracteristica(Atores *a, char *caracteristica, func_ptr_compara_caracteristica compara);
void *getAtorNaFila(Atores *a, int i);
void notificaAtores(Atores *a);
void notificaRankingAtores(Atores *a, func_ptr_compara_ranking compara);

#endif
