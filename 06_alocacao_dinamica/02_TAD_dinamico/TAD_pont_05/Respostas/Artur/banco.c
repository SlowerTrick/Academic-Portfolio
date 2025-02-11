#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco *b = malloc(sizeof(tBanco));
    if(!b)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    b->contas = malloc(sizeof(tConta *) * 5);
    if(!b->contas)
    {
        free(b);
        printf("Erro! falta de memoria");
        exit(1);
    }
    b->contasAlocadas = 5;
    b->qtdContas = 0;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    if(banco)
    {
        for(int i = 0; i < banco->qtdContas; i++)
            DestroiConta(banco->contas[i]);
        free(banco->contas);
        free(banco);
    }
    banco = NULL;
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    tConta *c = CriaConta();
    LeConta(c);
    banco->contas[banco->qtdContas++] = c;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int index, valor;
    scanf("%d %d", &index, &valor);
    int c;
    while ((c = getchar()) != '\n' && c == ' ' || c == '\t') {
        // Continua removendo caracteres em branco
    }
    if (c != '\n') {
        // Se o caractere não for uma quebra de linha, devolve-o ao buffer
        ungetc(c, stdin);
    }

    for(int i = 0; i < banco->qtdContas; i++)
    {
        if(VerificaConta(banco->contas[i], index))
        {
            SaqueConta(banco->contas[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int index, valor;
    scanf("%d %d", &index, &valor);
    int c;
    while ((c = getchar()) != '\n' && c == ' ' || c == '\t') {
        // Continua removendo caracteres em branco
    }
    if (c != '\n') {
        // Se o caractere não for uma quebra de linha, devolve-o ao buffer
        ungetc(c, stdin);
    }

    for(int i = 0; i < banco->qtdContas; i++)
    {
        if(VerificaConta(banco->contas[i], index))
        {
            DepositoConta(banco->contas[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    int index1, index2, valor;
    scanf("%d %d %d", &index1, &index2, &valor);
    int c;
    while ((c = getchar()) != '\n' && c == ' ' || c == '\t') {
        // Continua removendo caracteres em branco
    }
    if (c != '\n') {
        // Se o caractere não for uma quebra de linha, devolve-o ao buffer
        ungetc(c, stdin);
    }

    int flagConta1 = 0, flagConta2 = 0, indexConta1 = -1, indexConta2 = -1;
    for(int i = 0; i < banco->qtdContas; i++)
    {
        if(VerificaConta(banco->contas[i], index1) || VerificaConta(banco->contas[i], index2))
        {
            if(VerificaConta(banco->contas[i], index1))
            {
                flagConta1 = 1;
                indexConta1 = i;
            }
            else if (VerificaConta(banco->contas[i], index2))
            {
                flagConta2 = 1;
                indexConta2 = i;
            }
            
        }        
    }

    if(flagConta1 && flagConta2)
        TransferenciaConta(banco->contas[indexConta1], banco->contas[indexConta2], valor);
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");
    for(int i = 0; i < banco->qtdContas; i++)
    {
        ImprimeConta(banco->contas[i]);
        printf("\n");
    }
}
