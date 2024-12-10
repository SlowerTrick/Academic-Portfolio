#include "data.h"
#include <stdio.h>

tData CriaData(int dia, int mes, int ano)
{
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int VerificaDataValida(tData data)
{
    if (data.mes < 1 || data.mes > 12)
        return 0;
    else if (data.dia < 1 || data.dia > NumeroDiasMes(data))
        return 0;
    else if (data.ano < 0)
        return 0;
    return 1;
}

void ImprimeMesExtenso(tData data)
{
    switch (data.mes)
    {
        case 1:
        {
            printf("Janeiro");
            break;
        }
        case 2:
        {
            printf("Fevereiro");
            break;
        }
        case 3:
        {
            printf("Marco");
            break;
        }
        case 4:
        {
            printf("Abril");
            break;
        }
        case 5:
        {
            printf("Maio");
            break;
        }
        case 6:
        {
            printf("Junho");
            break;
        }
        case 7:
        {
            printf("Julho");
            break;
        }
        case 8:
        {
            printf("Agosto");
            break;
        }
        case 9:
        {
            printf("Setembro");
            break;
        }
        case 10:
        {
            printf("Outubro");
            break;
        }
        case 11:
        {
            printf("Novembro"); 
            break;
        }
        case 12:
        {
            printf("Dezembro");
            break;
        }
    }
}

void ImprimeDataExtenso(tData data)
{
    printf("%.2d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
}

int VerificaBissexto(tData data)
{
    return ((data.ano % 4 == 0 && data.ano % 100 != 0) || data.ano % 400 == 0);
}

int NumeroDiasMes(tData data)
{
    int mes = data.mes;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        return 31;
    }
    else if (mes != 2)
    {
        return 30;
    }
    else
    {
        if (VerificaBissexto(data))
            return 29;
        return 28;
    }
}

int ComparaData(tData data1, tData data2)
{
    if (data1.ano > data2.ano)
    {
        return 1;
    }
    else if (data1.ano < data2.ano)
    {
        return -1;
    }

    if (data1.mes > data2.mes)
    {
        return 1;
    }
    else if (data1.mes < data2.mes)
    {
        return -1;
    }

    if (data1.dia > data2.dia)
    {
        return 1;
    }
    else if (data1.dia < data2.dia)
    {
        return -1;
    }
    return 0;
}

int CalculaDiasAteMes(tData data)
{
    return NumeroDiasMes(data) - data.dia;
}

int CalculaDiferencaDias(tData data1, tData data2)
{
    if(data2.dia < data1.dia && data2.mes < data1.mes && data2.ano < data1.ano)
    {
        tData temp = data1;
        data1 = data2;
        data2 = temp;
    }

    tData temp = data1;
    int dias = 0;
    while (temp.ano != data2.ano || temp.mes != data2.mes || temp.dia != data2.dia)
    {
        if(temp.dia <= NumeroDiasMes(temp))
        {
            dias++;
            temp.dia++;
        }
        else
        {
            if(temp.mes == 12)
            {
                temp.mes = 1;
                temp.dia = 1;
                temp.ano++;
            }
            else
            {
                temp.dia = 1;
                temp.mes++;
            }
        }

    }
    return dias;
}
