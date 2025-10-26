#include <stdio.h>

int main (void)
{
    int total1 = 0;
    scanf ("%d", &total1);
    int lista1[total1];
    int i = 0;
    for (i = 0; i < total1; i++)
    {
        scanf ("%d", &lista1[i]);
    }
    
    int total2 = 0;
    scanf ("%d", &total2);
    int lista2[total2];
    for (i = 0; i < total2; i++)
    {
        scanf ("%d", &lista2[i]);
    }

    int flag = 0;
    int auxTotal2 = 0;
    printf("PARES:\n");
    for (i = 0; i < total1; i++)
    {
        if (auxTotal2 > 0 && flag == 0)
        {
            printf ("%d - %d\n", lista1[i], lista2[i]);
            auxTotal2--;
        }
        else
        {
            flag++;

            printf ("%d - %d\n", lista1[i], lista2[auxTotal2]);
            auxTotal2++;
            if (auxTotal2 == total2)
            {
                auxTotal2 = 0;
            }
        }
    }
    return 0;
}