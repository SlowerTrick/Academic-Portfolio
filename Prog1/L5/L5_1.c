#include <stdio.h>
#include <math.h>

int main (void)
{
    int participantes = 0, i = 0, nota = 0, maiornota = -1, menornota = 101, contador = 0;
    int reprovado = 0, aprovado = 0;
    float desvio = 0, somatorio = 0;
    scanf ("%i", &participantes);
    int notas[participantes];

    for (i = 0; i < participantes; i++)
    {
        scanf ("%i", &nota);
        somatorio += nota;
        if (nota > maiornota)
        {
            maiornota = nota;
        }
        if (nota < menornota)
        {
            menornota = nota;
        }
        if (nota < 70)
        {
            reprovado++;
        }
        notas[contador] = nota;
        contador++;
    }
    float media = somatorio / contador;
    somatorio = 0;

    for (i = 0; i < participantes; i++)
    {
        somatorio += pow((notas[i] - media), 2);
        if (notas[i] > media)
        {
            aprovado++;
        }
    }
    desvio = sqrt((somatorio / contador));

    printf ("MENOR:%i, MAIOR:%i, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%i, REPROV:%i", menornota, maiornota, media, desvio, aprovado, reprovado);
    return 0;
}
