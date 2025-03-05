#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    int altura;
    int largura;
    Tipo tipo;
    void *array;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img)
{
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img)
{
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->array;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo)
{
    Imagem *img = malloc(sizeof(*img));
    img->altura = altura;
    img->largura = largura;
    img->tipo = tipo;
    if (tipo == FLOAT)
        img->array = malloc(altura * largura * sizeof(float));
    else if (tipo == INT)
        img->array = malloc(altura * largura * sizeof(int));
    return img;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem()
{
    int altura, largura, tipo;
    scanf("%d %d %d%*c", &altura, &largura, &tipo);
    Imagem *img = CriarImagem(altura, largura, tipo);
    if(tipo == FLOAT)
    {
        float *dados = (float *) img->array;
        for(int i = 0; i < img->largura * img->altura; i++)
            scanf("%f", &dados[i]); 
    }
    else if(tipo == INT)
    {
        int *dados = (int *) img->array;
        for(int i = 0; i < img->largura * img->altura; i++)
            scanf("%d", &dados[i]); 
    }
    return img;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img)
{

}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img)
{
    if(img)
    {
        free(img->array);
        img->array = NULL;
        free(img);
    }
    img = NULL;
}
