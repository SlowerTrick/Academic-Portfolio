#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gerenciadorpacotes
{
    tPacote **pacotes;
    int qtd_max_pacotes;
    int qtd_atual_pacotes;
};


/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador()
{
    int qtd_incial = 10;
    tGerenciador *g = malloc(sizeof(*g));
    if(!g)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    g->pacotes = malloc(sizeof(tPacote *) * qtd_incial);
    if(!g->pacotes)
    {
        free(g);
        printf("ERRO! falta de memoria");
        exit(1);
    }
    g->qtd_max_pacotes = qtd_incial;
    g->qtd_atual_pacotes = 0;
    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac)
{
    if(++geren->qtd_atual_pacotes >= geren->qtd_max_pacotes)
    {
        geren->qtd_max_pacotes += 10;
        geren->pacotes = realloc(geren->pacotes, sizeof(tPacote *) * geren->qtd_max_pacotes);
        if(!geren->pacotes)
        {
            DestroiGerenciador(geren);
            printf("ERRO! falta de memoria");
            exit(1);
        }
    }
    geren->pacotes[geren->qtd_atual_pacotes-1] = pac;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren)
{
    if(geren)
    {
        if(geren->pacotes)
        {
            for(int i = 0; i < geren->qtd_atual_pacotes; i++)
                DestroiPacote(geren->pacotes[i]);
            free(geren->pacotes);
        }
        geren->pacotes = NULL;
        free(geren);
    }
    geren = NULL;
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx)
{
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren)
{
    for(int i = 0; i < geren->qtd_atual_pacotes; i++)
    {
        ImprimePacote(geren->pacotes[i]);
    }
}
