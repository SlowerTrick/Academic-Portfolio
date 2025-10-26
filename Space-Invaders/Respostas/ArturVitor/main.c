#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ALTURA_MAX 41
#define LARGURA_MAX 101
#define INIMIGOS_MAX 35

typedef struct
{
    int posX;
    int posY;
}
tPosicao;

typedef struct
{
    char desenho[3][3][4];
    tPosicao inimigoLinha1[INIMIGOS_MAX]; // Eh impossivel a quantidade de inimigos ser maior do que 35,
    tPosicao inimigoLinha2[INIMIGOS_MAX]; // considerando um mapa de no maximo 100 de largura.
    tPosicao inimigoLinha3[INIMIGOS_MAX]; // 
    int totalInimigosLinha1;
    int totalInimigosLinha2;
    int totalInimigosLinha3;
    int desenhoAtual;
    int CoeficienteDeMovimento;
    bool AvancouNessaIteracao;
}
tInimigo;

typedef struct
{
    tPosicao pos;
    char desenhoJogador[4][4];
}
tJogador;

typedef struct
{
    tPosicao pos;
    char desenhoTiro[1][2];
    bool estado;
}
tTiro;

typedef struct
{
    int bonus;
    int totalPontos;
}
tInformacoes;

typedef struct 
{
    char mapa[ALTURA_MAX][LARGURA_MAX];
    int altura;
    int largura;
    tJogador jogador;
    tTiro tiro;
    tInimigo inimigo;
    tInformacoes informacoes;
}
tMapa;

typedef struct
{
    int movimentos;
    int tirosEfetivos;
    int tirosNaoEfetivos;
    int avancoInimigo;
}
tEstatisticas;

typedef struct
{
    int indice;
    int fileira;
    int linha;
    int iteracao;
}
tRanking;

typedef struct
{
    int altura;
    int largura;
    int mapa[ALTURA_MAX][LARGURA_MAX];
}
tHeatMap;

// Funcoes de Inicializacao do Mapa
tMapa InicializaMapa(char *diretorio);
tInformacoes ArmazenaBonus(FILE *arquivo);
void ArmazenaDesenhoInimigo(FILE *arquivo, char desenho[3][3][4]);
int InicializaPosicoesInimigos(FILE *arquivo, tPosicao posicao[]);
tJogador InicializaJogador(FILE *arquivo);
tInimigo InicializaInimigo(FILE *desenho, FILE *posicoes);
tTiro InicializaTiro();

// Funcoes de Realizacao do Jogo
tMapa RealizaJogo (char *diretorio, tMapa mapa);
tMapa VerificaColisao(tMapa mapa, tInimigo inimigo, tTiro tiro, tRanking ranking[], int iteracao, FILE * diretorio);
tInimigo AlterarPosicaoInimigos(tInimigo inimigo, int largura);
tInimigo MovimentaInimigosNaVertical(tInimigo inimigo);
tInimigo MovimentaInimigosNaHorizontal(tInimigo inimigo, int CoeficienteDeMovimento);
tInimigo ResetaFlagInimigo(tInimigo inimigo);
tJogador AlterarPosicaoPlayer(tJogador player, char movimento);
tTiro AlterarPosicaoTiro(tTiro tiro);
tTiro DispararTiro(tJogador player);
tPosicao PosicionaTiro (tPosicao jogador);
tInformacoes AdicionaPontos(tInformacoes info, tPosicao inimigo, tPosicao tiro, int altura);
bool HouveColisao(tPosicao tiro, tPosicao inimigo);
bool Vitoria(int totalinimigos);
bool Derrota(tJogador jogador, tInimigo inimigo);
bool ExisteTiroAtivo(tTiro tiro);
bool TiroChegouNoLimite(tTiro tiro);
bool EhMovimentoValido(char movimento, tJogador jogador, tTiro tiro, int largura);
bool InimigoAvancou(tInimigo inimigo);
bool VaiSairDaBordaHorizontal(tPosicao entidade, int largura, int coeficiente);
char LeMovimentoPlayer(FILE *arquivo);
int EncontraMaisProximoDaBorda(tInimigo inimigo, int modo, int largura);
int InimigosRestantes(tInimigo inimigo);

// Funcoes Acessorias
FILE *InicializaFile(char *diretorio, int modo);
tPosicao InicializaPosicao(FILE *arquivo);
tTiro TiraTiroDaTela(tTiro tiro);
tInimigo VerificaBonus(tInimigo inimigo, tInformacoes info);
tPosicao TiraInimigoDaTela(tPosicao inimigo);
tPosicao RetornaPosicaoJogador(tJogador jogador);
tPosicao RetornaPosicaoTiro(tTiro tiro);
tEstatisticas InicializaEstatisticas();
tInformacoes InicializaInformacoes(tInformacoes info);
tHeatMap InicializaHeatMap(int altura, int largura);
tHeatMap AlteraHeatMapJogador(tHeatMap heatmap, tJogador jogador, int largura);
tHeatMap AlteraHeatMapTiro(tHeatMap heatmap, tTiro tiro);
int RetornaX(tPosicao entidade);
int RetornaY(tPosicao entidade);
int RetornaTotalInimigos(tInimigo inimigo);
int RetornaTotalInimigosLinha(tInimigo inimigo, int modo);
bool VerificaResumoJogadorLateral(FILE *diretorio, bool flag, char movimento, int iteracao);
void DesenhaTiro(char desenhoTiro[1][2]);
void PreencheMapa(char mapa[ALTURA_MAX][LARGURA_MAX], int altura, int largura, tJogador jogador, tInimigo inimigo, tTiro tiro);
void PrintaBordaMapaHorizontal(FILE *arquivo, int largura);
void PrintaMapa(char mapa[ALTURA_MAX][LARGURA_MAX], FILE *arquivo, tJogador jogador, int altura, int largura);
void PosicionaJogadorNoMapa (char mapa[ALTURA_MAX][LARGURA_MAX], tPosicao jogador, char desenhoJogador[4][4]);
void PosicionaInimigosNoMapa (char mapa[ALTURA_MAX][LARGURA_MAX], tInimigo inimigo);
void PosicionaTiroNoMapa(char mapa[ALTURA_MAX][LARGURA_MAX], tPosicao tiro, char desenhoTiro[1][2]);
void PrintaPosicaoInicialJogador(FILE *diretorio, tPosicao jogador);
void PrintaPontosIteracao(FILE *diretorio, tInformacoes info, int i);
void PrintaResumoInimigoAtingido(FILE *diretorio, int i, int indice, int fileira, tPosicao bala);
void PrintaResumoInimigoLateral(FILE *diretorio, int iteracao, int largura, tInimigo inimigo);
void PrintaResumoJogadorLateral(FILE *diretorio, int i, int modo);
void InicializaRanking(tRanking ranking[], int totalInimigos);
void RegistraRanking(tRanking ranking[], tPosicao tiro, int iteracao, int indice, int fileira, int alturaMapa);
void PrintaRanking(FILE *diretorio, tRanking ranking[], int total);
void PrintaEstatisticas(FILE *diretorio, tEstatisticas estatisticas);
void PrintaHeatMap(FILE *diretorio, tHeatMap heatmap);

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf ("ERRO: Informe o diretorio com os arquivos de configuracao.");
        return 1;
    }
    tMapa mapa;
    mapa = InicializaMapa(argv[1]);
    mapa = RealizaJogo(argv[1], mapa);

    return 0;
}

