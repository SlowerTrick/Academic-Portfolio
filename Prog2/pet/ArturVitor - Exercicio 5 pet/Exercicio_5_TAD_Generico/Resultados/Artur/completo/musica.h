#ifndef MUSICA_H
#define MUSICA_H

#define MAXTAM_STRINGS 100

typedef struct Musica Musica;

// Aloca dinamicamente uma nova estrutura Musica e realiza a leitura dos dados
// de entrada associados à música. Pode envolver múltiplos participantes na música.
// Retorna: Ponteiro para a Musica recém-criada, com os dados carregados.
Musica* musica_construct();

// Imprime os dados da música. Recebe um ponteiro genérico para a música
// e exibe suas informações relevantes, como título, artistas, etc.
// Parâmetros:
//  m - Ponteiro para a Musica a ser impressa.
void musica_print(void* m);

// Libera a memória alocada para a música, desalocando a estrutura Musica
// e seus dados associados de forma adequada.
// Parâmetros:
//  m - Ponteiro para a Musica a ser destruída.
void musica_destroy(void* m);

#endif
