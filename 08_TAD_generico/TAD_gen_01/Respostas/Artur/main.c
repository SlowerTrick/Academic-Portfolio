#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int tipo, qtd_elementos;
    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");
    scanf("%d %d%*c", &tipo, &qtd_elementos);
    tGeneric *generico = (tipo == INT) ? CriaGenerico(INT, qtd_elementos) : CriaGenerico(FLOAT, qtd_elementos);
    LeGenerico(generico);
    ImprimeGenerico(generico);
    DestroiGenerico(generico);
}