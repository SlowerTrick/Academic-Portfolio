#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
}
tData;

bool VerificaAnoBissexto(tData data);
int VerificaDias(tData data);

int main (void)
{
    tData data;
    int total = 0, i = 0;
    scanf("%i", &total);
    
    for (i = 0; i < total; i ++)
    {
        scanf ("%i %i %i", &data.dia, &data.mes, &data.ano);

        if (data.mes > 12)
        {
            data.mes = 12; 
        }
        if (data.mes < 1)
        {
            data.mes = 1; 
        }
        if (data.dia > 28)
        {
            if (data.mes == 2)
            {
                if (!VerificaAnoBissexto(data))
                {
                    data.dia = 28;
                }
            }
            if (data.mes != 2)
            {
                if (VerificaDias(data) == 1)
                {
                    if (data.dia > 31)
                    {
                        data.dia = 31;
                    }
                }
                if (VerificaDias(data) == 0)
                {
                    if (data.dia > 30)
                    {
                        data.dia = 30;
                    }
                }
            }
        }

        if (VerificaAnoBissexto(data))
        {
            if (data.dia < 10)
            {
                printf ("'0%i/", data.dia);
            }
            else
            {
                printf ("'%i/", data.dia);
            }
            if (data.mes < 10)
            {
                printf ("0%i/", data.mes);
            }
            else
            {
                printf ("%i/", data.mes);
            }
            printf ("%i'", data.ano);
            printf (":Bisexto\n", data.ano);
        }
        else
        {
            if (data.dia < 10)
            {
                printf ("'0%i/", data.dia);
            }
            else
            {
                printf ("'%i/", data.dia);
            }
            if (data.mes < 10)
            {
                printf ("0%i/", data.mes);
            }
            else
            {
                printf ("%i/", data.mes);
            }
            printf ("%i'", data.ano);
            printf (":Normal\n", data.ano);
        }
    }  
}

bool VerificaAnoBissexto(tData data)
{
    if (((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0)))
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