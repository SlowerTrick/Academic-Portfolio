#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main(void)
{
    float num1 = 0, num2 = 0, resultado = 0, extra = 1;
    char operacao = 0;

    scanf("%f%f %c", &num1, &num2, &operacao);
    if (operacao == '+')
    {
        resultado = Soma(num1, num2);
    }
    if (operacao == '-')
    {
        resultado = Subtracao(num1, num2);
    }
    if (operacao == '*')
    {
        resultado = Multiplicacao(num1, num2);
    }
    if (operacao == '/')
    {
        resultado = Divisao(num1, num2);
    }

    while (scanf("%f %c", &extra, &operacao) != EOF)
    {
        if (operacao == '+')
        {
            resultado = Soma(resultado, extra);
        }
        if (operacao == '-')
        {
            resultado = Subtracao(resultado, extra);
        }
        if (operacao == '*')
        {
            resultado = Multiplicacao(resultado, extra);
        }
        if (operacao == '/')
        {
            resultado = Divisao(resultado, extra);
        }
    }
    printf ("%.2f", resultado);

    return 0; 
}

float Soma(float num1, float num2)
{
    float soma = 0;
    soma = num1 + num2;

    return soma;
}

float Subtracao(float num1, float num2)
{
    float subtracao = 0;
    subtracao = num1 - num2;

    return subtracao;
}

float Divisao(float num1, float num2)
{
    float divisao = 0;
    divisao = num1 / num2;

    return divisao;
}

float Multiplicacao(float num1, float num2)
{
    float multiplicacao = 0;
    multiplicacao = num1 * num2;

    return multiplicacao;
}