/*
 compacta.c
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/
#include "arvore.h"
#include "listaArvores.h"
#include "utils.h"
#include "compactador.h"

int main(int argc, char *argv[])
{

    // Verificaçao e abertura do arquivo desejado
    check(argc >= 2, "Insira algum parâmetro para rodar o programa");

    FILE *entrada = fopen(argv[1], "rb");
    char message[256];
    snprintf(message, sizeof(message), "Erro ao abrir o arquivo: %s", argv[1]);
    check(entrada != NULL, message);

    // Montagem da tabela de frequancia
    int frequencia[256], n = 256;
    tListaArv *listaArvores = criaListaArv();
    count_frequency(entrada, frequencia, n);
    for (int i = 0; i < n; i++)
    {
        if (frequencia[i] > 0)
        {
            Arv *arv = arv_cria(i, frequencia[i], NULL, NULL);
            insereFinalListaArv(listaArvores, arv);
        }
    }

    // Teste da lista inicial

    // Teste da lista ordenada
    quickSortListaArv(retornaHeadListaArv(listaArvores), retornaTailListaArv(listaArvores));

    // Teste da arvore final
    transformaListaEmArv(listaArvores);

    // Criacao do arquivo compactado
    Arv *arv_huffman = retornaArvoreListaArv(listaArvores, 0); // Funcao nova
    int tam = strlen(argv[1])+10;
    char path[tam];
    snprintf(path, sizeof(path), "%s.comp", argv[1]); 
    FILE *saida = fopen(path, "wb");
    Compactador *compactador = criaCompactador(arv_huffman);

    // Serializacao da arvore (cabecalho)
    serializaArvoreCompactador(compactador);

    // Geracao da tabela de codigos
    geraTabelaCompactador(compactador);
    //imprimeTabelaCompactador(compactador);

    // Geracao do bitmap
    preencheBitmapCompactador(compactador, entrada);

    // Impressao no arquivo (Arvore e bitmap)
    salvaBinarioCompactador(compactador, saida);

    // Finalizacao do programa
    fclose(entrada);
    fclose(saida);
    liberaListaArv(listaArvores);
    liberaCompactador(compactador);

    return 0;
}
