#include <stdio.h>
#include <math.h>

int main (void)
{
    float x = 0;
    char y = 0;
    float temp = 0;
    scanf ("%f %c", &x, &y);

    if (y == 'c' || y == 'C')
    {
        temp = (x * 1.8) + 32;
        printf ("%.2f (F)\n", temp);
    }
    if (y == 'f' || y == 'F')
    {
        temp = (x - 32) / 1.8;
        printf ("%.2f (C)\n", temp);
    }

    return 0;
}
