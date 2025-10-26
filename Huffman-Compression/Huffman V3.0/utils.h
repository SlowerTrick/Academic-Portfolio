/*
 utils.h
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#ifndef UTILS_H
#define UTILS_H

#include "arvore.h"
#include "listaArvores.h"
// #include "bitmap.h"
#include <stdio.h>
#include <string.h>

/**
 * Funcao auxiliar que imprime uma mensagem de falha e aborta o programa caso testresult seja falso.
 * @param testresult Valor booleano representando o resultado do teste que deveria ser verdadeiro.
 * @param message A mensagem para ser impressa se resultado do teste for falso.
 */
void check(int testresult, char* message);

int comp_int(const void* a, const void* b);

void check_memory(void *p);

/*
    Recebe um vetor de frequencias, e seu tamanho
    Além disso recebe um arquivo binario

    Assim eh possivel fazer frequencia[ASCII_do_Caracter_Lido]++
*/
void count_frequency(FILE* input, int* frequency_array, int n);

char* geraNomeArquivoOriginal(char* path);

#endif