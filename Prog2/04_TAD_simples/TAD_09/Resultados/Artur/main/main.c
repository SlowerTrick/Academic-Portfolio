#include <stdio.h>
#include "empresa.h"

int main(void)
{
    int total;
    scanf("%d", &total);
    getchar();
    getchar();
    tEmpresa empresa[total];
    
    for(int i = 0; i < total; i++)
    {
        empresa[i] = leEmpresa();
        int qtdFuncionarios;
        scanf("%d", &qtdFuncionarios);
        getchar();
        for(int j = 0; j < qtdFuncionarios; j++)
        {
            tFuncionario funcionario = leFuncionario();
            empresa[i] = contrataFuncionarioEmpresa(empresa[i], funcionario);
        }
    }
    for(int i = 0; i < total; i++)
    {
        imprimeEmpresa(empresa[i]);
    }
}