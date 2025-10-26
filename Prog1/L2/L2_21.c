#include <stdio.h>

int main (void)
{
    int numeros[9];
    int index = 0;
    int i = 0;
    char c = 0;
    
    scanf ("%i", &index);

    for (i = 0; i < index; i++)
    {
        scanf("%i", &numeros[i]);
    }
    getchar();

    while (scanf("%c", &c) != EOF)
    {
        printf ("%c", c);
    }

}