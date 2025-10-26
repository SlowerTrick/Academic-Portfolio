#include <stdio.h>
#include <stdlib.h>
void ConcatenaString(char * str1, char * str2, char * strOut);

int main()
{
    char nome[1000];
    char sobrenome[1000];
    char nomeCompleto[2000];
    while (scanf("%s", &sobrenome) == 1 && scanf("%s", &nome) == 1)
    {
        ConcatenaString(nome, sobrenome, nomeCompleto);
        printf("%s\n", nomeCompleto);
    }
    return 0; 
}

void ConcatenaString(char * str1, char * str2, char * strOut)
{
    int contador1 = 0, contador2 = 0;

    while (str1[contador1] != '\0')
    {
        strOut[contador1] = str1[contador1];
        contador1++;
    }
    while (str2[contador2] != '\0')
    {
        strOut[contador1] = str2[contador2];
        contador1++;
        contador2++;
    }
    strOut[contador1] = '\0';
    return;
}
