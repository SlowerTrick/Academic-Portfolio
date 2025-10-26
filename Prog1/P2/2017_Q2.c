#include <stdio.h>

int EhIgual(int a, int b) {
    return a == b;
}

int InverteNumero(int num) {
    int invertido = 0;
    while (num != 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}

int main() {
    int num, count = 0;
    while (scanf("%d", &num) == 1) {
        if (EhIgual(num, InverteNumero(num))) {
            count++;
        }
    }
    printf("COUNT:%d", count);
    return 0;
}