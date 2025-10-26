#include <stdio.h>
#include <stdbool.h>

char Codifica(char c, int n);
char Decodifica (char c, int codigo);
int EhLetra (char c);
int EhLetraMaiuscula (char c);
int EhLetraMinuscula (char c);


int main (void)
{
    int opcao = 0, codigo = 0, i = 0;
    scanf("%i%i", &opcao, &codigo);
    getchar();
    
    char c = 0;
    codigo = codigo % 26;

    if(opcao == 1)
    {
        while (scanf("%c", &c) != EOF)
        {
            if (c == '.')
            {
                printf (".");
                break;
            }
            
            if (EhLetra(c))
            {
            	printf("%c", Codifica(c, codigo));
            }
            else
            {
                printf ("%c", c);
            }
        }
    }

    else if (opcao == 2)
    {
        while (scanf("%c", &c) != EOF)
        {
            if (c == '.')
            {
                printf (".");
                break;
            }
            
            if (EhLetra(c))
            {
                printf("%c", Decodifica(c, codigo));
            }
            else
            {
                printf ("%c", c);
            }
        }
    }

    else
    {
        printf("Operacao invalida.");
    }
    return 0;
}

int EhLetra (char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    {
    	return true;
    }
    return false;
}

int EhLetraMinuscula (char c)
{
    if ((c >= 'a' && c <= 'z')) 
    {
    	return true;
    }
    return false;
}

int EhLetraMaiuscula (char c)
{
    if ((c >= 'A' && c <= 'Z')) 
    {
    	return true;
    }
    return false;
}

char Codifica(char letra, int n)
{
    if (EhLetraMinuscula(letra))
    {
        letra = (letra - 'a' + n) % 26 + 'a';
        return letra;
    }
        
    if (EhLetraMaiuscula(letra))
    {
        letra = (letra - 'A' + n*2) % 26 + 'A';
        return letra;
    }
    
    return letra;
}

char Decodifica (char letra, int n)
{
    if (EhLetraMinuscula(letra))
    {
        letra = (letra - 'a' - n + 26) % 26 + 'a';
        return letra;
    }
        
    if (EhLetraMaiuscula(letra))
    {
        letra = (letra - 'A' - n*2 + 26) % 26 + 'A';
        return letra;
    }
    
    return letra;
}