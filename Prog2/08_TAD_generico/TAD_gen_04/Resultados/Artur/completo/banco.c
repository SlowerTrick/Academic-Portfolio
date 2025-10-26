#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Banco
{
    char nome[1000];
    tAgencia **agencias;
    int qtd_agencias_total;
    int qtd_agencias_atuais;
};

 
 /**
  * @brief Função para criar um novo banco.
  * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
  */
tBanco *CriaBanco()
{
    tBanco *b = malloc(sizeof(*b));
    if(!b)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
    b->qtd_agencias_total = 10;
    b->qtd_agencias_atuais = 0;
    b->agencias = malloc(sizeof(tAgencia *) * b->qtd_agencias_total);
    if(!b->agencias)
    {
        free(b);
        printf("ERRO! falta de memoria");
        exit(1);
    }
    return b;
}
 
 /**
  * @brief Função para destruir um banco.
  * @param banco O banco a ser destruído.
  */
void DestroiBanco(tBanco *banco)
{
    if(banco)
    {
        for(int i = 0; i < banco->qtd_agencias_atuais; i++)
            DestroiAgencia(banco->agencias[i]);
        free(banco->agencias);
        banco->agencias = NULL;
        free(banco);
    }
    banco = NULL;
}
 
 /**
  * @brief Função para ler o nome de um banco.
  * @param banco O banco a ser lido.
  */
void LeBanco(tBanco *banco)
{
    scanf("%[^\n]%*c", banco->nome);
}
 
 /**
  * @brief Função para adicionar uma agência a um banco.
  * @param banco O banco.
  * @param agencia A agência a ser adicionada.
  */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia)
{
    if(banco->qtd_agencias_atuais == banco->qtd_agencias_total)
    {
        banco->qtd_agencias_total += 10;
        banco->agencias = realloc(banco->agencias, sizeof(tAgencia *) * banco->qtd_agencias_total);
    }
    banco->agencias[banco->qtd_agencias_atuais++] = agencia;
}
 
 /**
  * @brief Função para inserir uma conta em uma agência pertencente ao banco.
  * @param banco O banco.
  * @param numAgencia O número da agência.
  * @param cliente A conta a ser inserida.
  * @pre A agência deve pertencer ao banco.
 */
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente)
{
    for(int i = 0; i < banco->qtd_agencias_atuais; i++)
    {
        if(ComparaAgencia(numAgencia, banco->agencias[i]))
        {
            AdicionaConta(banco->agencias[i], cliente);
            break;
        }      
    }
}
 
 /**
  * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
  * @param banco O banco.
  */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    for(int i = 0; i < banco->qtd_agencias_atuais; i++)
    {
        ImprimeDadosAgencia(banco->agencias[i]);
    }
}