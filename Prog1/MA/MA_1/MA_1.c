#include <stdio.h>

int main (int argc, char *argv[])
{
    FILE *arquivo = NULL;
    arquivo = fopen(argv[1], "r");
    if (!arquivo)
    {
        printf ("Erro ao abrir o arquivo");
        return 1;
    }

    while (!feof(arquivo))
    {
        printf ("-> ");
        char c = 0;
        int contador = 0;

        while (c != '\n' && !feof(arquivo))
        {
            fscanf(arquivo, "%c", &c);
            if (c == ';')
            {
                if (contador == 0)
                {
                    printf (" tem ");
                    contador++;
                }
                else if (contador == 1)
                {
                    printf (" anos e cursa ");
                    contador++;
                }
            }
            else
            {
                if (!feof(arquivo))
                {
                    printf ("%c", c);
                }
            }
        }
        contador = 0;
        printf ("\n");
    }
    printf ("\n");
    fclose(arquivo);
}