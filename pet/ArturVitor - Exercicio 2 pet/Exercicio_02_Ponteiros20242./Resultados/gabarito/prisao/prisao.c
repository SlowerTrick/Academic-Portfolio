#include "prisao.h"

tPrisao criaPrisao(char* nome, int nCelas, int capacidadeCelas){
    tPrisao p;

    strcpy(p.nome,nome);
    p.dia = 0;
    p.nCelas = nCelas;
    p.capacidadeCelas = capacidadeCelas;

    for(int i=0; i<nCelas; i++){
        p.celas[i] = criaCela(capacidadeCelas);
    }

    return p;
}

void executaPrisao(tPrisao* prisao){
    int exit = 0;
    while(!exit){
        imprimeDiaEMenuPrisao(prisao);

        char opcao;
        scanf("%c%*c",&opcao);

        switch (opcao)
        {
        case 'I':
            inserePrisioneiroPrisao(prisao);
            if(obtemNumeroPrisioneirosPrisao(prisao)==prisao->nCelas * prisao->capacidadeCelas){
                rebeliaoGeralPrisao(prisao);
                exit = 1;
            }
            break;

        case 'P':
            passaDiaPrisao(prisao);
            break;

        case 'F':
            registraFugaCelaPrisao(prisao);
            break;

        case 'E':
            finalizaPrograma(prisao);
            exit = 1;
            break;

        default:
            break;
        }
    }
}

void imprimeDiaEMenuPrisao(tPrisao* prisao){
    printf("Dia %d na prisao de %s\nMenu:\n I - Inserir detento\n P - Passar o dia\n F - Registrar fuga de cela\n E - Encerrar programa\n",
    prisao->dia,prisao->nome);
}

void inserePrisioneiroPrisao(tPrisao* prisao){
    char nome[MAXTAM_NOME];
    int pena = -1;
    printf("Informe a pena e o nome do prisioneiro:\n");
    scanf("%d %[^\n]%*c", &pena, nome);
    if(pena <= 0){
        printf("Valor invalido\n");
        return;
    }

    tPrisioneiro p = criaPrisioneiro(nome,pena);

    for(int i=0; i<prisao->nCelas; i++){
        if(possuiVagaCela(&prisao->celas[i])){
            inserePrisioneiroCela(&prisao->celas[i],p);
            printf("Detento %s foi inserido na cela %d\n",nome,i);
            break;
        }
    }
}

void passaDiaPrisao(tPrisao* prisao){
    prisao->dia++;
    for(int i=0; i < prisao->nCelas; i++)
        passaDiaCela(&prisao->celas[i]);
}

void registraFugaCelaPrisao(tPrisao* prisao){
    int idxCela;
    printf("Informe a cela em qual ocorreu a fuga:\n");
    scanf("%d%*c",&idxCela);
    if(idxCela < 0 || idxCela >= prisao->nCelas){
        printf("Valor invalido\n");
        return;
    }
    fogePrisioneirosCela(&prisao->celas[idxCela]);
}

int obtemNumeroPrisioneirosPrisao(tPrisao* prisao){
    int soma=0;
    for(int i=0; i<prisao->nCelas;i++){
        soma += obtemNumeroPrisioneirosCela(&prisao->celas[i]);
    }
    return soma;
}

void finalizaPrograma(tPrisao* prisao){
    if(obtemNumeroPrisioneirosPrisao(prisao) > 0){
        printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
    }else{
        printf("Fim do programa.\n");
    }
}

void rebeliaoGeralPrisao(tPrisao* prisao){
    printf("REBELIAO GERAL\n");
    for(int i=0; i<prisao->nCelas; i++){
        fogePrisioneirosCela(&prisao->celas[i]);
    }
    printf("Fim do programa.\n");
}
