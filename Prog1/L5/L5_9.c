#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int verificapH(float pH);
int verificaGotaChuvaAcida(float pH);
float porcentagem(float total, float valor);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

int main (void)
{
    int area = 0, densidade = 0, tempo = 0;
    int gotasacidas = 0, gotasbasicas = 0, gotasneutras = 0;
    float gota = 0;
    float pHmaisacido = 10, pHmaisbasico = 7, pHmaisneutro = 10;
    int chuvaacida = 0, chuvabasica = 0, totalgotas = 0;
        
    scanf ("%i%i%i", &area, &densidade, &tempo);

    while (scanf("%f", &gota) != EOF)
    {
        int pH = verificapH(gota);

        if (fabs(7 - gota) < fabs(7 - pHmaisneutro))
        {
            pHmaisneutro = gota;
        }

        if (pH == 0)
        {
            gotasneutras++;
            totalgotas++;
        }
        else if (pH == 1)
        {
            if (gota < pHmaisacido)
            {
                pHmaisacido = gota;
            }
            gotasacidas++;
            totalgotas++;
            if (verificaGotaChuvaAcida(gota))
            {
                chuvaacida++;
            }
        }
        else if (pH == 2)
        {
            if (gota > pHmaisbasico)
            {
                pHmaisbasico = gota;
            }
            gotasbasicas++;
            totalgotas++;
        }
        if (!verificaGotaChuvaAcida(gota))
        {
                chuvabasica++;
         }
    }
    if (gotasacidas == 0 && gotasbasicas == 0 && gotasneutras == 0)
    {
        printf ("Nenhuma gota foi avaliada");
        return 0;
    }
    else
    {
        printf ("%i %i %i %.2f %.2f %.2f\n", gotasacidas, gotasbasicas, gotasneutras, pHmaisacido, pHmaisbasico, pHmaisneutro);
    }

    float porcentagemChuvaAcida = porcentagem(totalgotas, chuvaacida);
    float porcentagemChuvaNormal = porcentagem(totalgotas, chuvabasica);
    imprimeResultadosAnalise(porcentagemChuvaAcida, porcentagemChuvaNormal);

    return 0;
}

int verificapH(float pH)
{
    if (pH == 7)
    {
        return 0;
    }
    else if (pH < 7)
    {
        return 1;
    }
    else if (pH > 7)
    {
        return 2;
    }
}

int verificaGotaChuvaAcida(float pH)
{
    if (pH < 5.7)
    {
        return true;
    }
    return false;
}

float porcentagem(float total, float valor)
{
    return (valor / total) * 100;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal)
{
    if (porcentagemGotasChuvaAcida >= 75.0)
    {
        printf ("Chuva Acida ");
    }
    else if (porcentagemGotasChuvaNormal >= 75.0)
    {
        printf ("Chuva Normal ");
    }
    else
    {
        printf ("Chuva com indicios de chuva acida ");
    }
    printf ("%.2f%% ", porcentagemGotasChuvaAcida);
    printf ("%.2f%%", porcentagemGotasChuvaNormal);
}