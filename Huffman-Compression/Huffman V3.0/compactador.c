/*
 compactador.c
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#include "compactador.h"

// Funções auxiliares internas

//Retorna o tamanho serializado da arvore
static int tamanhoSerializacaoArvore(Arv *a);

//Escreve apenas um unico bit em um buffer pre-existente
static void escreveBit(unsigned char *buffer, int *pos, int bit);

//Escreve apenas um unico byte em um buffer pre-existente
static void escreveByte(unsigned char *buffer, int *pos, unsigned char b);

/*
    Objetivo: Serializar uma árvore binária em um buffer.
    Parâmetros:
    - Arv *a: ponteiro para a árvore a ser serializada
    - unsigned char *buffer: vetor que armazena os bits/bytes resultantes
    - int pos: posição atual no buffer (em bits) onde escrever
    Retorno: posição atualizada no buffer após a escrita
*/
static int serializaArvoreBuffer(Arv *a, unsigned char *buffer, int pos);

//Funcao auxiliar da tabela
static void gerarCodigos(Arv *a, char **tabela, char *prefixo);

struct compactador
{
    Arv *arvore;
    char **tabela;
    bitmap *bm;
    unsigned char *bufferSerializado;
    int tamanhoBuffer;
};

Compactador *criaCompactador(Arv *arvore)
{
    Compactador *c = malloc(sizeof(*c));
    check_memory(c);

    c->arvore = arvore;
    c->tabela = NULL;
    c->bm = NULL; // sera inicializado posteriormente com o tamanho apropriado
    c->bufferSerializado = NULL;
    c->tamanhoBuffer = 0;

    return c;
}

void liberaCompactador(Compactador *c)
{
    if (c)
    {
        if (c->tabela)
        {
            for (int i = 0; i < TABELA_MAX_SIZE; i++)
                free(c->tabela[i]);
            free(c->tabela);
        }

        if (c->bm)
            bitmapLibera(c->bm);

        free(c->bufferSerializado);
        free(c);
    }
}

void serializaArvoreCompactador(Compactador *c)
{
    if (!c || !c->arvore)
        return;

    int bits = tamanhoSerializacaoArvore(c->arvore);
    c->tamanhoBuffer = (bits + 7) / 8; // converte pra bytes

    c->bufferSerializado = calloc(c->tamanhoBuffer, 1);
    check_memory(c->bufferSerializado);

    serializaArvoreBuffer(c->arvore, c->bufferSerializado, 0);
}

// Funcao auxiliar da compactacao da arvore binaria
static int tamanhoSerializacaoArvore(Arv *a)
{
    if (!a)
        return 0;
    if (ehFolhaArv(a))
        return 1 + 8; // 1 bit de marcador + 8 bits do caractere
    return 1 + tamanhoSerializacaoArvore(retornaEsqArv(a)) +
               tamanhoSerializacaoArvore(retornaDirArv(a));
}

/*
    Escrever apenas um unico bit em um buffer pre-existente
    Fonte de inspiração: https://stackoverflow.com/questions/30007665/how-can-i-store-value-in-bit-in-c-language
*/
static void escreveBit(unsigned char *buffer, int *pos, int bit)
{
    int byte = *pos / 8;
    int bitPos = 7 - (*pos % 8); // bit mais significativo primeiro
    if (bit)
        buffer[byte] |= (1 << bitPos);
    else
        buffer[byte] &= ~(1 << bitPos);
    (*pos)++;
}

/*
    Extensão natural da funcao escreveBit
    Fonte de inspiração: https://stackoverflow.com/questions/30007665/how-can-i-store-value-in-bit-in-c-language
*/
static void escreveByte(unsigned char *buffer, int *pos, unsigned char b)
{
    for (int i = 0; i < 8; i++)
    {
        int bit = (b >> (7 - i)) & 1;
        escreveBit(buffer, pos, bit);
    }
}

