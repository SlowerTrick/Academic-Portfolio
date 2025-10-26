#include <stdio.h>
#include <ctype.h>

int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);
int EhNumero(char c);
int AnalisaSenha();

int main (void)
{   
    int grupo = 0, i = 0, j = 0;
    int grupomaisforte = 0, grupomaisfraco = 0, grupomaisinvalido = 0;
    int qtdmaisforte = 0, qtdmaisfraco = 0, qtdmaisinvalido = 0;
    int contador1 = 0, contador2 = 0, contador3 = 0;
    
    scanf ("%i", &grupo);
    getchar();

    for (i = 0; i < grupo; i++)
    {
        printf ("GRUPO %i\n", i+1);

        while (1)
        {
            int usuario = 0;
            scanf("%i", &usuario);

            if (usuario == -1)
            {
                break;
            }

            int senha = AnalisaSenha();
            if (senha == 0)
            {
                printf ("INVALIDA\n");
                contador1++;
            }

            else if (senha == 1)
            {
                printf ("FRACA\n");
                contador2++;
            }
            else
            {
                printf ("FORTE\n");
                contador3++;
            }
        }
        if (contador1 > qtdmaisinvalido)
        {
            qtdmaisinvalido = contador1;
            grupomaisinvalido = i+1;
        }
        if (contador2 > qtdmaisfraco)
        {
            qtdmaisfraco = contador2;
            grupomaisfraco = i+1;
        }
        if (contador3 > qtdmaisforte)
        {
            qtdmaisforte = contador3;
            grupomaisforte = i+1;
        }
        printf ("\n");
        contador1 = 0;
        contador2 = 0;
        contador3 = 0;
    }
    printf ("FORTES: GRUPO(%i) QTD(%i)\n", grupomaisforte, qtdmaisforte);
    printf ("FRACAS: GRUPO(%i) QTD(%i)\n", grupomaisfraco, qtdmaisfraco);
    printf ("INVALIDAS: GRUPO(%i) QTD(%i)\n", grupomaisinvalido, qtdmaisinvalido);

    return 0;
}

int EhLetraMaiuscula(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    return 0;
}

int EhLetraMinuscula(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    return 0;
}

int EhNumero(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int AnalisaSenha()
{
    int verificador1 = 0, verificador2 = 0, verificador3 = 0, verificador4 = 0; 
    int contador = 0;
    char digito = 0;
    getchar();

    while (1)
    {
        scanf("%c", &digito);
        if (digito == ')')
        {
            break;
        }

        if (isalpha(digito))
        {
            if (isupper(digito))
            {
                verificador1 = 1;
            }
            if (islower(digito))
            {
                verificador2 = 1;
            }
        }

        if (isdigit(digito))
        {
            verificador3 = 1;
        }

        if (!(isalpha(digito)) && !(isdigit(digito)))
        {
            verificador4 = 1;
        }
        contador++;
    }

    if (contador < 6)
    {
        return 0;
    }
    else if (verificador1 == 0 || verificador2 == 0 || verificador3 == 0 || verificador4 == 0)
    {
        return 1;
    }
    else if (verificador1 == 1 && verificador2 == 1 && verificador3 == 1 && verificador4 == 1)
    {
        return 2;
    }
}