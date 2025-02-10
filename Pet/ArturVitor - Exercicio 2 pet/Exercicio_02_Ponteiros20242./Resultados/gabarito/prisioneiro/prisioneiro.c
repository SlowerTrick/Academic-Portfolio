#include "prisioneiro.h"

/**
 * @brief Cria o prisioneiro a partir dos parâmetros fornecidos
 * @param nome Nome do prisioneiro
 * @param pena Pena a ser cumprida pelo prisioneiro
*/
tPrisioneiro criaPrisioneiro(char* nome, int pena){
    tPrisioneiro p;

    strcpy(p.nome,nome);
    p.pena = pena;
    p.tempoPassado = 0;
    return p;
}

/**
 * @brief Aumenta o tempo passado do prisioneiro
*/
void passaTempoPrisioneiro(tPrisioneiro* prisioneiro){
    prisioneiro->tempoPassado++;
}

/**
 * @brief Imprime a fuga do prisioneiro na tela e chama a função de desalocação 
*/
void fogePrisioneiro(tPrisioneiro* prisioneiro){
    printf("Detento %s fugiu!\n",prisioneiro->nome);
}

int acabouPenaPrisioneiro(tPrisioneiro* prisioneiro){
    return (prisioneiro->pena == prisioneiro->tempoPassado);
}

/**
 * @brief Imprime a liberação do prisioneiro na tela e chama a função de desalocação 
*/
void liberaPrisioneiroCumpriuPena(tPrisioneiro* prisioneiro){
    printf("Detento %s cumpriu sua pena e foi liberado\n",prisioneiro->nome);
}

void liberaPrisioneiroFimPrograma(tPrisioneiro* prisioneiro){
    printf("Detento %s liberado para finalizar o programa\n",prisioneiro->nome);
}
