#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct impr
{
    char *msg;
};


/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg) {
    tImpr *tarefa = malloc(sizeof(*tarefa));
    tarefa->msg = malloc(strlen(msg) + 2);

    tarefa->msg[0] = '\n';
    strcpy(tarefa->msg + 1, msg);

    return tarefa;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp)
{
    tImpr *t = (tImpr *)imp;
    printf("%s", t->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp)
{
    tImpr *t = (tImpr *) imp;
    if(t)
    {
        if(t->msg)
            free(t->msg);
        t->msg = NULL;
        free(t);
    }
    t = NULL;
}
