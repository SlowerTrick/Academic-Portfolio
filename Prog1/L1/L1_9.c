#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);

    if(c >= 'a' && c <= 'z')
    {
        printf("%c(%d)", c - 32, c - 32);
    } else if(c >= 'A' && c <= 'Z') {
        printf("A letra deve ser minuscula!");
    } else {
        printf("Nao e letra!");
    }

    return 0;
}
