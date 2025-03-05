#include "software.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Software
{
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    int tempo;
};

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo)
{
    Software *s = malloc(sizeof(*s));
    if(!s)
    {
        printf("ERRO! Falta de memoria");
        exit(1);
    }
    strcpy(s->nome, nome);
    strcpy(s->categoria, categoria);
    strcpy(s->motivo, motivo);
    s->impacto = impacto;
    s->tempo = 0;
    return s;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Software *lerSoftware()
{
    char nome[MAX_TAM_NOME_SOFTWARE], categoria[MAX_TAM_CAT], motivo[MAX_TAM_MOTIVO];
    int impacto;
    scanf("%[^\n] %[^\n] %d %[^\n]%*c", nome, categoria, &impacto, motivo);
    Software *s = criaSoftware(nome, categoria, impacto, motivo);
    return s;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s)
{
    if(strcmp(s->categoria, "BUG") == 0)
        s->tempo = TEMPO_ESTIMADO_BUG + s->impacto;
    else if(strcmp(s->categoria, "OUTROS") == 0)
        s->tempo = TEMPO_ESTIMADO_OUTROS + s->impacto;
    else if(strcmp(s->categoria, "DUVIDA") == 0)
        s->tempo = TEMPO_ESTIMADO_DUVIDA + s->impacto;
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado)
{
    Software *s = (Software *) dado;
    return s->tempo;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware()
{
    return 'S';
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s)
{
    Software *software = (Software *) s;
    if(software)
        free(software);
    software = NULL;
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaSoftware(void *dado)
{
    Software *s = (Software *) dado;
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n", s->nome);
    printf("- Categoria: %s\n", s->categoria);
    printf("- Nível do impacto: %d\n", s->impacto);
    printf("- Motivo: %s\n", s->motivo);
    printf("- Tempo estimado: %dh\n", s->tempo);
}