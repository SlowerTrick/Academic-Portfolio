#include "duelo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct duelo
{
    int id;
    int id_c1;
    int id_c2;
    int diff_pontos;
    bool desempate;
    char atributo;
};


/**
 * @brief Lê um duelo do usuário.
 * @return Retorna um ponteiro para o duelo lido.
 */
tDuelo LeDuelo()
{
    tDuelo d = malloc(sizeof(*d));
    scanf("%d %d %d %c%*c", &d->id, &d->id_c1, &d->id_c2, &d->atributo);
    d->diff_pontos = 0;
    d->desempate = false;
    return d;
}

/**
 * @brief Libera a memória alocada para um duelo.
 * @param d Ponteiro para o duelo a ser liberado.
 */
void LiberaDuelo(tDuelo d)
{
    if(d)
        free(d);
    d = NULL;
}

/**
 * @brief Imprime as informações de um duelo.
 * @param d Ponteiro para o duelo a ser impresso.
 */
void ImprimeDuelo(tDuelo d)
{
    printf("%d %d %d %d %d %c\n\n", d->id, d->id_c1, d->id_c2, d->diff_pontos, d->desempate, d->atributo);
}

/**
 * @brief Realiza um duelo entre duas cartas.
 * @param d Ponteiro para o duelo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 */
void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2)
{
    if(EhCartaValida(c1) && EhCartaValida(c2))
    {
        int resultado = 0;
        d->diff_pontos = 0;

        if(d->atributo == 'M')
        {
            resultado = ComparaMagiaCarta(c1, c2);
            d->diff_pontos = abs(GetMagiaCarta(c1) - GetMagiaCarta(c2));
        }
        else if(d->atributo == 'F')
        {
            resultado = ComparaAtaqueCarta(c1, c2);
            d->diff_pontos = abs(GetAtaqueCarta(c1) - GetAtaqueCarta(c2));
        }
        else if(d->atributo == 'G')
        {
            resultado = ComparaFogoCarta(c1, c2);
            d->diff_pontos = abs(GetFogoCarta(c1) - GetFogoCarta(c2));
        }
    
        if(resultado == 0)
            d->desempate = true;
    }
}

/**
 * @brief Retorna o ID da primeira carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da primeira carta do duelo.
 */
int GetC1Duelo(tDuelo d)
{
    return d->id_c1;
}

/**
 * @brief Retorna o ID da segunda carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da segunda carta do duelo.
 */
int GetC2Duelo(tDuelo d)
{
    return d->id_c2;
}

/**
 * @brief Retorna se houve desempate no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna true se houve desempate e false caso contrário.
 */
bool GetDesempateDuelo(tDuelo d)
{
    return d->desempate;
}

/**
 * @brief Retorna a diferença de pontos entre as cartas no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna a diferença de pontos entre as cartas no duelo.
 */
int GetDiferencaDuelo(tDuelo d)
{
    return d->diff_pontos;
}

/**
 * @brief Retorna o ID do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID do duelo.
 */
int GetIdDuelo(tDuelo d)
{
    return d->id;
}
