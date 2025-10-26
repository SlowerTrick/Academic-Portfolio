#include "hash.h"
#include "pais.h"

int compare(const void *p1, const void *p2)
{
    Pais *pais1 = *(Pais **)p1;
    Pais *pais2 = *(Pais **)p2;

    int diff = retornaOuroPais(pais2) - retornaOuroPais(pais1);
    if (diff != 0) return diff;

    diff = retornaPrataPais(pais2) - retornaPrataPais(pais1);
    if (diff != 0) return diff;

    diff = retornaBronzePais(pais2) - retornaBronzePais(pais1);
    return diff;
}
        
int main(void)
{
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");
    if(!entrada || !saida)
    {
        perror("ERRO! nao foi possivel abrir os arquivos necessarios");
        exit(1);
    }
    
    Hash *hash_map = criaHash();
    char nome[4];
    int ouro, prata, bronze, total;
    while(fscanf(entrada, "%3s %d %d %d %d", nome, &ouro, &prata, &bronze, &total) == 5)
    {
        Pais *p = criaPais(nome, ouro, prata, bronze, total);
        insereHash(hash_map, p);
    }
    
    int tam_vetor = retornaUnicosHash(hash_map);
    printf("%d\n", tam_vetor);
    Pais **vet = malloc(tam_vetor * sizeof(Pais *));
    preencheVetor(hash_map, vet);
    
    qsort(vet, tam_vetor, sizeof(Pais *), compare);
    
    for(int i = 0; i < tam_vetor; i++)
    {
        fprintf(saida, "%s %d %d %d %d",  retornaNomePais(vet[i]),
                                            retornaOuroPais(vet[i]),
                                            retornaPrataPais(vet[i]),
                                            retornaBronzePais(vet[i]),
                                            retornaTotalPais(vet[i]));
        if(i < tam_vetor - 1)
            fprintf(saida, "\n");
    }

    free(vet);
    liberaHash(hash_map);
    fclose(entrada);
    fclose(saida);
    return 0;
}
