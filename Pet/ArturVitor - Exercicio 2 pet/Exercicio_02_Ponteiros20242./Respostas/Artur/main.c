#include "prisao.h"

int main(void)
{
    char nome[MAXTAM_NOME];
    int numero_celas, capacidade;
    scanf("%[^\n]%*c",nome);
    scanf("%d %d%*c", &numero_celas, &capacidade);
    tPrisao prisao = criaPrisao(nome, numero_celas, capacidade);
    executaPrisao(&prisao);
    return 0;
}