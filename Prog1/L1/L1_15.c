#include <stdio.h>

int main(void) 
{
    int num, temp, digito, ordem;
    int indice = 0;
    int digitos[5] = {0};

    scanf("%i%i", &num, &ordem);

    temp = num;

    while (temp != 0) {
        digito = temp % 10;
        digitos[indice] = digito;
        indice++;
        temp = temp / 10;
    }
    
    int algarismo_ordem = digitos[ordem - 1];
    
    if (algarismo_ordem % 2 == 0) 
    {
        printf("PAR\n");
    } 
    else 
    {
        printf("IMPAR\n");
    }

    return 0;
}