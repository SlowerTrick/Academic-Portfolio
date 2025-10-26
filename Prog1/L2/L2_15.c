#include <stdio.h>

int main (void)
{
	int x = 0, somapositivos = 0, somanegativos = 0, npositivos = 0, nnegativos = 0;
	int xnegativos = 0;
	int xpositivos = 0; 
	int infinito = 0;
	char final;
	int i = -1;
	
	while(infinito == 0)
	{
		if (x < 0)
		{
			somanegativos = somanegativos + x;
			nnegativos++;
		}
		
		if (x > 0)
		{
			somapositivos = somapositivos + x;
			npositivos++;
		}
		
		if(scanf("%i ", &x) != 1)
		{
			infinito = 1;
			break;
		}
		i++;
	}

	printf ("%i ", nnegativos);
	printf ("%i ", npositivos);
	printf ("%i ", somanegativos);
	printf ("%i", somapositivos);
	return 0;
}