tMapa InicializaMapa(char *diretorio)
{
    // Cria as strings para acessar os arquivos correspondentes
    char localMapa[1000];
    char localInimigo[1000];
    sprintf(localMapa, "%s/mapa.txt", diretorio);
    sprintf(localInimigo, "%s/inimigo.txt", diretorio);

    // Abre os arquivos a partir das strings criadas anteriormente
    FILE *arquivoMapa = InicializaFile(localMapa, 1);
    if (!arquivoMapa)
    {
        exit(1);
    }
    FILE *arquivoInimigo = InicializaFile(localInimigo, 1);
    if (!arquivoInimigo)
    {
        fclose(arquivoMapa);
        exit(1);
    }

    // Cria o mapa e armazena informacoes inatas ao tipo
    tMapa mapa;
    fscanf (arquivoMapa, "%d %d", &mapa.largura, &mapa.altura);
    fgetc(arquivoMapa);
    mapa.jogador = InicializaJogador(arquivoMapa);
    mapa.informacoes = ArmazenaBonus(arquivoInimigo);
    mapa.inimigo = InicializaInimigo(arquivoInimigo, arquivoMapa);
    mapa.tiro = InicializaTiro();

    // Criacao do arquivo de saida "inicializacao"
    char arquivoSaidaInicializacao[50];
    sprintf(arquivoSaidaInicializacao, "%s/saida/inicializacao.txt", diretorio);
    FILE *saidaInicializacao = InicializaFile(arquivoSaidaInicializacao, 2);
    if (!saidaInicializacao)
    {
        fclose(arquivoMapa);
        fclose(arquivoInimigo);
        exit(1);
    }

    // Bloco de funcoes para printar o mapa no arquivo inicializacao
    PreencheMapa (mapa.mapa, mapa.altura, mapa.largura, mapa.jogador, mapa.inimigo, mapa.tiro);
    PrintaBordaMapaHorizontal (saidaInicializacao, mapa.largura);
    PrintaMapa (mapa.mapa, saidaInicializacao, mapa.jogador, mapa.altura, mapa.largura);
    PrintaBordaMapaHorizontal(saidaInicializacao, mapa.largura);

    PrintaPosicaoInicialJogador(saidaInicializacao, RetornaPosicaoJogador(mapa.jogador));

    fclose(arquivoMapa);
    fclose(arquivoInimigo);
    fclose(saidaInicializacao);
    return mapa;
}

tPosicao InicializaPosicao(FILE *arquivo)
{
    /*
        Le as posicoes de um arquivo e as retorna
    */

    tPosicao posicao;
    fscanf (arquivo, "(%d %d)", &posicao.posX, &posicao.posY);
    fgetc(arquivo);
    return posicao;
}

tPosicao RetornaPosicaoJogador(tJogador jogador)
{
    /*
        Extrai do tipo tJogador o tPosicao do Jogador
    */

    return jogador.pos;
}

tPosicao RetornaPosicaoTiro(tTiro tiro)
{
    /*
        Extrai do tipo tTiro o tPosicao do Tiro
    */

    return tiro.pos;
}

int RetornaX(tPosicao entidade)
{
    /*
        Extrai de um tPosicao o valor X
    */

    return entidade.posX;
}

int RetornaY(tPosicao entidade)
{
    /*
        Extrai de um tPosicao o valor Y
    */

    return entidade.posY;
}

void PreencheMapa(char mapa[ALTURA_MAX][LARGURA_MAX], int altura, int largura, tJogador jogador, tInimigo inimigo, tTiro tiro)
{
    /*
        Parametros:
        
        - char mapa[ALTURA_MAX][LARGURA_MAX]: Este parametro eh a matriz que representa o mapa do jogo. 
          A funcao utiliza esta matriz para preencher o mapa com espacos em branco inicialmente e, em seguida, 
          para posicionar os elementos do jogo (jogador, inimigos e tiro) nas suas posicoes corretas.

        - int altura: Este parametro define a altura atual do mapa. Ele eh usado nos loops 'for' para 
          iterar sobre as linhas da matriz 'mapa' e garantir que apenas a parte ativa do mapa seja preenchida 
          e modificada de forma correta.

        - int largura: Este parametro define a largura atual do mapa. Ele eh usado nos loops 'for' para 
          iterar sobre as colunas da matriz 'mapa' e garantir que apenas a parte ativa do mapa seja preenchida 
          e modificada de forma correta.

        - tJogador jogador: Este parametro fornece a posicao e o desenho do jogador. 
          A funcao 'PosicionaJogadorNoMapa' utiliza essas informacoes para colocar o jogador 
          na posicao correta dentro da matriz 'mapa'.

        - tInimigo inimigo: Este parametro fornece as informacoes dos inimigos. 
          A funcao 'PosicionaInimigosNoMapa' utiliza essas informacoes para colocar os inimigos 
          nas suas posicoes corretas dentro da matriz 'mapa'.

        - tTiro tiro: Este parametro fornece a posicao, o desenho e o estado do tiro. 
          Se o tiro estiver ativo ('tiro.estado == true'), a funcao 'PosicionaTiroNoMapa' 
          eh chamada para colocar o tiro na posicao correta dentro da matriz 'mapa'.
    */

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            // Deixa o mapa atual todo em branco
            mapa[i][j] = ' ';
        }
    }
    PosicionaJogadorNoMapa (mapa, jogador.pos, jogador.desenhoJogador);
    PosicionaInimigosNoMapa (mapa, inimigo);
    if (tiro.estado == true)
    {
        PosicionaTiroNoMapa(mapa, tiro.pos, tiro.desenhoTiro);
    }
    return;
}

FILE *InicializaFile(char *diretorio, int modo)
{
    /*
        Abre um arquivo no modo desejado e retorna esse arquivo, utiliza-se modos:

        Modo 1 para criar arquivo de leitura e Modo 2 para escrever em um arquivo
    */

    FILE *arquivo = NULL;

    if (modo == 1)
    {
        arquivo = fopen(diretorio, "r");
        if (!arquivo)
        {
            printf ("Nao foi possivel abrir o arquivo %s", diretorio);
            return arquivo;
        }
        return arquivo;
    }
    if (modo == 2)
    {
        arquivo = fopen(diretorio, "w");
        if (!arquivo)
        {
            printf ("Nao foi possivel abrir o arquivo %s", diretorio);
            return arquivo;
        }
        return arquivo;
    }
    return arquivo;
}

tJogador InicializaJogador(FILE *arquivo)
{
    /*
        Inicializa o desenho do jogador, e armazena a sua posicao a partir do arquivo fornecido
    */
    tJogador jogador;

    jogador.desenhoJogador[0][0] = 'M';
    jogador.desenhoJogador[0][1] = ' ';
    jogador.desenhoJogador[0][2] = 'M';

    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            jogador.desenhoJogador[i][j] = 'M';
        }
    }

    jogador.pos = InicializaPosicao(arquivo);

    return jogador;
}

tInimigo InicializaInimigo(FILE *desenho, FILE *posicoes)
{
    /*
        "desenho" para armazenar o desenho do inimigo e "posicoes" para as posicoes do mesmo
    */
    tInimigo inimigo;
    ArmazenaDesenhoInimigo(desenho, inimigo.desenho);

    inimigo.totalInimigosLinha1 = InicializaPosicoesInimigos(posicoes, inimigo.inimigoLinha1);
    inimigo.totalInimigosLinha2 = InicializaPosicoesInimigos(posicoes, inimigo.inimigoLinha2);
    inimigo.totalInimigosLinha3 = InicializaPosicoesInimigos(posicoes, inimigo.inimigoLinha3);

    inimigo.desenhoAtual = 0;
    inimigo.CoeficienteDeMovimento = 1;
    inimigo.AvancouNessaIteracao = false;
    
    return inimigo;
}

tTiro InicializaTiro()
{
    /*
        Inicializa o tiro, com seu estado atual como false e faz ele nao aparecer no mapa na primeira iteracao    
    */

    tTiro tiro;
    tiro.estado = false;
    tiro = TiraTiroDaTela(tiro);
    return tiro;
}

tTiro TiraTiroDaTela(tTiro tiro)
{  
    tPosicao posicao;
    posicao.posX = -1; // "pos = -1", significa que o elemento nao aparecera no mapa
    posicao.posY = -1; // "pos = -1", significa que o elemento nao aparecera no mapa
    tiro.pos = posicao;
    tiro.estado = false; // "estado = false", eh o mesmo que tiro nao eh posicionado no mapa
    return tiro;
}

tPosicao TiraInimigoDaTela(tPosicao inimigo)
{
    inimigo.posX = -1; // "pos = -1", significa que o elemento nao aparecera no mapa
    inimigo.posY = -1; // "pos = -1", significa que o elemento nao aparecera no mapa
    return inimigo;
}

tInformacoes ArmazenaBonus(FILE *arquivo)
{
    /*
        Armazena o bonus no decorrer da entrada
    */
    tInformacoes info;
    fscanf (arquivo, "%d", &info.bonus);
    fgetc(arquivo);
    return info;
}

void ArmazenaDesenhoInimigo(FILE *arquivo, char desenho[3][3][4])
{
    char temp;

    // Funcao responsavel por armazenar o desenho do inimigo no array tridimensional
    for (int p = 0; p < 3; p++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fscanf(arquivo, "%c", &desenho[p][i][j]);
            }
            temp = fgetc(arquivo); // Retira o '\n'
        }
    }
    return;
}

