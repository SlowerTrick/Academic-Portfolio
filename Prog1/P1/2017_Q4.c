#include <stdio.h>

int main (void)
{
    int hora1 = 0, minuto1 = 0, segundo1 = 0, hora2 = 0, minuto2 = 0, segundo2 = 0;
    scanf("%i%i%i%i%i%i", &hora1, &minuto1, &segundo1, &hora2, &minuto2, &segundo2);

    if (hora1 == hora2 && minuto1 == minuto2 && segundo1 == segundo2)
    {
        printf ("IGUAIS");
        return 0;
    }
    printf ("RESP:");

    int somatorio1 = (hora1 + minuto1 + segundo1) / 10;
    int somatorio2 = (hora2 + minuto2 + segundo2) / 10;
    
    if (somatorio1 >= 10)
    {
        somatorio1 = somatorio1 % 10;
    }
    if (somatorio2 >= 10)
    {
        somatorio2 = somatorio2 % 10;
    }

    if (hora1 > hora2)
    {
        printf ("%i", somatorio1);
    }

    else if (hora2 > hora1)
    {
        printf ("%i", somatorio2);
    }

    else if (hora1 == hora2 && minuto1 > minuto2)
    {
        printf ("%i", somatorio1);
    }

    else if (hora2 == hora1 && minuto2 > minuto1)
    {
        printf ("%i", somatorio2);
    }

    else if (hora1 == hora2 && minuto1 == minuto2 && segundo1 > segundo2)
    {
        printf ("%i", somatorio1);
    }

    else if (hora2 == hora1 && minuto2 == minuto1 && segundo2 > segundo1)
    {
        printf ("%i", somatorio2);
    }
    return 0;
}