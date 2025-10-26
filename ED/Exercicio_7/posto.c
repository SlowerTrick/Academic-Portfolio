//
//  posto.h
//  PostoSaude
//
//  Created by Artur Vitor Cintra Bernardes on 11/06/25.
//

/*Tipo que define um Posto de Saúde (tipo opaco)
 *Um posto deve ter os seguintes atributos:
 * * Nome do Posto
 * * Uma FILA de amostras para exame não processadas
 * * Uma FILA de amostras processadas com resultado POSITIVO
 * * Uma FILA de amostras processadas com resultado NEGATIVO
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amostra.h"
#include "fila.h"
#include "posto.h"

static void memory_check(void *p);

struct posto
{
    char *nome;
    Fila *amostras_nao_processadas;
    Fila *amostras_positivas;
    Fila *amostras_negativas;
};

/* Cria um posto de saúde, ainda vazio, com as 3 filas, vazias
* inputs: nome do posto de saúde.
* output: posto alocado e vazio, com filas de amostras ainda vazias
* pre-condicao: nao tem
* pos-condicao: posto alocado e vazio, com filas de amostras alocadas e vazias
 */
Posto* inicPosto(char* nome)
{
    Posto *p = malloc(sizeof(*p));
    p->nome = strdup(nome);
    p->amostras_nao_processadas = cria_fila();
    p->amostras_positivas = cria_fila();
    p->amostras_negativas = cria_fila();
    return p;
}

/* Imprime os dados do Posto no seguinte formato:
 
 Dados do Posto: <nome do posto>
 Amostras não processadas
 <fila de amostras não processadas - do início ao fim>
 
 Amostras com resultados positivos
 <fila de amostras positivas - do início ao fim>
 
 Amostra com resultados negativos
 <fila de amostras negativas - do início ao fim>
 
* inputs: referencia para o posto
* output: nenhum
* pre-condicao: posto alocado
* pos-condicao: dados do posto não são alterados
 */
void imprimePosto(Posto* posto)
{
    printf("Dados do Posto: %s\n\n", posto->nome);

    printf("Amostras não processadas\n");
    imprime_fila(posto->amostras_nao_processadas);
    printf("\n");

    printf("Amostras com resultados positivos\n");
    imprime_fila(posto->amostras_positivas);
    printf("\n");

    printf("Amostra com resultados negativos\n");
    imprime_fila(posto->amostras_negativas);
    printf("\n");
}

/* Simula a realização de uma coleta de material para teste
 * A função deve criar uma amostra e fazer as devidas atribuições à amostra
 * Deve-se inserir a amostra na fila de "não processados"
 * ATENÇÃO: se a pessoa for idosa (idade>=60), ela deve ir para o início da fila de não processados
* inputs: referência para o posto de saúde, o nome do dono da coleta e a idade da pessa
* output: nenhum
* pre-condicao: posto válido, nome da pessoa válido
* pos-condicao: Amostra alocada e inserida na fila de amostras não processadas
 */
void realizaColeta(Posto* posto, char* pessoa, int idade)
{
    Amostra *a = inicAmostra(pessoa, idade);
    insere_fila(posto->amostras_nao_processadas, a);
}


/* Essa função simula o processamento (testagem) das amostras e atualiza os resultados nas amostras. Deve-se usar a constante LIMITE_CARGA_VIRAL para definir positivo e negativo.
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: amostras foram devidamente processadas; fila de amostras não processadas deve ficar vazia; fila de amostras positivas deve conter as amostras que testaram positivo (idosos na frente); fila de amostras negativas deve conter as amostras que testaram negativo (idosos na frente).
 */
void processaLoteAmostras(Posto* posto)
{
    while (1)
    {
        Amostra *a = remove_elemento_fila(posto->amostras_nao_processadas);
        if(a == NULL)
            break;
        int carga_viral = retornaCargaViral(a);
        int resultado = carga_viral >= LIMITE_CARGA_VIRAL ? POSITIVO : NEGATIVO;
        registraResultado(a, resultado);
        if(resultado == POSITIVO)
            insere_fila(posto->amostras_positivas, a);
        else
            insere_fila(posto->amostras_negativas, a);
    }
    
}

/* Libera toda a memória alocada para o posto de saúde
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: Memória para a string nome liberada; memória para as 3 filas liberada, memoria do posto liberada
 */
void liberaPosto(Posto* posto)
{
    if(posto)
    {
        free(posto->nome);
        libera_fila(posto->amostras_nao_processadas);
        libera_fila(posto->amostras_negativas);
        libera_fila(posto->amostras_positivas);
        free(posto);
    }
}

static void memory_check(void *p)
{
    if(!p)
    {
        printf("ERRO! falta de memoria");
        exit(1);
    }
}