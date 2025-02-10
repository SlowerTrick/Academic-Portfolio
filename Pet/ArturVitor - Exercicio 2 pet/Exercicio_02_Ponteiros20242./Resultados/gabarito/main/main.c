#include <stdio.h>
#include "prisao.h"

int main(){
    char nome[MAXTAM_NOME];
    int nCelas, capacidadeCelas;

    scanf("%[^\n]%*c",nome);
    scanf("%d %d%*c", &nCelas, &capacidadeCelas);

    tPrisao p = criaPrisao(nome,nCelas,capacidadeCelas);

    executaPrisao(&p);

    return 0;
}