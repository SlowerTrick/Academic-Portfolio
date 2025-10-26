#include <stdio.h>
#include <string.h>

void VerificaLogin(FILE *arquivo, FILE *saida, int qtddados);

int main (void)
{
    FILE *arquivo = NULL, *saida = NULL;
    arquivo = fopen("teste3/input.txt","r");
    saida = fopen("outprog/log3.txt", "w");

    if (!arquivo)
    {
        printf ("Erro na abertura do arquivo");
        return 1;
    }

    int qtddados = 0;
    fscanf(arquivo, "%d", &qtddados);

    while (qtddados != 0)
    {
        VerificaLogin(arquivo, saida, qtddados);
        qtddados--;
    }

    fclose(arquivo);       
    fclose(saida);
    return 0;
}

void VerificaLogin(FILE *arquivo, FILE *saida, int qtddados)
{
    char usuario[100], senha[100];
    char tempUsuario[100], tempSenha[100];
    FILE *dados = NULL;
    dados = fopen("teste3/data.txt", "r");
    fscanf(arquivo, "%s %s", usuario, senha);
    

    while (!feof(dados))
    {
        fscanf (dados, "%s %s", tempUsuario, tempSenha);
        printf ("%s %s\n", usuario, senha);
        printf ("%s %s\n", tempUsuario, tempSenha);
        if (strcmp(usuario, tempUsuario) == 0)
        {   
            if (strcmp(senha, tempSenha) == 0)
            {
                fprintf(saida, "Bem vindo, usuario %s\n", usuario);
                break;
            }
            else
            {
                fprintf(saida, "Senha incorreta!\n");
                break;
            }
        }
        if (feof(dados))
        {
            fprintf(saida, "ERROR! login %s nao existe\n", usuario);
        }
    }
    printf ("\n\n");
    fclose(dados);
    qtddados--;
}