#include <stdio.h>
#include <stdbool.h>

bool EhPrimo (int x);

int main (void)
{
    int menor = 0, maior = 0, i = 0;
    scanf("%i%i", &menor, &maior);
    
    for (i = menor + 1; i < maior; i++)
    {
    	if ((EhPrimo(i)) == true)
    	{
    	    printf ("%i ", i); 
    	}
    }
    return 0;
}

bool EhPrimo (int x)
{
    int i = 0;
    int contador = 0;
    
    for(i = 1; i <= x; i++)
    {
        if ((x % i) == 0)
        {
            contador++;
        }
    }
    
    if (contador == 2)
    {
    	return true;
    } 
    else
    {
        return false;
    }
}
