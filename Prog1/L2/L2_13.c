#include <stdio.h>
#include <string.h>

int main (void)
{
    char string[1000];
    int tamanho = 0, i = 0, verificador = 1;

    while (verificador == 1)
    {
        scanf ("%c", &string[i]);

        if (string[i] == '!' || string[i] == '.' || string[i] == '?')
        {
            verificador++;
        }

        if (string[i] > 'Z' && verificador == 1)
        {
            string[i] = string[i] - 32;
            printf ("%c", string[i]);
        }
        else
        
        printf ("%c", string[i]);

        i++;
    }
    return 0;
}