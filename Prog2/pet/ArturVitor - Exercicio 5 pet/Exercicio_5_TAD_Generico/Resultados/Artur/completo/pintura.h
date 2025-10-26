#ifndef PINTURA_H
#define PINTURA_H

#define MAXTAM_STRINGS 100

typedef struct Pintura Pintura;

// Aloca dinamicamente uma nova estrutura Pintura e realiza a leitura dos dados
// de entrada associados à pintura. Retorna o ponteiro para o objeto Pintura.
// Retorna: Ponteiro para a Pintura recém-criada, com dados carregados.
Pintura* pintura_construct();

// Imprime os dados de uma pintura. Recebe um ponteiro genérico para a pintura,
// e utiliza a função de impressão para exibir as informações relevantes.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser impressa.
void pintura_print(void* p);

// Libera a memória alocada para a pintura, chamando a função de desalocação
// apropriada para os dados da estrutura Pintura.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser destruída.
void pintura_destroy(void* p);

#endif
