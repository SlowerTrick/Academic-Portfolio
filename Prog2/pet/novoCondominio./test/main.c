#include <stdio.h>
#include "reserva.h"
#include <stdlib.h>

int main(void)
{
    int totalAreas;
    scanf("%d", &totalAreas);
    getchar();
    Area areas[totalAreas];

    for(int i = 0; i < totalAreas; i++)
    {
        areas[i] = lerArea();
    }

    int totalMoradores;
    scanf("%d", &totalMoradores);
    getchar();
    Morador moradores[totalMoradores];

    for(int i = 0; i < totalMoradores; i++)
    {
        moradores[i] = lerMorador();
    }

    int totalReservas, totalReservasCorretas = 0;
    scanf("%d", &totalReservas);
    getchar();
    Reserva reservas[totalReservas];

    for(int i = 0; i < totalReservas; i++)
    {
        char idArea[MAX_TAM_ID], cpf[MAX_TAM_CPF], turno[2];
        Data *dt = malloc(sizeof(Data));
        int *qtdConv = malloc(sizeof(int));
        lerDadosSolicitacaoReserva(idArea, cpf, dt, qtdConv, turno);

        Morador mTemp;
        Area aTemp;

        for(int j = 0; j < totalMoradores; j++)
        {
            if(verificaCPFMorador(moradores[j], cpf))
            {
                mTemp = moradores[j];
                break;
            }
        }
        for(int j = 0; i < totalAreas; j++)
        {
            if(verificaIdArea(areas[j], idArea))
            {
                aTemp = areas[j];
                break;
            }
        }
        if (verificaSolicitacaoReserva(reservas, totalReservasCorretas, mTemp, aTemp, *dt, *qtdConv, *turno))
            reservas[totalReservasCorretas++] = criaReserva(mTemp, aTemp, *dt, *qtdConv, *turno);
        free(dt);
        free(qtdConv);
    }

    for(int i = 0; i < totalReservas; i++)
    {
        imprimeReserva(reservas[i]);
    }
    return 0;
}