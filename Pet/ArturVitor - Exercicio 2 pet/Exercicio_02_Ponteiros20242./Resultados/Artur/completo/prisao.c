#include "prisao.h"


/**
 * @brief Construtor do tipo prisão
 * @param nome Nome da prisão
 * @param nCelas Número de celas ocupadas
 * @param capacidadeCelas Número total de celas
*/
tPrisao criaPrisao(char* nome, int nCelas, int capacidadeCelas)
{
    tPrisao p;
    strcpy(p.nome,nome);
    p.dia = 0;
    p.nCelas = nCelas;
    p.capacidadeCelas = capacidadeCelas;

    for(int i=0; i<nCelas; i++)
        p.celas[i] = criaCela(capacidadeCelas);

    return p;
}

/**
 * @brief Contém o loop do programa que deve imprimir o menu e selecionar opção
*/
void executaPrisao(tPrisao* prisao)
{
    while(1)
    {
        imprimeDiaEMenuPrisao(prisao);

        char opcao;
        scanf("%c%*c",&opcao);

        switch (opcao)
        {
            case 'I':
                inserePrisioneiroPrisao(prisao);
                if(obtemNumeroPrisioneirosPrisao(prisao)==prisao->nCelas * prisao->capacidadeCelas)
                {
                    rebeliaoGeralPrisao(prisao);
                    return;
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
                return;

            default:
                break;
        }
    }
}

/**
 * @brief Imprime o menu
*/
void imprimeDiaEMenuPrisao(tPrisao* prisao)
{
    printf("Dia %d na prisao de %s\n", prisao->dia, prisao->nome);
    printf("Menu:\n");
    printf("I - Inserir detento\n");
    printf("P - Passar o dia\n");
    printf("F - Registrar fuga de cela\n");
    printf("E - Encerrar programa\n");
}

/**
 * @brief Faz a leitura e adiciona o prisioneiro na prisão
*/
void inserePrisioneiroPrisao(tPrisao* prisao)
{
    char nome[MAXTAM_NOME];
    int pena;
    printf("Informe a pena e o nome do prisioneiro:\n");
    scanf("%d %[^\n]%*c", &pena, nome);
    if(pena <= 0)
    {
        printf("Valor invalido\n");
        return;
    }

    tPrisioneiro p = criaPrisioneiro(nome, pena);

    for(int i=0; i<prisao->nCelas; i++)
    {
        if(possuiVagaCela(&prisao->celas[i]))
        {
            inserePrisioneiroCela(&prisao->celas[i],p);
            printf("Detento %s foi inserido na cela %d\n",nome,i);
            break;
        }
    }
}

/**
 * @brief Passa o dia em cada uma das celas da prisão
*/
void passaDiaPrisao(tPrisao* prisao)
{
    for(int i = 0; i < prisao->nCelas; i++)
        passaDiaCela(&prisao->celas[i]);
    prisao->dia++;
}

/**
 * @brief Le da entrada padrão o índice da cela no qual ocorreu a fuga
*/
void registraFugaCelaPrisao(tPrisao* prisao)
{
    int index;
    printf("Informe a cela em qual ocorreu a fuga:\n");
    scanf("%d%*c",&index);

    if(index < 0 || index >= prisao->nCelas)
    {
        printf("Valor invalido\n");
        return;
    }
    fogePrisioneirosCela(&prisao->celas[index]);
}

/**
 * @brief Obtém o total de prisioneiros
*/
int obtemNumeroPrisioneirosPrisao(tPrisao* prisao)
{
    int total = 0;
    for(int i = 0; i < prisao->nCelas; i++)
        total += obtemNumeroPrisioneirosCela(&prisao->celas[i]);

    return total;
}

/**
 * @brief Finaliza o programa, havendo diferença na finalização caso tenha ou nao prisioneiros na prisao
*/
void finalizaPrograma(tPrisao* prisao)
{
    if(obtemNumeroPrisioneirosPrisao(prisao) > 0)
    {
        printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
    }
    else
    {
        printf("Fim do programa.\n");
    }
}

/**
 * @brief Imprime mensagem de rebelião e realiza fuga de todos os prisioneiros
*/
void rebeliaoGeralPrisao(tPrisao* prisao)
{
    printf("REBELIAO GERAL\n");
    for(int i = 0; i < prisao->nCelas; i++)
    {
        fogePrisioneirosCela(&prisao->celas[i]);
    }
    printf("Fim do programa.\n");
}

