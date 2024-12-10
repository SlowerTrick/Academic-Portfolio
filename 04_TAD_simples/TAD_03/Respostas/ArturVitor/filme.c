#include "filme.h"
#include <string.h>
#include <stdio.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade)
{
    tFilme filme;
    filme.codigo = codigo;
    strncpy(filme.nome, nome, 20);
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    return filme;
}

tFilme leFilme(int codigo)
{
    char nome[20];
    int valor, quantidade;
    scanf(" %20[^,],%d,%d", nome, &valor, &quantidade);
    tFilme filme = criarFilme(nome, codigo, valor, quantidade);
    return filme;
}

int obterCodigoFilme (tFilme filme)
{
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme)
{
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme)
{
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme)
{
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme)
{
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo)
{
    return filme.codigo == codigo;
}

tFilme alugarFilme (tFilme filme)
{
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

tFilme devolverFilme (tFilme filme)
{
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2)
{
    if (strncmp(filme1.nome, filme2.nome, 20) == 0)
        return 0;
    else if (strlen(filme1.nome) < strlen(filme2.nome))
        return -1;
    return 1;
}