#include <stdio.h>

int main (void)
{
    int preco1 = 0, preco2 = 0, preco3 = 0, quantidade = 0, i = 0, custo = 0, pedido = 0;
    scanf ("%i%i%i%i", &preco1, &preco2, &preco3, &quantidade);
    
    for (i = 0; i < quantidade; i++)
    {
        scanf("%i", &pedido);
        if (pedido == 1)
        {
            custo += preco1;
        }
        if (pedido == 2)
        {
            custo += preco2;
        }
        if (pedido == 3)
        {
            custo += preco3;
        }
    }
    printf ("CUSTO:%i\n", custo);
    return 0;
}