#include <stdio.h>
#include <ctype.h>
#include <string.h>

int EhVogal(char c);

int main(void)
{
    char palavra[1000];
    while (scanf("%s", &palavra) == 1)
    {
        int vogais = 0, consoantes = 0;
        
        int i = 0, j = 0;
        for (i = 0; i < strlen(palavra); i++)
        {
            if (isalpha(palavra[i]))
            {
                if (EhVogal(palavra[i]))
                {
                    vogais++;
                }
                else
                {
                    consoantes++;
                }
            }
        }

        if (vogais == consoantes)
        {
            printf ("%s\n", palavra);
        }
        else if (vogais > consoantes)
        {
            for (i = 0; i < strlen(palavra); i++)
            {
                if (EhVogal(palavra[i]) && !isdigit(palavra[i]))
                {
                    printf ("%c", palavra[i]);
                }
            }
            printf ("\n");
        }
        else if (consoantes > vogais)
        {
            for (i = 0; i < strlen(palavra); i++)
            {
                if (!EhVogal(palavra[i]) && !isdigit(palavra[i]))
                {
                    printf ("%c", palavra[i]);
                }
            }
            printf ("\n");
        }
    }
    return 0;
}

int EhVogal(char c)
{
    if (toupper(c) == 'A' || toupper(c) == 'E' || toupper(c) == 'I' || toupper(c) == 'O' || toupper(c) == 'U')
    {
        return 1;
    }
    return 0;
}