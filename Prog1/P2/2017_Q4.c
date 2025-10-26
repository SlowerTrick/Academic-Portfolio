#include <stdio.h>
#include <ctype.h>

/* Função para verificar se o caractere é uma letra */
int EhLetra(char c) 
{
    return isalpha(c) ? 1 : 0;
}

/* Função para verificar se o caractere é uma vogal */
int EhVogal(char c) 
{
    char vogais[] = "aeiouAEIOU";
    int i;
    for (i = 0; vogais[i] != '\0'; i++) 
    {
        if (c == vogais[i]) 
        {
            return 1;
        }
    }
    return 0;
}

/* Função para reconhecer o símbolo e consumir caracteres até o próximo asterisco */
int ReconheceSimbolo() 
{
    char proximoChar;
    int simbolo = -1; /* Valor padrão para símbolo inválido */

    /* Ler o próximo caractere após o asterisco */
    scanf("%c", &proximoChar);

    /* Verificar se é um dos símbolos válidos */
    if (proximoChar >= '1' && proximoChar <= '3') 
    {
        char proximoProximoChar;
        scanf("%c", &proximoProximoChar);
        if (proximoProximoChar == '*') 
        {
            simbolo = proximoChar - '0'; /* Converte char para int */
        } 
        else 
        {
            /* Consumir todos os caracteres até o próximo asterisco */
            while (proximoProximoChar != '*' && scanf("%c", &proximoProximoChar) == 1);
        }
    } 
    else 
    {
        /* Consumir todos os caracteres até o próximo asterisco */
        while (proximoChar != '*' && scanf("%c", &proximoChar) == 1);
    }

    return simbolo;
}

int main() 
{
    char c;
    int contLetras = 0, contVogais = 0, contConsoantes = 0;
    int simbolo;

    while (scanf("%c", &c) == 1 && c != '.') 
    {
        if (EhLetra(c)) 
        {
            contLetras++;
            if (EhVogal(c)) 
            {
                contVogais++;
            } 
            else 
            {
                contConsoantes++;
            }
        }

        if (c == '*') 
        {
            simbolo = ReconheceSimbolo();
            switch (simbolo) 
            {
                case 1:
                    printf("*L:%d V:%d C:%d*", contLetras, contVogais, contConsoantes);
                    contLetras = contVogais = contConsoantes = 0;
                    break;
                case 2:
                    printf("*V:%d*", contVogais);
                    contVogais = 0;
                    break;
                case 3:
                    printf("*C:%d*", contConsoantes);
                    contConsoantes = 0;
                    break;
                default:
                    printf("*ERRO*");
                    break;
            }
        } 
        else if (EhLetra(c)) 
        {
            printf("%c", c);
        }
    }

    printf("."); /* Imprime o ponto final ao final do input */
    return 0;
}