int InicializaPosicoesInimigos(FILE *arquivo, tPosicao posicao[])
{
    /*
        Retira do arquivo fornecido as posicoes dos inimigos em uma determinada linha, e ao final,
        retorna a quantidade de inimigos da linha
    */
    int i = 0;
    
    char temp = fgetc(arquivo); // Verificacao para linha vazia no primeiro armazenamento
    if (temp == '\n')
        return i;
    ungetc(temp, arquivo); // Devolve o caractere para o arquivo se a linha nao estiver vazia

    char linha[500]; //Segundo a logica do programa, a linha nao tera mais de 500 caracteres
    fgets(linha, sizeof(linha), arquivo);

    if (linha[i] == '\n' || feof(arquivo))
    {
        return i;
    }

    int read = 0;
    int atual = 0;
    while (sscanf(&linha[atual] ,"(%d %d)%c%n", &posicao[i].posX, &posicao[i].posY, &temp, &read) == 3)
    {
        if (read == 0) // Nada foi lido, sscanf chegou ao final da linha.
            break;
        atual += read; // "Avanca" o atual, (quantidade de caracteres lidos) vezes.
        i++;
        if (temp == '\n')
        {
            return i;
        }
    }
    return i;
}

void PrintaBordaMapaHorizontal(FILE *arquivo, int largura)
{
    /*
        Esta funcao tem como objetivo printar a borda horizontal no inicio e fim do mapa
    */
    fprintf (arquivo, "+");
    for (int i = 0; i < largura; i++)
    {
        fprintf (arquivo, "-");
    }
    fprintf (arquivo, "+\n");
    return;
}

void PosicionaJogadorNoMapa (char mapa[ALTURA_MAX][LARGURA_MAX], tPosicao jogador, char desenhoJogador[4][4])
{
    /*
        Posiciona o jogador no mapa em sua respectiva posicao, os coeficientes "-2" e "-1" sao utilizados
        para o posicionamento correto do jogador no mapa devido ao fato de que o mapa eh inciado na posicao
        (1, 1) e nao (0, 0) que e o esperado para uma matriz
    */
    mapa[jogador.posY-2][jogador.posX] = desenhoJogador[0][2];
    mapa[jogador.posY-2][jogador.posX-1] = desenhoJogador[0][1];
    mapa[jogador.posY-2][jogador.posX-2] = desenhoJogador[0][0];

    mapa[jogador.posY-1][jogador.posX] = desenhoJogador[1][2];
    mapa[jogador.posY-1][jogador.posX-1] = desenhoJogador[1][1];
    mapa[jogador.posY-1][jogador.posX-2] = desenhoJogador[1][0];

    mapa[jogador.posY][jogador.posX] = desenhoJogador[2][2];
    mapa[jogador.posY][jogador.posX-1] = desenhoJogador[2][1];
    mapa[jogador.posY][jogador.posX-2] = desenhoJogador[2][0];

    return;
}

void PosicionaInimigosNoMapa (char mapa[ALTURA_MAX][LARGURA_MAX], tInimigo inimigo)
{
    /*
        Posiciona todos os inimigos no mapa em suas respectivas posicoes, os coeficientes "-2" e "-1" sao 
        utilizados para o posicionamento correto dos inimigos no mapa devido ao fato de que o mapa eh inciado 
        na posicao (1, 1) e nao (0, 0) que e o esperado para uma matriz
    */

    for (int i = 0; i < inimigo.totalInimigosLinha1; i++)
    {
        if (RetornaX(inimigo.inimigoLinha1[i]) != -1)
        {
            mapa[RetornaY(inimigo.inimigoLinha1[i])-2][RetornaX(inimigo.inimigoLinha1[i])] = inimigo.desenho[inimigo.desenhoAtual][0][2];
            mapa[RetornaY(inimigo.inimigoLinha1[i])-2][RetornaX(inimigo.inimigoLinha1[i])-1] = inimigo.desenho[inimigo.desenhoAtual][0][1];
            mapa[RetornaY(inimigo.inimigoLinha1[i])-2][RetornaX(inimigo.inimigoLinha1[i])-2] = inimigo.desenho[inimigo.desenhoAtual][0][0];

            mapa[RetornaY(inimigo.inimigoLinha1[i])-1][RetornaX(inimigo.inimigoLinha1[i])] = inimigo.desenho[inimigo.desenhoAtual][1][2];
            mapa[RetornaY(inimigo.inimigoLinha1[i])-1][RetornaX(inimigo.inimigoLinha1[i])-1] = inimigo.desenho[inimigo.desenhoAtual][1][1];
            mapa[RetornaY(inimigo.inimigoLinha1[i])-1][RetornaX(inimigo.inimigoLinha1[i])-2] = inimigo.desenho[inimigo.desenhoAtual][1][0];

            mapa[RetornaY(inimigo.inimigoLinha1[i])][RetornaX(inimigo.inimigoLinha1[i])] = inimigo.desenho[inimigo.desenhoAtual][2][2];
            mapa[RetornaY(inimigo.inimigoLinha1[i])][RetornaX(inimigo.inimigoLinha1[i])-1] = inimigo.desenho[inimigo.desenhoAtual][2][1];
            mapa[RetornaY(inimigo.inimigoLinha1[i])][RetornaX(inimigo.inimigoLinha1[i])-2] = inimigo.desenho[inimigo.desenhoAtual][2][0];
        }
    }
    for (int i = 0; i < inimigo.totalInimigosLinha2; i++)
    {
        if (RetornaX(inimigo.inimigoLinha2[i]) != -1)
        {
            mapa[RetornaY(inimigo.inimigoLinha2[i])-2][RetornaX(inimigo.inimigoLinha2[i])] = inimigo.desenho[inimigo.desenhoAtual][0][2];
            mapa[RetornaY(inimigo.inimigoLinha2[i])-2][RetornaX(inimigo.inimigoLinha2[i])-1] = inimigo.desenho[inimigo.desenhoAtual][0][1];
            mapa[RetornaY(inimigo.inimigoLinha2[i])-2][RetornaX(inimigo.inimigoLinha2[i])-2] = inimigo.desenho[inimigo.desenhoAtual][0][0];

            mapa[RetornaY(inimigo.inimigoLinha2[i])-1][RetornaX(inimigo.inimigoLinha2[i])] = inimigo.desenho[inimigo.desenhoAtual][1][2];
            mapa[RetornaY(inimigo.inimigoLinha2[i])-1][RetornaX(inimigo.inimigoLinha2[i])-1] = inimigo.desenho[inimigo.desenhoAtual][1][1];
            mapa[RetornaY(inimigo.inimigoLinha2[i])-1][RetornaX(inimigo.inimigoLinha2[i])-2] = inimigo.desenho[inimigo.desenhoAtual][1][0];

            mapa[RetornaY(inimigo.inimigoLinha2[i])][RetornaX(inimigo.inimigoLinha2[i])] = inimigo.desenho[inimigo.desenhoAtual][2][2];
            mapa[RetornaY(inimigo.inimigoLinha2[i])][RetornaX(inimigo.inimigoLinha2[i])-1] = inimigo.desenho[inimigo.desenhoAtual][2][1];
            mapa[RetornaY(inimigo.inimigoLinha2[i])][RetornaX(inimigo.inimigoLinha2[i])-2] = inimigo.desenho[inimigo.desenhoAtual][2][0];
        }
    }
    for (int i = 0; i < inimigo.totalInimigosLinha3; i++)
    {
        if (RetornaX(inimigo.inimigoLinha3[i]) != -1)
        {
            mapa[RetornaY(inimigo.inimigoLinha3[i])-2][RetornaX(inimigo.inimigoLinha3[i])] = inimigo.desenho[inimigo.desenhoAtual][0][2];
            mapa[RetornaY(inimigo.inimigoLinha3[i])-2][RetornaX(inimigo.inimigoLinha3[i])-1] = inimigo.desenho[inimigo.desenhoAtual][0][1];
            mapa[RetornaY(inimigo.inimigoLinha3[i])-2][RetornaX(inimigo.inimigoLinha3[i])-2] = inimigo.desenho[inimigo.desenhoAtual][0][0];

            mapa[RetornaY(inimigo.inimigoLinha3[i])-1][RetornaX(inimigo.inimigoLinha3[i])] = inimigo.desenho[inimigo.desenhoAtual][1][2];
            mapa[RetornaY(inimigo.inimigoLinha3[i])-1][RetornaX(inimigo.inimigoLinha3[i])-1] = inimigo.desenho[inimigo.desenhoAtual][1][1];
            mapa[RetornaY(inimigo.inimigoLinha3[i])-1][RetornaX(inimigo.inimigoLinha3[i])-2] = inimigo.desenho[inimigo.desenhoAtual][1][0];

            mapa[RetornaY(inimigo.inimigoLinha3[i])][RetornaX(inimigo.inimigoLinha3[i])] = inimigo.desenho[inimigo.desenhoAtual][2][2];
            mapa[RetornaY(inimigo.inimigoLinha3[i])][RetornaX(inimigo.inimigoLinha3[i])-1] = inimigo.desenho[inimigo.desenhoAtual][2][1];
            mapa[RetornaY(inimigo.inimigoLinha3[i])][RetornaX(inimigo.inimigoLinha3[i])-2] = inimigo.desenho[inimigo.desenhoAtual][2][0];
        }
    }
    return;
}

