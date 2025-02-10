#include "pessoa.h"
#include <stdio.h>

int main(void)
{
    int total_pessoas;
    scanf("%d%*c", &total_pessoas);
    tPessoa pessoas[total_pessoas];
    
    for(int i = 0; i < total_pessoas; i++)
    {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }
    
    AssociaFamiliasGruposPessoas(pessoas, total_pessoas);

    for(int i = 0; i < total_pessoas; i++)
    {
        ImprimePessoa(&pessoas[i]);
    }
    return 0;
}