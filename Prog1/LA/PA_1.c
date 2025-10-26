#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main (void)
{
    int n1 = 0, n2 = 0;
    char c1 = 0;

    scanf("(%c,%i,%i)", &c1, &n1, &n2);

    int digitos1 = floor(log10(abs(n1))) + 1;
    int digitos2 = floor(log10(abs(n2))) + 1;
    int zeroesquerda = 1;

    printf ("(");


    if (isalpha(c1))
    {
        if (digitos1 == digitos2)
        {
            while (digitos1 > 0 && digitos2 > 0)
            {
                int potencia = pow(10, digitos1 - 1);
                int x1 = n1 / potencia;
                int x2 = n2 / potencia;

                if (x2 != 0 || !zeroesquerda)
                {
                    printf("%i", x2);
                    zeroesquerda = 0;
                }
                if (x1 != 0 || !zeroesquerda)
                {
                    printf("%i", x1);
                    zeroesquerda = 0;
                }

                n1 = n1 % potencia;
                n2 = n2 % potencia;

                digitos1--;
                digitos2--;
            }
        }

        if (digitos1 < digitos2)
        {
            while (digitos2 > 0)
            {
                int potencia1 = 1;
                int x1 = 0;

                if (digitos1 == digitos2)
                {
                    potencia1 = pow(10, digitos1 - 1);
                    x1 = n1 / potencia1;
                }
                int potencia2 = pow(10, digitos2 - 1);
                int x2 = n2 / potencia2;

                if (x2 != 0 || !zeroesquerda)
                {
                    printf("%i", x2);
                    zeroesquerda = 0;
                }
                if (x1 != 0 || !zeroesquerda)
                {
                    printf("%i", x1);
                    zeroesquerda = 0;
                }

                if (digitos1 == digitos2)
                {
                    n1 = n1 % potencia1;
                }

                n2 = n2 % potencia2;

                if (digitos1 == digitos2)
                {
                    digitos1--;
                }
                digitos2--;
            }
        }

        if (digitos1 > digitos2)
        {
            while (digitos1 > 0)
            {
                int potencia2 = 1;
                int x2 = 0;

                if (digitos1 == digitos2)
                {
                    potencia2 = pow(10, digitos2 - 1);
                    x2 = n2 / potencia2;
                }
                int potencia1 = pow(10, digitos1 - 1);
                int x1 = n1 / potencia1;

                if (x2 != 0 || !zeroesquerda)
                {
                    printf("%i", x2);
                    zeroesquerda = 0;
                }
                if (x1 != 0 || !zeroesquerda)
                {
                    printf("%i", x1);
                    zeroesquerda = 0;
                }

                if (digitos1 == digitos2)
                {
                    n2 = n2 % potencia2;
                }

                n1 = n1 % potencia1;

                if (digitos1 == digitos2)
                {
                    digitos2--;
                }
                digitos1--;
            }
        }
        printf (")\n");
    }
    else
    {
        if (digitos1 == digitos2)
        {
            while (digitos1 > 0 && digitos2 > 0)
            {
                int potencia = pow(10, digitos1 - 1);
                int x1 = n1 / potencia;
                int x2 = n2 / potencia;

                if (x1 != 0 || !zeroesquerda)
                {
                    printf("%i", x1);
                    zeroesquerda = 0;
                }
                if (x2 != 0 || !zeroesquerda)
                {
                    printf("%i", x2);
                    zeroesquerda = 0;
                }

                n1 = n1 % potencia;
                n2 = n2 % potencia;

                digitos1--;
                digitos2--;
            }
        }

        if (digitos1 < digitos2)
        {
            while (digitos2 > 0)
            {
                int potencia1 = 1;
                int x1 = 0;

                if (digitos1 == digitos2)
                {
                    potencia1 = pow(10, digitos1 - 1);
                    x1 = n1 / potencia1;
                }
                int potencia2 = pow(10, digitos2 - 1);
                int x2 = n2 / potencia2;

                if (x1 != 0 || !zeroesquerda)
                {
                    printf("%i", x1);
                    zeroesquerda = 0;
                }
                if (x2 != 0 || !zeroesquerda)
                {
                    printf("%i", x2);
                    zeroesquerda = 0;
                }

                if (digitos1 == digitos2)
                {
                    n1 = n1 % potencia1;
                }

                n2 = n2 % potencia2;

                if (digitos1 == digitos2)
                {
                    digitos1--;
                }
                digitos2--;
            }
        }

        if (digitos1 > digitos2)
        {
            while (digitos1 > 0)
            {
                int potencia2 = 1;
                int x2 = 0;

                if (digitos1 == digitos2)
                {
                    potencia2 = pow(10, digitos2 - 1);
                    x2 = n2 / potencia2;
                }
                int potencia1 = pow(10, digitos1 - 1);
                int x1 = n1 / potencia1;

                if (x1 != 0 || !zeroesquerda)
                {
                    printf("%i", x1);
                    zeroesquerda = 0;
                }
                if (x2 != 0 || !zeroesquerda)
                {
                    printf("%i", x2);
                    zeroesquerda = 0;
                }

                if (digitos1 == digitos2)
                {
                    n2 = n2 % potencia2;
                }

                n1 = n1 % potencia1;

                if (digitos1 == digitos2)
                {
                    digitos2--;
                }
                digitos1--;
            }
        }
        printf (")\n");
    }
    return 0;


}