#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct tHistograma
{
    Imagem *img;
    int *intervalos;
    int total_intervalos;
    int tamanho_intervalo;
};


/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    Histograma *h = malloc(sizeof(*h));
    h->total_intervalos = nIntervalos;
    h->img = img;
    h->tamanho_intervalo = ceil(256.0 / nIntervalos);
    h->intervalos = malloc(sizeof(int) * h->total_intervalos);
    for(int i = 0; i < h->total_intervalos; i++)
        h->intervalos[i] = h->tamanho_intervalo * (i + 1);
    return h;
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma)
{
    int tipo = ObterTipoImagem(histograma->img);
    int largura = ObterLargura(histograma->img);
    int altura = ObterAltura(histograma->img);
    void *dados_void = ObterDadosImagem(histograma->img);
    int *dados_int = (int *) dados_void;
    float *dados_float = (float *) dados_void;

    if(tipo == INT)
    {
        for(int i = 0; i < histograma->total_intervalos; i++)
        {
            int total = 0;
            for(int j = 0; j < largura * altura; j++)
            {
                int valor = dados_int[j];
                if(i == 0)
                {
                    if(valor >= 0 && valor < histograma->intervalos[i])
                        total++;
                }
                else
                {
                    if(valor >= histograma->intervalos[i-1] && valor < histograma->intervalos[i])
                        total++;
                }
            }
            if(i == 0)
            {
                printf("[0, %d): %d\n", histograma->intervalos[0], total);
            }
            else
            {
                printf("[%d, %d): %d\n", histograma->intervalos[i-1], histograma->intervalos[i], total);
            }
        }
    }
    else if(tipo == FLOAT)
    {
        for(int i = 0; i < histograma->total_intervalos; i++)
        {
            int total = 0;
            for(int j = 0; j < largura * altura; j++)
            {
                int valor = (int) (dados_float[j] * 255);
                if(i == 0)
                {
                    if(valor >= 0 && valor < histograma->intervalos[i])
                        total++;
                }
                else
                {
                    if(valor >= histograma->intervalos[i-1] && valor < histograma->intervalos[i])
                        total++;
                }
            }
            if(i == 0)
            {
                printf("[0, %d): %d\n", histograma->intervalos[0], total);
            }
            else
            {
                printf("[%d, %d): %d\n", histograma->intervalos[i-1], histograma->intervalos[i], total);
            }
        }
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{
    if(histograma)
    {
        //DestruirImagem(histograma->img);
        free(histograma->intervalos);
        free(histograma);
    }
    histograma = NULL;
}
