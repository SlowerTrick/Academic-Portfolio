#ifndef ROTEIRO_H
#define ROTEIRO_H

#include "midia.h"

typedef struct Roteiro Roteiro;

// Aloca dinamicamente um novo objeto Roteiro e retorna o ponteiro para ele.
// Retorna: Ponteiro para o Roteiro recém-criado.
Roteiro *roteiro_construct();

// Aumenta o espaço de armazenamento de mídias no Roteiro, insere a nova mídia
// utilizando o construtor de mídia (midia_construct), e incrementa o contador de mídias.
// Parâmetros:
//  r       - Ponteiro para o Roteiro onde a mídia será inserida.
//  dado    - Ponteiro genérico contendo os dados da nova mídia a ser inserida.
//  print_fn - Função de impressão personalizada para a mídia.
//  free_fn  - Função de liberação personalizada para os recursos da mídia.
void roteiro_inserir_midia(Roteiro* r, void *dado, PrintFunction print_fn, FreeFunction free_fn);

// Imprime todas as mídias presentes no Roteiro. Se não houver mídias,
// imprime a mensagem "SEM MIDIAS PARA IMPRIMIR".
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser impresso.
void roteiro_imprimir_midias(Roteiro *r);

// Libera a memória alocada para o Roteiro e suas mídias, desalocando
// adequadamente cada um dos elementos armazenados.
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser destruído.
void roteiro_destroy(Roteiro *r);

#endif
