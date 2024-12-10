#include "jogo.h"
#include <stdio.h>

int main(void)
{
    tJogo jogo = CriaJogo();
    int gameManager = 0;
    while (1)
    {   
        if (gameManager % 2 == 0)
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        else
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if (VenceuJogador(jogo.jogador1, jogo.tabuleiro) || VenceuJogador(jogo.jogador2, jogo.tabuleiro))
        {
            if (ContinuaJogo())
            {
                gameManager = 0;
                jogo = CriaJogo();
                continue;
            }
            break;
        }
        else if (AcabouJogo(jogo))
        {
            if (ContinuaJogo())
            {
                gameManager = 0;
                jogo = CriaJogo();
                continue;
            }
            break;
        }
        gameManager++;
    }
    return 0;
}