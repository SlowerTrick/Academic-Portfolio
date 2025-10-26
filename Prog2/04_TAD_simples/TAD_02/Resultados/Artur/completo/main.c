#include "eleicao.h"

int main(void)
{
    tEleicao eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    return 0;
}