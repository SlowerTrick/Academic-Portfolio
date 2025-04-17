#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

struct Database
{
    Vector *elementos;
};

/**
 * @brief Cria um nova database.
 * @return Um ponteiro para a estrutura database criada. Caso a alocação falhe, a função termina o programa.
 */
tDatabase *CriaDatabase()
{
    tDatabase *b = malloc(sizeof(*b));
    b->elementos = VectorConstruct();
    return b;
}

/**
 * @brief Destroi uma database.
 * @param db Ponteiro para a estrutura da database a ser destruída.
 */
void DestroiDatabase(tDatabase *db)
{
    /* if(db)
    {

    } */
}

/**
 * @brief Lê uma database da entrada padrão.
 * @param db Ponteiro para a estrutura da database a ser lida.
 */
void LeDatabase(tDatabase *db)
{
    int total_elementos;
    scanf("%d%*c", &total_elementos);
    for(int i = 0; i < total_elementos; i++)
    {
        
    }
}

/**
 * @brief Ordena uma database, primeiro os alunos e depois os professores, de acordo com o nome.
 * @param db Ponteiro para a estrutura da database a ser ordenada.
 */
void OrdenaDatabase(tDatabase *db);

/**
 * @brief Salva uma database em um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser salva.
 * @param file Ponteiro para o arquivo onde a database será salva.
 * @return Um inteiro indicando o total de bytes salvos.
 */
int SalvarDatabase(tDatabase *db, FILE *file);

/**
 * @brief Carrega uma database de um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser carregada.
 * @param file Ponteiro para o arquivo de onde a database será carregada.
 * @return Um inteiro indicando o total de bytes lidos.
 */
int CarregaDatabase(tDatabase *db, FILE *file);

/**
 * @brief Imprime uma database, primeiro os alunos e depois os professores. Apenas os nomes são impressos.
 * @param db Ponteiro para a estrutura da database a ser impressa.
 */
void ImprimeDatabase(tDatabase *db);
