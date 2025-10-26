#include <stdio.h>
#include <stdlib.h>

void VerificaDiferenca (int poste[], int total);

int main (void)
{
    int total = 0, i = 0;
    scanf("%i", &total);
    int postes[total];

    for (i = 0; i < total; i++)
    {
        scanf ("%i", &postes[i]);
    }
    VerificaDiferenca (postes, total);
    return 0;
}

void VerificaDiferenca (int poste[], int total)
{
    int i = 0, j = 0, diferenca = -1, maiordiferenca = 0;
    if (total == 1)
    {
        printf ("IMPOSSIVEL");
        return;
    }

    for (i = 0; i < total - 1; i++)
    {
        diferenca = abs(poste[i] - poste[i+1]); 
        if (diferenca > maiordiferenca)
        {
            maiordiferenca = diferenca;
        }
    }

    for (i = 0; i < total - 1; i++)
    {
        diferenca = abs(poste[i] - poste[i+1]);
        if (diferenca == maiordiferenca)
        {
            printf (" (%i %i)", i, i+1);
        }
    }

}