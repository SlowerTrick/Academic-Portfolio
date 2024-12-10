#include "jogo.h"
#include <stdio.h>
/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo()
{
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);
    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
/* void ComecaJogo(tJogo jogo)
{
    return;
} */

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo)
{
    if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro))
    {
        printf("Sem vencedor!\n");
        return 1;
    }
    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    printf("Jogar novamente? (s,n)\n");
    char escolha;
    do
    {
        scanf("%c", &escolha);
    }
    while (escolha != 's' && escolha != 'n');
    return escolha == 's' ? 1 : 0;
}