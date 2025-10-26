#include <stdio.h>

int main (void)
{
	char letra = 0;
	int infinito = 0;
	
	while (infinito < 2)
	{
		scanf("%c", &letra);
		
		
		if (letra == ' ')
		{
			letra = '\0';
		}
	
		else if (letra == '!' || letra == '?' || letra == '.')
		{	
			if (infinito == 0)
			{
				printf ("RESP:");
				infinito++;	
			}
			infinito = 2;
			printf ("%c", letra);
		}
	
		else if (letra != '\0')
		{
			if (infinito == 0)
			{
				printf ("RESP:");
				infinito++;	
			}
			printf ("%c", letra);
		}	

	}
}

