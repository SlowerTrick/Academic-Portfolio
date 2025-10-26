#include "lista.h"
#include "retangulo.h"

int main()
{
    FILE *entrada = fopen("entrada.txt", "r");
    if(!entrada)
    {
        printf("ERRO! impossivel abrir o arquivo");
        exit(1);
    }
    FILE *saida = fopen("saida.txt", "w");
    if(!saida)
    {
        printf("ERRO! impossivel abrir o arquivo");
        exit(1);
    }

    Lista *lista = criaLista();
    double base, altura;
    while (fscanf(entrada, "%lf %lf%*c", &base, &altura) == 2)
    {
        Retangulo *r = criaRetangulo(base, altura);
        insereLista(lista, r);
    }
    double media = percorreLista(lista, saida, imprimeRetangulo);
    
    fprintf(saida, "MEDIA RETANGULOS = %.2lf", media);

    liberaLista(lista, liberaRetangulo);
    fclose(entrada);
    fclose(saida);
    return 0;
}
