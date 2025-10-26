#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main()
{
    float num1, num2;

    while (scanf("%f %f", &num1, &num2) == 2 )
    {
        float result;
        result = Soma(num1, num2);
        printf("%.2f", result);
        result = Subtracao(num1, num2);
        printf(" %.2f", result);
        result = Divisao(num1, num2);
        printf(" %.2f", result);
        result = Multiplicacao(num1, num2);
        printf(" %.2f\n", result);
    }

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