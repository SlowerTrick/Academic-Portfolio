#include <stdio.h>

int main()
{
	
	int l, c, i, j;
	int soma1 = 0, soma2 = 0, atual;
	

	scanf("%d %d", &l, &c);

	
	for (i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++)
		{
			scanf("%d", &atual);
			soma2 = soma2 + atual;
			soma1 = soma1 + atual;
		}
		printf("%d\n", soma1);
		soma1 = 0;
	}

	printf("%d\n", soma2);

	return 0;
}
