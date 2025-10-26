
#include <stdio.h>
#include "fila.h"
#include "amostra.h"

int main(int argc, const char * argv[]) 
{
    Fila *f = cria_fila();
    Amostra *a1 = inicAmostra("a1", 1);
    Amostra *a2 = inicAmostra("a2", 2);
    Amostra *a3 = inicAmostra("a3", 60);

    insere_fila(f, a1);
    insere_fila(f, a2);
    insere_fila(f, a3);

    /* for(int i = 0; i < 3; i++)
        remove_elemento_fila(f); */

    imprime_fila(f);

    libera_fila(f);
    liberaAmostra(a1);
    liberaAmostra(a2);
    liberaAmostra(a3);
    return 0;
}
