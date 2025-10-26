#include <stdio.h>

int main(void)
{
    char digito1 = 0, digito2 = 0, digito3 = 0, digito4 = 0, digito5 = 0, digito6 = 0;
    char digito7 = 0, digito8 = 0, digito9 = 0, digito10 = 0, digito11 = 0;

    int falha = 0;

    scanf("%c%c%c.%c%c%c.%c%c%c-%c%c", &digito1, &digito2, &digito3, &digito4, &digito5, &digito6, &digito7, &digito8, &digito9, &digito10, &digito11);

    // Verifica se todos os dígitos são iguais
    if (digito1 == digito2 && digito2 == digito3 && digito3 == digito4 && digito4 == digito5 && digito5 == digito6 && digito6 == digito7 && digito7 == digito8 && digito8 == digito9 && digito9 == digito10 && digito10 == digito11)
    {
        printf("CPF invalido: digitos iguais!");
        return 1;
    }

    int soma = ((digito1 - '0') * 10) + ((digito2 - '0') * 9) + ((digito3 - '0') * 8) + ((digito4 - '0') * 7) + ((digito5 - '0') * 6) + ((digito6 - '0') * 5) + ((digito7 - '0') * 4) + ((digito8 - '0') * 3) + ((digito9 - '0') * 2);
    int resto = soma % 11;
    int primeiro_digito_verificador;
    if (resto < 2)
    {
        primeiro_digito_verificador = 0;
    }
    else
    {
        primeiro_digito_verificador = 11 - resto;
    }

    soma = ((digito1 - '0') * 11) + ((digito2 - '0') * 10) + ((digito3 - '0') * 9) + ((digito4 - '0') * 8) + ((digito5 - '0') * 7) + ((digito6 - '0') * 6) + ((digito7 - '0') * 5) + ((digito8 - '0') * 4) + ((digito9 - '0') * 3) + (primeiro_digito_verificador * 2);

    resto = soma % 11;
    int segundo_digito_verificador;
    if (resto < 2)
    {
        segundo_digito_verificador = 0;
    }
    else
    {
        segundo_digito_verificador = 11 - resto;
    }

    if (digito10 != primeiro_digito_verificador + '0' || digito11 != segundo_digito_verificador + '0')
    {
        if (digito10 != primeiro_digito_verificador + '0' && digito11 != segundo_digito_verificador + '0')
        {
            printf("CPF invalido: dois digitos!");
        }
        else if (digito10 != primeiro_digito_verificador + '0')
        {
            printf("CPF invalido: primeiro digito!");
        }
        else
        {
            printf("CPF invalido: segundo digito!");
        }
        return 1;
    }

    printf("CPF valido!");
    return 0;
}