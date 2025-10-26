#include "hash.h"
#include "palavra.h"

int compare(const void* a, const void* b) {
    Palavra *pa = *(Palavra **)a;
    Palavra *pb = *(Palavra **)b;
    int freq_pa = retorna_frequencia_palavra(pa);
    int freq_pb = retorna_frequencia_palavra(pb);
    if(freq_pa != freq_pb)
        return freq_pa - freq_pb;
    else
        return strcmp(retorna_palavra(pa), retorna_palavra(pb));
}

int main(void)
{
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");
    if (!entrada || !saida)
    {
        perror("ERRO! nao foi possivel abrir o arquivo");
        exit(1);
    }

    Hash *hash_map = criaHash();
    char buffer[1000];
    while (fscanf(entrada, "%s", buffer) != EOF)
    {
        if (buffer[strlen(buffer) - 1] == '.')
            buffer[strlen(buffer) - 1] = '\0';
        Palavra *p = cria_palavra(buffer);
        Palavra *ja_existe = buscaHash(hash_map, p, soma_caracter_palavra, busca_palavra_lista);
        insereHash(hash_map, p, soma_caracter_palavra, insere_palavra_lista);
        if(ja_existe)
            libera_palavra(p);
    }
    printf("Hashmap:\n");
    imprimeHash(hash_map, imprime_palavra);
    printf("\n");

    int total_elementos = totalElementosHash(hash_map, retorna_frequencia_palavra);
    int total_elementos_unicos = totalUnicosHash(hash_map, total_palavras_lista);

    printf("Total elementos: %d\nUnicos: %d\n", total_elementos, total_elementos_unicos);

    Palavra *vetor[total_elementos_unicos];
    cria_vetor_palavras(hash_map, vetor);

    qsort(vetor, total_elementos_unicos, sizeof(Palavra *), compare);

    for(int i = 0; i < total_elementos_unicos; i++)
        fprintf(saida, "%s %d\n", retorna_palavra(vetor[i]), retorna_frequencia_palavra(vetor[i]));
    fprintf(saida, "------------------------\n");
    fprintf(saida, "%d palavras distintas encontradas\n", total_elementos_unicos);
    fprintf(saida, "%d palavras no total\n", total_elementos);
    fprintf(saida, "%s é a palavra de maior frequência (%d)",
            retorna_palavra(vetor[total_elementos_unicos - 1]),
            retorna_frequencia_palavra(vetor[total_elementos_unicos - 1]));

    fclose(entrada);
    fclose(saida);
    liberaHash(hash_map, libera_palavra);
    return 0;
}
