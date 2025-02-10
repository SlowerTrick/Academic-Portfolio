#include "utils_char.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int tamanho;
    scanf("%d%*c", &tamanho);
    char *vetor = CriaVetor(tamanho);
    ImprimeString(vetor, tamanho);
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);
}