// Funcao auxiliar da compactacao da arvore binaria
static int serializaArvoreBuffer(Arv *a, unsigned char *buffer, int pos)
{
    if (!a) return pos;

    if (ehFolhaArv(a))
    {
        escreveBit(buffer, &pos, 1); // No folha
        escreveByte(buffer, &pos, retornaByteArv(a));
    } 
    else
    {
        escreveBit(buffer, &pos, 0); // No interno
        pos = serializaArvoreBuffer(retornaEsqArv(a), buffer, pos);
        pos = serializaArvoreBuffer(retornaDirArv(a), buffer, pos);
    }
    return pos;
}

void geraTabelaCompactador(Compactador *c)
{
    if (!c || !c->arvore)
        return;

    c->tabela = calloc(TABELA_MAX_SIZE, sizeof(char *));
    check_memory(c->tabela);

    char prefixo[TABELA_MAX_SIZE] = "";
    gerarCodigos(c->arvore, c->tabela, prefixo);
}

// Funcao auxiliar para gerar a tabela
static void gerarCodigos(Arv *a, char **tabela, char *prefixo)
{
    if (!a)
        return;

    if (ehFolhaArv(a))
    {
        unsigned char c = retornaByteArv(a);
        tabela[c] = strdup(prefixo);
        check_memory(tabela[c]);
        return;
    }

    char esquerda[TABELA_MAX_SIZE], direita[TABELA_MAX_SIZE];
    snprintf(esquerda, sizeof(esquerda), "%s0", prefixo);
    snprintf(direita, sizeof(direita), "%s1", prefixo);

    gerarCodigos(retornaEsqArv(a), tabela, esquerda);
    gerarCodigos(retornaDirArv(a), tabela, direita);
}

void preencheBitmapCompactador(Compactador *c, FILE *entrada)
{
    if (!c || !c->tabela || !entrada)
        return;

    // Descobre tamanho do arquivo
    fseek(entrada, 0, SEEK_END);
    long tamanhoArquivo = ftell(entrada);
    fseek(entrada, 0, SEEK_SET);

    if (tamanhoArquivo <= 0) return;

    // Carrega o arquivo inteiro em memória
    unsigned char *buffer = malloc(tamanhoArquivo);
    check_memory(buffer);
    fread(buffer, 1, tamanhoArquivo, entrada);

    // 1a passagem: calcular bits necessarios
    long bitsNecessarios = 0;
    for (long i = 0; i < tamanhoArquivo; i++)
    {
        char *codigo = c->tabela[buffer[i]];
        bitsNecessarios += strlen(codigo);
    }

    // Inicializa o bitmap
    if (!c->bm)
        c->bm = bitmapInit(bitsNecessarios);

    // 2a passagem: preencher bitmap
    for (long i = 0; i < tamanhoArquivo; i++)
    {
        char *codigo = c->tabela[buffer[i]];
        for (int j = 0; codigo[j] != '\0'; j++)
            bitmapAppendLeastSignificantBit(c->bm, codigo[j] == '1');
    }

    free(buffer);
}

void salvaBinarioCompactador(Compactador *c, FILE *saida)
{
    if (!c || !saida)
        return;

    // Escreve tamanho e buffer da arvore
    int bits = tamanhoSerializacaoArvore(c->arvore);
    fwrite(&bits, sizeof(int), 1, saida);
    fwrite(c->bufferSerializado, 1, c->tamanhoBuffer, saida);

    // Escreve bitmap
    unsigned int tam = bitmapGetLength(c->bm);
    fwrite(&tam, sizeof(unsigned int), 1, saida);

    unsigned char *dados = bitmapGetContents(c->bm);
    size_t bytes = (tam + 7) / 8;
    fwrite(dados, 1, bytes, saida);
}

