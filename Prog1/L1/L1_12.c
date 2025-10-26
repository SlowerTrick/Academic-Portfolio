#include <stdio.h>

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 < n2 && n1 < n3) {
        printf("N1 = %d, ", n1);
        if (n2 < n3) {
            printf("N2 = %d, N3 = %d\n", n2, n3);
        } else {
            printf("N3 = %d, N2 = %d\n", n3, n2);
        }
    } else if (n2 < n1 && n2 < n3) {
        printf("N2 = %d, ", n2);
        if (n1 < n3) {
            printf("N1 = %d, N3 = %d\n", n1, n3);
        } else {
            printf("N3 = %d, N1 = %d\n", n3, n1);
        }
    } else {
        printf("N3 = %d, ", n3);
        if (n1 < n2) {
            printf("N1 = %d, N2 = %d\n", n1, n2);
        } else {
            printf("N2 = %d, N1 = %d\n", n2, n1);
        }
    }
    
    getchar();
    return 0;
}
