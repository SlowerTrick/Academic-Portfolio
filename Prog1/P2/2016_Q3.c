#include <stdio.h>

int EhProduto(char prd);
int AcabaramOsProdutos(char prd);
int QtdDoProdutoMaisComprado();

int main (void)
{
    int id = 0, quantidade = 0, maiorid = 0, maiorquantidade = 0;
    char produto = 0;

    while (1)
    {
        scanf ("%i ", &id);
        if (id == -1)
        {
            break;
        }
        quantidade = QtdDoProdutoMaisComprado();
        if (quantidade > maiorquantidade)
        {
            maiorquantidade = quantidade;
            maiorid = id;
        }
    }
    printf ("CLIENT:%i QTD:%i", maiorid, maiorquantidade);
}

int EhProduto(char prd)
{
    if (prd >= 'A' && prd <= 'Z')
    {
        return 1;
    }
    return 0;
}

int AcabaramOsProdutos(char prd)
{
    if (prd == '0')
    {
        return 1;
    }
    return 0;
}

int QtdDoProdutoMaisComprado()
{
    char produto = 0, replica = 0;
    int produtomaiscomprado = 0, contador = 1;

    scanf("%c", &produto);

    while (1)
    {
        if(!AcabaramOsProdutos(produto))
        {
            if (EhProduto(produto))
            {
                while (1)
                {
                    scanf ("%c", &replica);
                    if (produto == replica)
                    {
                        contador++;
                    }
                    else
                    {
                        break;
                    }
                }
                produto = replica;
                if (contador > produtomaiscomprado)
                {
                    produtomaiscomprado = contador;
                }
                contador = 1;
            }
            else
            {
                scanf ("%c", &produto);
            }
        }
        else
        {
            break;
        }
    }
    return produtomaiscomprado;
}
