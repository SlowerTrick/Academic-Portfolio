#include <stdio.h>

int main() {
    int x = 0;
    scanf ("%i", &x);

    char *mes[12] = {"Jan.", "Fev.", "Mar.", "Abr.", "Mai.", "Jun.", "Jul.", "Ago.", "Set.", "Out.", "Nov.", "Dec."};

    if (x < 1 || x > 12) {
        printf ("Invalido.\n");
        return 1;
    }

    printf ("%s\n", mes[x-1]);

    return 0;
}
