#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool CodigoValido (char codigo[3]);
bool EhIgual (char *codigo1, char *codigo2);

int main (void)
{
    FILE *arquivoInput = NULL, *arquivoOutput = NULL;
    arquivoInput = fopen("input/entrada3.txt", "r");
    arquivoOutput = fopen("outprog/saida3.txt", "w");
    if (!arquivoInput)
    {   
        printf ("Erro ao abrir o arquivo");
        return 1;
    }
    char codigo1[4];
    char codigo2[4];

    while (!feof(arquivoInput))
    {
        fscanf(arquivoInput, " %c %c %c %c %c %c", &codigo1[0], &codigo1[1], &codigo1[2], &codigo2[0], &codigo2[1], &codigo2[2]);
        codigo1[3] = '\0';
        codigo2[3] = '\0';
        printf ("%s %s\n", codigo1, codigo2);

        if (CodigoValido(codigo1) && CodigoValido(codigo2))
        {
            if (EhIgual(codigo1, codigo2))
            {
                fprintf (arquivoOutput, "IGUAIS");
            }
            else
            {
                fprintf (arquivoOutput, "DIFERENTES");
            }
        }
        else
        {
            fprintf (arquivoOutput, "INVALIDO");
        }

        if (!feof(arquivoInput))
        {
            fprintf (arquivoOutput, "\n");
        }
    }
    fclose(arquivoInput);
    fclose(arquivoOutput);
}

bool CodigoValido (char codigo[3])
{
    int verificador = 0;

    if (isalpha(codigo[0]) || isdigit(codigo[0]))
    {
        verificador++;
    }
    if (isalpha(codigo[1]) || isdigit(codigo[1]))
    {
        verificador++;
    }
    if (isalpha(codigo[2]) || isdigit(codigo[2]))
    {
        verificador++;
    }

    if (verificador == 3)
    {
        return true;
    }
    return false;
}

bool EhIgual (char *codigo1, char *codigo2)
{
    for (int i = 0; i < 3; i++)
    {
        if (!(toupper(codigo1[i]) == toupper(codigo2[i])))
        {
            return false;
        }
    }
    return true;
}