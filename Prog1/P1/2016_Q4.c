#include <stdio.h>

int main (void)
{
    int n1, n2, n3;
    int x = 0, y = 0, z = 0;
    scanf ("%i%i%i", &n1, &n2, &n3);

    if (n1 < 100 && n2 < 100 & n3 < 100)
    {
        printf ("Nenhum");
        return 0;
    }

    if (n1 > 99)
    {
        x = n1 / 100;
        if (x > 9)
        {
            x = x % 10;
        }
    }
    else
    {
        x = 9999999;
    }

    if (n2 > 99)
    {
        y = n2 / 100;
        if (x > 9)
        {
            y = y % 10;
        }
    }
    else
    {
        y = 9999999;
    }

    if (n3 > 99)
    {
        z = n3 / 100;
        if (z > 9)
        {
            z = z % 10;
        }
    }

    else
    {
        z = 9999999;
    }

    if (x < y && x < z)
    {
        printf ("N1");
        return 0;
    }
    if (y < x && y < z)
    {
        printf ("N2");
        return 0;
    }
    if (z < x && z < y)
    {
        printf ("N3");
        return 0;
    }
    if ((x == y || x == z) && x != 9999999)
    {
        printf ("N1");
        return 0;
    }
    if (y == z && y != 9999999)
    {
        printf ("N2");
        return 0;
    }
}