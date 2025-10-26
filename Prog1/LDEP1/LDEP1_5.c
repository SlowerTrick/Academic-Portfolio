#include <stdio.h>

int main(void) 
{
    int min = 0, max = 0;
	scanf ("%i%i", &min, &max);
	int i = 0;

	printf("RESP:");

	for (i = min; i < max; i++)
	{
		if ((i % 2) == 0)
		{
			printf ("%i", i);
		}

		if (i != max - 1)
		{
			printf (" ");
		}
	}
    return 0;
}