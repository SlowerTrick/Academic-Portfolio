#include "evento.h"
#include <stdio.h>
#include <string.h>

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos)
{
    char nome[50];
    int dia, mes, ano;
    scanf(" %s %d %d %d", nome, &dia, &mes, &ano);
    strcpy(eventos[*numEventos].nome, nome);
    eventos[*numEventos].dia = dia;
    eventos[*numEventos].mes = mes;
    eventos[*numEventos].ano = ano;
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos)
{
    printf("Eventos cadastrados:\n");
    for(int i = 0; i < *numEventos; i++)
        printf("%d - %s - %d/%d/%d", i, eventos[*numEventos].nome, eventos[*numEventos].dia, eventos[*numEventos].mes, eventos[*numEventos].ano);
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int dia, mes, ano, index = -1;

    while (index < 0 || index > *numEventos)
    {
        scanf("%d", &index);
        printf("Indice invalido!\n");
    }
    scanf("%d %d %d", &dia, &mes, &ano);
    eventos[index].dia = dia;
    eventos[index].mes = mes;
    eventos[index].ano = ano;
    printf("Data modificada com sucesso!\n");
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    Evento aux = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = aux;
}
