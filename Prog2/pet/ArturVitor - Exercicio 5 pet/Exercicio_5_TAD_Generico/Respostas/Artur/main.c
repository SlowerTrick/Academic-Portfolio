#include "roteiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "livro.h"
#include "pintura.h"

int main(void)
{
    int total_midias;
    scanf("%d%*c", &total_midias);
    Roteiro *roteiro = roteiro_construct();

    for(int i = 0; i < total_midias; i++)
    {
        char tipo;
        scanf("%c ", &tipo);
        if(tipo == 'L')
        {
            Livro *livro = livro_construct();
            roteiro_inserir_midia(roteiro, livro, livro_print, livro_destroy);
        }
        else if(tipo == 'P')
        {
            Pintura *pintura = pintura_construct();
            roteiro_inserir_midia(roteiro, pintura, pintura_print, pintura_destroy);
        }
        else if(tipo == 'M')
        {
            Musica *musica = musica_construct();
            roteiro_inserir_midia(roteiro, musica, musica_print, musica_destroy);
        }
    }
    roteiro_imprimir_midias(roteiro);
    roteiro_destroy(roteiro);
    return 0;
}