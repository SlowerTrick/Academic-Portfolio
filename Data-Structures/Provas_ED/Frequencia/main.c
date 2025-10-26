#include "aluno.h"
#include "hash.h"

int main(void)
{
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");
    if(!entrada || !saida)
    {
        perror("ERRO! nao foi possivel abrir os arquivos necessarios");
        exit(1);
    }

    int total = 0;
    fscanf(entrada, "%*c %d", &total);

    Hash *hash_map = criaHash();
    char nome[1000];
    while(fscanf(entrada, " %s", nome) == 1)
    {
        Aluno *a = criaAluno(nome);
        insereHash(hash_map, a);
    }

    for(int i = 0; i < total; i++)
    {
        char buffer[100];
        sprintf(buffer, "entrada%d.txt", i+1);
        FILE *fptr = fopen(buffer, "r");
        if(!fptr)
        {
            perror("ERRO! nao foi possivel abrir os arquivos necessarios");
            exit(1);
        }
        char presenca;
        while(fscanf(fptr, " %s %c", nome, &presenca) == 2)
        {
            Aluno *a = buscaHash(hash_map, nome);
            atualizaPresencaAluno(a, presenca);
        }
        fclose(fptr);
    }
    imprimeHash(hash_map);

    liberaHash(hash_map);
    fclose(entrada);
    fclose(saida);
    return 0;
}