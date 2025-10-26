#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movel
{
    char nome[30];
};


/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome)
{
    tMovel *movel = malloc(sizeof(*movel));
    strcpy(movel->nome, nome);
    return movel;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m)
{
    if(m)
        free(m);
    m = NULL;
}

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel()
{
    tMovel *movel = malloc(sizeof(*movel));
    scanf("%s%*c", movel->nome);
    return movel;
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m)
{
    printf("%s\n",m->nome);
}
