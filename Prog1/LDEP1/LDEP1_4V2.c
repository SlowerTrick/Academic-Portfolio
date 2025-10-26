#include <stdio.h>

int main()
{
  int i = 0; 
  int j = 0;
  int k = 0;
  int den = 0;
  int primo = 0; 
  int qtd = 0; 
  int cont = 0;
  int verificador1 = 0;
  int verificador2 = 0;
  int verificador3 = 0;

  
 

  scanf("%i", &qtd);
    
  int primos[qtd];

  for(i = 1; i <= qtd; i++)
  {
    cont = 1;
    
    for (j = 1; j <= i; j++)
    {
    	if (j % i == 0 || i % 2 == 0 || i % 5 == 0 || i % 3 == 0 || (primos[j] > 0 && i % primos[j] == 0))
    	{
    		cont++;
    	}
    }
    
    if (verificador1 == 0 && qtd > 3)
    {
    	printf ("2");
    	verificador1++;
    }
    
    if (cont == 2 && i != 1)
    {
    	printf (" %i", i);
    	primos[i] = i;
    }
    
    if (qtd == 3 && cont == 3)
    {
    	if (verificador3 == 0)
    	{
    		printf ("3");
    		verificador2++;
    	}
    }
    
    if (i == 3 && qtd != 3)
    {
    	if (verificador3 == 0)
    	{
    		printf (" 3");
    		verificador3++;
    	}
    } 
    
    if (cont > 5)
    {
    	if (verificador2 == 0)
    	{
    		printf ("5 ");
    		verificador2++;
    	}
    }
    
    if (cont == 5)
    {
    	if (verificador2 == 0)
    	{
    		printf (" 5");
    		verificador2++;
    	}
    	
    	for (k = 0; k < qtd; k++)
  	{
  		primos[k] = 0;
  	}
    } 
    
    if (qtd == 2 && verificador1 == 0)
    {
    	printf ("2");
    	verificador1++;
    }
  }
  
  return 0;
 }
