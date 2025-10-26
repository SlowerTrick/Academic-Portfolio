#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila
{
    Ticket **elementos;
    int qtd_total;
    int qtd_atual;
};


/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila()
{
    Fila *f = malloc(sizeof(*f));
    if(!f)
    {
        printf("ERRO! Falta de memoria");
        exit(1);
    }
    f->qtd_total = 10;
    f->qtd_atual = 0;
    f->elementos = malloc(sizeof(Ticket *) * f->qtd_total);
    return f;
}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
void desalocaFila(Fila *f)
{
    if(f)
    {
        if(f->elementos)
            for(int i = 0; i < f->qtd_atual; i++)
                desalocaTicket(f->elementos[i]);
        free(f->elementos);
        free(f);
    }
    f = NULL;
}

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca)
{
    if(f->qtd_atual == f->qtd_total)
    {
        f->qtd_total += 10;
        f->elementos = realloc(f->elementos, sizeof(Ticket *) * f->qtd_total);
        if(!f->elementos)
        {
            printf("ERRO! falta de memoria");
            exit(1);
        }
    }
    f->elementos[f->qtd_atual] = criaTicket(cpfSol, dado, getTempo, getTipo, notifica, desaloca);

    char id_ticket[16]; // 16 bytes: "Tick-" (5 digitos) + Maior int (10 digitos) + '\0' (1 digito)
    sprintf(id_ticket, "Tick-%d", f->qtd_atual + 1);

    setIDTicket(f->elementos[f->qtd_atual], id_ticket);
    f->qtd_atual++; 
}

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f)
{
    return f->qtd_atual;
}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status)
{
    int total = 0;
    for(int i = 0; i < f->qtd_atual; i++)
        if(getStatusTicket(f->elementos[i]) == status)
            total++;
    return total;
}

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i)
{
    return f->elementos[i];
}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f)
{
    for(int i = 0; i < f->qtd_atual; i++)
        notificaTicket(f->elementos[i]);
}
