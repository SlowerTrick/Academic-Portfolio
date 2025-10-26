//
//  ComidaNaoVegana.h
//  HawaiEd
//
//  Created by Artur Vitor Cintra Bernardes on 24/06/25.
//

#include "Pedido.h"
#include "Lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CAL 500

//2 listas
//1 lista comidas > 500 calorias (calóricos)
//1 lista comidas <=500 calorias (magros)
/*Tipo que define um pedido (tipo opaco)
 *Um pedido deve ter os seguintes atributos:
 * * Numero do pedido
 * * Uma lista de comidas (veganas e nao veganas) com calorias > 500 (alimentos calóricos)
 * * Uma lista de comidas (veganas e nao veganas) com calorias <=500 (alimentos magros)
 * */
struct pedido
{
    int numero;
    Lista *caloricas;
    Lista *magras;
};

/* Cria um pedido, ainda vazio, com duas listas de alimentos, vazias
* inputs: numero do pedido.
* output: pedido alocado e vazia, com listas de alimentos ainda vazias
* pre-condicao: nao tem
* pos-condicao: pedido alocado e vazio, com listas de alimentos criadas e vazias
 */
Pedido* inicPedido (int numero)
{
    Pedido *p = malloc(sizeof(*p));
    p->numero = numero;
    p->caloricas = criaLista();
    p->magras = criaLista();
    return p;
}

/* Insere uma comida vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaVegana (Pedido* pedido, ComidaVegana* food)
{
    int cal = retornaCaloriasComidaVegana(food);

    if(cal > MAX_CAL)
        adicionaLista(pedido->caloricas, food, VEGANA);
    else
        adicionaLista(pedido->magras, food, VEGANA);
}


/* Insere uma comida não vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaNaoVegana (Pedido* pedido, ComidaNaoVegana* food)
{
    int cal = retornaCaloriasComidaNaoVegana(food);

    if(cal > MAX_CAL)
        adicionaLista(pedido->caloricas, food, N_VEGANA);
    else
        adicionaLista(pedido->magras, food, N_VEGANA);
}

//retorna o numero do pedido
int retornaNumeroPedido(Pedido* pedido)
{
    return pedido->numero;
}

/* Essa função atualiza a situação de uma comida nao vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaNaoVegana(Pedido* pedido, ComidaNaoVegana* food)
{
    char *nome = retornaNomeComidaNaoVegana(food);
    ComidaNaoVegana *calorica = obtemLista(pedido->caloricas, nome);
    ComidaNaoVegana *magra = obtemLista(pedido->magras, nome);

    if(calorica != NULL)
    {
        int cal = retornaCaloriasComidaNaoVegana(food);
        if(cal <= MAX_CAL)
        {
            removeLista(pedido->caloricas, nome);
            adicionaLista(pedido->magras, food, N_VEGANA);
        }
    }
    if(magra != NULL)
    {
        int cal = retornaCaloriasComidaNaoVegana(food);
        if(cal > MAX_CAL)
        {
            removeLista(pedido->magras, nome);
            adicionaLista(pedido->caloricas, food, N_VEGANA);
        }
    }
}

/* Essa função atualiza a situação de uma comida vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaVegana(Pedido* pedido, ComidaVegana* food)
{
    char *nome = retornaNomeComidaVegana(food);
    ComidaVegana *calorica = obtemLista(pedido->caloricas, nome);
    ComidaVegana *magra = obtemLista(pedido->magras, nome);

    if(calorica != NULL)
    {
        int cal = retornaCaloriasComidaVegana(food);
        if(cal <= MAX_CAL)
        {
            removeLista(pedido->caloricas, nome);
            adicionaLista(pedido->magras, food, VEGANA);
        }
    }
    if(magra != NULL)
    {
        int cal = retornaCaloriasComidaVegana(food);
        if(cal > MAX_CAL)
        {
            removeLista(pedido->magras, nome);
            adicionaLista(pedido->caloricas, food, VEGANA);
        }
    }
}


//Imprime os dados do pedido, seguindo o formato a seguir
/*Imprimindo Detalhes do Pedido número: 123
  Valor total do Pedido: 135.90

 Lista de Itens de Baixa Caloria: 1
 Nome comida nao vegana: Picanha, valor: 90.50, calorias: 300

 Lista de Itens de Alta Caloria: 2
 Nome comida vegana: Empadao, calorias: 600
 Nome comida nao vegana: Sorvete de Creme, valor: 15.40, calorias: 600
*/
void imprimePedido (Pedido* pedido)
{
    printf("Imprimindo Detalhes do Pedido número: %d\n", pedido->numero);
    printf("Valor total do Pedido: %.2f\n", calculaValorPedido(pedido));

    printf("Lista de Itens de Baixa Caloria: %d\n", obtemTotalElementosLista(pedido->magras));
    imprimeLista(pedido->magras);
    printf("\n");

    printf("Lista de Itens de Alta Caloria: %d\n", obtemTotalElementosLista(pedido->caloricas));
    imprimeLista(pedido->caloricas);
    printf("\n");
}

//comida vegana tem o valor fixo de 30 reais
float calculaValorPedido (Pedido* pedido)
{
    float total = obtemTotalVeganosElementosLista(pedido->caloricas) * 30;
    total += obtemTotalVeganosElementosLista(pedido->magras) * 30;
    total += calculaValorLista(pedido->caloricas);
    total += calculaValorLista(pedido->magras);
    return total;
}

/* Libera toda a memória alocada
* inputs: referencia para o pedido
* output: não tem
* pre-condicao: pedido alocado
* pos-condicao: Toda a memória liberada, a não ser alimentos, que são responsabilidade do cliente. */
void liberaPedido (Pedido* pedido)
{
    if(pedido)
    {
        liberaLista(pedido->caloricas);
        liberaLista(pedido->magras);
        free(pedido);
    }
}
