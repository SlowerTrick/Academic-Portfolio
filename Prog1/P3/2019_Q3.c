#include <stdio.h>

typedef struct
{
    int id;
    int qtdPassageiros;
    char tipoCarro[100];
    int km;
}
tCarro;

typedef struct
{
    int totalCarros;
    tCarro carros[100];
}
tConcessionaria;

tCarro LeCarro();
void ImprimeCarro(tCarro carro);
int ObtemNumPassageirosCarro(tCarro carro);
int ObtemKmCarro(tCarro carro);

tConcessionaria LeCarrosConcessionaria();
void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);

int main()
{
    tConcessionaria concessionaria;
    concessionaria = LeCarrosConcessionaria();
    int qtdPassageiros, km, i = 0;
    while(scanf("%d,%d", &qtdPassageiros, &km) == 2){
    printf("Caso %d:\n", ++i);
    ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);
    }
    return 0;
}

tCarro LeCarro()
{
    tCarro carro;
    scanf("%d %d %s %d", &carro.id, &carro.qtdPassageiros, &carro.tipoCarro, &carro.km);
    return carro;
}

void ImprimeCarro(tCarro carro)
{
    printf ("CARRO (%d): %s de %d passageiros e com %d km\n", carro.id, carro.tipoCarro, carro.qtdPassageiros, carro.km);
    return;
}

int ObtemNumPassageirosCarro(tCarro carro)
{
    return carro.qtdPassageiros;
}

int ObtemKmCarro(tCarro carro)
{
    return carro.km;
}

tConcessionaria LeCarrosConcessionaria()
{
    tConcessionaria concessionaria;
    scanf("%d", &concessionaria.totalCarros);
    int i = 0;
    for (i = 0; i < concessionaria.totalCarros; i++)
    {
        concessionaria.carros[i] = LeCarro();
    }
    return concessionaria;
}

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km)
{
    int i = 0;
    for (i = 0; i < concessionaria.totalCarros; i++)
    {
        //printf ("pass: %d, km: %d\ncarroPass: %d, carroKm: %d\n", pass, km, ObtemNumPassageirosCarro(concessionaria.carros[i]), ObtemKmCarro(concessionaria.carros[i]));
        int contador = 0;
        if ((ObtemKmCarro(concessionaria.carros[i]) <= km || km == -1) && (ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass || pass == -1))
        {
            ImprimeCarro(concessionaria.carros[i]);
        }
    }
    return;
}