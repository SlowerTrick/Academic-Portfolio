

#ifndef _RESERVA_H
#define _RESERVA_H

#include "data.h"
#include "morador.h"
#include "area.h"

typedef struct
{
    Morador morador;
    Area area;
    Data data;
    int qtdConvidados;
    char turno;
} Reserva;

/**
 * Função que recebe os dados necessários para criar uma reserva
 * e retorna a reserva criada.
 * morRes: Morador que está fazendo a reserva
 * aRes: Área que está sendo reservada
 * dRes: Data da reserva
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 * turno: Turno da reserva (M - manhã, T - tarde, N - noite)
 *
 * Retorna uma Reserva com os dados informados
 */
Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados, char turno);

/**
 * Função que lê da entrada padrão dos dados necessários para solicitação da reserva. São eles:
 * idArea: string com ID da área solicitada
 * cpf: string com o CPF do morador solicitante
 * dt: ponteiro para Data que armazenará a data da reserva
 * qtdConv: ponteiro para inteiro que armazenará a quantidade de convidados
 * turno: ponteiro para char que armazenará o turno da reserva
 *
 * Todas as informações devem ser lidas da entrada padrão (ver especificação e casos para detalhes) e
 * armazenadas de forma adequada nos parâmetros correspondentes.
 *
 * Dicas do coração:
 * 1. Observe que a função não tem retorno, logo, o que está acontecendo aqui é uma passage de parâmetros por referência,
 *    logo, manipulação de ponteiros
 * 2. O tipo Data é uma struct, logo, o acesso aos seus campos é feito com o operador '.' ou '->' no caso de ponteiros
 * 3. A função lerData() já está implementada, mas cuidado, ela retorna um tipo Data e não um ponteiro para Data. Como contornar isso
 *    sem implementar uma nova função? É isso que você tem que implementar!
 * 4. Cuidado para não referenciar uma memória de dentro da função que é liberada ao final da execução da função. Lembre-se da forma que
 *    Pilha de Memória (Stack) funciona.
 */
void lerDadosSolicitacaoReserva(char *idArea, char *cpf, Data *dt, int *qtdConv, char *turno);

/**
 * Função que verifica se é possível realizar uma reserva solicitada com os dados informados.
 * Essa verificação é baseada em todas as regras de reserva de áreas comuns descritas na especificação.
 *
 * agendaReservas: array que armazena todas as reservas de áreas comuns já realizadas
 * nRes: quantidade de reservas contidas no array agendaReservas
 * morRes: Morador que está solicitando a reserva
 * aRes: Área que está sendo solicitada
 * dRes: Data da reserva solicitada
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 * turno: Turno da reserva (M - manhã, T - tarde, N - noite)
 *
 * Retorna 1 se a reserva pode ser realizada e 0 caso contrário
 */
int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes,
                               int qtdConvidados, char turno);

/**
 * Função que imprime todas as informações de uma Reserva conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeReserva(Reserva r);

#endif