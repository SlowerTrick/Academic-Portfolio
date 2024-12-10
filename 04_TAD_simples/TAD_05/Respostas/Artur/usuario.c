#include "usuario.h"
#include <stdio.h>
#include <string.h>

tUsuario CriaUsuario(char nome[20], char cpf[15])
{
    tUsuario usuario;
    strncpy(usuario.nome, nome, 50);
    strncpy(usuario.cpf, cpf, 15);
    return usuario;
}

void ImprimeUsuario(tUsuario user)
{
    printf("Nome: %s\nCPF: %s\n\n", user.nome, user.cpf);
    return;
}