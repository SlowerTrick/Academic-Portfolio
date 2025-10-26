#include <stdio.h>
#include <math.h>

int main (void)
{
    int x, y;
    scanf ("%i%i", &x, &y);

    if (x > y)
    {
        printf ("N1 = %i\n", x);
    }
    else if (x == y)
    {
        printf ("N1 = N2\n");
    }
    else
    printf ("N2 = %i\n", y);
}
