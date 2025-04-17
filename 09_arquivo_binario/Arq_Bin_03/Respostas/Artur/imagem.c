#include "imagem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tImagem {
    void **mapa;  // Matriz de pixels
    int linhas;
    int colunas;
    Tipo tipo;
    int bytes_lidos;
};

Imagem *LerImagem(const char *caminho) {
    FILE *arquivo = fopen(caminho, "rb");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }
    
    Imagem *img = (Imagem *)malloc(sizeof(Imagem));
    if (!img) {
        perror("Erro ao alocar memória para a imagem");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }
    
    fread(&img->linhas, sizeof(int), 1, arquivo);
    fread(&img->colunas, sizeof(int), 1, arquivo);
    
    img->mapa = (void **)malloc(img->linhas * sizeof(void *));
    for (int i = 0; i < img->linhas; i++) {
        img->mapa[i] = (float *)malloc(img->colunas * sizeof(float));
    }
    
    int bytes_lidos = 2 * sizeof(int); // Conta os bytes do cabeçalho
    for (int i = 0; i < img->linhas; i++) {
        bytes_lidos += fread(img->mapa[i], sizeof(float), img->colunas, arquivo) * sizeof(float);
    }
    
    img->bytes_lidos = bytes_lidos;
    fclose(arquivo);
    return img;
}

void DestruirImagem(Imagem *img) {
    if (img) {
        for (int i = 0; i < img->linhas; i++) {
            free(img->mapa[i]);
        }
        free(img->mapa);
        free(img);
    }
}

int ObterNumeroBytesLidos(Imagem *img) {
    return img ? img->bytes_lidos : 0;
}

void ImprimirImagem(Imagem *img) {
    if (!img) return;
    printf("Numero de bytes lidos: %d\n", img->bytes_lidos);
    for (int i = 0; i < img->linhas; i++) {
        for (int j = 0; j < img->colunas; j++) {
            printf("%.2f ", ((float *)img->mapa[i])[j]);
        }
        printf("\n");
    }
}
