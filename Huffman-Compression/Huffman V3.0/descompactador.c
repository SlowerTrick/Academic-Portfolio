/*
 descompactador.c
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#include "descompactador.h"
#include "bitmap.h"
#include "utils.h"

// Funções auxiliares internas
static int leBit(unsigned char *buffer, int *pos);
static unsigned char leByte(unsigned char *buffer, int *pos);

/**
 * @brief Desserializa a árvore, remontando ela
 * Pre_condicao: Ponteiros válido
 * Pos_condicao: Arvore montada
 * 
 * @param buffer 
 * @param pos 
 * @return Ponteiro para Estrutura do tipo Árvore
 */
static Arv *desserializaArvore(unsigned char *buffer, int *pos);

/**
 * @brief Preenche o bitmap com a codificação do arquivo.
 * Pre_condicao: Arquivo deve estar aberto.
 * Pos_condicao: Bitmap é preenchido com a sequência de bits do arquivo.
 * 
 * @param d Ponteiro para Descompactador.
 * @param arquivo Arquivo de entrada aberto.
 */
static void preencheBitmapDescompactador(Descompactador *d, FILE *arquivo);

struct descompactador
{
    Arv *arvore;
    bitmap *bm;
};

Descompactador *criaDescompactador()
{
    Descompactador *d = malloc(sizeof(*d));
    check_memory(d);
    d->arvore = NULL;
    d->bm = NULL;

    return d;
}

void liberaDescompactador(Descompactador *d)
{
    if(d)
    {
        arv_libera(d->arvore);
        if(d->bm)
            bitmapLibera(d->bm);
        free(d);
    }
}

void leBinarioDescompactador(Descompactador *d, FILE *arquivo)
{
    if(!d || !arquivo) return;

    int tam_arvore;
    fread(&tam_arvore, sizeof(int), 1, arquivo);

    unsigned char *buffer = malloc((tam_arvore + 7) / 8);
    check_memory(buffer);
    fread(buffer, 1, (tam_arvore + 7) / 8, arquivo);

    int pos = 0;
    d->arvore = desserializaArvore(buffer, &pos);
    //imprimeArvoreDesompactador(d->arvore, buffer, (tam_arvore + 7) / 8);

    free(buffer);

    preencheBitmapDescompactador(d, arquivo);
}

void descompactaArquivo(Descompactador* d, FILE* arquivo_normal){
    if(!d || !arquivo_normal){
        return;
    }

    int idx = 0;
    while(1){
        Arv* node = d->arvore;

        //Caminha na arvore ate achar uma folha
        while(!ehFolhaArv(node)){
            if(idx >= bitmapGetLength(d->bm)){ //Protecao contra leitura além do bitmap e o que nos faz sair da funcao (nosso pseudo-caracter)
                return;
            }

            unsigned char bit = bitmapGetBit(d->bm, idx++);
            if(bit == 1){//Caminha para a direita
                node = retornaDirArv(node);
            }else{//Caminha para a esquerda
                node = retornaEsqArv(node);
            }
        }

        unsigned char ch = retornaByteArv(node);

        fwrite(&ch, sizeof(unsigned char), 1, arquivo_normal);
    }
}

static Arv *desserializaArvore(unsigned char *buffer, int *pos)
{
    int bit = leBit(buffer, pos); // Pos eh incrementado aqui
    if (bit == 1)
    {
        unsigned char c = leByte(buffer, pos);
        return arv_cria(c, 0, NULL, NULL); // Cria um no folha da arvore
    } 
    else
    {
        Arv *esq = desserializaArvore(buffer, pos);
        Arv *dir = desserializaArvore(buffer, pos);
        return arv_cria(0, 0, esq, dir); // Cria um no interno da arvore
    }
}

/*
    Auxilio para a leitura bit a bit do buffer
    Fonte de inspiração: https://www.geeksforgeeks.org/c/extract-bits-in-c/
*/
static int leBit(unsigned char *buffer, int *pos)
{
    int byte_idx = *pos / 8;
    int bit_idx  = 7 - (*pos % 8);
    (*pos)++;
    return (buffer[byte_idx] >> bit_idx) & 1;
}

/*
    Montagem do byte a partir da leitura bit a bit com a funcao leBit
    Fonte de inspiração: https://www.geeksforgeeks.org/c/extract-bits-in-c/
*/
static unsigned char leByte(unsigned char *buffer, int *pos)
{
    unsigned char c = 0;
    for (int i = 0; i < 8; i++) 
        c = (c << 1) | leBit(buffer, pos);
    return c;
}

static void preencheBitmapDescompactador(Descompactador *d, FILE *arquivo){
    // Le bitmap
    unsigned int tam;
    fread(&tam, sizeof(unsigned int), 1, arquivo);

    
    d->bm = bitmapInit(tam);
    
    size_t bytes = (tam + 7) / 8;
    unsigned char *dados = calloc(bytes, sizeof(char));
    fread(dados, 1, bytes, arquivo);

    bitmapSetContents(d->bm, tam, dados);
}

// Funcoes de debug
void imprimeArvoreDesompactador(Arv *arvore, unsigned char *buffer, int tamanho_buffer)
{
    if (!buffer || tamanho_buffer <= 0)
    {
        printf("Arvore serializada inexistente ou vazia.\n");
        return;
    }

    printf("Arvore obtida:\n");
    arv_imprime(arvore);
    printf("\n");

    printf("\nTamanho do buffer da arvore: %d bytes\n", tamanho_buffer);
    printf("Buffer serializado da arvore:\n");

    for (int i = 0; i < tamanho_buffer; i++)
    {
        printf("%02x ", buffer[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    if (tamanho_buffer % 16 != 0)
        printf("\n");
    printf("\n");
}