void PosicionaTiroNoMapa(char mapa[ALTURA_MAX][LARGURA_MAX], tPosicao tiro, char desenhoTiro[1][2])
{
    /*
        Esta funcao posiciona o tiro no mapa com base em sua posicao
    */
    mapa[tiro.posY][tiro.posX] = 'o';
    return;
}

void PrintaMapa(char mapa[ALTURA_MAX][LARGURA_MAX], FILE *arquivo, tJogador jogador, int altura, int largura)
{
    /*
        Parametros:

        - char mapa[ALTURA_MAX][LARGURA_MAX]: Este parametro eh a matriz que representa o mapa do jogo. 
          A funcao usa esta matriz para acessar e imprimir cada parte do mapa, representando os 
          elementos do jogo na saida.

        - FILE *arquivo: Este parametro eh o arquivo onde o mapa sera impresso. 

        - tJogador jogador: Este parametro fornece a posicao do jogador. 
          A funcao usa a posicao do jogador ('jogador.pos.posY') para determinar onde imprimir a borda 
          especial (linha '-') logo acima do jogador.

        - int altura: Este parametro define a altura atual do mapa. Ele eh usado no loop 'for' para 
          iterar sobre as linhas da matriz 'mapa' e garantir que toda a altura ativa do mapa seja impressa.

        - int largura: Este parametro define a largura atual do mapa. Ele eh usado no loop 'for' para 
          iterar sobre as colunas da matriz 'mapa' e garantir que toda a largura ativa do mapa seja impressa.
    */

    for (int i = 0; i < altura; i++)
    {
        if (i != jogador.pos.posY - 3) // Printa borda lateral esquerda do mapa 
        {
            fprintf (arquivo, "|");
        }
        if (i == jogador.pos.posY - 3)  // Printa borda lateral esquerda do mapa logo acima do jogador
        {
            fprintf (arquivo, "-");
        }

        for (int j = 0; j < largura; j++)
        {
            fprintf (arquivo, "%c", mapa[i][j]); // Printa o mapa todo
        }

        if (i != jogador.pos.posY - 3)
        {
            fprintf (arquivo, "|\n"); // Printa borda lateral direita do mapa 
        }
        if (i == jogador.pos.posY - 3)
        {
            fprintf (arquivo, "-\n"); // Printa borda lateral direita do mapa logo acima do jogador
        }
    }
}

void PrintaPosicaoInicialJogador(FILE *diretorio, tPosicao jogador)
{
    /*
        Printa no arquivo "inicializacao" a posicao inicial do jogador
    */
    
    fprintf (diretorio, "A posicao central do jogador iniciara em (%d %d).", jogador.posX, jogador.posY);
    return;
}

tMapa RealizaJogo (char *diretorio, tMapa mapa)
{
    // Inicializaco de variaveis 
    int i = 0;
    int totalInimigos = RetornaTotalInimigos(mapa.inimigo);
    int totalRanking = totalInimigos + 1;
    mapa.informacoes = InicializaInformacoes(mapa.informacoes);

    // Inicializacao das saidas
    tEstatisticas estatisticas = InicializaEstatisticas();
    tHeatMap heatmap = InicializaHeatMap(mapa.altura, mapa.largura);
    tRanking ranking[totalInimigos + 1];
    InicializaRanking(ranking, totalRanking);

    // Inicializacao dos arquivos de entrada e saida
    char localEntrada[1000];
    sprintf(localEntrada, "%s/entrada.txt", diretorio);
    FILE *arquivoEntrada = InicializaFile(localEntrada, 1);
    if (!arquivoEntrada)
    {
        exit(1);
    }
    char arquivoSaidaSaida[50];
    sprintf(arquivoSaidaSaida, "%s/saida/saida.txt", diretorio);
    FILE *saidaSaida = InicializaFile(arquivoSaidaSaida, 2);
    if (!saidaSaida)
    {
        fclose(arquivoEntrada);
        exit(1);
    }
    char arquivoSaidaRanking[50];
    sprintf(arquivoSaidaRanking, "%s/saida/ranking.txt", diretorio);
    FILE *saidaRanking = InicializaFile(arquivoSaidaRanking, 2);
    if (!saidaRanking)
    {
        fclose(saidaSaida);
        fclose(arquivoEntrada);
        exit(1);
    }
    char arquivoSaidaResumo[50];
    sprintf(arquivoSaidaResumo, "%s/saida/resumo.txt", diretorio);
    FILE *saidaResumo = InicializaFile(arquivoSaidaResumo, 2);
    if (!saidaResumo)
    {
        fclose(saidaResumo);
        fclose(saidaSaida);
        fclose(arquivoEntrada);
        exit(1);
    }
    char arquivoSaidaEstatisticas[50];
    sprintf(arquivoSaidaEstatisticas, "%s/saida/estatisticas.txt", diretorio);
    FILE *saidaEstatisticas = InicializaFile(arquivoSaidaEstatisticas, 2);
    if (!saidaEstatisticas)
    {
        fclose(saidaRanking);
        fclose(saidaResumo);
        fclose(saidaSaida);
        fclose(arquivoEntrada);
        exit(1);
    }
    char arquivoSaidaHeatmap[50];
    sprintf(arquivoSaidaHeatmap, "%s/saida/heatmap.txt", diretorio);
    FILE *saidaHeatmap = InicializaFile(arquivoSaidaHeatmap, 2);
    if (!saidaHeatmap)
    {
        fclose(saidaEstatisticas);
        fclose(saidaRanking);
        fclose(saidaResumo);
        fclose(saidaSaida);
        fclose(arquivoEntrada);
        exit(1);
    }

    // Bloco de funcoes para printar a iteracao 0
    PrintaPontosIteracao(saidaSaida, mapa.informacoes, i);
    PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);
    PrintaMapa (mapa.mapa, saidaSaida, mapa.jogador, mapa.altura, mapa.largura);
    PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);

    // 
    heatmap = AlteraHeatMapJogador(heatmap, mapa.jogador, mapa.largura);
    heatmap = AlteraHeatMapTiro(heatmap, mapa.tiro);

    bool CheckVitoria = false; // Vitoria tem que passar 2 vezes para a iteracao final ser contabilizada
    int ContaVitorias = 0; // Contador auxiliar da flag "CheckVitoria"
    bool FlagResumoJogador = false; // Flag para o resumo do jogador ser printado na iteracao correta
    char movimentoAnterior = 0; // Variavel auxiliar da flag printa resumo do jogador.
    
    if (!Vitoria(totalInimigos)) // Evitar caso onde o jogo comeca ganho
    {
        while ((!CheckVitoria && !Derrota(mapa.jogador, mapa.inimigo)))
        {
            // Movimentacao do player e sua nuances
            char movimento = LeMovimentoPlayer(arquivoEntrada);

            if (EhMovimentoValido(movimento, mapa.jogador, mapa.tiro, mapa.largura))
            {
                if (movimento == ' ')
                {
                    mapa.tiro = DispararTiro(mapa.jogador);
                    estatisticas.tirosEfetivos++;
                }
                else if (movimento == 'a' || movimento == 'd')
                {
                    mapa.jogador = AlterarPosicaoPlayer(mapa.jogador, movimento);
                    estatisticas.movimentos++;
                }
            }
            else if (movimento == 'a' || movimento == 'd') // Economia sintatica para ("!EhMovimentoValido()")
            {
                movimentoAnterior = movimento;
                FlagResumoJogador = true;
            }

            // Movimentacao do inimigo
            mapa.inimigo = AlterarPosicaoInimigos(mapa.inimigo, mapa.largura);

            if (totalInimigos > 0)
            {
                if (InimigoAvancou(mapa.inimigo))
                {
                    PrintaResumoInimigoLateral(saidaResumo, i, mapa.largura, mapa.inimigo);
                    estatisticas.avancoInimigo++;
                }
            }
            
            // Movimentacao do tiro
            if (ExisteTiroAtivo(mapa.tiro))
            {
                mapa.tiro = AlterarPosicaoTiro(mapa.tiro);
            }

            // Alteracao do desenho do inimigo caso o bonus esteja ativo
            mapa.inimigo = VerificaBonus(mapa.inimigo, mapa.informacoes);

            // Preenchimento do mapa com todas as alteracoes feitas no decorrer da iteracao
            PreencheMapa (mapa.mapa, mapa.altura, mapa.largura, mapa.jogador, mapa.inimigo, mapa.tiro); 

            // Modificacoes no heatmap
            heatmap = AlteraHeatMapJogador(heatmap, mapa.jogador, mapa.largura);
            heatmap = AlteraHeatMapTiro(heatmap, mapa.tiro);

            // Bloco de funcoes para printar as iteracoes do jogo
            i++;
            PrintaPontosIteracao(saidaSaida, mapa.informacoes, i);
            PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);
            PrintaMapa (mapa.mapa, saidaSaida, mapa.jogador, mapa.altura, mapa.largura);
            PrintaBordaMapaHorizontal(saidaSaida, mapa.largura);

            // Verificacao para o registro correto do resumo na parte do jogador
            FlagResumoJogador = VerificaResumoJogadorLateral(saidaResumo, FlagResumoJogador, movimentoAnterior, i);

            // Verificacao para casos onde o jogo deve ser parado prematuramente
            if (Derrota(mapa.jogador, mapa.inimigo))
            {
                break;
            }

            // Verificacao de colisoes tiro-inimigo
            mapa = VerificaColisao(mapa, mapa.inimigo, mapa.tiro, ranking, i, saidaResumo);

            if (TiroChegouNoLimite(mapa.tiro))
            {
                mapa.tiro = TiraTiroDaTela(mapa.tiro);
                estatisticas.tirosNaoEfetivos++;
            }

            totalInimigos = InimigosRestantes(mapa.inimigo);
            mapa.inimigo = ResetaFlagInimigo(mapa.inimigo);

            // Confirmacao para a flag "CheckVitoria", explicada anteriormente
            if (Vitoria(totalInimigos))
            {
                ContaVitorias++;
                if (ContaVitorias == 2)
                {
                    CheckVitoria = true;
                }
            }
        }
    }
    // Verificacao final para a printagem correta do resumo
    VerificaResumoJogadorLateral(saidaResumo, FlagResumoJogador, movimentoAnterior, i);

    if (Vitoria(totalInimigos))
    {
        fprintf(saidaSaida, "Parabéns, você ganhou!\n");
        PrintaRanking(saidaRanking,ranking, totalRanking);
    }
    if (Derrota(mapa.jogador, mapa.inimigo))
    {
        fprintf(saidaSaida, "Você perdeu, tente novamente!\n");
        PrintaRanking(saidaRanking,ranking, totalRanking - totalInimigos);
    }

    // Printa os dados coletados durante as iteracoes
    PrintaEstatisticas(saidaEstatisticas, estatisticas);
    PrintaHeatMap(saidaHeatmap, heatmap);

    fclose(saidaHeatmap);
    fclose(saidaEstatisticas);
    fclose(saidaRanking);
    fclose(saidaResumo);
    fclose(saidaSaida);
    fclose(arquivoEntrada);
    return mapa;
}

