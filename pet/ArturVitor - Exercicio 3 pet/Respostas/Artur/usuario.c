#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria um usuario.
 * @param nome nome do usuario.
 * @param cpf cpf do usuario.
 * @return Usuario criado.
 */
Usuario* CriaUsuario(char* nome, int cpf)
{
    Usuario *u = malloc(sizeof(Usuario));
    u->cpf = cpf;
    u->nome = malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(u->nome, nome);
    return u;
}

/**
 * @brief Retorna o nome de um usuario.
 * @param usuario  um usuario.
 * @return nome do usuario.
 */
char* RecuperaNomeUsuario(Usuario* usuario)
{
    return usuario->nome;
}

/**
 * @brief Retorna o cpf de um usuario.
 * @param usuario  um usuario.
 * @return cpf do usuario.
 */
int RecuperaCpfUsuario(Usuario* usuario)
{
    return usuario->cpf;
}   

/**
 * @brief Destroi um usuario.
 * @param usuario  um usuario.
 */
void DestroiUsuario(Usuario* usuario)
{
    if(usuario)
    {
        free(usuario->nome);
        usuario->nome = NULL;
        free(usuario);
    }
    usuario = NULL;
}