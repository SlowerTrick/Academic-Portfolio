#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario()
{
    tUsuario *u = malloc(sizeof(tUsuario));
    if(!u)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    return u;
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user)
{
    free(user);
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user)
{
    scanf(" %s %s", user->nome, user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user)
{
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}
