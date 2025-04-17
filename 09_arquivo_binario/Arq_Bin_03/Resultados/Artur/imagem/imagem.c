#include "imagem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tImagem
{
    void **mapa;  // Agora é um array bidimensional
    int linhas;
    int colunas;
    Tipo tipo;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e alocá-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho)
{
    Imagem *img = malloc(sizeof(*img));
    if (!img)
    {
        printf("ERRO! Falta de memoria\n");
        exit(1);
    }

    FILE *arquivo = fopen(caminho, "rb");
    if (!arquivo)
    {
        printf("ERRO! Nao foi possivel abrir o arquivo\n");
        free(img);
        exit(1);
    }

    // Lê as dimensões e o tipo da imagem
    fread(&img->linhas, sizeof(int), 1, arquivo);
    fread(&img->colunas, sizeof(int), 1, arquivo);
    fread(&img->tipo, sizeof(int), 1, arquivo);

    // Aloca memória para o array bidimensional
    if (img->tipo == FLOAT)
    {
        img->mapa = malloc(img->linhas * sizeof(float *));
        for (int i = 0; i < img->linhas; i++)
        {
            ((float **)img->mapa)[i] = malloc(img->colunas * sizeof(float));
            fread(((float **)img->mapa)[i], sizeof(float), img->colunas, arquivo);
        }
    }
    else if (img->tipo == INT)
    {
        img->mapa = malloc(img->linhas * sizeof(int *));
        for (int i = 0; i < img->linhas; i++)
        {
            ((int **)img->mapa)[i] = malloc(img->colunas * sizeof(int));
            fread(((int **)img->mapa)[i], sizeof(int), img->colunas, arquivo);
        }
    }

    fclose(arquivo);
    return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{
    if (img)
    {
        if (img->mapa)
        {
            for (int i = 0; i < img->linhas; i++)
            {
                free(((void **)img->mapa)[i]);  // Libera cada linha
            }
            free(img->mapa);  // Libera o array principal
        }
        free(img);
    }
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img)
{
    return img->linhas * img->colunas;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img)
{
    Tipo tipo = img->tipo;

    if (tipo == INT)
    {
        for (int i = 0; i < img->linhas; i++)
        {
            for (int j = 0; j < img->colunas; j++)
            {
                printf("%d ", ((int **)img->mapa)[i][j]);
            }
            printf("\n");
        }
    }
    else if (tipo == FLOAT)
    {
        for (int i = 0; i < img->linhas; i++)
        {
            for (int j = 0; j < img->colunas; j++)
            {
                printf("%.2f ", ((float **)img->mapa)[i][j]);
            }
            printf("\n");
        }
    }
}