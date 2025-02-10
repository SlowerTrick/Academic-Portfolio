#include "utils_char2.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *vetor = CriaVetorTamPadrao();
    int tamanho = strlen(vetor);
    LeVetor(vetor, &tamanho);
    ImprimeString(vetor);
    LiberaVetor(vetor);
}