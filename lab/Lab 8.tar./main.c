#include "terrenos.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int total;
    scanf("%d%*c", &total);
    Terrenos_pt terrenos = InicializaTerrenos(total);

    for(int i = 0; i < total; i++)
    {
        char opcao;
        scanf(" %c", &opcao);

        if(opcao == 'C')
        {
            Circulo c = criaCirculo();
            leCirculo(c);
            Terreno_pt terreno = InicializaTerreno(c, CIRCULO);
            printf("Circulo: %.2lf\n", Area(terreno));
            adicionarArea(terrenos, terreno);
        }
        else if(opcao == 'R')
        {
            Retangulo r = criaRetangulo();
            leRetangulo(r);
            Terreno_pt terreno = InicializaTerreno(r, RETANGULO);
            printf("Retangulo: %.2lf\n", Area(terreno));
            adicionarArea(terrenos, terreno);
            
        }
        else if(opcao == 'T')
        {
            Triangulo t = criaTriangulo();
            leTriangulo(t);
            Terreno_pt terreno = InicializaTerreno(t, TRIANGULO);
            printf("Triangulo: %.2lf\n", Area(terreno));
            adicionarArea(terrenos, terreno);
        }
    }
    printf("\nMedia: %.2lf\n", Media(terrenos));
    printf("Area total: %.2lf\n", AreaTotal(terrenos));
    printf("Desvio padrao: %.2lf\n", DesvioPadrao(terrenos));
    liberaTerrenos(terrenos);
    return 0;
}