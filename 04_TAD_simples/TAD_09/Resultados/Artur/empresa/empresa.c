#include "empresa.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id)
{
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;
    return empresa;
}

tEmpresa leEmpresa()
{
    tEmpresa empresa;
    int id;
    scanf("%d", &id);
    getchar();
    empresa = criaEmpresa(id);
    empresa.qtdFuncionarios = 0;
    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{
    for(int i = 0; i < empresa.qtdFuncionarios; i++)
    {
        if(getIdFuncionario(empresa.funcionarios[i]) == getIdFuncionario(funcionario))
        {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);
            return empresa;
        }
    }
    empresa.funcionarios[empresa.qtdFuncionarios++] = funcionario;
    printf("\n\n%d\n\n", empresa.qtdFuncionarios);
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa)
{
    printf("Empresa %d:\n", empresa.id);
    for(int i = 0; i < empresa.qtdFuncionarios; i++)
    {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}
