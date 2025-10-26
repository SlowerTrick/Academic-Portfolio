#include "pintura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pintura
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char movimento[MAXTAM_STRINGS];
    char material[MAXTAM_STRINGS];
    int ano;
};


// Aloca dinamicamente uma nova estrutura Pintura e realiza a leitura dos dados
// de entrada associados à pintura. Retorna o ponteiro para o objeto Pintura.
// Retorna: Ponteiro para a Pintura recém-criada, com dados carregados.
Pintura* pintura_construct()
{
    Pintura *p = malloc(sizeof(*p));
    if(!p)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    scanf("%s %s %s %s %d%*c", p->titulo, p->artista, p->movimento, p->material, &p->ano);
    return p;
}

// Imprime os dados de uma pintura. Recebe um ponteiro genérico para a pintura,
// e utiliza a função de impressão para exibir as informações relevantes.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser impressa.
void pintura_print(void* p)
{
    Pintura *pintura = (Pintura *) p;
    printf("PINTURA\n");
    printf("Titulo: %s\n", pintura->titulo);
    printf("Artista: %s\n", pintura->artista);
    printf("Movimento: %s\n", pintura->movimento);
    printf("Material: %s\n", pintura->material);
    printf("Ano: %d\n", pintura->ano);
}

// Libera a memória alocada para a pintura, chamando a função de desalocação
// apropriada para os dados da estrutura Pintura.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser destruída.
void pintura_destroy(void* p)
{
    Pintura *pintura = (Pintura *) p;
    if(pintura)
        free(pintura);
    pintura = NULL;
}

