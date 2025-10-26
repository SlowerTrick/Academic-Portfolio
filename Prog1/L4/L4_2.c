#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
}
tData;

bool VerificaDatasIguais(tData data1, tData data2);
int VerificaDias(tData data);
bool VerificaAnoBissexto(tData data);

int main (void)
{
    tData data1;
    tData data2;

    scanf ("%i %i %i", &data1.dia, &data1.mes, &data1.ano);
    scanf ("%i %i %i", &data2.dia, &data2.mes, &data2.ano);

    if (data1.mes > 12)
    {
        data1.mes = 12; 
    }
    if (data1.mes < 1)
    {
        data1.mes = 1; 
    }
    if (data2.mes > 12)
    {
        data2.mes = 12; 
    }
    if (data2.mes < 1)
    {
        data2.mes = 1; 
    }
    if (data1.dia > 28)
    {
        if (data1.mes == 2)
        {
            if (!VerificaAnoBissexto(data1))
            {
                data1.dia = 28;
            }
        }
        if (data1.mes != 2)
        {
            if (VerificaDias(data1) == 1)
            {
                if (data1.dia > 31)
                {
                    data1.dia = 31;
                }
            }
            if (VerificaDias(data1) == 0)
            {
                if (data1.dia > 30)
                {
                    data1.dia = 30;
                }
            }
        }
    }
        
    if (data2.dia > 28)
    {
        if (data2.mes == 2)
        {
            if (!VerificaAnoBissexto(data2))
            {
                data2.dia = 28;
            }
        }
        if (data2.mes != 2)
        {
            if (VerificaDias(data2) == 1)
            {
                if (data2.dia > 31)
                {
                    data2.dia = 31;
                }
            }
            if (VerificaDias(data2) == 0)
            {
                if (data2.dia > 30)
                {
                    data2.dia = 30;
                }
            }
        }
    }
    
    while (1)
    {
        if (VerificaDatasIguais(data1, data2) == true)
        {
            break;
        }
        if (data1.dia < 10)
        {
            printf ("'0%i/", data1.dia);
        }
        else
        {
            printf ("'%i/", data1.dia);
        }
        if (data1.mes < 10)
        {
            printf ("0%i/", data1.mes);
        }
        else
        {
            printf ("%i/", data1.mes);
        }
        printf ("%i'\n", data1.ano);

        if (VerificaDias(data1) == 2)
        {
            data1.dia++;
            if (data1.dia > 28)
            {
                if (!VerificaAnoBissexto(data1))
                {
                    data1.dia = 1;
                    data1.mes++;
                }
                else
                {
                    if (data1.dia == 30)
                    {
                        data1.dia = 1;
                        data1.mes++;
                    }
                }
            }
        }
        else if (VerificaDias(data1) == 1)
        {
            data1.dia++;
            if (data1.dia > 31 && data1.mes != 12)
            {
                data1.dia = 1;
                data1.mes++;
            }
            if (data1.dia > 31 && data1.mes == 12)
            {
                data1.dia = 1;
                data1.mes = 1;
                data1.ano++;
            }
        } 
        else if (VerificaDias(data1) == 0)
        {
            data1.dia++;
            if (data1.dia > 30)
            {
                data1.dia = 1;
                data1.mes++;
            }
        }
    }
    return 0;
}

bool VerificaDatasIguais(tData data1, tData data2)
{
    if (data1.dia == data2.dia && data1.mes == data2.mes && data1.ano == data2.ano)
    {   
        return true;
    }
    return false;
}

int VerificaDias(tData data)
{
    if (data.mes == 2)
    {
        return 2;
    }
    else if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool VerificaAnoBissexto(tData data)
{
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0))
    {
        return true;
    }
    return false;
}
