#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brasileirao.h"

int main(void)
{
    BRA *campeonato = CriaCamp();
    RealizaCamp(campeonato);
    FinalizaCamp(campeonato);
    return 0;
}