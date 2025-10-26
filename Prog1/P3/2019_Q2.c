#include <stdio.h>
#include <string.h>

#define MAX 100

int contar_padroes_horizontais(char matriz[][MAX], int linhas, int colunas, int tamanho_padroes) {
    int cont = 0;
    int i = 0, j = 0, k = 0;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j <= colunas - tamanho_padroes; j++) {
            int k;
            for (k = 0; k < tamanho_padroes; k++) {
                if (matriz[i][j + k] != 'X') {
                    break;
                }
            }
            if (k == tamanho_padroes) {
                cont++;
            }
        }
    }
    return cont;
}

int contar_padroes_verticais(char matriz[][MAX], int linhas, int colunas, int tamanho_padroes) {
    int cont = 0;
    int i = 0, j = 0;
    for (i = 0; i <= linhas - tamanho_padroes; i++) {
        for (j = 0; j < colunas; j++) {
            int k;
            for (k = 0; k < tamanho_padroes; k++) {
                if (matriz[i + k][j] != 'X') {
                    break;
                }
            }
            if (k == tamanho_padroes) {
                cont++;
            }
        }
    }
    return cont;
}

int main() {
    int tamanho_padroes, linhas, colunas;
    char orientacao;
    char matriz[MAX][MAX];

    // Leitura da entrada
    scanf("%d%c", &tamanho_padroes, &orientacao);
    scanf("%d %d", &linhas, &colunas);
    int i = 0;
    for (i = 0; i < linhas; i++) {
        scanf("%s", matriz[i]);
    }

    int cont = 0;
    if (orientacao == 'H') {
        cont = contar_padroes_horizontais(matriz, linhas, colunas, tamanho_padroes);
        printf("CONT: H %d\n", cont);
    } else if (orientacao == 'V') {
        cont = contar_padroes_verticais(matriz, linhas, colunas, tamanho_padroes);
        printf("CONT: V %d\n", cont);
    }

    return 0;
}
