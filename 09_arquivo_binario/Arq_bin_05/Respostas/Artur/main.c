#include "estabelecimento.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    tEstabelecimento *estabelecimento = CriaEstabelecimento();
    LeEstabelecimento(estabelecimento);
    ImprimeProdutosEmFaltaEstabelecimento(estabelecimento);
    DestroiEstabelecimento(estabelecimento);
    return 0;
}