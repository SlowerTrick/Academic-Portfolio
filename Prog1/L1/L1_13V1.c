#include <stdio.h>

int main (void)
{
    int pessoas, itens = {0};
    scanf ("%i%i", &pessoas, &itens);

    int temp = 0;

    while (itens > 0)
    {
        if (temp < pessoas)
        {
            temp++;
        }
        
        else if (pessoas == 1)
        {
            temp = 1;
        }

        else if (temp == pessoas)
        {
            temp = 0;
            temp++;
        }
        itens--;
    }
    printf ("RESP:%i", temp);
}