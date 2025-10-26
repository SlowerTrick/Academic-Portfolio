#include <stdio.h>

void desenhar (int topo, int meio);

int main (void)
{
    int topo = 0, meio = 0;
    scanf("%i%i", &topo, &meio);

    desenhar(topo, meio);

    return 0;
}

void desenhar (int topo, int meio)
{
    int i = 0, j = 0;

    while (topo <= meio)
    {
        for (j = 0; j < (meio - topo ) / 2; j++)
        {
            printf ("_");
        }
        for (j = 0; j < topo; j++)
        {
            printf ("$");
        }
        for (j = 0; j < (meio - topo ) / 2; j++)
        {
            printf ("_");
        }
        printf ("\n");
        topo +=2;
    }

    int traco = 1;
    meio -= 2;

    while (meio >= 1)
    {
        for (j = 0; j < traco; j++)
        {
            printf ("_");
        }

        for (j = 0; j < meio; j++)
        {
            printf ("$");
        }

        for (j = 0; j < traco; j++)
        {
            printf ("_");
        }

        printf ("\n");
        traco++;
        meio -= 2;
    }
}