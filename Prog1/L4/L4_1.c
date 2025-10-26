#include <stdio.h>

typedef struct {
    int codigo;
    float preco;
    int estoque;
} tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1, tProduto p2);
int TemProdutoEmEstoque(tProduto p);
void ImprimeProduto(tProduto p, char* tipo);

int main(void) {
    int totalprodutos = 0, i = 0;
    tProduto produto, maior, menor;
    maior.preco = -1; // Inicializa com um valor inválido
    menor.preco = __FLT_MAX__; // Inicializa com o maior valor possível

    scanf("%i", &totalprodutos);
    getchar(); // Consome o newline após o número

    for (i = 0; i < totalprodutos; i++) 
    {
        produto = LeProduto();

        if (!TemProdutoEmEstoque(produto)) {
            printf("FALTA:COD %i, PRE %.2f, QTD 0\n", produto.codigo, produto.preco);
        }

        if (maior.preco == -1 || EhProduto1MaiorQ2(produto, maior)) {
            maior = produto;
        }

        if (menor.preco == __FLT_MAX__ || EhProduto1MenorQ2(produto, menor)) {
            menor = produto;
        }
    }

    if (maior.preco != -1) {
        ImprimeProduto(maior, "MAIOR");
    }
    if (menor.preco != __FLT_MAX__) {
        ImprimeProduto(menor, "MENOR");
    }

    return 0;
}

tProduto LeProduto() 
{
    tProduto produto;
    scanf("%i;%f;%i", &produto.codigo, &produto.preco, &produto.estoque);
    getchar(); // Consome o newline após o produto
    return produto;
}

int TemProdutoEmEstoque(tProduto p) 
{
    return p.estoque > 0;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2) 
{
    return p1.preco > p2.preco;
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2) 
{
    return p1.preco < p2.preco;
}

void ImprimeProduto(tProduto p, char* tipo) 
{
    printf("%s:COD %i, PRE %.2f, QTD %i\n", tipo, p.codigo, p.preco, p.estoque);
}