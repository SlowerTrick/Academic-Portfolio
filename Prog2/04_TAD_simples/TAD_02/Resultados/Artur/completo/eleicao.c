#include "eleicao.h"
#include "candidato.h"
#include <stdio.h>
#include <stdlib.h>

tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    int totalCandidatos = 0;
    scanf("%d\n", &totalCandidatos);

    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;

    for(int i = 0; i < totalCandidatos; i++)
    {
        tCandidato candidato = LeCandidato();
        if(ObtemCargo(candidato) == 'P')
        {
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }
        else
        {
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }
    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    int totalEleitores;
    scanf("%d", &totalEleitores);

    if(totalEleitores > 10 || totalEleitores < 1)
    {
        printf("ELEICAO ANULADA\n");
        exit(1);
    } 
    
    eleicao.totalEleitores = 0;
    
    for(int i = 0; i < totalEleitores; i++)
    {   
        eleicao.eleitores[eleicao.totalEleitores] = LeEleitor();
        eleicao.totalEleitores++;
    }
    for(int i = 0; i < totalEleitores; i++)
    {
        for(int j = i+1; j < totalEleitores; j++)
        {
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
            {
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }
    }

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;

    for(int i = 0; i < totalEleitores; i++)
    {   
        if (ObtemVotoPresidente(eleicao.eleitores[i]) == 0)
            eleicao.votosBrancosPresidente++;
        else
            eleicao.votosNulosPresidente++;
        for(int j = 0; j < eleicao.totalPresidentes; j++)
        {
            if(VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(eleicao.eleitores[i])))
            {
                eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                eleicao.votosNulosPresidente--;
            }
        }

        if (ObtemVotoGovernador(eleicao.eleitores[i]) == 0)
            eleicao.votosBrancosGovernador++;
        else
            eleicao.votosNulosGovernador++;
        for(int j = 0; j < eleicao.totalGovernadores; j++)
        {
            if(VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(eleicao.eleitores[i])))
            {
                eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                eleicao.votosNulosGovernador--;
            }
        }
    }
    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    int maior_qtd_votos_p = ObtemVotos(eleicao.presidentes[0]);
    int maior_qtd_votos_g = ObtemVotos(eleicao.governadores[0]);

    //if (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente > eleicao.totalEleitores)
    for(int i = 0; i < eleicao.totalPresidentes; i++)
    {
        for(int j = i; j < eleicao.totalPresidentes; j++)
        {
            if(!EhMesmoCandidato(eleicao.presidentes[i], eleicao.presidentes[j]))
            {
                if (ObtemVotos(eleicao.presidentes[i]) > ObtemVotos(eleicao.presidentes[j]))
                {
                    if (maior_qtd_votos_p < ObtemVotos(eleicao.presidentes[i]))
                        maior_qtd_votos_p = ObtemVotos(eleicao.presidentes[i]);
                }
                else
                {
                    if (maior_qtd_votos_p < ObtemVotos(eleicao.presidentes[j]))
                        maior_qtd_votos_p = ObtemVotos(eleicao.presidentes[j]);
                }
            }
        }
    }
    for(int i = 0; i < eleicao.totalGovernadores; i++)
    {
        for(int j = i; j < eleicao.totalGovernadores; j++)
        {
            if(!EhMesmoCandidato(eleicao.governadores[i], eleicao.governadores[j]))
            {
                if (ObtemVotos(eleicao.governadores[i]) > ObtemVotos(eleicao.governadores[j]))
                {
                    if (maior_qtd_votos_g < ObtemVotos(eleicao.governadores[i]))
                        maior_qtd_votos_g = ObtemVotos(eleicao.governadores[i]);
                }
                else
                {
                    if (maior_qtd_votos_g < ObtemVotos(eleicao.governadores[j]))
                        maior_qtd_votos_g = ObtemVotos(eleicao.governadores[j]);
                }
            }
        }
    }

    int count = 0;
    int winner = 0;
    for(int i = 0; i < eleicao.totalPresidentes; i++)
    {
        if(ObtemVotos(eleicao.presidentes[i]) == maior_qtd_votos_p)
        {
            count++;
            winner = i;
        }
    }
    printf("- PRESIDENTE ELEITO: ");
    if(count > 1)
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else if (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente > maior_qtd_votos_p)
        printf("SEM DECISAO\n");
    else
        ImprimeCandidato(eleicao.presidentes[winner], CalculaPercentualVotos(eleicao.presidentes[winner], eleicao.totalEleitores));

    count = 0;
    winner = 0;
    for(int i = 0; i < eleicao.totalGovernadores; i++)
    {
        if(ObtemVotos(eleicao.governadores[i]) == maior_qtd_votos_g)
        {
            count++;
            winner = i;
        }
    }

    printf("- GOVERNADOR ELEITO: ");
    if(count > 1)
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else if (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador > maior_qtd_votos_g)
        printf("SEM DECISAO\n");
    else
        ImprimeCandidato(eleicao.governadores[winner], CalculaPercentualVotos(eleicao.governadores[winner], eleicao.totalEleitores));
    printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosGovernador + eleicao.votosNulosPresidente, eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente);
}
