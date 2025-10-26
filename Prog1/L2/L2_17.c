#include <stdio.h>

int main (void)
{
    int opcao = 0, codigo = 0, i = 0;
    scanf("%i%i", &opcao, &codigo);
    getchar();
    
    char c = 0;
    codigo = codigo % 26; // Garante que o código esteja no intervalo de 0 a 25

    if(opcao == 1)
    {
        while (scanf("%c", &c) != EOF)
        {
            if (c == '.')
            {
                printf (".");
                break;
            }

            if (c >= 'a' && c <= 'z')
            {
                c += codigo;
                if (c > 'z')
                {
                    c = 'a' + (c - 'z') - 1;
                    printf ("%c", c);
                }
                else
                {
                    printf ("%c", c);
                }
            } 
            else
            {
                printf ("%c", c);
            }
        }
    }

    else if (opcao == 2)
    {
        while (scanf("%c", &c) != EOF)
        {
            if (c == '.')
            {
                printf (".");
                break;
            }
            if (c >= 'a' && c <= 'z')
            {
                c -= codigo;
                if (c < 'a')
                {
                    c = 'z' - ('a' - c) + 1;
                    printf ("%c", c);
                }
                else
                {
                    printf ("%c", c);
                }
            } 
            else
            {
                printf ("%c", c);
            }
        }
    }

    else
    {
        printf("Operacao invalida.");
    }
    return 0;
}