bool Vitoria(int totalinimigos)
{
    /*
        Esta funcao verifica se o total de inimigos eh igual a 0, em caso positivo ele retorna verdadeiro,
        caso contrario, retorna false
    */
    if (totalinimigos == 0)
    {
        return true;
    }
    return false;
}

bool Derrota(tJogador jogador, tInimigo inimigo)
{
    /*
        Esta funcao recebe um inimigo e um jogador, caso o inimigo chegue ao jogador, a funcao retorna
        "true" e em caso contrario retorna false, a funcao passa por cada uma das linhas que possui inimigos
    */

    for (int i = 0; i < inimigo.totalInimigosLinha1; i++)
    {
        if (RetornaX(inimigo.inimigoLinha1[i]) != -1)
        {
            if (RetornaY(inimigo.inimigoLinha1[i]) == RetornaY(jogador.pos) - 2)
            {
                return true;
            }
        }
    }
    for (int i = 0; i < inimigo.totalInimigosLinha2; i++)
    {
        if (RetornaY(inimigo.inimigoLinha2[i]) == RetornaY(jogador.pos) - 2)
        {
            if (RetornaY(inimigo.inimigoLinha2[i]) == RetornaY(jogador.pos) - 2)
            {
                return true;
            }
        }
    }
    for (int i = 0; i < inimigo.totalInimigosLinha3; i++)
    {
        if (RetornaX(inimigo.inimigoLinha3[i]) != -1)
        {
            if (RetornaY(inimigo.inimigoLinha3[i]) == RetornaY(jogador.pos) - 2)
            {
                return true;
            }
        }
    }
    return false;
}

char LeMovimentoPlayer(FILE *arquivo)
{
    // Esta funcao registra o movimento do player

    // Retira todos os '\n' da entrada ateh encontrar algo diferente

    char movimento = fgetc(arquivo);
    while (movimento == '\n')
    {
        movimento = fgetc(arquivo);
    }
    return movimento;
}

bool EhMovimentoValido(char movimento, tJogador jogador, tTiro tiro, int largura)
{
    /*
        Esta funcao lida com todas as possibilidades de movimento do jogador e caso o movimento
        possa ocorrer nessa iteracao ela retorna "true"
    */

    if (movimento == 's')
    {
        return true;
    }
    if (movimento == ' ')
    {
        if (!ExisteTiroAtivo(tiro))
        {
            return true;
        }
        return false;
    }
    if (movimento == 'a')
    {
        if (!VaiSairDaBordaHorizontal(jogador.pos, largura, -1))
        {
            return true;
        }
        return false;
    }
    if (movimento == 'd')
    {
        if (!VaiSairDaBordaHorizontal(jogador.pos, largura, 1))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool ExisteTiroAtivo(tTiro tiro)
{
    /*
        Esta funcao verifica se o tiro esta ativo, ou seja, se o estado do tiro eh true.
        Se o tiro esta ativo, retorna true; caso contrario, retorna false.
    */
   
    if (tiro.estado == true)
    {
        return true;
    }
    return false;
}

bool TiroChegouNoLimite(tTiro tiro)
{
    /*
        Esta funcao verifica se o tiro chegou ao limite superior da tela (y == 0).
        Se o tiro chegou ao limite, retorna true; caso contrario, retorna false.
    */

    tPosicao posicao = tiro.pos;
    if (RetornaY(posicao) == 0)
    {
        return true;
    }
    return false;
}

tMapa VerificaColisao(tMapa mapa, tInimigo inimigo, tTiro tiro, tRanking ranking[], int iteracao, FILE *diretorio)
{
    /*
        Esta funcao verifica se houve colisao entre o tiro e algum inimigo em cada uma das tres fileiras.
        Se houve colisao, registra no ranking, adiciona pontos, remove o tiro e o inimigo da tela,
        e retorna o mapa atualizado. Se nao houve colisao, retorna o mapa inalterado.
    */

    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 1); i++)
    {
        if (HouveColisao(tiro.pos, inimigo.inimigoLinha1[i]))
        {
            PrintaResumoInimigoAtingido(diretorio, iteracao, i+1, 1, tiro.pos);
            RegistraRanking(ranking, tiro.pos, iteracao, i+1, 1, mapa.altura);
            mapa.informacoes = AdicionaPontos(mapa.informacoes, inimigo.inimigoLinha1[i], tiro.pos, mapa.altura);
            tiro = TiraTiroDaTela(tiro);
            mapa.tiro = tiro;
            inimigo.inimigoLinha1[i] = TiraInimigoDaTela(inimigo.inimigoLinha1[i]);
            mapa.inimigo = inimigo;
            return mapa;
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 2); i++)
    {
        if (HouveColisao(tiro.pos, inimigo.inimigoLinha2[i]))
        {
            PrintaResumoInimigoAtingido(diretorio, iteracao, i+1, 2, tiro.pos);
            RegistraRanking(ranking, tiro.pos, iteracao, i+1, 2, mapa.altura);
            mapa.informacoes = AdicionaPontos(mapa.informacoes, inimigo.inimigoLinha2[i], tiro.pos, mapa.altura);
            tiro = TiraTiroDaTela(tiro);
            mapa.tiro = tiro;
            inimigo.inimigoLinha2[i] = TiraInimigoDaTela(inimigo.inimigoLinha2[i]);
            mapa.inimigo = inimigo;
            return mapa;
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 3); i++)
    {
        if (HouveColisao(tiro.pos, inimigo.inimigoLinha3[i]))
        {
            PrintaResumoInimigoAtingido(diretorio, iteracao, i+1, 3, tiro.pos);
            RegistraRanking(ranking, tiro.pos, iteracao, i+1, 3, mapa.altura);
            mapa.informacoes = AdicionaPontos(mapa.informacoes, inimigo.inimigoLinha3[i], tiro.pos, mapa.altura);
            tiro = TiraTiroDaTela(tiro);
            mapa.tiro = tiro;
            inimigo.inimigoLinha3[i] = TiraInimigoDaTela(inimigo.inimigoLinha3[i]);
            mapa.inimigo = inimigo;
            return mapa;
        }
    }
    return mapa;
}

