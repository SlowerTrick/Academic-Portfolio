/*
 utils.c
 Compactador/Descompactador de Arquivos (Huffman)

 Created by Artur Vitor Cintra Bernardes && Felipe Pedrini Oliveira in 2025/8 at UFES.
*/

#include "utils.h"

#define EXTENSAO ".comp"

void check(int testresult, char* message) {
	if (!testresult) {
		fprintf(stderr, "%s\n", message);
		exit(EXIT_FAILURE);
	}
}

int comp_int(const void* a, const void* b){
    int* a1 = (int*) a;
    int* b1 = (int*) b;

    return *b1 - *a1;
}

void count_frequency(FILE* input, int* frequency_array, int n){
    fseek(input, 0, SEEK_SET);//Seta o ponteiro do arquivo para o início, pois pode ser que ele esteja no final

    //Inicializar o vetor de frequência
    for(int i=0; i<n; i++){
        frequency_array[i] = 0;
    }

    int c;//Utiliza 4 bytes em vez de um só, mas é necessário por causa do EOF, pois um char de 255 podia ser mal interpretado como -1 
    while((c = fgetc(input)) != EOF){//Enquanto tiver mais de 0 bytes lidos, continua o loop
        frequency_array[c]++;
    }
}

void check_memory(void *p)
{
    if(!p)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
}

char* geraNomeArquivoOriginal(char* path){
    int tam_path = strlen(path);
    int tam_ext = strlen(EXTENSAO);

    // Verifica se termina com .comp
    if(tam_path <= tam_ext || strcmp(path + tam_path - tam_ext, EXTENSAO) != 0){
        fprintf(stderr, "Erro: Arquivo de entrada não tem extensão .comp\n");
        return NULL;
    }

    char* nome_saida = malloc(sizeof(char)*(tam_path - tam_ext + 1));
    check_memory(nome_saida);
    strncpy(nome_saida, path, tam_path - tam_ext);
    nome_saida[tam_path - tam_ext] = '\0';

    return nome_saida;
}