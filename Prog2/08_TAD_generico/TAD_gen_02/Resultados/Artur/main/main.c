#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime_menu();

int main(void)
{
    printf("tad_gen_02\n\n");
    tGerenciador *gerenciador = CriaGerenciador();
    while (1)
    {
        imprime_menu();
        int opacao;
        scanf("%d%*c", &opacao);

        if(opacao == 1)
        {
            Type tipo;
            int tamanho;
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d%*c", &tipo, &tamanho);
            if((tipo > 1 || tipo < 0))
            {
                printf("\nDigite um tipo valido!\n");
                continue;
            }
            if(tipo == 0)
                tipo = 2;
            tPacote *p = CriaPacote(tipo, tamanho);
            LePacote(p);
            AdicionaPacoteNoGerenciador(gerenciador, p);
            printf("\n");
        }
        else if(opacao == 2)
        {
            int idx;
            scanf("%d%*c", &idx);
            ImprimirPacoteNoIndice(gerenciador, idx);
        }
        else if(opacao == 3)
        {
            ImprimirTodosPacotes(gerenciador);
            break;
        }
        else
        {
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }
    DestroiGerenciador(gerenciador);
    return 0;
}

void imprime_menu()
{
    printf("Escolha uma opcao:\n\t(1) Cadastrar um novo pacote\n\t(2) Imprimir um pacote específico\n\t(3) Imprimir todos os pacotes e sair\n");
}