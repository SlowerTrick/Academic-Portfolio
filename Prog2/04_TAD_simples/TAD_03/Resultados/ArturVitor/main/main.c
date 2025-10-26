#include "locadora.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    tLocadora locadora = criarLocadora();

    char operacao[100];
    while (scanf(" %s", operacao) == 1)
    {
        if (strncmp(operacao, "Cadastrar", 100) == 0) {
            locadora = lerCadastroLocadora(locadora);
        }
        else if (strncmp(operacao, "Estoque", 100) == 0) {
            consultarEstoqueLocadora(locadora);
        }
        else if (strncmp(operacao, "Alugar", 100) == 0) {
            locadora = lerAluguelLocadora (locadora);
        }
        else if (strncmp(operacao, "Devolver", 100) == 0) {
            locadora = lerDevolucaoLocadora(locadora);
        }
    }
    consultarLucroLocadora(locadora);
    return 0;
}