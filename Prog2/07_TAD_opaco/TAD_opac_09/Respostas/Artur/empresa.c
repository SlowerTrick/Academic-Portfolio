#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct empresa
{
    int id;
    int qtd_total_funcionarios;
    int qtd_atual_funcionarios;
    tFuncionario **funcionarios;
};

/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa()
{
    tEmpresa *e = malloc(sizeof(*e));
    e->id = -1;
    e->qtd_atual_funcionarios = 0;
    e->qtd_total_funcionarios = -1;
    e->funcionarios = NULL;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa)
{
    scanf("%d %d", &empresa->id, &empresa->qtd_total_funcionarios);
    empresa->funcionarios = malloc(sizeof(tFuncionario *) * empresa->qtd_total_funcionarios);
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa)
{
    if(empresa)
    {
        for(int i = 0; i < empresa->qtd_total_funcionarios; i++)
            ApagaFuncionario(empresa->funcionarios[i]);
        empresa->funcionarios = NULL;
        free(empresa);
    }
    empresa = NULL;
}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario)
{
    for(int i = 0; i < empresa->qtd_atual_funcionarios; i++)
    {
        if(GetIdFuncionario(empresa->funcionarios[i]) == GetIdFuncionario(funcionario))
            return;
    }
    empresa->funcionarios[empresa->qtd_atual_funcionarios++] = funcionario;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa)
{
    printf("Empresa %d:\n", empresa->id);
    for(int i = 0; i < empresa->qtd_atual_funcionarios; i++)
        ImprimeFuncionario(empresa->funcionarios[i]);
}