// Funcoes de debug
void imprimeArvoreCompactador(Compactador *c)
{
    if (!c || !c->bufferSerializado || c->tamanhoBuffer <= 0)
    {
        printf("Arvore serializada inexistente ou vazia.\n");
        return;
    }

    printf("\nTamanho do buffer da arvore: %d bytes\n", c->tamanhoBuffer);
    printf("Buffer serializado da arvore:\n");

    for (int i = 0; i < c->tamanhoBuffer; i++)
    {
        printf("%02x ", c->bufferSerializado[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    if (c->tamanhoBuffer % 16 != 0)
        printf("\n");
}

void imprimeTabelaCompactador(Compactador *c)
{
    if (!c || !c->tabela)
        return;

    printf("\nTabela de codificacao:\n");
    for (int i = 0; i < TABELA_MAX_SIZE; i++)
    {
        if (c->tabela[i])
        {
            if (i >= ' ' && i <= '~')
                printf("'%c': %s\n", i, c->tabela[i]);
            else
                printf("0x%02X: %s\n", i, c->tabela[i]);
        }
    }
}

void imprimeBitmapCompactador(Compactador *c)
{
    if (!c || !c->bm)
    {
        printf("Bitmap inexistente.\n");
        return;
    }

    unsigned int tamBits = bitmapGetLength(c->bm);
    unsigned char *dados = bitmapGetContents(c->bm);
    size_t tamBytes = (tamBits + 7) / 8;

    printf("\nTamanho do bitmap: %u bits (%zu bytes)\n", tamBits, tamBytes);
    printf("Conteudo do bitmap (hexadecimal):\n");

    for (size_t i = 0; i < tamBytes; i++)
    {
        printf("%02x ", dados[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    if (tamBytes % 16 != 0)
        printf("\n");

    printf("Bits individuais:\n");
    for (unsigned int i = 0; i < tamBits; i++)
    {
        printf("%d", bitmapGetBit(c->bm, i));
        if ((i + 1) % 8 == 0)
            printf(" ");
        if ((i + 1) % 64 == 0)
            printf("\n");
    }
    if (tamBits % 64 != 0)
        printf("\n");
}

void imprimeBinarioCompactador(const char *nome_arquivo)
{
    FILE *f = fopen(nome_arquivo, "rb");
    if (!f)
    {
        perror("Erro ao abrir o arquivo binário\n");
        return;
    }

    // Ler e mostrar o tamanho da árvore serializada
    int tam;
    fread(&tam, sizeof(int), 1, f);
    printf("\nTamanho da árvore serializada: %d bytes\n", tam);

    // Ler e mostrar o buffer da árvore
    unsigned char *buffer = malloc(tam);
    fread(buffer, sizeof(unsigned char), tam, f);

    printf("Bytes da árvore:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%02x ", buffer[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n");
    free(buffer);

    // Ler e mostrar o tamanho do bitmap (em bits)
    unsigned int tam_bm_bits;
    fread(&tam_bm_bits, sizeof(unsigned int), 1, f);
    printf("Tamanho do bitmap: %u bits (%u bytes)\n", tam_bm_bits, (tam_bm_bits + 7) / 8);

    // Ler os bytes do bitmap
    unsigned int num_bytes = (tam_bm_bits + 7) / 8;
    unsigned char *dados = malloc(num_bytes);
    fread(dados, sizeof(unsigned char), num_bytes, f);

    // Mostrar os bytes
    printf("Bytes do bitmap:\n");
    for (unsigned int i = 0; i < num_bytes; i++)
    {
        printf("%02x ", dados[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n");

    // Mostrar os bits válidos do bitmap
    printf("Bits do bitmap:\n");
    for (unsigned int i = 0; i < tam_bm_bits; i++)
    {
        unsigned char bit = (dados[i / 8] >> (7 - (i % 8))) & 0x01;
        printf("%d", bit);
        if ((i + 1) % 8 == 0)
            printf(" ");
        if ((i + 1) % 64 == 0)
            printf("\n");
    }
    printf("\n");

    free(dados);
    fclose(f);
}