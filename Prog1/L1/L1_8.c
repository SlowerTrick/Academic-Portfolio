#include <stdio.h>
#include <math.h>

int main (void)
{
    char y = 0;
    scanf ("%c", &y);

    if (y == 'a' || y == 'e'|| y == 'i' || y == 'o' || y == 'u' || y == 'A' || y == 'E'|| y == 'I'|| y == 'O' || y == 'U')
    {
        printf ("Vogal\n");
    }
    else
    {
        printf ("Nao vogal\n");
    }

    return 0;
}
