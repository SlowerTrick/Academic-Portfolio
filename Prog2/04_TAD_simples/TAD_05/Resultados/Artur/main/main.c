#include "conta.h"
#include <stdio.h>

int main(void)
{
    int total;
    scanf("%d", &total);
    tConta contasUsuarios[total];
    int contas = 0;
    
    while(1)
    {
        char operacao;
        scanf(" %c", &operacao);
        if (operacao == '0')
        {
            break;
        }
        else if (operacao == '1')
        {
            int conta, valor, indexConta;
            scanf(" %d %d", &conta, &valor);
            
            for(int i = 0; i < total; i++)
            {
                if (VerificaConta(contasUsuarios[i], conta))
                {
                    indexConta = i;
                    break;
                }
            }
            contasUsuarios[indexConta] = SaqueConta(contasUsuarios[indexConta], valor);
        }
        else if (operacao == '2')
        {
            int conta, valor, indexConta;
            scanf(" %d %d", &conta, &valor);

            for(int i = 0; i < total; i++)
            {
                if (VerificaConta(contasUsuarios[i], conta))
                {
                    indexConta = i;
                    break;
                }
            }
            contasUsuarios[indexConta] = DepositoConta(contasUsuarios[indexConta], valor);
        }
        else if (operacao == '3')
        {
            int numero;
            char nome[50], cpf[15];
            scanf(" %s %s %d", nome, cpf, &numero);
            tUsuario usuario = CriaUsuario(nome, cpf);
            contasUsuarios[contas++] = CriaConta(numero, usuario);
        }
        else if (operacao == '4')
        {
            printf("===| Imprimindo Relatorio |===\n");
            for(int i = 0; i < total; i++)
            {
                ImprimeConta(contasUsuarios[i]);
            }
        }
    }
    return 0;
}