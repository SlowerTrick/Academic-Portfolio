#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int ArmazenaTexto(char array[][500]);
void PrintaTextoInvertido(char array[][500], int totalpalavras);
bool EhLetra(char c);

int main(void)
{
    char texto[500][500];
    int palavras = ArmazenaTexto(texto);
    PrintaTextoInvertido(texto, palavras);
    return 0;
}

bool EhLetra(char c)
{
    return isalpha(c);
}

int ArmazenaTexto(char array[][500])
{
    int i = 0, j = 0, totalpalavras = 0;
    char c;

    while ((c = getchar()) != EOF)
    {
        if (EhLetra(c))
        {
            array[i][j++] = c;
        }
        else if (c == '-' || c == '\'')
        {
            if (j > 0)
            {
                array[i][j] = '\0';
                i++;
                j = 0;
                totalpalavras++;
            }
        }
        else
        {
            if (j > 0)
            {
                array[i][j] = '\0';
                i++;
                j = 0;
                totalpalavras++;
            }
        }
    }

    if (j > 0)
    {
        array[i][j] = '\0';
        totalpalavras++;
    }

    return totalpalavras;
}

void PrintaTextoInvertido(char array[][500], int totalpalavras)
{
    int i = 0;
    for (i = totalpalavras - 1; i >= 0; i--)
    {
        printf("%s ", array[i]);
    }
}