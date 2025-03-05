#include "musica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musica
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    int numero_participantes;
    char **participantes;
    char album[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
};


// Aloca dinamicamente uma nova estrutura Musica e realiza a leitura dos dados
// de entrada associados à música. Pode envolver múltiplos participantes na música.
// Retorna: Ponteiro para a Musica recém-criada, com os dados carregados.
Musica* musica_construct()
{
    Musica *m = malloc(sizeof(*m));
    if(!m)
    {
        perror("ERRO! falta de memoria");
        exit(1);
    }
    scanf("%s %s %d ", m->titulo, m->artista, &m->numero_participantes);
    m->participantes = malloc(sizeof(char *) * m->numero_participantes);
    for(int i = 0; i < m->numero_participantes; i++)
    {
        m->participantes[i] = malloc(sizeof(char) * MAXTAM_STRINGS);
        scanf("%s ", m->participantes[i]);
    }
    scanf("%s ", m->album);
    scanf("%s%*c", m->genero);

    return m;
}

// Imprime os dados da música. Recebe um ponteiro genérico para a música
// e exibe suas informações relevantes, como título, artistas, etc.
// Parâmetros:
//  m - Ponteiro para a Musica a ser impressa.
void musica_print(void* m)
{
    Musica *musica = (Musica *) m;

    printf("MUSICA\n");
    printf("%s - %s", musica->artista, musica->titulo);
    
    printf(" (feat. ");
    for (int i = 0; i < musica->numero_participantes; i++)
    {
        printf("%s", musica->participantes[i]);
        if(i < musica->numero_participantes -1)
            printf(", ");
    }
    printf(")\n");
    
    printf("Album: %s\n", musica->album);
    printf("Genero: %s\n", musica->genero);
}


// Libera a memória alocada para a música, desalocando a estrutura Musica
// e seus dados associados de forma adequada.
// Parâmetros:
//  m - Ponteiro para a Musica a ser destruída.
void musica_destroy(void* m)
{
    Musica *musica = (Musica *) m;
    if(musica)
    {
        if(musica->participantes)
        {
            for(int i = 0; i < musica->numero_participantes; i++)
                free(musica->participantes[i]);
        }
        free(musica->participantes);
        musica->participantes = NULL;
        free(musica);
    }
    musica = NULL;
}
