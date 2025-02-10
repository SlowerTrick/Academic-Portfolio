#include "prisioneiro.h"

/**
 * @brief Cria o prisioneiro a partir dos parâmetros fornecidos
 * @param nome Nome do prisioneiro
 * @param pena Pena a ser cumprida pelo prisioneiro
*/
tPrisioneiro criaPrisioneiro(char* nome, int pena)
{
    tPrisioneiro p;
    strcpy(p.nome, nome);
    p.pena = pena;
    p.tempoPassado = 0;
    return p;
}

/**
 * @brief Aumenta o tempo passado do prisioneiro
*/
void passaTempoPrisioneiro(tPrisioneiro* prisioneiro)
{
    prisioneiro->tempoPassado++;
}

/**
 * @brief Imprime a fuga do prisioneiro na tela e chama a função de desalocação 
*/
void fogePrisioneiro(tPrisioneiro* prisioneiro)
{
    printf("Detento %s fugiu!\n", prisioneiro->nome);
}

/**
 * @brief Retorna 1 quando a pena do prisioneiro termina
*/
int acabouPenaPrisioneiro(tPrisioneiro* prisioneiro)
{
    return prisioneiro->tempoPassado >= prisioneiro->pena;
}

/**
 * @brief Imprime a liberação do prisioneiro na tela
*/
void liberaPrisioneiroCumpriuPena(tPrisioneiro* prisioneiro)
{
    printf("Detento %s cumpriu sua pena e foi liberado\n", prisioneiro->nome);
}

/**
 * @brief Imprime a liberação do prisioneiro na tela para encerrar o programa
*/
void liberaPrisioneiroFimPrograma(tPrisioneiro* prisioneiro)
{
    printf("Detento %s liberado para finalizar o programa\n",prisioneiro->nome);
}
