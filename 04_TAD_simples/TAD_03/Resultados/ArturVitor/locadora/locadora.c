#include "locadora.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

tLocadora criarLocadora ()
{
    tLocadora locadora;
    locadora.numFilmes = 0;
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo)
{
    for(int i = 0; i < locadora.numFilmes; i++)
    {
        if(obterCodigoFilme(locadora.filme[i]) == codigo)
            return 1;
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme)
{
    if (!verificarFilmeCadastrado(locadora, obterCodigoFilme(filme)))
    {
        locadora.filme[locadora.numFilmes++] = filme;
        printf("Filme cadastrado %d - ", filme.codigo);
        imprimirNomeFilme(filme);
        printf("\n");
        return locadora;
    }
    printf ("Filme ja cadastrado no estoque\n");
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora)
{
    while(1)
    {
        char c;
        scanf(" %c", &c);
        getchar();
        if (c == '#')
            break;

        int codigo = c - '0';
        tFilme filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
    }
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    int totalAlugados = 0, valor = 0;

    for(int i = 0; i < quantidadeCodigos; i++)
    {
        if (verificarFilmeCadastrado(locadora, codigos[i]))
        {
            for(int j = 0; j < locadora.numFilmes; j++)
            {
                if (ehMesmoCodigoFilme (locadora.filme[j], codigos[i]))
                {
                    if(obterQtdEstoqueFilme(locadora.filme[j]) > 0)
                    {
                        locadora.filme[j] = alugarFilme(locadora.filme[j]);
                        totalAlugados++;
                        valor += obterValorFilme(locadora.filme[j]);
                    }
                    else
                    {
                        printf("Filme %d  - ", obterCodigoFilme(locadora.filme[j]));
                        imprimirNomeFilme(locadora.filme[j]);
                        printf("  nao  disponivel  no  estoque.  Volte  mais tarde.");
                    }
                    break;
                }
            }
        }
        else
        {
            printf("Filme  %d  nao  cadastrado\n", codigos[i]);
        }
    }
    printf("Total de filmes alugados: %d com custo de R$%d\n", totalAlugados, valor);
    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora)
{
    int quantidadeCodigos = 0;
    int codigos[MAX_FILMES];
    while(1)
    {
        char c;
        scanf(" %c", &c);
        if (c == '#')
            break;

        int codigo = c - '0';
        codigos[quantidadeCodigos++] = codigo;
    }
    printf("\n"); 
    locadora = alugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    for(int i = 0; i < quantidadeCodigos; i++)
    {
        if (verificarFilmeCadastrado(locadora, codigos[i]))
        {
            for(int j = 0; j < locadora.numFilmes; j++)
            {
                if (ehMesmoCodigoFilme (locadora.filme[j], codigos[i]))
                {
                    if(obterQtdAlugadaFilme(locadora.filme[j]) > 0)
                    {
                        locadora.filme[j] = devolverFilme(locadora.filme[j]);
                        locadora.lucro += obterValorFilme(locadora.filme[j]);
                        printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                        imprimirNomeFilme(locadora.filme[j]);
                        printf(" Devolvido!\n");
                    }
                    else
                    {
                        printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[j]));
                        imprimirNomeFilme(locadora.filme[j]);
                    }
                    break;
                }
            }
        }
        else
        {
            printf("Filme  %d  nao  cadastrado\n", codigos[i]);
        }
    }
    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora)
{
    int quantidadeCodigos = 0;
    int codigos[MAX_FILMES];
    while(1)
    {
        char c;
        scanf(" %c", &c);
        if (c == '#')
            break;

        int codigo = c - '0';
        codigos[quantidadeCodigos++] = codigo;
    }
    printf("\n"); 
    locadora = devolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
    return locadora;
}

tLocadora ordenarFilmesLocadora(tLocadora locadora) 
{
    for (int i = 0; i < locadora.numFilmes - 1; i++) 
    {
        for (int j = i + 1; j < locadora.numFilmes; j++) 
        {
            if (strcasecmp(locadora.filme[i].nome, locadora.filme[j].nome) > 0) {
                tFilme temp = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = temp;
            }
        }
    }
    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora)
{
    locadora = ordenarFilmesLocadora (locadora);

    printf("\n~ESTOQUE~\n");
    for(int i = 0; i < locadora.numFilmes; i++)
    {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

void consultarLucroLocadora (tLocadora locadora)
{
    if(locadora.lucro > 0)
        printf("\nLucro total R$%d\n", locadora.lucro);
    return;
}
