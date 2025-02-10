#include "cela.h"

tCela criaCela(int capacidade){
    tCela c;

    c.capacidade = capacidade;
    c.nPresidiarios = 0;
    return c;
}

int possuiVagaCela(tCela* cela){
    return cela->capacidade > cela->nPresidiarios;
}

int obtemNumeroPrisioneirosCela(tCela* cela){
    return cela->nPresidiarios;
}

void inserePrisioneiroCela(tCela* cela, tPrisioneiro prisioneiro){
    if(possuiVagaCela(cela)){
        cela->prisioneiros[cela->nPresidiarios] = prisioneiro;
        cela->nPresidiarios++;
    }
}

tPrisioneiro obtemPrisioneiroCela(tCela* cela, int i){
    return cela->prisioneiros[i];
}

void fogePrisioneirosCela(tCela* cela){
    for(int i = 0; i < cela->nPresidiarios; i++){
        fogePrisioneiro(&cela->prisioneiros[i]);
    }
    cela->nPresidiarios = 0;
}

void passaDiaCela(tCela* cela){
    for(int i = 0; i<cela->nPresidiarios; i++){
        passaTempoPrisioneiro(&cela->prisioneiros[i]);
    }
    for(int i = 0; i < cela->nPresidiarios; i++){
        if(acabouPenaPrisioneiro(&cela->prisioneiros[i])){
            liberaPrisioneiroCumpriuPena(&cela->prisioneiros[i]);
            for(int j = i; j < cela->nPresidiarios - 1; j++){
                cela->prisioneiros[j] = cela->prisioneiros[j+1];
            }
            cela->nPresidiarios--;
        }
    }
}
