#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x, y;
    scanf("%i%i%i%i%i%i", &x1, &y1, &x2, &y2, &x, &y);

    int xmin, xmax, ymin, ymax;

    if (x1 < x2) {
        xmin = x1;
        xmax = x2;
    } else {
        xmin = x2;
        xmax = x1;
    }

    if (y1 < y2) {
        ymin = y1;
        ymax = y2;
    } else {
        ymin = y2;
        ymax = y1;
    }

    if (x >= xmin && x <= xmax && y >= ymin && y <= ymax) {
        printf("Dentro\n");
    } else {
        printf("Fora\n");
    }

    return 0;
}