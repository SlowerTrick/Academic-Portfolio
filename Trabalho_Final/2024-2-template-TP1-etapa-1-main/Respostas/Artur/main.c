#include "atores.h"
#include "usuario.h"
#include "tecnico.h"
#include "fila.h"
#include "software.h"
#include "ticket.h"
#include "outros.h"
#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimeRelatorioGeral(Atores *usuarios, Atores *tecnicos, Fila *fila_tickets);
void distribuiTickets(Atores *tecnicos, Fila *fila_tickets);
int associaTecnicoTicket(Atores *tecnicos, Ticket *ticket, int *tecnico_inicial, int qtd_tickets, int qtd_tecnicos);
void limparBufferUsuarioInexistente(char *tipo);

int main(void)
{
    Atores *usuarios = criaAtores(notificaUsuario, desalocaUsuario);
    Atores *tecnicos = criaAtores(notificaTecnico, desalocaTecnico);
    Fila *fila_tickets = criaFila();

    while(1)
    {
        char opcao;
        scanf("%c%*c", &opcao);
        if(toupper(opcao) == 'U')
        {
            Usuario *usuario = lerUsuario();
            insereAtor(usuarios, usuario);
        }
        else if(toupper(opcao) == 'T')
        {
            Tecnico *tecnico = lerTecnico();
            insereAtor(tecnicos, tecnico);
        }
        else if(toupper(opcao) == 'A')
        {
            char cpf[MAX_TAM_CPF], tipo[MAX_TAM_NOME];
            scanf("%[^\n] %[^\n]%*c", cpf, tipo);
            Usuario *usuario = getElementoCaracteristica(usuarios, cpf, comparaCpfcomCpfUsuario);

            if(usuario != NULL)
            {
                aumentaQtdTicketsSolicitados(usuario);

                if(strcmp(tipo, "SOFTWARE") == 0)
                {
                    Software *ticket_software = lerSoftware();
                    setTempoEstimadoSoftware(ticket_software);
                    insereTicketFila(fila_tickets, cpf, ticket_software, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
                }
                else if(strcmp(tipo, "MANUTENCAO") == 0)
                {
                    Manutencao *ticket_manutencao = lerManutencao();
                    setTempoEstimadoManutencao(ticket_manutencao, getSetorUsuario(usuario));
                    insereTicketFila(fila_tickets, cpf, ticket_manutencao, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
                }
                else if(strcmp(tipo, "OUTROS") == 0)
                {
                    Outros *ticket_outros = lerOutros();
                    setTempoEstimadoOutros(ticket_outros);
                    insereTicketFila(fila_tickets, cpf, ticket_outros, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
                }
            }
            else
            {
                limparBufferUsuarioInexistente(tipo);
            }
        }
        else if(toupper(opcao) == 'E')
        {
            char tarefa[25];
            scanf("%[^\n]%*c", tarefa);
            
            if (strcmp(tarefa, "DISTRIBUI") == 0)
            {
                distribuiTickets(tecnicos, fila_tickets);
            }
            else if(strcmp(tarefa, "USUARIOS") == 0)
            {
                printf("----- BANCO DE USUARIOS -----\n");
                notificaAtores(usuarios);
                printf("----------------------------\n\n");
            }
            else if(strcmp(tarefa, "TECNICOS") == 0)
            {
                printf("----- BANCO DE TECNICOS -----\n");
                notificaAtores(tecnicos);
                printf("----------------------------\n\n");
            }
            else if(strcmp(tarefa, "NOTIFICA") == 0)
            {
                printf("----- FILA DE TICKETS -----\n");
                notificaFila(fila_tickets);
                printf("----------------------------\n\n");
            }
            else if(strcmp(tarefa, "RANKING TECNICOS") == 0)
            {
                printf("----- RANKING DE TECNICOS -----\n");
                notificaRankingAtores(tecnicos, comparaQtdHorasTrabalhadas);
                printf("-------------------------------\n");
            }
            else if(strcmp(tarefa, "RANKING USUARIOS") == 0)
            {
                printf("----- RANKING DE USUARIOS -----\n");
                notificaRankingAtores(usuarios, comparaQtdTicketsSolicitados);
                printf("-------------------------------\n");
            }
            else if(strcmp(tarefa, "RELATORIO") == 0)
            {
                imprimeRelatorioGeral(usuarios, tecnicos, fila_tickets);
            }
        }
        else if(toupper(opcao) == 'F')
        {
            desalocaAtores(usuarios);
            desalocaAtores(tecnicos);
            desalocaFila(fila_tickets);
            break;
        }
    }
    return 0;
}

void distribuiTickets(Atores *tecnicos, Fila *fila_tickets)
{
    int qtd_tickets = getQtdTicketsNaFila(fila_tickets);
    int qtd_tecnicos = getQtdAtores(tecnicos);
    int tecnico_inicial = 0;

    for(int i = 0; i < qtd_tickets; i++)
    {
        Ticket *ticket = getTicketNaFila(fila_tickets, i);
        char status_ticket = getStatusTicket(ticket);
        int tempo_ticket = getTempoEstimadoTicket(ticket);

        if(status_ticket == 'A')
        {
            int ticket_atribuido = associaTecnicoTicket(tecnicos, ticket, &tecnico_inicial, qtd_tickets, qtd_tecnicos);

            if (tecnico_inicial >= qtd_tecnicos || ticket_atribuido == 0)  
                tecnico_inicial = 0;

            if (ticket_atribuido == 0)
                associaTecnicoTicket(tecnicos, ticket, &tecnico_inicial, qtd_tickets, qtd_tecnicos);
        }
    }
}

int associaTecnicoTicket(Atores *tecnicos, Ticket *ticket, int *tecnico_inicial, int qtd_tickets, int qtd_tecnicos)
{
    char tipo_ticket = getTipoTicket(ticket);
    int tempo_ticket = getTempoEstimadoTicket(ticket);

    for(int j = *tecnico_inicial; j < qtd_tecnicos; j++)
    {
        Tecnico *tecnico = getAtorNaFila(tecnicos, j);
        char area_atuacao_tecnico[MAX_TAM_AREA_ATUACAO];
        strcpy(area_atuacao_tecnico, getAreaAtuacaoTecnico(tecnico));
        int tempo_tecnico = getTempoDisponivelTecnico(tecnico);
        int flag_finalizar_ticket = 1;

        if(tipo_ticket == 'S' && strcmp(area_atuacao_tecnico, "TI") != 0)
            flag_finalizar_ticket = 0;
        else if(tipo_ticket != 'S' && strcmp(area_atuacao_tecnico, "TI") == 0)
            flag_finalizar_ticket = 0;
        else if(tempo_tecnico < tempo_ticket)
            flag_finalizar_ticket = 0;

        if(flag_finalizar_ticket)
        {
            finalizaTicket(ticket);
            alteraTempoTrabalhoTecnico(tecnico, tempo_ticket);
            *tecnico_inicial = j + 1;
            return 1;
        }
    }
    return 0;
}

void imprimeRelatorioGeral(Atores *usuarios, Atores *tecnicos, Fila *fila_tickets)
{
    int qtd_tickets = getQtdTicketsNaFila(fila_tickets);
    int qtd_tickets_abertos = getQtdTicketsPorStatusNaFila(fila_tickets, 'A');
    int qtd_tickets_fechados = getQtdTicketsPorStatusNaFila(fila_tickets, 'F');
    int qtd_usuarios = getQtdAtores(usuarios);
    int qtd_tecnicos = getQtdAtores(tecnicos);
    int media_idade_usuarios = getMediaCaracteristicaAtores(usuarios, calculaIdadeUsuario);
    int media_idade_tecnicos = getMediaCaracteristicaAtores(tecnicos, calculaIdadeTecnico);
    int media_horas_trabalho_tecnicos = getMediaCaracteristicaAtores(tecnicos, getTempoTrabalhadoTecnico);

    printf("----- RELATORIO GERAL -----\n");
    printf("- Qtd tickets: %d\n", qtd_tickets);
    printf("- Qtd tickets (A): %d\n", qtd_tickets_abertos);
    printf("- Qtd tickets (F): %d\n", qtd_tickets_fechados);
    printf("- Qtd usuarios: %d\n", qtd_usuarios);
    printf("- Md idade usuarios: %d\n", media_idade_usuarios);
    printf("- Qtd tecnicos: %d\n", qtd_tecnicos);
    printf("- Md idade tecnicos: %d\n", media_idade_tecnicos);
    printf("- Md trabalho tecnicos: %d\n", media_horas_trabalho_tecnicos);
    printf("---------------------------\n\n");
}

void limparBufferUsuarioInexistente(char *tipo)
{
    if(strcmp(tipo, "SOFTWARE") == 0)
    {
        char nome[MAX_TAM_NOME_SOFTWARE], categoria[MAX_TAM_CAT], motivo[MAX_TAM_MOTIVO];
        int impacto;
        scanf("%[^\n] %[^\n] %d %[^\n]%*c", nome, categoria, &impacto, motivo);
    }
    else if(strcmp(tipo, "MANUTENCAO") == 0)
    {
        char nome[MAX_TAM_NOME_MANUTENCAO], estado[MAX_TAM_ESTADO_MANUTENCAO], local[MAX_TAM_LOCAL_MANUTENCAO];
        scanf("%[^\n] %[^\n] %[^\n]%*c", nome, estado, local);
    }
    else if(strcmp(tipo, "OUTROS") == 0)
    {
        char descricao[MAX_TAM_DESCRICAO_OUTROS], local[MAX_TAM_LOCAL_OUTROS];
        int dificuldade;
        scanf("%[^\n] %[^\n] %d%*c", descricao, local, &dificuldade);
    }
}