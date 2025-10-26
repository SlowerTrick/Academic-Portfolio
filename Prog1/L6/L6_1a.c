#include <stdio.h>

typedef struct 
{
    char idMsg[4];
    char idPct[4];
    char tamanhoConteudo;
    char mensagem[10];
    char codigoErro[5];
} 
tPacote;

tPacote LePacote();
void ImprimePacote(tPacote pacote);

int main(void)
{
    int quantidade = 0;
    scanf("%i", &quantidade);
    tPacote pacote[quantidade];

    int i = 0;
    for (i = 0; i < quantidade; i++)
    {
        pacote[i] = LePacote();
        ImprimePacote(pacote[i]);
    }
    return 0;
}

tPacote LePacote()
{
    int i = 0;
    tPacote pacote;

    scanf("%3s", pacote.idMsg);
    scanf("%3s", pacote.idPct);
    scanf(" %c", &pacote.tamanhoConteudo);

    for (i = 0; i < 9; i++)
    {
        scanf("%c", &pacote.mensagem[i]);
    }
    pacote.mensagem[9] = '\0';
    getchar();

    for (i = 0; i < 4; i++)
    {
        scanf("%c", &pacote.codigoErro[i]);
    }
    pacote.codigoErro[4] = '\0';
    getchar();

    return pacote;
}

void ImprimePacote(tPacote pacote)
{
    int i = 0;
    printf("PCT: ");

    if(pacote.idMsg[0] > '0')
    {
        printf ("%c", pacote.idMsg[0]);
    }
    if(pacote.idMsg[1] > '0' || (pacote.idMsg[1] == '0' && pacote.idMsg[0] > '0'))
    {
        printf ("%c", pacote.idMsg[1]);
    }
    printf ("%c,", pacote.idMsg[2]);

    if(pacote.idPct[0] > '0')
    {
        printf ("%c", pacote.idPct[0]);
    }
    if(pacote.idPct[1] > '0' || (pacote.idPct[1] == '0' && pacote.idPct[0] > '0'))
    {
        printf ("%c", pacote.idPct[1]);
    }
    printf ("%c,", pacote.idPct[2]);

    printf("%c,", pacote.tamanhoConteudo);

    for (i = 0; i < (pacote.tamanhoConteudo - '0'); i++)
    {
        printf ("%c", pacote.mensagem[i]);
    }
    printf(",");

    if(pacote.codigoErro[0] > '0')
    {
        printf ("%c", pacote.codigoErro[0]);
    }
    if(pacote.codigoErro[1] > '0' || (pacote.codigoErro[1] == '0' && pacote.codigoErro[0] > '0'))
    {
        printf ("%c", pacote.codigoErro[1]);
    }
    if(pacote.codigoErro[2] > '0' || (pacote.codigoErro[2] == '0' && pacote.codigoErro[1] > '0'))
    {
        printf ("%c", pacote.codigoErro[2]);
    }
    printf ("%c", pacote.codigoErro[3]);

    printf("\n");
}