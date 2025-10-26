#include "utils_char2.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *vetor = CriaVetorTamPadrao();
    int tamanho = TAM_PADRAO;
    vetor = LeVetor(vetor, &tamanho);
    ImprimeString(vetor);
    LiberaVetor(vetor);
}