#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};


/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData()
{
    tData *d = malloc(sizeof(*d));
    d->dia = -1;
    d->mes = -1;
    d->ano = -1;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data)
{
    scanf("%d/%d/%d%*c", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data)
{
    free(data);
    data = NULL;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data)
{
    if (data->ano < 1) 
    {
        return 0;
    }

    if (data->mes < 1 || data->mes > 12) 
    {
        return 0;
    }

    int diasNoMes;
    if (data->mes == 2) 
    {
        diasNoMes = VerificaBissexto(data) ? 29 : 28;
    } 
    else if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) 
    {

        diasNoMes = 30;
    } 
    else 
    {
        diasNoMes = 31;
    }

    return(data->dia < 1 || data->dia > diasNoMes);
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data)
{
    const char* meses[] = {
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    if (data->mes >= 1 && data->mes <= 12) {
        printf("%s\n", meses[data->mes - 1]);
    } else {
        printf("Mês inválido!\n");
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data)
{
    const char* meses[] = {
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    // Verifica se a data é válida antes de imprimir
    if (VerificaDataValida(data))
    {
        printf("%d de %s de %d\n", data->dia, meses[data->mes - 1], data->ano);
    } 
    else 
    {
        printf("Data inválida!\n");
    }
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data)
{
    return ((data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0));

}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data)
{
    return data->dia;
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2)
{
    if (data1->ano != data2->ano)
        return (data1->ano > data2->ano) ? 1 : -1;
    if (data1->mes != data2->mes) 
        return (data1->mes > data2->mes) ? 1 : -1;
    if (data1->dia != data2->dia)
        return (data1->dia > data2->dia) ? 1 : -1;
    return 0;
}

int DiasNoMes(tData *d, int mes, int ano) {
    if (mes == 2) {
        return VerificaBissexto(d) ? 29 : 28;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    return 31;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data)
{
    int dias = 0;
    for (int mes = 1; mes < data->mes; mes++) {
        dias += DiasNoMes(data, mes, data->ano);
    }
    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */

int DataParaDias(tData* data) {
    int totalDias = 0;
    
    // Soma os dias dos anos anteriores
    for (int ano = 1; ano < data->ano; ano++) {
        totalDias += VerificaBissexto(data) ? 366 : 365;
    }
    
    // Soma os dias dos meses anteriores no ano atual
    totalDias += CalculaDiasAteMes(data);
    
    // Soma os dias do mês atual
    totalDias += data->dia;
    
    return totalDias;
}

int CalculaDiferencaDias(tData* data1, tData* data2) {
    int diasData1 = DataParaDias(data1);
    int diasData2 = DataParaDias(data2);
    return abs(diasData1 - diasData2);
}