bool HouveColisao(tPosicao tiro, tPosicao inimigo)
{
     /*
        Esta funcao verifica se houve colisao entre o tiro e o inimigo.
        A colisao eh detectada comparando as posicoes do tiro e do inimigo em diversas combinacoes.
        Se houver colisao, retorna true; caso contrario, retorna false.
    */

    if (inimigo.posX != -1)
    {
        if (tiro.posX == inimigo.posX - 1 && tiro.posY == inimigo.posY - 1)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 2 && tiro.posY == inimigo.posY - 1)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 2 && tiro.posY == inimigo.posY - 2)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 1 && tiro.posY == inimigo.posY - 2)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX && tiro.posY == inimigo.posY - 1)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX && tiro.posY == inimigo.posY)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 1 && tiro.posY == inimigo.posY)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX && tiro.posY == inimigo.posY - 2)
        {
            return true;
        }
        if (tiro.posX == inimigo.posX - 2 && tiro.posY == inimigo.posY)
        {
            return true;
        }
    }
    return false;
}

int RetornaTotalInimigos(tInimigo inimigo)
{
    /*
        Esta funcao retorna o total de inimigos somando os inimigos nas tres fileiras.
    */
    return inimigo.totalInimigosLinha1 + inimigo.totalInimigosLinha2 + inimigo.totalInimigosLinha3;
}

int InimigosRestantes(tInimigo inimigo)
{
    /*
        Esta funcao retorna o numero de inimigos restantes nas tres fileiras, 
        verificando se a posicao x do inimigo eh diferente de -1 (inimigo ainda esta na tela).
    */
    int total = 0;
    for (int i = 0; i < inimigo.totalInimigosLinha1; i++)
    {
        if (RetornaX(inimigo.inimigoLinha1[i]) != -1)
        {
            total++;
        }
    }
    for (int i = 0; i < inimigo.totalInimigosLinha2; i++)
    {
        if (RetornaX(inimigo.inimigoLinha2[i]) != -1)
        {
            total++;
        }
    }
    for (int i = 0; i < inimigo.totalInimigosLinha3; i++)
    {
        if (RetornaX(inimigo.inimigoLinha3[i]) != -1)
        {
            total++;
        }
    }
    return total;
}

int RetornaTotalInimigosLinha(tInimigo inimigo, int modo)
{
    /*
        Esta funcao retorna o total de inimigos em uma das tres fileiras, 
        dependendo do valor do parametro 'modo'.
        modo 1 para linha 1, modo 2 para linha 2 e modo 3 para linha 3.
    */
    if (modo == 1)
    {
        return inimigo.totalInimigosLinha1;
    }
    if (modo == 2)
    {
        return inimigo.totalInimigosLinha2;
    }
    if (modo == 3)
    {
        return inimigo.totalInimigosLinha3;
    }
    return 0;
}

tInformacoes InicializaInformacoes(tInformacoes info)
{
    /*
        Inicializa a estrutura tInformacoes com os valores padrao.
        Nesse caso, o total de pontos eh inicializado como 0.
    */

    info.totalPontos = 0;
    return info;
}

tInformacoes AdicionaPontos(tInformacoes info, tPosicao inimigo, tPosicao tiro, int altura)
{
    /*
        Esta funcao adiciona pontos a estrutura tInformacoes.
        A pontuacao eh calculada com base na posicao do inimigo e na altura do mapa.
    */

    info.totalPontos += inimigo.posX * (altura - inimigo.posY);
    return info;
}

tInimigo AlterarPosicaoInimigos(tInimigo inimigo, int largura)
{
    /*
        Esta funcao altera a posicao dos inimigos no mapa.
        Primeiro, verifica se os inimigos devem se mover horizontalmente ou verticalmente.
        Se eles vao se mover verticalmente, inverte o coeficiente de movimento.
        Atualiza a posicao dos inimigos e retorna a estrutura atualizada.
    */

    if (inimigo.CoeficienteDeMovimento == 1)
    {
        tPosicao inimigoMaisAhDireita;
        inimigoMaisAhDireita.posX = EncontraMaisProximoDaBorda(inimigo, 1, largura);
        
        if (VaiSairDaBordaHorizontal(inimigoMaisAhDireita, largura, inimigo.CoeficienteDeMovimento))
        {
            inimigo = MovimentaInimigosNaVertical(inimigo);
            inimigo.AvancouNessaIteracao = true;
            return inimigo;
        }
        else
        {
            inimigo = MovimentaInimigosNaHorizontal(inimigo, inimigo.CoeficienteDeMovimento);
            return inimigo;
        }
    }
    if (inimigo.CoeficienteDeMovimento == -1)
    {
        tPosicao inimigoMaisAhEsquerda;
        inimigoMaisAhEsquerda.posX = EncontraMaisProximoDaBorda(inimigo, 2, largura);

        if (VaiSairDaBordaHorizontal(inimigoMaisAhEsquerda, largura, inimigo.CoeficienteDeMovimento))
        {
            inimigo = MovimentaInimigosNaVertical(inimigo);
            inimigo.AvancouNessaIteracao = true;
            return inimigo;
        }
        else
        {
            inimigo = MovimentaInimigosNaHorizontal(inimigo, inimigo.CoeficienteDeMovimento);
            return inimigo;
        }
    }
    return inimigo;
}

tInimigo MovimentaInimigosNaVertical(tInimigo inimigo)
{
    /*
        Movimenta os inimigos na vertical e inverte o coeficiente de movimento 
    */

    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 1); i++)
    {
        if (RetornaX(inimigo.inimigoLinha1[i]) != -1)
        {
            tPosicao posicao = inimigo.inimigoLinha1[i]; 
            posicao.posY += 1;
            inimigo.inimigoLinha1[i] = posicao;
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 2); i++)
    {
        if (RetornaX(inimigo.inimigoLinha2[i]) != -1)
        {
            tPosicao posicao = inimigo.inimigoLinha2[i]; 
            posicao.posY += 1;
            inimigo.inimigoLinha2[i] = posicao;
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 3); i++)
    {
        if (RetornaX(inimigo.inimigoLinha3[i]) != -1)
        {
            tPosicao posicao = inimigo.inimigoLinha3[i]; 
            posicao.posY += 1;
            inimigo.inimigoLinha3[i] = posicao;
        }
    }
    inimigo.CoeficienteDeMovimento = inimigo.CoeficienteDeMovimento * (-1);
    return inimigo;
}

tInimigo MovimentaInimigosNaHorizontal(tInimigo inimigo, int CoeficienteDeMovimento)
{
    /*
        Funcao que movimenta os inimigos na Horizontal
    */
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 1); i++)
    {
        if (RetornaX(inimigo.inimigoLinha1[i]) != -1)
        {
            tPosicao posicao = inimigo.inimigoLinha1[i]; 
            posicao.posX += CoeficienteDeMovimento;
            inimigo.inimigoLinha1[i] = posicao;
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 2); i++)
    {
        if (RetornaX(inimigo.inimigoLinha2[i]) != -1)
        {
            tPosicao posicao = inimigo.inimigoLinha2[i]; 
            posicao.posX += CoeficienteDeMovimento;
            inimigo.inimigoLinha2[i] = posicao;
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 3); i++)
    {
        if (RetornaX(inimigo.inimigoLinha3[i]) != -1)
        {
            tPosicao posicao = inimigo.inimigoLinha3[i]; 
            posicao.posX += CoeficienteDeMovimento;
            inimigo.inimigoLinha3[i] = posicao;
        }
    }
    return inimigo;
}

