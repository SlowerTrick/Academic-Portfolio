/* #include "Pedido.h"
#include "Lista.h"

int main(void)
{
    ComidaNaoVegana* picanha = inicComidaNaoVegana("Picanha", 300, 90.5);
    ComidaNaoVegana* linguica = inicComidaNaoVegana("Linguica", 400, 30.8);
    ComidaNaoVegana* sorvete = inicComidaNaoVegana("Sorvete de Creme", 600, 15.4);
    ComidaVegana* abobrinha = inicComidaVegana("abobrinha", 200);
    ComidaVegana* empadao = inicComidaVegana("Empadao", 600);

    Lista *lista = criaLista();
    adicionaLista(lista, picanha, N_VEGANA);
    adicionaLista(lista, linguica, N_VEGANA);
    adicionaLista(lista, sorvete, N_VEGANA);
    adicionaLista(lista, abobrinha, VEGANA);
    adicionaLista(lista, empadao, VEGANA);

    imprimeLista(lista);

    removeLista(lista, "Picanha");
    removeLista(lista, "Empadao");
    removeLista(lista, "Sorvete de Creme");

    imprimeLista(lista);

    ComidaNaoVegana *nv = obtemLista(lista, "Linguica");
    ComidaVegana *v = obtemLista(lista, "abobrinha");

    imprimeComidaNaoVegana(nv);
    imprimeComidaVegana(v);

    liberaLista(lista);
    liberaComidaNaoVegana(picanha);
    liberaComidaNaoVegana(linguica);
    liberaComidaNaoVegana(sorvete);
    liberaComidaVegana(abobrinha);
    liberaComidaVegana(empadao);
} */