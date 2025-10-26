#include <stdio.h>

int ReduzInteiro(int n);
int MontaSenha(int senha, int dig);
int ReduzCodigo();

int main (void)
{
    char texto = 0;
    int senha = 0;

    while (1)
    {
        scanf ("%c", &texto);
        if (texto == '.')
        {
            printf (".");
            break;
        }
        else if (texto == '(')
        {
            int resultado = ReduzCodigo();
            if (resultado == -1)
            {
                printf ("[ERRO]");
                continue;
            }
            printf ("[");
            printf ("%i", resultado);
            printf ("]");

            senha = MontaSenha(senha, resultado);
        }
        else
        {
            printf ("%c", texto);
        }
    }
    printf (" SENHA:%i\n", senha);
    return 0;
}

int ReduzInteiro(int n)
{
    int direita = 0, esquerda = 0;

    direita = n % 10;
    esquerda = n / 10;

    return direita + esquerda;
}

int MontaSenha(int senha, int dig)
{
    return (senha * 10) + dig;
}

int ReduzCodigo()
{
    char x = 0;
    int codigo = 0;
    scanf ("%c", &x);

    if (!(x >= '0' && x <= '9'))
    {
        return -1;
    }
    codigo += x - '0';

    while (1)
    {
        scanf ("%c", &x);
        if (x == ')')
        {
            break;
        }
        codigo += x - '0';
        if (codigo >= 10)
        {
            codigo = ReduzInteiro(codigo);
        }
    }
    return codigo;
}