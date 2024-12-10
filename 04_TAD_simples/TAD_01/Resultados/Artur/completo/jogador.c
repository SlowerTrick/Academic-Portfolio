#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

/**
 * Recebe um jogador e um tabuleiro.posicoes e retorna o tabuleiro.posicoes com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro.posicoes atual.
 * 
 * @return o tabuleiro.posicoes atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;
    do
    {
        printf("Jogador %d\nDigite uma posicao (x e y):\n", jogador.id);
        jogada = LeJogada();
        if (!EhPosicaoValidaTabuleiro(jogada.x, jogada.y))
        {
            jogada.sucesso = 0;
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            continue;
        }
        if (!EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y))
        {
            jogada.sucesso = 0;
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }
    } 
    while (!FoiJogadaBemSucedida(jogada));

    printf("Jogada [%d,%d]!\n", jogada.x, jogada.y);
    if (jogador.id == 1)
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, tabuleiro.peca1, jogada.x, jogada.y);
    else
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, tabuleiro.peca2, jogada.x, jogada.y);
    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro.posicoes e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro.posicoes o tabuleiro.posicoes atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    char peca = tabuleiro.peca1;
    if (jogador.id == 2)
        peca = tabuleiro.peca2;
    for (int i = 0; i < 3; i++) 
    {
        if (tabuleiro.posicoes[i][0] == peca && 
            tabuleiro.posicoes[i][1] == peca && 
            tabuleiro.posicoes[i][2] == peca) { 
                printf("JOGADOR %d Venceu!\n", jogador.id);
                return 1;
        }
    }

    for (int i = 0; i < 3; i++) 
    {
        if (tabuleiro.posicoes[0][i] == peca && 
            tabuleiro.posicoes[1][i] == peca && 
            tabuleiro.posicoes[2][i] == peca) {
                printf("JOGADOR %d Venceu!\n", jogador.id);
                return 1;
        }
    }

    if (tabuleiro.posicoes[0][0] == peca && 
        tabuleiro.posicoes[1][1] == peca && 
        tabuleiro.posicoes[2][2] == peca) {
            printf("JOGADOR %d Venceu!\n", jogador.id);
            return 1;
    }

    if (tabuleiro.posicoes[0][2] == peca && 
        tabuleiro.posicoes[1][1] == peca && 
        tabuleiro.posicoes[2][0] == peca) {
            printf("JOGADOR %d Venceu!\n", jogador.id);
            return 1;
    }
    return 0;
}
