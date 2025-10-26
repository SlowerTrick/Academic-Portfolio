#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    tBanco *banco = CriaBanco();
    LeBanco(banco);

    while(1)
    {
        char opacao;
        scanf(" %c%*c", &opacao);
        if(opacao == 'A')
        {
            tAgencia *agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }
        else if(opacao == 'C')
        {
            tConta *conta = CriaConta();
            LeConta(conta);
            int id;
            scanf("%d%*c", &id);
            InsereContaBanco(banco, id, conta);
        }
        else if(opacao == 'F')
        {
            ImprimeRelatorioBanco(banco);
            DestroiBanco(banco);
            break;
        }
    }
    return 0;
}