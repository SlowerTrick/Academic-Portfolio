#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Cria uma nova conta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para a nova conta criada.
 */
tConta *CriaConta()
{
    tConta *c = malloc(sizeof(tConta));
    if(!c)
    {
        printf("Erro! falta de memoria");
        exit(1);
    }
    c->numero = 0;
    c->saldo = 0;
    c->user = CriaUsuario();
    return c;
}

/**
 * @brief Desaloca a memória de uma conta.
 * 
 * @param conta Ponteiro para a conta a ser destruída.
 */
void DestroiConta(tConta *conta)
{
    DestroiUsuario(conta->user);
    free(conta);
    conta = NULL;
}

/**
 * @brief Lê os dados de uma conta e do usuario atraves da entrada padrão.
 * 
 * @param conta Ponteiro para a conta a ser lida.
 */
void LeConta(tConta *conta)
{
    LeUsuario(conta->user);
    scanf("%d", &conta->numero);
    int c;
    while ((c = getchar()) != '\n' && isspace(c)) {
        // Continua removendo caracteres em branco
    }
    if (c != '\n') {
        // Se o caractere não for uma quebra de linha, devolve-o ao buffer
        ungetc(c, stdin);
    }
}

/**
 * @brief Imprime os dados de uma conta e do proprietário.
 * 
 * @param conta Ponteiro para a conta a ser impressa.
 */
void ImprimeConta(tConta *conta)
{
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

/**
 * @brief Verifica se uma conta possui o numero especificado.
 * 
 * @param conta Ponteiro para a conta a ser verificada.
 * @param numero Número da conta a ser verificado.
 * @return 1 se a conta possui o número especificado, 0 caso contrário.
 */
int VerificaConta(tConta *conta, int numero)
{
    return conta->numero == numero;
}

/**
 * @brief Realiza um saque em uma conta caso o saldo seja suficiente.
 * 
 * @param conta Ponteiro para a conta a ser sacada.
 * @param valor Valor a ser sacado.
 */
void SaqueConta(tConta *conta, float valor)
{
    if(conta->saldo >= valor)
        conta->saldo -= valor;
}

/**
 * @brief Realiza um depósito em uma conta.
 * 
 * @param conta Ponteiro para a conta a ser depositada.
 * @param valor Valor a ser depositado.
 */
void DepositoConta(tConta *conta, float valor)
{
    conta->saldo += valor;
}

/**
 * @brief Realiza uma transferência entre duas contas, caso o saldo da conta de origem seja suficiente.
 * 
 * @param destino Ponteiro para a conta de destino.
 * @param origem Ponteiro para a conta de origem.
 * @param valor Valor a ser transferido.
*/
void TransferenciaConta(tConta *destino, tConta *origem, float valor)
{
    if(origem->saldo >= valor)
    {
        destino->saldo += valor;
        origem->saldo -= valor;
    }
}
