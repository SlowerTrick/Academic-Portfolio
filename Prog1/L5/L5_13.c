#include <stdio.h>
#include <stdlib.h>

int ComparaString(char * str1, char * str2);

int main()
{
    char str1[1000];
    char str2[1000];
    while ( scanf("%s", &str1) == 1 && scanf("%s", &str2) == 1)
    {
        if (ComparaString(str1, str2)) 
        printf("IGUAL\n");
        else
        printf("DIFERENTE\n");
    }
    return 0; 
}

int ComparaString(char * str1, char * str2)
{
    int contador1 = 0, contador2 = 0;

    while (str1[contador1] != '\0')
    {
        contador1++;
    }
    while (str2[contador2] != '\0')
    {
        contador2++;
    }

    if (contador1 != contador2)
    {
        return 0;
    }

    int i = 0;
    for (i = 0; i < contador1; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}