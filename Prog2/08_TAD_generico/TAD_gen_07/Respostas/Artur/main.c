#include "histograma.h"
#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int total_intervalos, altura, largura, tipo;
    scanf("%d%*c", &total_intervalos);
    Imagem *imagem = LerImagem();
    Histograma *histograma = CalcularHistograma(imagem, total_intervalos);
    MostrarHistograma(histograma);
    DestruirHistograma(histograma);
    DestruirImagem(imagem);
    return 0;
}
