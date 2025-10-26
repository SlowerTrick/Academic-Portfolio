#include <stdio.h>

void VerificaOrdem (int nota[], int total);

int main (void)
{
    int participantes = 0, i = 0;
    scanf ("%i", &participantes);
    int nota[participantes];

    for (i = 0; i < participantes; i++)
    {
        scanf("%i", &nota[i]);
    }
    VerificaOrdem (nota, participantes);
    return 0;
}

void VerificaOrdem (int nota[], int total)
{
    if (total == 1)
    {
        printf ("CRESCENTE&DECRESCENTE");
        return;
    }

    int i = 0;
    for (i = 0; i < total - 1; i++)
    {
        if (!(nota[i] == nota[i+1]))
        {
            break;
        }
        if (i == total - 2)
        {
            printf ("CRESCENTE&DECRESCENTE");
            return;
        }
    }
    for (i = 0; i < total - 1; i++)
    {
        if (!(nota[i] >= nota[i+1]))
        {
            break;
        }
        if (i == total - 2)
        {
            printf ("DECRESCENTE");
            return;
        }
    }

    for (i = 0; i < total - 1; i++)
    {
        if (!(nota[i] <= nota[i+1]))
        {
            break;
        }
        if (i == total - 2)
        {
            printf ("CRESCENTE");
            return;
        }
    }
    printf ("DESORDENADO");
    return;
}