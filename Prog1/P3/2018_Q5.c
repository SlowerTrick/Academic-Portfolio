#include <stdio.h>

int main(void)
{
    int total = 0;
    scanf ("%d", &total);
    int numeros1[51];
    int numeros2[51];

    int i = 0;
    while (total != 0)
    {
        int contador1 = 0, contador2 = 0, contador3 = 0;
        int temp = 0;
        while (1)
        {
            scanf ("%d", &temp);
            if (temp == -1)
            {
                break;
            }
            else
            {
                numeros1[contador1] = temp;
                contador1++;
            }
        }
        while (1)
        {
            scanf ("%d", &temp);
            if (temp == -1)
            {
                break;
            }
            else
            {
                numeros2[contador2] = temp;
                contador2++;
            }
        }

        int resultado[52] = {0};
        int numeroASerSomado = 0;
        while (contador1 >= 0)
        {
            if (contador1 > 0)
            {
                if (contador2 > 0)
                {
                    resultado[contador1] = numeros1[contador1 - 1] + numeros2[contador2 - 1] + numeroASerSomado;
                    if (resultado[contador1] >= 10)
                    {
                        numeroASerSomado = resultado[contador1] / 10;
                        resultado[contador1] = resultado[contador1] % 10;
                    }
                }
                else
                {
                    resultado[contador1] = numeros1[contador1 - 1] + numeroASerSomado;
                    if (resultado[contador1] >= 10)
                    {
                        numeroASerSomado = resultado[contador1] / 10;
                        resultado[contador1] = resultado[contador1] % 10;
                    }
                    else
                    {
                        numeroASerSomado = 0;
                    }
                }
            }
            else
            {
                if (numeroASerSomado > 0)
                {
                    resultado[contador1] = numeroASerSomado;
                }
            }
            contador2--;
            contador1--;
            contador3++;
        }
        total--;

        int i = 0;
        for (i = 0; i < contador3; i++)
        {
            if (i == 0)
            {
                if (numeroASerSomado > 0)
                {
                    printf("%d", resultado[i]);
                }
                continue;
            }
            printf("%d", resultado[i]);
        }
        printf("\n");
    }
}