int EncontraMaisProximoDaBorda(tInimigo inimigo, int modo, int largura)
{
    /*
        O objetivo dessa funcao eh encontrar o inimigo mais proximo da borda do mapa,
        com base no coeficiente de movimento especificado.
        Modo 1 para borda direita e Modo 2 para borda esquerda.
    */
    if (modo == 1)
    {
        tPosicao inimigoMaisAhDireita;
        inimigoMaisAhDireita.posX = 0;

        for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 1); i++)
        {
            if (inimigoMaisAhDireita.posX < RetornaX(inimigo.inimigoLinha1[i]) && RetornaX(inimigo.inimigoLinha1[i]) != -1)
            {
                inimigoMaisAhDireita.posX = RetornaX(inimigo.inimigoLinha1[i]);
            }
        }
        for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 2); i++)
        {
            if (inimigoMaisAhDireita.posX < RetornaX(inimigo.inimigoLinha2[i]) && RetornaX(inimigo.inimigoLinha2[i]) != -1)
            {
                inimigoMaisAhDireita.posX = RetornaX(inimigo.inimigoLinha2[i]);
            }
        }
        for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 3); i++)
        {
            if (inimigoMaisAhDireita.posX < RetornaX(inimigo.inimigoLinha3[i]) && RetornaX(inimigo.inimigoLinha3[i]) != -1)
            {
                inimigoMaisAhDireita.posX = RetornaX(inimigo.inimigoLinha3[i]);
            }
        }
        return inimigoMaisAhDireita.posX;
    }
    if (modo == 2)
    {
        tPosicao inimigoMaisAhEsquerda;
        inimigoMaisAhEsquerda.posX = largura;

        for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 1); i++)
        {
            if (RetornaX(inimigo.inimigoLinha1[i]) < inimigoMaisAhEsquerda.posX && RetornaX(inimigo.inimigoLinha1[i]) != -1)
            {
                inimigoMaisAhEsquerda.posX = RetornaX(inimigo.inimigoLinha1[i]);
            }
        }
        for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 2); i++)
        {
            if (RetornaX(inimigo.inimigoLinha2[i]) < inimigoMaisAhEsquerda.posX && RetornaX(inimigo.inimigoLinha2[i]) != -1)
            {
                inimigoMaisAhEsquerda.posX = RetornaX(inimigo.inimigoLinha2[i]);
            }
        }
        for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 3); i++)
        {
            if (RetornaX(inimigo.inimigoLinha3[i]) < inimigoMaisAhEsquerda.posX && RetornaX(inimigo.inimigoLinha3[i]) != -1)
            {
                inimigoMaisAhEsquerda.posX = RetornaX(inimigo.inimigoLinha3[i]);
            }
        }
        return inimigoMaisAhEsquerda.posX;
    }
    return 0;
}

tTiro AlterarPosicaoTiro(tTiro tiro)
{
    /*
        Esta funcao altera a posicao do tiro, decrementando sua posicao vertical em 1.
    */

    tPosicao posicao = RetornaPosicaoTiro(tiro);
    posicao.posY -= 1;
    tiro.pos = posicao;
    return tiro;
}

tJogador AlterarPosicaoPlayer(tJogador player, char movimento)
{
    /*
        Esta funcao altera a posicao do jogador com base no movimento ('a' para esquerda, 'd' para direita).
    */
    tPosicao posicao = RetornaPosicaoJogador(player);

    if (movimento == 'a')
    {
        posicao.posX -= 1;
        player.pos = posicao;
        return player;
    }
    if (movimento == 'd')
    {
        posicao.posX += 1;
        player.pos = posicao;
        return player;
    }
    return player;
}

tTiro DispararTiro(tJogador player)
{
    /*
        Esta funcao cria e retorna um tiro disparado pelo jogador, definindo a posicao inicial do tiro 
        com base na posicao do jogador e ativando o estado do tiro.
    */

    tTiro tiro;
    tPosicao jogador = RetornaPosicaoJogador(player);
    tiro.pos = PosicionaTiro(jogador);
    tiro.estado = true;
    DesenhaTiro(tiro.desenhoTiro);
    return tiro;
}

void DesenhaTiro(char desenhoTiro[1][2])
{
    /*
        Esta funcao desenha o tiro na matriz desenhoTiro
    */

    desenhoTiro[0][0] = 'o';
    desenhoTiro[0][1] = '\0';
    return;
}

tPosicao PosicionaTiro (tPosicao jogador)
{
    /*
        Esta funcao define a posicao inicial do tiro com base na posicao do jogador,
        ajustando a posicao do tiro para que ele apareca logo acima do jogador.
    */

    tPosicao tiro;
    tiro.posX = jogador.posX - 1;
    tiro.posY = jogador.posY - 2;
    return tiro;
}

bool VaiSairDaBordaHorizontal(tPosicao entidade, int largura, int coeficiente)
{
    /*
        Esta funcao verifica se uma entidade vai sair da borda horizontal do mapa
        com base na sua posicao atual, na largura do mapa e no coeficiente de movimento.
    */

    if (entidade.posX + coeficiente == largura || entidade.posX + coeficiente == 1)
    {
        return true;
    }
    return false;
}

bool InimigoAvancou(tInimigo inimigo)
{
    /*
        Esta funcao verifica se um inimigo avancou na iteracao atual.
    */

    if (inimigo.AvancouNessaIteracao == true)
    {
        return true;
    }
    return false;
}

tInimigo ResetaFlagInimigo(tInimigo inimigo)
{
    /*
        Esta funcao reseta a flag que indica se um inimigo avancou na iteracao atual.
    */

    inimigo.AvancouNessaIteracao = false;
    return inimigo;
}

void PrintaPontosIteracao(FILE *diretorio, tInformacoes info, int i)
{
    /*
        Esta funcao imprime no arquivo especificado o total de pontos e o numero de iteracoes.
    */

    fprintf(diretorio, "Pontos: %i | Iteracoes: %i\n", info.totalPontos, i);
    return;
}

tInimigo VerificaBonus(tInimigo inimigo, tInformacoes info)
{
    /*
        Esta funcao verifica e altera o bonus do inimigo, mudando seu desenho atual
        se o bonus estiver ativo.
    */

    if (inimigo.desenhoAtual == 2 && info.bonus == 1)
    {
        inimigo.desenhoAtual = 0;
    }
    else if (inimigo.desenhoAtual < 2 && info.bonus == 1)
    {
        inimigo.desenhoAtual++;
    }
    return inimigo;
}

void PrintaResumoInimigoAtingido(FILE *diretorio, int i, int indice, int fileira, tPosicao bala)
{
    /*
        Esta funcao imprime no arquivo especificado o resumo de quando um inimigo foi atingido por um tiro,
        informando a iteracao, o indice do inimigo, a fileira e a posicao em que foi atingido.
    */

    fprintf(diretorio, "[%d] Inimigo de indice %d da fileira %d foi atingido na posicao (%d %d).\n", i, indice, fileira, bala.posX+1, bala.posY+1);
    return;
}

