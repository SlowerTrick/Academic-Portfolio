#include <stdio.h>
#include <string.h>

int main (void)
{
    char string[1000];
    int i = 0, tamanho = 0;
    fgets(string, 1000, stdin);

    tamanho = strlen(string) - 1;

    printf("RESP:");

    for (i = 0; i <= tamanho; i++)
    {
        if (string[i] == ' ')
        {
            string[i] = '_';
            printf ("%c", string[i]);
        }
        else 
        printf ("%c", string[i]);
    }

    return 0;
}