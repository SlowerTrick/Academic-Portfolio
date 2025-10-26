#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int total;
    scanf("%d", &total);
    tEmpresa *empresas[total];

    for(int i = 0; i < total; i++)
    {
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);

        for(int i = 0; i < empresas[i])
    }
}