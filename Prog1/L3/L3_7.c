#include <stdio.h>
#include <stdbool.h>

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
int area (int x1, int y1, int x2, int y2);

int main (void)
{
    int r1_x1 = 0, r1_y1 = 0, r1_x2 = 0, r1_y2 = 0;
    int r2_x1 = 0, r2_y1 = 0, r2_x2 = 0, r2_y2 = 0;

    scanf ("%i%i%i%i", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf ("%i%i%i%i", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    printf ("RESP:%i", area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2));
}

int area (int x1, int y1, int x2, int y2)
{
    int base = x2 - x1;
    int altura = y2 - y1;

    return base * altura;
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2)
{
    int area1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
    int area2 = area(r2_x1, r2_y1, r2_x2, r2_y2);
    int areatotal = area1 + area2;
    int uniaox = 1, uniaoy = 1, uniao = 0;

    if (r2_x1 < r1_x2 && r2_y1 < r1_y2)
    {
        uniaox = r1_x2 - r2_x1;
        uniaoy = r1_y2 - r2_y1;
        uniao = uniaox * uniaoy;
    }

    return areatotal - uniao;
}