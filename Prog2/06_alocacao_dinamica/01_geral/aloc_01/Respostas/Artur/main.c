#include "utils.h"
#include <stdio.h>

int main(void)
{
    int total;
    scanf("%d%*c", &total);

    int *vetor = CriaVetor(total);
    LeVetor(vetor, total);
    printf("%.2f\n", CalculaMedia(vetor, total));
    LiberaVetor(vetor);

    return 0;
}