void PrintaResumoInimigoLateral(FILE *diretorio, int iteracao, int largura, tInimigo inimigo)
{
    /*
        Esta funcao imprime no arquivo especificado o resumo de quando um inimigo colidiu na lateral do mapa,
        informando a iteracao, o indice do inimigo e a fileira em que estava.
    */

    // * (-1) pq o coeficiente ja foi invertido na iteracao atual

    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 1); i++)
    {
        if (VaiSairDaBordaHorizontal(inimigo.inimigoLinha1[i], largura, inimigo.CoeficienteDeMovimento * (-1)))
        {
            if (inimigo.CoeficienteDeMovimento * (-1) > 0)
            {
                fprintf(diretorio, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral direita.\n", iteracao, i+1, 1);
            }
            if (inimigo.CoeficienteDeMovimento * (-1) < 0)
            {
                fprintf(diretorio, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral esquerda.\n", iteracao, i+1, 1);
            }
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 2); i++)
    {
        if (VaiSairDaBordaHorizontal(inimigo.inimigoLinha2[i], largura, inimigo.CoeficienteDeMovimento * (-1)))
        {
            if (inimigo.CoeficienteDeMovimento * (-1) > 0)
            {
                fprintf(diretorio, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral direita.\n", iteracao, i+1, 2);
            }
            if (inimigo.CoeficienteDeMovimento * (-1) < 0)
            {
                fprintf(diretorio, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral esquerda.\n", iteracao, i+1, 2);
            }
        }
    }
    for (int i = 0; i < RetornaTotalInimigosLinha(inimigo, 3); i++)
    {
        if (RetornaX(inimigo.inimigoLinha3[i]) != -1)
        {
            if (VaiSairDaBordaHorizontal(inimigo.inimigoLinha3[i], largura, inimigo.CoeficienteDeMovimento * (-1)))
            {
                if (inimigo.CoeficienteDeMovimento * (-1) > 0)
                {
                    fprintf(diretorio, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral direita.\n", iteracao, i+1, 3);
                }
                if (inimigo.CoeficienteDeMovimento * (-1) < 0)
                {
                    fprintf(diretorio, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral esquerda.\n", iteracao, i+1, 3);
                }
            }
        }
    }
    return;
}

bool VerificaResumoJogadorLateral(FILE *diretorio, bool flag, char movimento, int iteracao)
{
    /*
        Esta funcao verifica se o jogador colidiu na lateral do mapa e imprime o resumo
        no arquivo se a flag estiver ativa.
    */

    if (flag == true)
    {
        if (movimento == 'a')
        {
            PrintaResumoJogadorLateral(diretorio, iteracao, 1);
        }
        if (movimento == 'd')
        {
            PrintaResumoJogadorLateral(diretorio, iteracao, 2);
        }
        return false;
    }
    return false;
}

void PrintaResumoJogadorLateral(FILE *diretorio, int i, int modo)
{
    /*
        Esta funcao imprime no arquivo o resumo de quando o jogador colidiu na lateral,
        informando a iteracao e o lado da colisao, tudo isso com base em modos:

        modo 1 para esquerda e modo 2 para direita
    */
    if (modo == 1)
    {
        fprintf(diretorio, "[%d] Jogador colidiu na lateral esquerda.\n", i);
    }

    if (modo == 2)
    {
        fprintf(diretorio, "[%d] Jogador colidiu na lateral direita.\n", i);
    }
    return;
}

tEstatisticas InicializaEstatisticas()
{
    /*
        Esta funcao inicializa as estatisticas do jogo, zerando todos os contadores.
    */

    tEstatisticas stats;
    stats.movimentos = 0;
    stats.tirosEfetivos = 0;
    stats.tirosNaoEfetivos = 0;
    stats.avancoInimigo = 0;
    return stats;
}

void InicializaRanking(tRanking ranking[], int totalInimigos)
{
    /*
        Esta funcao inicializa o ranking dos inimigos, definindo todos os valores como -1 (valores impossiveis),
        para evitar possiveis erros.
    */
    for (int i = 0; i < totalInimigos; i++)
    {
        ranking[i].indice = -1;
        ranking[i].fileira = -1;
        ranking[i].linha = -1;
        ranking[i].iteracao = -1;
    }
    return;
}

tHeatMap InicializaHeatMap(int altura, int largura)
{
    /*
        Esta funcao inicializa o heatmap do jogo, zerando todas as posicoes do mapa.
    */
    tHeatMap heatmap;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            heatmap.mapa[i][j] = 0;
        }
    }
    heatmap.altura = altura;
    heatmap.largura = largura;
    return heatmap;
}

tHeatMap AlteraHeatMapJogador(tHeatMap heatmap, tJogador jogador, int largura)
{
    /*
        Esta funcao altera o heatmap com base na posicao do jogador,
        incrementando os valores nas posicoes proximas ao jogador.
    */

    tPosicao pJogador = RetornaPosicaoJogador(jogador);

    if (heatmap.mapa[pJogador.posY-2][pJogador.posX] != 999)
        heatmap.mapa[pJogador.posY-2][pJogador.posX]++;
    if (heatmap.mapa[pJogador.posY-2][pJogador.posX-1] != 999)
        heatmap.mapa[pJogador.posY-2][pJogador.posX-1]++;
    if (heatmap.mapa[pJogador.posY-2][pJogador.posX-2] != 999)
        heatmap.mapa[pJogador.posY-2][pJogador.posX-2]++;

    if (heatmap.mapa[pJogador.posY-1][pJogador.posX] != 999)
        heatmap.mapa[pJogador.posY-1][pJogador.posX]++;
    if (heatmap.mapa[pJogador.posY-1][pJogador.posX-1] != 999)
        heatmap.mapa[pJogador.posY-1][pJogador.posX-1]++;
    if (heatmap.mapa[pJogador.posY-1][pJogador.posX-2] != 999)
        heatmap.mapa[pJogador.posY-1][pJogador.posX-2]++;

    if (heatmap.mapa[pJogador.posY][pJogador.posX] != 999)
        heatmap.mapa[pJogador.posY][pJogador.posX]++;
    if (heatmap.mapa[pJogador.posY][pJogador.posX-1] != 999)
        heatmap.mapa[pJogador.posY][pJogador.posX-1]++;
    if (heatmap.mapa[pJogador.posY][pJogador.posX-2] != 999)
        heatmap.mapa[pJogador.posY][pJogador.posX-2]++;

    return heatmap;
}

tHeatMap AlteraHeatMapTiro(tHeatMap heatmap, tTiro tiro)
{
    /*
        Esta funcao altera o heatmap com base na posicao do tiro,
        incrementando o valor na posicao atual do tiro.
    */

    tPosicao pTiro = RetornaPosicaoTiro(tiro);
    if (pTiro.posX != -1)
    {
        heatmap.mapa[pTiro.posY][pTiro.posX]++;
    }
    return heatmap;
}

void RegistraRanking(tRanking ranking[], tPosicao tiro, int iteracao, int indice, int fileira, int alturaMapa)
{
    /*
        Esta funcao registra a posicao do tiro no ranking,
        atualizando os valores do ranking com base na iteracao atual, indice e fileira.
    */

    ranking[0].indice = indice;
    ranking[0].fileira = fileira;
    ranking[0].linha = alturaMapa - tiro.posY;
    ranking[0].iteracao = iteracao;

    int i = 1;

    // Medida defensiva do codigo para deixar a posicao 0 do array invalida, para facilitar a insercao de elementos
    // no array
    while(1)
    {
        if (ranking[i].indice == -1)
        {
            ranking[i] = ranking[0];
            ranking[0].indice = -1;
            ranking[0].fileira = -1;
            ranking[0].linha = -1;
            ranking[0].iteracao = -1;
            break;
        }
        i++;
    }
    return;
}

void PrintaRanking(FILE *diretorio, tRanking ranking[], int total)
{
    /*
        Esta funcao imprime o ranking no arquivo, ordenando os inimigos atingidos
        por linha e iteracao.
    */

    for (int i = 1; i < total; i++)
    {
        for (int j = i+1; j < total; j++)
        {
            if (ranking[i].linha > ranking[j].linha)
            {
                tRanking aux = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = aux;
            }
        }
    }
    for (int i = 1; i < total; i++)
    {
        for (int j = i+1; j < total; j++)
        {
            if (ranking[i].linha == ranking[j].linha && ranking[i].iteracao > ranking[j].iteracao)
            {
                tRanking aux = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = aux;
            }
        }
    }
    fprintf(diretorio, "indice,fileira,linha,iteracao\n");
    for (int i = 1; i < total; i++)
    {
        fprintf(diretorio, "%d,%d,%d,%d\n", ranking[i].indice, ranking[i].fileira, ranking[i].linha, ranking[i].iteracao);
    }
    return;
}

void PrintaEstatisticas(FILE *diretorio, tEstatisticas estatisticas)
{
    /*
        Esta funcao imprime as estatisticas do jogo no arquivo, incluindo o numero total
        de movimentos, tiros efetivos, tiros nao acertados e o numero de descidas dos inimigos.
    */

    fprintf (diretorio, "Numero total de movimentos (A ou D): %d;\n", estatisticas.movimentos);
    fprintf (diretorio, "Numero de tiros efetivos: %d;\n", estatisticas.tirosEfetivos);
    fprintf (diretorio, "Numero de tiros que nao acertaram: %d;\n", estatisticas.tirosNaoEfetivos);
    fprintf (diretorio, "Numero de descidas dos inimigos: %d;\n", estatisticas.avancoInimigo);
    return;
}

void PrintaHeatMap(FILE *diretorio, tHeatMap heatmap)
{
    /*
        Esta funcao imprime o heatmap no arquivo, mostrando a quantidade de vezes que cada
        posicao do mapa foi ocupada pelo tiro ou pelo jogador.
    */

    for (int i = 0; i < heatmap.altura; i++)
    {
        for (int j = 0; j < heatmap.largura; j++)
        {
            fprintf (diretorio, "%3d ", heatmap.mapa[i][j]);
        }
        fprintf (diretorio, "\n");
    }
    return;
}