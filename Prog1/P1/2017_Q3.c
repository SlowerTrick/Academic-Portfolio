#include <stdio.h>
#include <ctype.h>

int main (void)
{
    char primeiro = 0, segundo = 0;
    char terceiro = 0, quarto = 0;
    scanf("%c%c %c%c", &primeiro, &segundo, &terceiro, &quarto);

    if (!((isdigit(primeiro) || isalpha(primeiro)) && (isdigit(segundo) || isalpha(segundo)) && (isdigit(terceiro) || isalpha(terceiro)) && (isdigit(quarto) || isalpha(quarto))))
    {
        printf ("Invalido");
        return 1;
    }

    if (toupper(primeiro) == toupper(terceiro) && toupper(segundo) == toupper(quarto))
    {
        printf ("IGUAIS");
        return 0;
    }
    if (toupper(primeiro) != toupper(terceiro) || toupper(segundo) != toupper(quarto))
    {
        printf ("DIFERENTES");
        return 0;
    }
}