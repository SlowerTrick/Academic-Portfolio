#include <stdio.h>

float FazOperacao(float num1, float num2, char op);
float ResolveExpressao();

int main (void)
{
    char c = 0;
    float maior = 0, provisorio = 0;

    while (scanf("%c", &c) != EOF)
    {
        if (c == '.')
        {
            printf (".");
            break;
        }

        if (c != '(')
        {
            printf ("%c", c);
        }
        else
        {
            provisorio = ResolveExpressao();
            printf ("%.2f", provisorio);
            if (provisorio > maior)
            {
                maior = provisorio;
            }
        }
    }
    printf (" MAIOR:%.2f", maior);
    return 0;
}

float FazOperacao(float num1, float num2, char op)
{
    if (op == '+')
    {
        return num1 + num2;
    }
    if (op == '-')
    {
        return num1 - num2;
    }
    if (op == '*')
    {
        return num1 * num2;
    }
    if (op == '/')
    {
        return num1 / num2;
    }
}

float ResolveExpressao()
{
    char op = 0, caractere = 0;
    float x = 0, y = 0, z = 0, resultado = 0;
    scanf ("%f %f %c%c", &x, &y, &op, &caractere);

    resultado = FazOperacao(x, y, op);

    if (caractere == ')')
    {
        return resultado;
    }

    while (caractere != ')')
    {
        scanf ("%f %c%c", &x, &op, &caractere);
        resultado = FazOperacao(resultado, x, op);
    }

    return resultado;
}