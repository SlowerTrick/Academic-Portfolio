#include "data.h"
#include <stdio.h>

int main(void)
{
    tData datas[2];
    for (int i = 0; i < 2; i++)
    {
        int dia, mes, ano;
        scanf("%d/%d/%d", &dia, &mes, &ano);
        datas[i] = CriaData(dia, mes, ano);
        if (!VerificaDataValida(datas[i]))
        {
            printf("A primeira e/ou segunda data(s) invalida(s)\n");
            return 1;
        }
    }
    printf("Primeira data: ");
    ImprimeDataExtenso(datas[0]);
    printf("Segunda data: ");
    ImprimeDataExtenso(datas[1]);

    int data_mais_antiga = ComparaData(datas[0], datas[1]);
    if (data_mais_antiga == -1)
    {
        printf("A primeira data eh mais antiga\n");
    }
    else if (data_mais_antiga == 1)
    {
        printf("A segunda data eh mais antiga\n");
    }
    else
    {
        printf("As datas sao iguais\n");    
    }

    printf("A diferenca em dias entre as datas eh: %.2d dias\n", CalculaDiferencaDias(datas[0], datas[1]));
}