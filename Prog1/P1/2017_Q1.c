#include <stdio.h>

int main() {
    int num1, num2;
    char op;

    scanf("%d %d %c", &num1, &num2, &op);

    switch(op) 
    {
        case '+':
            printf("RESP:%d\n", num1 + num2);
            break;
        case '-':
            printf("RESP:%d\n", num1 - num2);
            break;
        case '*':
            printf("RESP:%d\n", num1 * num2);
            break;
        case '/':
            if(num2 != 0) {
                printf("RESP:%d\n", num1 / num2);
            } else {
                printf("Invalido\n");
            }
            break;
        default:
            printf("Invalido\n");
    }

    return 0;
}