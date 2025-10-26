#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main (void)
{
    float x, area1, raio2;

    scanf ("%f", &x);

    area1 = pow(x, 2) * PI;
    raio2 = sqrt(((area1/2)/PI));
    printf ("%.2f %.2f\n", area1, raio2);
}
