/*
 descompacta.c
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#include "descompactador.h"
#include <string.h>

int main(int argc, char *argv[])
{
    // Verificacao e abertura do arquivo desejado
    check(argc >= 2, "Insira algum parâmetro para rodar o programa");

    FILE *entrada = fopen(argv[1], "rb");
    char message[256];
    snprintf(message, sizeof(message), "Erro ao abrir o arquivo: %s", argv[1]);
    check(entrada != NULL, message);

    Descompactador *decompactador = criaDescompactador();
    leBinarioDescompactador(decompactador, entrada);

    char *nome_original = geraNomeArquivoOriginal(argv[1]);
    FILE *saida = fopen(nome_original, "w");
    free(nome_original);
    if (!saida)
    {
        printf("Erro ao abrir o arquivo de saida!\n");
        exit(1);
    }
    descompactaArquivo(decompactador, saida);

    fclose(entrada);
    fclose(saida);
    liberaDescompactador(decompactador);
}