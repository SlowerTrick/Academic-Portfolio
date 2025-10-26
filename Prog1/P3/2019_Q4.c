#include <stdio.h>

typedef struct
{
    int id;
    int qtdPassageiros;
    char tipoCarro[100];
    int km;
    int cliente;
    int alugado;
}
tCarro;

typedef struct
{
    int totalCarros;
    tCarro carros[100];
    int carroAlugadoComSucesso;
}
tConcessionaria;

tCarro LeCarro();
void ImprimeCarro(tCarro carro);
int ObtemNumPassageirosCarro(tCarro carro);
int ObtemKmCarro(tCarro carro);
int ObtemClienteAlugouCarro(tCarro carro);
int EstaDisponivelCarro(tCarro carro);
tCarro AlugaCarro(tCarro carro, int cliente);
tCarro DevolveCarro(tCarro carro);

tConcessionaria LeCarrosConcessionaria();
void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);
tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km);
tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente);

int main(void)
{
    tConcessionaria concessionaria;
    concessionaria = LeCarrosConcessionaria();
    int idCliente = 0;
    char tipo = 0;
    int qtdPassageiros, km, i = 0;
    while(scanf("%d,%c", &idCliente, &tipo) == 2)
    {
        if (tipo == 'A')
        {
            scanf("%d,%d", &qtdPassageiros, &km);
        }
        if (tipo == 'A')
        {
            concessionaria = AlugaCarroConcessionaria(concessionaria, idCliente, qtdPassageiros, km);
            if (concessionaria.carroAlugadoComSucesso == 0)
            {
                printf ("Carro Indisponivel\n");
            }
        }
        else
        {
            concessionaria = DevolveCarroConcessionaria(concessionaria, idCliente);
        }
    }
    return 0;
}

tCarro LeCarro()
{
    tCarro carro;
    scanf("%d %d %s %d", &carro.id, &carro.qtdPassageiros, &carro.tipoCarro, &carro.km);
    carro.cliente = -1;
    carro.alugado = 0;
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

int ObtemClienteAlugouCarro(tCarro carro)
{
    return carro.cliente;
}

int EstaDisponivelCarro(tCarro carro)
{
    if (carro.alugado == 0)
    {
        return 1;
    }
    return 0;
}

tCarro AlugaCarro(tCarro carro, int cliente)
{
    carro.alugado = 1;
    carro.cliente = cliente;
    return carro;
}

tCarro DevolveCarro(tCarro carro)
{
    carro.alugado = 0;
    carro.cliente = -1;
    return carro;
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
    concessionaria.carroAlugadoComSucesso = 1;
    return concessionaria;
}

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km)
{
    int i = 0;
    for (i = 0; i < concessionaria.totalCarros; i++)
    {
        int contador = 0;
        if ((ObtemKmCarro(concessionaria.carros[i]) <= km || km == -1) && (ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass || pass == -1))
        {
            ImprimeCarro(concessionaria.carros[i]);
        }
    }
    return;
}

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km)
{
    int i = 0;
    concessionaria.carroAlugadoComSucesso = 0;
    for (i = 0; i < concessionaria.totalCarros; i++)
    {
        if (EstaDisponivelCarro(concessionaria.carros[i]) && ((ObtemKmCarro(concessionaria.carros[i]) <= km || km == -1) && (ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass || pass == -1)))
        {
            concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], cliente);
            printf ("Alugado (cliente %d) -> ", cliente);
            ImprimeCarro(concessionaria.carros[i]);
            concessionaria.carroAlugadoComSucesso = 1;
            break;
        }
    }
    return concessionaria;
}

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente)
{
    int i = 0;
    for (i = 0; i < concessionaria.totalCarros; i++)
    {
        if (ObtemClienteAlugouCarro(concessionaria.carros[i]) == cliente)
        {
            concessionaria.carros[i] = DevolveCarro(concessionaria.carros[i]);
            printf ("Devolvido (cliente %d) -> ", cliente);
            ImprimeCarro(concessionaria.carros[i]);
            break;
        }
    }
    return concessionaria;
}