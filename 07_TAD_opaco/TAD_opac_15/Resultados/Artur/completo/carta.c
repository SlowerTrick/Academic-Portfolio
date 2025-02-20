#include "carta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carta
{
    int id;
    char nome[MAX_NOME];
    int poder_magia;
    int poder_forca;
    int poder_fogo;
    int num_vitorias;
};


/**
 * @brief Lê uma carta do usuário e retorna um ponteiro para ela.
 * @return Retorna um ponteiro para a carta lida.
 */
tCarta LeCarta()
{
    tCarta c = malloc(sizeof(*c));
    scanf(" %d %100[^\n] %d %d %d%*c", &c->id, c->nome, &c->poder_magia, &c->poder_forca, &c->poder_fogo);
    c->num_vitorias = 0;
    return c;
}

/**
 * @brief Libera a memória alocada para uma carta.
 * @param c Ponteiro para a carta a ser liberada.
 */
void LiberaCarta(tCarta c)
{
    if(c)
        free(c);
    c = NULL;
}

/**
 * @brief Imprime as informações de uma carta.
 * @param c Ponteiro para a carta a ser impressa.
 */
void ImprimeCarta(tCarta c)
{

}

/**
 * @brief Retorna o ID de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o ID da carta.
 */
int GetIdCarta(tCarta c)
{
    return c->id;
}

/**
 * @brief Retorna o nome de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o nome da carta.
 */
char * GetNomeCarta(tCarta c)
{
    return c->nome;
}

/**
 * @brief Retorna o número de vitórias de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o número de vitórias da carta.
 */
int GetNumVitCarta(tCarta c)
{
    return c->num_vitorias;
}

/**
 * @brief Retorna o valor de magia de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de magia da carta.
 */
int GetMagiaCarta(tCarta c)
{
    return c->poder_magia;
}

/**
 * @brief Retorna o valor de ataque de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de ataque da carta.
 */
int GetAtaqueCarta(tCarta c)
{
    return c->poder_forca;
}

/**
 * @brief Retorna o valor de fogo de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de fogo da carta.
 */
int GetFogoCarta(tCarta c)
{
    return c->poder_fogo;
}

/**
 * @brief Verifica se uma carta é válida.
 * @param c Ponteiro para a carta.
 * @return Retorna true se a carta é válida e false caso contrário.
 */
bool EhCartaValida(tCarta c)
{
    int poder_total = c->poder_fogo + c->poder_forca + c->poder_magia;
    return (strlen(c->nome) <= 50 && c->poder_fogo <= 30 && c->poder_magia <= 30 && c->poder_forca <= 30 && poder_total <= 80);
}

/**
 * @brief Verifica se duas cartas possuem o mesmo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna true se as cartas possuem o mesmo ID e false caso contrário.
 */
bool EhMesmoIdCarta(tCarta c1, tCarta c2)
{
    return c1->id == c2->id;
}

/**
 * @brief Compara duas cartas pelo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaIdCarta(tCarta c1, tCarta c2)
{
    if(c1->id != c2->id)
        return (c1->id < c2->id) ? -1 : 1;
    return 0;
}

/**
 * @brief Compara duas cartas pelo valor de magia.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaMagiaCarta(tCarta c1, tCarta c2)
{
    if(EhCartaValida(c1) && EhCartaValida(c2))
        if(c1->poder_magia != c2->poder_magia)
            return (c1->poder_magia < c2->poder_magia) ? -1 : 1;
    return 0;
}

/**
 * @brief Compara duas cartas pelo valor de ataque.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaAtaqueCarta(tCarta c1, tCarta c2)
{
    if(EhCartaValida(c1) && EhCartaValida(c2))
        if(c1->poder_forca != c2->poder_forca)
            return (c1->poder_forca < c2->poder_forca) ? -1 : 1;
    return 0;
}

/**
 * @brief Compara duas cartas pelo valor de fogo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaFogoCarta(tCarta c1, tCarta c2)
{
    if(EhCartaValida(c1) && EhCartaValida(c2))
        if(c1->poder_fogo != c2->poder_fogo)
            return (c1->poder_fogo < c2->poder_fogo) ? -1 : 1;
    return 0;
}

/**
 * @brief Adiciona uma vitória para uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o novo número de vitórias da carta.
 */
int AdicionaVitoriaCarta(tCarta c)
{
    return ++c->num_vitorias;
}
