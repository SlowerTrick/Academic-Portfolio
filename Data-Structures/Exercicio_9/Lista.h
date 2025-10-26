#ifndef Lista_h
#define Lista_h

#define VEGANA 1
#define N_VEGANA 2

typedef struct lista Lista;

Lista *criaLista();
void adicionaLista(Lista *l, void *dado, int tipo);
void *obtemLista(Lista *l, char *nome);
void removeLista(Lista *l, char *nome);
float calculaValorLista(Lista *l);
int obtemTotalElementosLista(Lista *l);
int obtemTotalVeganosElementosLista(Lista *l);
int obtemTotalNVeganosElementosLista(Lista *l);
void imprimeLista(Lista *l);
void liberaLista(Lista *l);

#endif