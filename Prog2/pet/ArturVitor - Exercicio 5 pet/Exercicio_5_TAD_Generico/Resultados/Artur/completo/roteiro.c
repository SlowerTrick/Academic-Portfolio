#include "roteiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Roteiro
{
    Midia **midia;
    int total_midia;
    int midia_atual;
};


// Aloca dinamicamente um novo objeto Roteiro e retorna o ponteiro para ele.
// Retorna: Ponteiro para o Roteiro recém-criado.
Roteiro *roteiro_construct()
{
    Roteiro *roteiro = malloc(sizeof(*roteiro));
    if(!roteiro)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    roteiro->total_midia = 10;
    roteiro->midia = malloc(sizeof(Midia *) * roteiro->total_midia);
    if(!roteiro->midia)
    {
        free(roteiro);
        perror("ERRO! falta de memoria");
        exit(1);
    }
    roteiro->midia_atual = 0;
    return roteiro;
}

// Aumenta o espaço de armazenamento de mídias no Roteiro, insere a nova mídia
// utilizando o construtor de mídia (midia_construct), e incrementa o contador de mídias.
// Parâmetros:
//  r       - Ponteiro para o Roteiro onde a mídia será inserida.
//  dado    - Ponteiro genérico contendo os dados da nova mídia a ser inserida.
//  print_fn - Função de impressão personalizada para a mídia.
//  free_fn  - Função de liberação personalizada para os recursos da mídia.
void roteiro_inserir_midia(Roteiro* r, void *dado, PrintFunction print_fn, FreeFunction free_fn)
{
    if(r->midia_atual == r->total_midia)
    {
        r->total_midia += 10;
        r->midia = realloc(r->midia, sizeof(Midia *) * r->total_midia);
        if(!r->midia)
        {
            free(r);
            perror("ERRO! falta de memoria");
            exit(1);
        }
    }
    r->midia[r->midia_atual++] = midia_construct(dado, print_fn, free_fn);
}

// Imprime todas as mídias presentes no Roteiro. Se não houver mídias,
// imprime a mensagem "SEM MIDIAS PARA IMPRIMIR".
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser impresso.
void roteiro_imprimir_midias(Roteiro *r)
{
    if(r->midia_atual == 0)
    {
        printf("SEM MIDIAS PARA IMPRIMIR\n");
        return;
    }
    printf("IMPRIMINDO MIDIAS\n");
    for(int i = 0; i < r->midia_atual; i++)
    {
        printf("MIDIA %d: ", i+1);
        midia_print(r->midia[i]);
        printf("\n");
    }
}

// Libera a memória alocada para o Roteiro e suas mídias, desalocando
// adequadamente cada um dos elementos armazenados.
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser destruído.
void roteiro_destroy(Roteiro *r)
{
    if(r)
    {
        for(int i = 0; i < r->midia_atual; i++)
            midia_destroy(r->midia[i]);
        free(r->midia);
        r->midia = NULL;
        free(r);
    }
    r = NULL;
}
