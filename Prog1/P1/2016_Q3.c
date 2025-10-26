#include <stdio.h>
#include <ctype.h>

int main (void)
{
    char primeiro = 0, segundo = 0, terceiro = 0, quarto = 0;
    scanf ("%c%c%c%c", &primeiro, &segundo, &terceiro, &quarto);

    if (!isupper(primeiro))
    {
        printf ("Invalido");
        return 1;
    }
    if (!isdigit(segundo))
    {
        printf ("Invalido"); 
        return 1;
    }
    if (!(terceiro == 'a' || terceiro == 'A' || terceiro == 'e' || terceiro == 'E' || terceiro == 'i' || terceiro == 'I' || terceiro == 'o' || terceiro == 'O' || terceiro == 'u' || terceiro == 'U'))
    {
        printf ("Invalido"); 
        return 1;
    }

    if (!(quarto == 'b' || quarto == 'c' || quarto == 'd' || quarto == 'f' || quarto == 'g' || quarto == 'h' || quarto == 'j' || quarto == 'k' || quarto == 'l' || quarto == 'm' || quarto == 'n' || quarto == 'p' || quarto == 'q' || quarto == 'r' || quarto == 's' || quarto == 't' || quarto == 'v' || quarto == 'w' || quarto == 'x' || quarto == 'y' || quarto == 'z'))
    {
        printf("Invalido");
        return 1;
    }

    printf ("%c%c%c%c", toupper(primeiro), segundo, toupper(terceiro), toupper(quarto));
    return 0;
}