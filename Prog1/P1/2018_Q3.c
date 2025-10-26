#include <stdio.h>
#include <ctype.h>

int main (void)
{
    char primeiro1 = 0, segundo1 = 0, terceiro1 = 0, primeiro2 = 0, segundo2 = 0, terceiro2 = 0;
    scanf("%c %c %c %c %c %c", &primeiro1, &segundo1, &terceiro1, &primeiro2, &segundo2, &terceiro2);

    if (!(isdigit(primeiro1)) || !(isdigit(primeiro2)))
    {
        printf ("Codigo invalido!");
        return 1;
    }

    if (!(segundo1 >= 'a' && segundo1 <= 'z') || !(segundo2 >= 'a' && segundo1 <= 'z'))
    {
        printf ("Codigo invalido!");
        return 1;
    }

    if (!isalpha(terceiro1) || !isalpha(terceiro2))
    {
        printf ("Codigo invalido!");
        return 1;
    }

    if (primeiro1 == primeiro2)
    {
        printf ("I");
    }
    else
    {
        printf ("D");
    }

    if (segundo1 == segundo2)
    {
        printf ("I");
    }
    else
    {
        printf ("D");
    }

    if (terceiro1 == terceiro2)
    {
        printf ("I\n");
    }
    else if (toupper(terceiro1) == toupper(terceiro2))
    {
        printf ("C\n");
    }
    else
    {
        printf ("D\n");
    }
}
