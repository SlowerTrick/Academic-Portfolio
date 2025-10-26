#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

int main(void)
{
    Conta *contas[1000];
    int total_contas = 0;

    while(1)
    {
        int opcao;
        scanf("%d", &opcao);

        if(opcao == 0)
        {
            for(int i = 0; i < total_contas; i++)
            {
                Usuario *usuario = RecuperaUsuario(contas[i]);
                DestroiUsuario(usuario);
                DestroiConta(contas[i]);
            }
            break;
        }
        else if(opcao == 1)
        {
            int id_conta, valor;
            scanf("%d %d", &id_conta, &valor);
            Conta *conta_temp = BuscaConta(contas, total_contas, id_conta);
            if(conta_temp)
                Saque(conta_temp, valor);
        }
        else if(opcao == 2)
        {
            int id_conta, valor;
            scanf("%d %d", &id_conta, &valor);
            Conta *conta_temp = BuscaConta(contas, total_contas, id_conta);
            if(conta_temp)
                Deposito(conta_temp, valor);
        }
        else if(opcao == 3)
        {
            int id_conta1, id_conta2, valor;
            scanf("%d %d %d", &id_conta1, &id_conta2, &valor);
            Conta *conta_temp1 = BuscaConta(contas, total_contas, id_conta1);
            Conta *conta_temp2 = BuscaConta(contas, total_contas, id_conta2);
            if(conta_temp1 && conta_temp2)
                Transferencia(conta_temp1, conta_temp2, valor);
        }
        else if(opcao == 4)
        {
            char nome[1000];
            int cpf, id_conta;
            scanf("%s %d %d", nome, &cpf, &id_conta);
            Usuario *usuario = CriaUsuario(nome, cpf);
            contas[total_contas++] = CriaConta(usuario, id_conta);
        }
        else if(opcao == 5)
        {
            printf("===| Imprimindo Relatorio |===\n");
            for(int i = 0; i < total_contas; i++)
            {
                printf("Conta: %d\n", RecuperaNConta(contas[i]));
                printf("Saldo: R$ %.2f\n", RecuperaSaldo(contas[i]));
                printf("Nome: %s\n", RecuperaNomeUsuario(RecuperaUsuario(contas[i])));
                printf("CPF: %d\n\n", RecuperaCpfUsuario(RecuperaUsuario(contas[i])));
            }
        }
        else if(opcao == 6)
        {
            int id_conta, n_transacoes;
            scanf(" %d %d%*c", &id_conta, &n_transacoes);
            Conta *conta_temp = BuscaConta(contas, total_contas, id_conta);

            if(conta_temp)
            {
                float *transacoes = RecuperaMovimentacoes(conta_temp);
                int transacoes_totais = RecuperaQtdMovimentacoes(conta_temp);
                printf("===| Imprimindo Extrato |===\n");
                printf("Conta: %d\n", RecuperaNConta(conta_temp));
                printf("Saldo: R$ %.2f\n", RecuperaSaldo(conta_temp));
                printf("Nome: %s\n", RecuperaNomeUsuario(RecuperaUsuario(conta_temp)));
                printf("CPF: %d\n\n", RecuperaCpfUsuario(RecuperaUsuario(conta_temp)));
                if(transacoes_totais >= n_transacoes)
                    printf("Ultimas %d transações\n", n_transacoes);
                else
                    printf("Ultimas %d transações\n", transacoes_totais);
                for(int i = transacoes_totais - 1; i > transacoes_totais - n_transacoes - 1; i--)
                {
                    if(i >= 0)
                        printf("%.2f\n", transacoes[i]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}