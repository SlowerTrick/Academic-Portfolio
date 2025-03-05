#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int total_tarefas;
    printf("Digite o numero de tarefas: ");
    scanf("%d%*c", &total_tarefas);
    tAgendaTarefas *tarefas = CriaAgendaDeTarefas(total_tarefas);

    for(int i = 0; i < total_tarefas; i++)
    {
        int prioridade = 0;
        char tipo = 0;
        scanf("%d %c", &prioridade, &tipo);

        if(tipo == 'I')
        {
            char msg[10000];
            scanf(" %[^\n]%*c", msg);
            tImpr *tarefa = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(tarefas, prioridade, tarefa, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else if(tipo == 'S')
        {
            float n1, n2;
            scanf("%f %f%*c", &n1, &n2);
            tSoma *tarefa = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(tarefas, prioridade, tarefa, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else if(tipo == 'M')
        {
            float n1, n2;
            scanf("%f %f%*c", &n1, &n2);
            tMult *tarefa = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(tarefas, prioridade, tarefa, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else
        {
            char msg[10000];
            scanf(" %[^\n]%*c", msg);
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            i--;
        }
        
    }
    ExecutarTarefasDaAgenda(tarefas);
    DestroiAgendaDeTarefas(tarefas);
    return 0;
}