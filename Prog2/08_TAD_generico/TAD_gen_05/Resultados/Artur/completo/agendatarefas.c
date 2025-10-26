#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agendatarefas
{
    int total_tarefas;
    int tarefa_atual;
    int *prioridades;
    void **tarefas;
    void (**executa)(void*);
    void (**destroi)(void*);
};

tAgendaTarefas* tar_global = NULL;

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem)
{
    tAgendaTarefas *t = malloc(sizeof(*t));
    t->prioridades = malloc(sizeof(int) * numElem);
    t->tarefas = malloc(sizeof(void *) * numElem);
    t->executa = malloc(sizeof(void *) * numElem);
    t->destroi = malloc(sizeof(void *) * numElem);
    t->total_tarefas = numElem;
    t->tarefa_atual = 0;
    return t;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar)
{
    if(tar)
    {
        for(int i = 0; i < tar->tarefa_atual; i++)
            tar->destroi[i](tar->tarefas[i]);
        free(tar->prioridades);
        free(tar->destroi);
        free(tar->tarefas);
        free(tar->executa);
        free(tar);
    }
    tar = NULL;
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*))
{
    tar->destroi[tar->tarefa_atual] = destroi;
    tar->executa[tar->tarefa_atual] = executa;
    tar->prioridades[tar->tarefa_atual] = prioridade;
    tar->tarefas[tar->tarefa_atual] = tarefa;
    tar->tarefa_atual++;
}   

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
// Função de comparação para o qsort
int compararTarefas(const void* a, const void* b)
{
    int idx_a = *((int*)a);
    int idx_b = *((int*)b);

    // Acessa os dados da agenda através da variável global temporária
    tAgendaTarefas* tar = tar_global;

    // Compara as prioridades (ordem decrescente)
    if (tar->prioridades[idx_a] > tar->prioridades[idx_b]) return -1;
    if (tar->prioridades[idx_a] < tar->prioridades[idx_b]) return 1;

    // Se as prioridades forem iguais, mantém a ordem original (estável)
    return idx_a - idx_b;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar)
{
    // Cria um array de índices para ordenar
    int* indices = (int*)malloc(tar->tarefa_atual * sizeof(int));
    if (!indices) {
        perror("Erro ao alocar memória");
        return;
    }

    for (int i = 0; i < tar->tarefa_atual; i++) {
        indices[i] = i;
    }

    // Usa a variável global temporária
    tar_global = tar;

    // Ordena os índices com base nas prioridades
    qsort(indices, tar->tarefa_atual, sizeof(int), compararTarefas);

    // Limpa a variável global temporária
    tar_global = NULL;

    // Executa as tarefas na ordem definida pelos índices ordenados
    for (int i = 0; i < tar->tarefa_atual; i++) {
        int idx = indices[i];
        tar->executa[idx](tar->tarefas[idx]);
    }

    // Libera o array de índices
    free(indices);
}