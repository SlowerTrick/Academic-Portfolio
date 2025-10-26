#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    tBanco *banco = CriaBanco();
    while (1)
    {
        char operacao;
        scanf("%c",&operacao);
        int flag_sair_programa = 0;

        switch (operacao)
        {
            case 'A':
                AbreContaBanco(banco);
                break;

            case 'D':
                DepositoContaBanco(banco);
                break;

            case 'S':
                SaqueContaBanco(banco);
                break;
            
            case 'T':
                TransferenciaContaBanco(banco);
                break;
            
            case 'R':
                ImprimeRelatorioBanco(banco);
                break;
            
            case 'F':
                DestroiBanco(banco);
                flag_sair_programa = 1;
                break;
            
            default:
                break;
        }
        if(flag_sair_programa)
            break;
    }
    return 0;
}