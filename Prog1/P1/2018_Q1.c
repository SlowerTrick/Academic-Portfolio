#include <stdio.h>

int main (void)
{
    int x = 0, y = 0, a = 0, b = 0;
    scanf ("%i%i%i%i", &x, &y, &a, &b);

    if (x < a && y < b)
    {
        printf ("(%i,%i)", x, b);
        printf ("(%i,%i)", x, y);
        printf ("(%i,%i)", a, y);
        printf ("(%i,%i)\n", a, b);
    }
    if (x > a && y > b)
    {
        printf ("(%i,%i)", a, y);
        printf ("(%i,%i)", a, b);
        printf ("(%i,%i)", x, b);
        printf ("(%i,%i)\n", x, y);
    }
    if (x < a && y > b)
    {
        printf ("(%i,%i)", x, y);
        printf ("(%i,%i)", x, b);
        printf ("(%i,%i)", a, b);
        printf ("(%i,%i)\n", a, y);
    }
    if (x > a && y < b)
    {
        printf ("(%i,%i)", a, b);
        printf ("(%i,%i)", a, y);
        printf ("(%i,%i)", x, y);
        printf ("(%i,%i)\n", x, b);
    }
    return 0;
}