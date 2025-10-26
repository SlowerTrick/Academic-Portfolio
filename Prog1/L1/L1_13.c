#include <stdio.h>

int main (void)
{
    int pessoas, itens;
    scanf ("%i%i", &pessoas, &itens);

    int temp = 0;

    if (pessoas == 1)
    {
        temp = 1;
    }
    else
    {
        temp = itens % pessoas;
        if (temp == 0)
        {
            temp = pessoas;
        }
    }

    printf ("RESP:%i", temp);

    return 0;
}