#include <stdio.h>
#include <stdbool.h>

bool EhPrimo (int x);

int main (void)
{
    int menor = 0, maior = 0, i = 0, produto = 0, contador = 2;
    scanf("%i%i", &menor, &maior);
    
    for (i = menor + 1; i < maior; i++)
    {
    	if ((EhPrimo(i)) == true)
    	{
    	    printf ("%i\n", i);
    	    while (produto < maior)
    	    {
    	    	produto = i * contador;
    	    	if (produto < maior)
    	    	{
    	    	    printf ("%i ", produto);
    	    	}
    	    	
    	    	if (produto >= maior && contador == 2)
    	    	{
    	    	    printf ("*\n");
    	    	}
    	    	if (produto >= maior && contador > 2)
    	    	{
    	    	    printf ("\n");
    	    	}
    	    	
    	        contador++;
    	    }
    	    produto = 0;
    	    contador = 2;
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
