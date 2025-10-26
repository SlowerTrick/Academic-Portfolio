#include <stdio.h>

int EhDigito(char c);
char LeProxChar(char terminador);
void ImprimePorExtenso(char digito);


int main (void)
{
    char delimitador = 0, c = 0, proximo = 0;
    int contador = 0;
    scanf ("%c ", &delimitador);

    while (1)
    {
        c = LeProxChar(delimitador);

        if(c == 0)
        {
            break;
        }

        if (EhDigito(c))
        {
            while (1)
            {
                scanf ("%c", &proximo);
                if (proximo >= '0' && proximo <= '9')
                {
                    if (contador == 0)
                    {
                        printf ("%c", c);
                        contador++;
                    }
                    printf ("%c", proximo);
                }
                if (contador == 0)
                {
                    ImprimePorExtenso(c);
                    if (proximo != delimitador)
                    {
                        printf ("%c", proximo);
                    }
                    break;
                }
                if (contador > 0 && !(proximo >= '0' && proximo <= '9'))
                {
                    if (proximo != delimitador)
                    {
                        printf ("%c", proximo);
                    }
                    break;
                } 
            }
        }
        else
        {
            printf ("%c", c);
        }
        contador = 0;
    }
    return 0;
}

int EhDigito(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

char LeProxChar(char terminador)
{
    char next = 0;
    scanf ("%c", &next);

    if (next != terminador)
    {
        return next;
    }
    return 0;
}

void ImprimePorExtenso(char digito)
{
    if (digito == '0')
    {
        printf ("zero");
        return;
    }
    if (digito == '1')
    {
        printf ("um");
        return;
    }
    if (digito == '2')
    {
        printf ("dois");
        return;
    }
    if (digito == '3')
    {
        printf ("tres");
        return;
    }
    if (digito == '4')
    {
        printf ("quatro");
        return;
    }
    if (digito == '5')
    {
        printf ("cinco");
        return;
    }
    if (digito == '6')
    {
        printf ("seis");
        return;
    }
    if (digito == '7')
    {
        printf ("sete");
        return;
    }
    if (digito == '8')
    {
        printf ("oito");
        return;
    }
    if (digito == '9')
    {
        printf ("nove");
        return;
    }
    return;
}