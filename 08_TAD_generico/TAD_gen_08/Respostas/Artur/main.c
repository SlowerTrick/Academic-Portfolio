#include "fila.h"
#include "vector.h"
#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DestroiMovelMain(void *m);

int main(void)
{
    int total_operacoes, item_atual = 0;
    scanf("%d%*c", &total_operacoes);
    Fila *fila = FilaConstruct();

    for(int i = 0; i < total_operacoes; i++)
    {
        char operacao[100];
        scanf("%s ", operacao);

        if(strcmp(operacao, "ENTRADA") == 0)
        {
            tMovel *movel = LeMovel();
            FilaPush(fila, movel);
        }
        else if(strcmp(operacao, "PRODUZIR") == 0)
        {
            tMovel *movel = FilaPop(fila);
            ImprimeMovel(movel);
            DestroiMovel(movel);
        }
    }
    FilaDestroy(fila, DestroiMovelMain);
    return 0;
}

void DestroiMovelMain(void *m)
{
    tMovel *movel = (tMovel *) m;
    if(m)
        free(m);
    m = NULL;
}