#include "Gato.h"
#include "Cachorro.h"
#include "BanhoTosa.h"
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Gato *gato = inicGato("Enzo", BRAVO);
    Cachorro *cachorro = inicCachorro("Eduardo", MANSO);
    Lista *lista = cria_lista();
    adiciona_elemento_lista(lista, gato,  GATO);
    adiciona_elemento_lista(lista, cachorro, CACHORRO);
    imprime_lista(lista);
    /* libera_lista(lista); */
    free(gato);
    free(cachorro);
    return 0;
}
