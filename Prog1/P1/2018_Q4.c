#include <stdio.h>

int main (void)
{
    int hora = 0, minuto = 0, minutoadicional = 0, dia = 0;
    int horaadicional = 0;
    scanf ("%i:%i %i", &hora, &minuto, &minutoadicional);

    minuto += minutoadicional;

    while (minuto >= 60)
    {
        minuto -= 60;
        hora++;
    }
    while (hora >= 24)
    {
        hora -= 24;
        dia++;
    }
    
    if (dia > 0)
    {
        if (dia == 1)
        {
            printf ("(%i dia)", dia);
        }
        else
        {
            printf ("(%i dias)", dia);
        }
    }
    if (hora > 0)
    {
        if (hora == 1)
        {
            printf ("(%i hora)", hora);
        }
        else
        {
            printf ("(%i horas)", hora);
        }
    }
    if (minuto > 0)
    {
        if (minuto == 1)
        {
            printf ("(%i minuto)\n", minuto);
        }
        else
        {
            printf ("(%i minutos)\n", minuto);
        }
    }
}